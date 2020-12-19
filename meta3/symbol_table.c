
#include "symbol_table.h"

struct Table * symboltable = NULL;

void start_table(){
	struct Table* symboltable = (struct Table*) malloc(sizeof(struct Table));
	strcpy(symboltable->type, strdup("Global");
	symboltable->name = strdup("");
	symboltable->flag = 1;
	symboltable->paramslist = NULL;

	insert("putchar","int(int)","","Global");
	insert("getchar","int(void)","","Global");
}

void init_function_table(char * name, char ** parameters, int flag){
	struct Table* auxtable = (struct Table*) malloc(sizeof(struct Table));
	
	editsymbol(auxtable,name,"Function",flag,parameters);
	
	struct Table * table = symboltable;

	if (table == NULL){
		table = auxtable;
		return;
	}
	
	while (table->next != NULL){
		if (strcmp(table->name, name)==0 && table->flag==0){
			table->flag = 1;
			free(auxtable);
			return;
		}
		table = table->next;
	}

	if (strcmp(table->name, name)==0 && table->flag==0){
		table->flag = 1;
		free(auxtable);
		return;
	}

	table->next = auxtable;

}


void insert(char * id, char * type, char * parameter, char * typetable){
	struct NodeTable* auxnodetable = (struct NodeTable*) malloc(sizeof(struct NodeTable));
	auxnodetable->id = id;
	auxnodetable->type = type;
	auxnodetable->parameter = parameter;
	auxnodetable->next = NULL;

	struct Table * table = NULL;

	if (strcmp(typetable, "Global")==0)
		table = symboltable;
	else{
		table = symboltable->next;
		while (table != NULL && strcmp(typetable,table->name)!=0)
			table = table->next;
	}


	if (table->nodetable == NULL){
		table->nodetable = auxnodetable;
		return;
	}
	struct NodeTable* nodetable = (struct NodeTable*) malloc(sizeof(struct NodeTable));
	
	nodeTable nodetable = table->nodetable;
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
	struct Table * table = symboltable;
	struct NodeTable* nodetable = (struct NodeTable*) malloc(sizeof(struct NodeTable));
	

	while (table != NULL){
		if (table->flag == 1){
			if (strcmp(table->type,"Global")==0)
				printf("===== Global Symbol Table =====\n");
			else 
				printf("===== %s %s Symbol Table =====\n", table->type, table->name);
			
			nodetable = table->nodetable;

			while ( nodetable != NULL){
				printf("%s\t%s%s\n", nodetable->id, nodetable->type, nodetable->parameter);
				nodetable = nodetable->next;
			}
			printf("\n");
		}
		table = table->next;
	}

}

char * search_type(char * id, char * typetable){
	struct Table * table = symboltable;
	struct NodeTable* nodetable = (struct NodeTable*) malloc(sizeof(struct NodeTable));
	

	while(table != NULL){
		if (strcmp(table->name, typetable) == 0){
			
			nodetable = table->nodetable;
			while (nodetable != NULL){
				if (strcmp(nodetable->id, id) == 0)
					return (char *) strdup(nodetable->type);

				nodetable = nodetable->next;
			}
		}
		table = table->next;
	}

	table = symboltable;
	nodetable = table->nodetable;

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




