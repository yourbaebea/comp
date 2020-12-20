#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodetable
{
	char * id;
	char * type;
	char * parameter;	
	struct nodetable * next;
}NodeTable;

typedef struct table
{
	char * name;
	char * type;
	int flag;
	char ** parameters;

	struct nodetable * nodetable;
	struct table * next;
}Table ;

void start_table();
void init_function_table(char * name, char ** parameters, int flag);
void insert(char * id, char * type, char * parameter, char * typetable);
void print_tables();
char * search_type(char * id, char * typetable);



#endif