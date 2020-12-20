#include "uccompiler.h"
#include "semantic.h"
#include "symbol_table.h"
#include <ctype.h>

char name[20];
char chartype[20];

void check_extra(char* str){
    int i = 0;
    while (i<strlen(str) - 1 && str[i] != '(')
        i++;
    if (str[i] == '('){
        str[i]='\0';
    }
    
}

void check_program(struct Node* node){ 
	if (node == NULL)
		return;

	if (node->type != NULL){
		if (strcmp(node->type, "Program")==0){
			start_table();
		}

		if (strcmp(node->type, "FuncDefinition")==0){
			check_func_definition(node);
		}

		if (strcmp(node->type, "FuncDeclaration")==0){
			check_func_declaration(node);
		}

		if (strcmp(node->type, "Declaration")==0){
			check_declaration(node);
		}
	}
	Node* aux = node->son;

	while(aux != NULL){
		if (node->type != NULL && strcmp(node->type, "Program")==0)
			strcpy(name,"Global");
		check_program(aux);
		aux = aux->brother;	
	}
}

void check_func_definition(struct Node* node){
	Node * son = node->son;
	char * type = check_type_specs(node->son->type);
	char * id = strdup(node->son->brother->son->id);
	
	while(son != NULL &&  strcmp(son->type,"ParamList") != 0){
            son = son->brother;
    }
    if(son == NULL) return;

	//save the current id on the global char name
	strcpy(name, id);

    char * parameter = check_parameter(son);
	char ** parameters = check_parameters(son);

	insert(id, type, parameter, "Global");
	init_function_table(id, parameters, 1);
	insert("return", type, "", id);
	insert_parameters_function(son, id);
}

void check_func_declaration(struct Node* node){

	Node * son = node->son;
	Node * brother = node->son->brother;

	char * type = check_type_specs(son->type);
	char * id = strdup(brother->id);
	
	while(strcmp(son->type,"ParamList") != 0){
            son = son->brother;
    }
    if(son == NULL) return;

	
    char * parameter = check_parameter(son);
	char ** parameters = check_parameters(son);

	insert(id, type, parameter, "Global");
	init_function_table(id, parameters, 1);
	
}

void check_declaration(struct Node* node){
	
	if (node->id != NULL){
		char * id = strdup(node->son->id);
	}
	else {
		char * type = check_type_specs(node->son->type);
		char * id = strdup(node->son->brother->id);
			
	}
	strcpy(chartype,type);
	insert(id, type, "", name);
}


char * check_type_specs(char * typespec){
	char * type;

	char typelist[][100]  = {"Char","Int","Void","Double"};


	for (int i=0; i< 4; i++){

		if (strcmp(typespec, typelist[i]) == 0){

			char * str = typelist[i];
			for(int i = 0; str[i]; i++){
			  str[i] = tolower(str[i]);
			}
			type = str;
		}
	}

			

	return strdup(type);
}


char * check_parameter(struct Node* node){
	char parameter[200] = "(";

	Node* aux = node->son;

	while(aux != NULL){
		char * type = check_type_specs(aux->son->type);	
		strcat(parameter,type);
		aux = aux->brother;
		if (aux != NULL)
			strcat(parameter,",");
	}
	strcat(parameter,")");
	return strdup(parameter);
}

char ** check_parameters(struct Node* node){
	//numero maximo de parametros é 100
	char ** parameters = (char **) malloc(sizeof(char *) * 100);
	int i = 1;
	Node* aux = node->son;

	while(aux != NULL){
		char * type = check_type_specs(aux->son->type);	
		parameters[i] = type;
		aux = aux->brother;
		
	}
	return parameters;
}

void insert_parameters_function(struct Node* node, char * typetable){
	Node* aux = node->son;

	while(aux != NULL){
		if (aux->son->brother != NULL){
			char * type = check_type_specs(aux->son->type);	
			insert(aux->son->brother->id, type, "\tparam", typetable);
		}
		aux = aux->brother;
	}
}



