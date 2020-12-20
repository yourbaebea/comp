#ifndef UCCOMPILER_H
#define UCCOMPILER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char chars[1000];
struct Node * node;


//meta 1 e 2

char * id;
char * type;
struct Node* insert_node(char * id, char * type, struct Node * son);
void insert_brother(struct Node *node,struct Node *brother);
void print_tree(struct Node *root, int dots);
void addSonFirst(struct Node* father, struct Node* son);
void clear(struct Node *node);
int yylex(void);
void yyerror (char * s);


//structs

typedef struct Node{
        struct Node *son;
        struct Node *brother;
        char *id;
        char *type;
        char *extra;
    }Node;


#endif
