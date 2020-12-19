#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "symbol_table.c"

typedef struct NodeTable NodeTable;
struct NodeTable * nodetable;

struct NodeTable
{
	char * id;
	char * type;
	char * parameter;	
	struct NodeTable * next;
};

//typedef struct Table Table;
struct Table * table;

struct Table
{
	char * name;
	char * type;
	int flag;
	char ** parameters;

	NodeTable * nodetable;
	struct Table * next;
} ;

void start_table();
void init_function_table(char * name, char ** parameters, int flag);
void insert(char * id, char * type, char * parameter, char * typetable);
void print_tables();
char * search_type(char * id, char * typetable);



#endif