void check_tree(struct Node* node){
	if (node == NULL)
		return;
	if (node->type != NULL){

		if (strcmp(node->type, "FuncDefinition") == 0){
			char * id = strdup(node->son->brother->son->id);
			check_func_body(node->son->brother->brother, id);
			strcpy(name, "");
		}

		if (strcmp(node->type, "Declaration") == 0 && strcmp(name, "Global") == 0){
			if (node->id == NULL )
				check_func_body(node, "Global");
		}
	}

	Node* aux = node->son;

	while(aux != NULL){
		if (node->type != NULL && strcmp(node->type, "Program")==0)
			strcpy(name,"Global");
		check_tree(aux);
		aux = aux->brother;	
	}
}


void check_func_body(struct Node* node, char * typetable){
	int flag = 0;
	char * extra;

	if (node == NULL)
		return;

	char* typespec= node->type ;

	if (typespec != NULL){
		char typelist  [][100]= {"Declaration","Id", "Or", "And","BitWiseAnd","BitWiseOr","BitWiseXor","Mod","Not","Eq",
			"Ne","Le","Ge","Lt","Gt","IntLit","ChrLit","RealLit"};

		
		for (int i=0; i< len(typelist); i++){

			if (strcmp(typespec, typelist[i]) == 0){
				switch(i){
					case 0: // declaration
						flag = 1;
						break;
					case 1:// id
						char * type = search_type(node->id, typetable);
						char * extra;
						strcat(extra," - ");

						if (strcmp(type, "") == 0){
							strcat(extra,"undef");
						}
						else{
							strcat(extra,type);
						}

						int size = strlen(extra)+1
						node->extra= strndup(extra, size)
						break;
					case 17: // reallit
						node->extra = strdup(" - double");
						break;

					default: // or and bitwise(all) mod not eq ne le ge lt gt intlit chrlit
						node->extra = strdup(" - int");
				}
			}
		}
		
	

		Node* aux = node->son;

		char typelist2 [][100]= {"Plus","Minus","Store","Comma","Add","Sub","Mul","Div","Call"};


		while(aux != NULL){
			if (flag == 1 && aux->type != NULL && strcmp(aux->type, "Id") == 0){
				if (aux->brother != NULL &&aux->brother->type != NULL && strcmp(aux->brother->type, "Id") == 0){
					aux = aux->brother;
					check_func_body(aux, typetable);
				}
			}
			
			else{
				check_func_body(aux, typetable);
			}

			aux = aux->brother;	
		}

		Node* aux1= node->son;


		for (int i=0; i< len(typelist2); i++){
			if (strcmp(typespec, typelist2[i]) == 0){
				switch(i){
					case 0: case 1: case 2: case 3: //plus minus store comma
						if (strcmp(node->type, "Comma") == 0)
		                  	aux1 = aux1->brother;
		                  
						while (strcmp(aux1->type,"Aux") == 0)
							aux1 = aux1->son;

						extra= strdup(aux1->extra);
						check_extra(extra);
						node->extra = strdup(extra);
						break;

					case 8: //call
						Node* aux2 =  node->son;
						while (strcmp(aux2->type, "Aux") == 0)
							aux2 = aux2->son;

						char * type = search_type(aux2->id, "Global");
						char * extra;
						strcat(extra," - ");

						if (strcmp(type, "") == 0){
							strcat(extra,"undef");
						}
						else{
							strcat(extra,type);
							checkextra(extra);
						}
						node->extra= extra;

						break;


					default: //case 4:	case 5: case 6: case 7:  add sub div mul
						
						while (strcmp(aux1->type,"Aux") == 0)
							aux1 = aux1->son;
						
						Node* aux2 = node->son->brother;
						while (strcmp(aux2->type,"Aux") == 0)
							aux2 = aux2->son;

						char * extra1 = strdup(aux1->extra);
						char * extra2 = strdup(aux2->extra);
						check_extra(extra1);
						check_extra(extra2);

						char* extra3;

						char extralist [][100]= {" - undef"," - double"," - int"," - short"," - char"};


						for (int i=0; i< len(extralist); i++){
							if (strcmp(extra1, extralist[i]) == 0)
								extra3= extra1;
							if (strcmp(extra2, extralist[i]) == 0)
								extra3= extra2;

						}

						node->extra = extra3;
						break;
		
				}	
			}

	
		}

	}


}




