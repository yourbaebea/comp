    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
    
    
    char chars[1000];
    
    typedef struct Node Node;
    struct Node * node;
   

    char * id;
    char * type;
    Node* insert_node(char * id, char * type, Node * son);
    void insert_brother(Node *node, Node *brother);
     void insert_first(Node* node, Node* son);
    void insert_son(Node* node, Node* son);
    void print_tree(Node *root, int dots);

    void clear(Node *root);
    int yylex(void);
    void yyerror (char * s);

    struct Node{
        Node *son;
        Node *brother;
        char *id;
        char *type;
    };


