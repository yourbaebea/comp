#include "symbol_table.h"
#include "y.tab.h"
#include "semantic.c"
//semantic  

void check_program(Node * node);
void check_func_definition(Node * node);
void check_func_declaration(Node * node);
void check_declaration(Node * node);
char * check_type_specs(char * typespec);
char * check_parameter(Node * node);
char ** check_parameters(Node * node);
void insert_parameters_function(Node * node, char * typetable);
void check_tree(Node * node);
void check_FuncBody(Node * node, char * typetable);

