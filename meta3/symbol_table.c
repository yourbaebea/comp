
#include "symbol_table.h"
#include <ctype.h>

Table * symboltable;

void start_table(){
	symboltable = (Table*) malloc(sizeof(Table));
	strcpy(symboltable->type, strdup("Global"));
	symboltable->name = strdup("");
	symboltable->flag = 1;
	symboltable->parameters = NULL;

	insert("putchar","int(int)","","Global");
	insert("getchar","int(void)","","Global");
}

void init_function_table(char * name, char ** parameters, int flag){
	Table* auxtable = (Table*) malloc(sizeof(Table));
	strcpy(auxtable->type, strdup("Function"));
	symboltable->name = strdup(name);
	symboltable->flag = flag;
	symboltable->parameters= parameters;
	
	Table * aux2table = (Table*) malloc(sizeof(Table));
	aux2table= symboltable;

	if (aux2table == NULL){
		aux2table = auxtable;
		return;
	}
	
	while (aux2table->next != NULL){
		if (strcmp(aux2table->name, name)==0 && aux2table->flag==0){
			aux2table->flag = 1;
			free(auxtable);
			return;
		}
		aux2table = aux2table->next;
	}

	if (strcmp(aux2table->name, name)==0 && aux2table->flag==0){
		aux2table->flag = 1;
		free(auxtable);
		return;
	}

	aux2table->next = auxtable;

}


void insert(char * id, char * type, char * parameter, char * typetable){
	NodeTable* auxnodetable = (NodeTable*) malloc(sizeof(NodeTable));
	auxnodetable->id = id;
	auxnodetable->type = type;
	auxnodetable->parameter = parameter;
	auxnodetable->next = NULL;

	Table * aux2table = (Table*) malloc(sizeof(Table));

	if (strcmp(typetable, "Global")==0)
		aux2table = symboltable;
	else{
		aux2table = symboltable->next;
		while (aux2table != NULL && strcmp(typetable,aux2table->name)!=0)
			aux2table = aux2table->next;
	}


	if (aux2table->nodetable == NULL){
		aux2table->nodetable = auxnodetable;
		return;
	}
	NodeTable* nodetable = (NodeTable*) malloc(sizeof(NodeTable));
	nodetable = aux2table->nodetable;
	while (nodetable->next != NULL){

		if (strcmp(nodetable->id, id)==0){
			free(auxnodetable);
			return;
		}
		nodetable = nodetable->next;
	}

	if (strcmp(nodetable->id, id)==0){
		free(auxnodetable);
		return;
	}
	
	nodetable->next = auxnodetable;	
}


void print_tables(){
	Table * auxtable = symboltable;
	NodeTable* nodetable = (NodeTable*) malloc(sizeof(NodeTable));
	

	while (auxtable != NULL){
		if (auxtable->flag == 1){
			if (strcmp(auxtable->type,"Global")==0)
				printf("===== Global Symbol Table =====\n");
			else 
				printf("===== %s %s Symbol Table =====\n", auxtable->type, auxtable->name);
			
			nodetable = auxtable->nodetable;

			while ( nodetable != NULL){
				printf("%s\t%s%s\n", nodetable->id, nodetable->type, nodetable->parameter);
				nodetable = nodetable->next;
			}
			printf("\n");
		}
		auxtable = auxtable->next;
	}

}

char * search_type(char * id, char * typetable){
	Table * auxtable = symboltable;
	NodeTable* nodetable = (NodeTable*) malloc(sizeof(NodeTable));
	

	while(auxtable != NULL){
		if (strcmp(auxtable->name, typetable) == 0){
			
			nodetable = auxtable->nodetable;
			while (nodetable != NULL){
				if (strcmp(nodetable->id, id) == 0)
					return (char *) strdup(nodetable->type);

				nodetable = nodetable->next;
			}
		}
		auxtable = auxtable->next;
	}

	auxtable = symboltable;
	nodetable = auxtable->nodetable;

	while (nodetable != NULL){
		if (strcmp(nodetable->id, id) == 0){
			char *s;
			sprintf(s, "%s%s", nodetable->type,nodetable->parameter);
			return s;
		}

		nodetable = nodetable->next;
	}

	return "";
}




