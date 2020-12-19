#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char chars[1000];
typedef struct Node Node;
struct Node * node;


//meta 1 e 2

char * id;
char * type;
Node* insert_node(char * id, char * type, Node * son);
void insert_brother(Node *node, Node *brother);
void print_tree(Node *root, int dots);
void addSonFirst(Node* father, Node* son);
void clear(Node *root);
int yylex(void);
void yyerror (char * s);


//structs

struct Node{
        Node *son;
        Node *brother;
        char *id;
        char *type;
        char *extra;
    };

