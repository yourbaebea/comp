#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <stdio.h>
#include <stdlib.h>  
#include <string.h> 
#include "symbol_table.h"
#include "semantic.c"

//semantic  

void check_program(struct Node * node);
void check_func_definition(struct  Node * node);
void check_func_declaration(struct  Node * node);
void check_declaration(struct  Node * node);
char * check_type_specs(char * typespec);
char * check_parameter(struct  Node * node);
char ** check_parameters(struct  Node * node);
void insert_parameters_function(struct Node * node, char * typetable);
void check_tree(struct  Node * node);
void check_func_body(struct  Node * node, char * typetable);
void check_extra(char* str);

#endif