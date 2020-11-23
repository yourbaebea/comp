%{


    //   Ana Beatriz Marques 2018274233
    //   Ivo Mendes 2018283892

    


    #include "uccompiler.h"

    int syn_error = 0;
    extern int flag;



    struct Node * insert_node(char* id, char* type,  struct Node * son){ 

    
    	struct Node* aux = (struct Node*) malloc(sizeof(struct Node));
        if(id==NULL && type==NULL){ printf("fuck\n");return aux;}
        aux->son = son;
        aux->brother = NULL; // ainda nao tem valor
        aux->type= type;
        aux->id= id;
        return aux; // return do node ja criado


    }


    void print(struct Node* aux){

        if(aux->type!=NULL || aux->id!=NULL){
            if(aux->id!=NULL) printf("%s(%s)\n", aux->type, aux->id);
            else printf("%s\n", aux->type);
        }

        }




    void insert_brother(struct Node *node, struct Node *brother) {
    	
        if(node == NULL){
       	node = brother;
        return;
        }

        struct Node* aux = (struct Node*) malloc(sizeof(struct Node));
        aux = node;
      
        while(aux->brother != NULL)    aux = aux->brother;
        

        if(brother!=NULL) aux->brother= brother;
 
    }

    void insert_son(struct Node* node, struct Node* son){
    if (node == NULL || son == NULL){
        return;
    }
    if (node->son == NULL){
        node->son = son;
    } else {
        insert_brother(node->son, son);
    }
} 


void insert_first(struct Node* node, struct Node* son){
    if (node == NULL || son == NULL){
        return;
    }
    struct Node * uncle = node->brother;
    if(node->son == NULL){
        node->son=(struct Node*) malloc(sizeof(struct Node));
        node->son = son;
    }
    else{
        struct Node * oldSon = (struct  Node*) malloc(sizeof( struct Node));
        oldSon = node->son;
        node->son = son;
        node->son->brother = oldSon; 
    }

    while(uncle != NULL){
        struct Node * oldSon = (struct Node*) malloc(sizeof(struct Node));
        oldSon =uncle->son;
        uncle->son = insert_node(NULL,son->type,NULL);
        uncle->son->brother = oldSon;
        if(uncle->brother == NULL) break;
        uncle = uncle->brother;

    
}

}
    


    

    

    void print_tree(struct Node *node, int dots){


    if(node == NULL)
        return;

    struct Node* aux = (struct Node *) malloc(sizeof(struct Node));
    aux=node;
    
    for (int i = 0; i < dots; ++i) {
        printf("..");
    }
    print(aux);
    
    if(aux->son != NULL){
    	//if(strcmp(aux->son->type,"Null")) print_tree(aux->son, dots);
    	//else
    	print_tree(aux->son, dots+1);
    	}

    if(node->brother != NULL)
        print_tree(aux->brother, dots);

	}


%}


%union{
    struct Node * node;
    char * id;
}




%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> CHRLIT

%type <node> FunctionsAndDeclarations
%type <node> FunctionDefinition
%type <node> FunctionBody
%type <node> DeclarationsAndStatements
%type <node> FunctionDeclaration
%type <node> FunctionDeclarator
%type <node> ParameterList
%type <node> ParameterList2
%type <node> ParameterDeclaration
%type <node> Declaration
%type <node> Declaration2
%type <node> TypeSpec
%type <node> Declarator
%type <node> Statement
%type <node> StatementERROR
%type <node> Statement2
%type <node> Expr
%type <node> Program
%type <node> Expr2
%type <node> Expr3

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI RESERVED


%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left LE LT GT GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%left RPAR LPAR

%nonassoc ELSE

%%


Program: FunctionsAndDeclarations                   {$$ = insert_node(NULL,"Program",$1);if (flag==2 && syn_error==0){print_tree($$,0);}}
    ;

FunctionsAndDeclarations:
     FunctionDefinition                             {$$ = $1;}
    |FunctionDeclaration                            {$$ = $1;}
    |Declaration                                    {$$ = $1;}
    |FunctionsAndDeclarations FunctionDefinition    {
    	if ($1 != NULL){
    		$$ = $1;
    		insert_brother($$,$2);
    	}
    	else $$=$2;
    }

    |FunctionsAndDeclarations FunctionDeclaration   {
    	if ($1 != NULL){
    		$$ = $1;
    		insert_brother($$,$2);
    	}
    	else $$=$2;
    }

    |FunctionsAndDeclarations Declaration           {
    	if ($1 != NULL){
    		$$ = $1;
    		insert_brother($$,$2);
    	}
    	else $$=$2;
    }
;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody        {
    	$$ = insert_node(NULL,"FuncDefinition", $1);
    	insert_son($$,$2);
    	insert_son($$,$3);
    }
;

FunctionBody:
    LBRACE RBRACE                                   {
    	$$ = insert_node(NULL,"FuncBody",NULL);
    }

    |LBRACE DeclarationsAndStatements RBRACE        {
    	$$ = insert_node(NULL,"FuncBody", $2);
    }
;

DeclarationsAndStatements:
    DeclarationsAndStatements  Statement            {
        if($1 != NULL){
        	$$ = $1;
        	insert_brother($$,$2);
        }
        else $$=$2;
    }

    |DeclarationsAndStatements Declaration          {
    	if ($1 != NULL){
    		$$ = $1;
    		insert_brother($$,$2);
    	}
    	else $$=$2;
    }

    |Statement                                      {$$ = $1;}
    |Declaration                                    {$$ = $1;}
;

FunctionDeclaration:
    TypeSpec FunctionDeclarator SEMI                {
    	$$ = insert_node(NULL,"FuncDeclaration", $1);
    	insert_son($$, $2);
    }
;

FunctionDeclarator:
    ID LPAR ParameterList RPAR                      {
    	$$ = insert_node($1,"Id",NULL);
    	insert_brother($$,$3);
    }
;


ParameterDeclaration:
    TypeSpec                                        {
    	$$ = insert_node(NULL,"ParamDeclaration",$1);
    }

    |TypeSpec ID                                    {
    	$$ = insert_node(NULL, "ParamDeclaration", $1);
    	insert_son($$, insert_node($2,"Id", NULL));
    }
;

ParameterList:
    ParameterDeclaration  ParameterList2            {
    	$$ = insert_node(NULL,"ParamList",$1);
    	insert_son($$, $2);
    }
;

ParameterList2:
    COMMA ParameterDeclaration ParameterList2      {
    	$$=$2;
    	insert_brother($$,$3);
    }
    |                                              {$$=NULL;}
;



Declarator:
    ID                            {
    	$$ = insert_node(NULL,"Declaration", insert_node($1,"Id",NULL));
    }

    |ID ASSIGN Expr2                        {
    	$$ = insert_node(NULL,"Declaration",insert_node($1,"Id",NULL)); insert_son($$,$3);
    }
;
Declaration:
    TypeSpec Declaration2 SEMI            {
    	$$ = $2;
    	insert_first($$, $1);
    }
    |error SEMI                        {syn_error = 1;$$ = NULL;}
;

Declaration2:
    Declaration2 COMMA Declarator            {
     	if ($1 != NULL) {
     		$$ = $1;
     		insert_brother($$,$3);
     	}
     	else $$ = $3;
    }

    |Declarator                            {$$ = $1;}
;



TypeSpec:
    CHAR                                            {
    	$$ = insert_node(NULL,"Char", NULL);
    }

    |INT                                            {
    	$$ = insert_node(NULL,"Int", NULL);
    }

    |VOID                                           {
    	$$ = insert_node(NULL,"Void", NULL);
    }

    |SHORT                                          {
    	$$ = insert_node(NULL,"Short", NULL);
    }

    |DOUBLE                                         {
    	$$ = insert_node(NULL,"Double", NULL);
    }
;





Statement:
    SEMI											{$$ = NULL;}

    |Expr2 SEMI								    	{$$ = $1;}
    |LBRACE RBRACE                               	{$$ = NULL;}
    |LBRACE Statement2 RBRACE                    	{
        if ($2!=NULL && $2->brother!=NULL)
        	$$ = insert_node(NULL,"StatList",$2);
        else $$=$2;
    }
    
    |LBRACE error RBRACE                         	{$$ = NULL;syn_error=1;}

    |IF LPAR Expr2 RPAR StatementERROR           {
        $$ = insert_node(NULL,"If",$3); 
        if($5 == NULL){
        	insert_brother($3, insert_node(NULL,"Null",NULL));
        }
        else if($5->brother != NULL){ 
            struct Node * aux = (struct Node*) malloc(sizeof(struct Node));
            aux= insert_node(NULL,"StatList",NULL);
            insert_son($$,aux);
            insert_brother(aux->son,$5);
        }
        else{
        	insert_son($$, $5);
        }
        insert_son($$, insert_node(NULL,"Null", NULL));
    }


    |IF LPAR Expr2 RPAR StatementERROR ELSE StatementERROR   {
        $$ = insert_node(NULL,"If",$3); 
        if($5 == NULL){
        	insert_son($$, insert_node(NULL,"Null",NULL));
        }
        else if($5->brother != NULL){
            struct Node * aux = (struct Node*) malloc(sizeof(struct Node));
            aux= insert_node(NULL,"StatList",NULL);
            insert_son($$, aux);
            insert_brother(aux->son,$5);
        }
        else insert_son($$, $5);
        if($7 == NULL){
        	insert_son($$, insert_node(NULL,"Null",NULL));
        }
        else if($7->brother != NULL){
            struct Node * aux = (struct Node*) malloc(sizeof(struct Node));
            aux= insert_node(NULL,"StatList",NULL);
            insert_son($$,aux);
            insert_brother(aux->son,$7);
        }
        else {
        	insert_son($$, $7);
        }

    }


    |WHILE LPAR Expr2 RPAR StatementERROR         	{
    	$$ = insert_node(NULL,"While",$3);
    	if($5 == NULL){
    		insert_son($$, insert_node(NULL,"Null",NULL));
    	}
    	else {
    		insert_son($$,$5);
    	}
    }


    |RETURN SEMI                                 	{
    	$$ = insert_node(NULL,"Return",insert_node(NULL,"Null",NULL));
    }

    |RETURN Expr2 SEMI                            	{
    	$$ = insert_node(NULL,"Return",$2);
    }
    ;

StatementERROR:
    Statement                                       {$$ = $1;}
    |error SEMI                                     {$$ = NULL; syn_error = 1;}
;

Statement2:
     Statement2 StatementERROR                    {
     	if ($1 != NULL) {
     		$$ = $1;
     		insert_brother($$,$2);
     	}
     	else $$ = $2;
    }

    |StatementERROR                                 {$$ = $1;}
;



Expr2:
	Expr2 COMMA Expr				{
		$$ = insert_node(NULL, "Comma",NULL);
		if($1!=NULL){
			insert_son($$,$1);
		}
		else {
			insert_son($$, insert_node(NULL, "Null",NULL));
		} 
		if($3 != NULL) {
			insert_son($$, $3);
		}
		else {
			insert_son($$, insert_node(NULL, "Null",NULL));
		}

	}

	|Expr							{$$ = $1;}
;


Expr3:
    Expr3 COMMA Expr             {
    	if($1!=NULL){
    		$$= $1;
			insert_brother($$,$3);
		}
		else if($3 != NULL) {
			$$=$3;
		}

		else {
			insert_son($$, insert_node(NULL, "Null",NULL));
		}

    }

    |                               {$$ = NULL;}

Expr:
	Expr ASSIGN Expr					{
		$$ = insert_node(NULL,"Store",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	
	|Expr PLUS Expr						{
		$$ = insert_node(NULL,"Add",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}

	|Expr MINUS Expr					{
		$$ = insert_node(NULL,"Sub",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}

	|Expr MUL Expr						{
		$$ = insert_node(NULL,"Mul",NULL);
		if($1 == NULL)
		insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}

	|Expr DIV Expr						{
		$$ = insert_node(NULL,"Div",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}

	|Expr MOD Expr						{
		$$ = insert_node(NULL,"Mod",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	
	|Expr OR Expr						{
		$$ = insert_node(NULL,"Or",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}

	|Expr AND Expr						{
		$$ = insert_node(NULL,"And",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	
	|Expr BITWISEAND Expr					{
		$$ = insert_node(NULL,"BitWiseAnd",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}

	|Expr BITWISEOR Expr					{
		$$ = insert_node(NULL,"BitWiseOr",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	|Expr BITWISEXOR Expr					{
		$$ = insert_node(NULL,"BitWiseXor",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
																			
	|Expr EQ Expr						{
		$$ = insert_node(NULL,"Eq",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	|Expr NE Expr						{
		$$ = insert_node(NULL,"Ne",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	|Expr LE Expr						{
		$$ = insert_node(NULL,"Le",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	|Expr GE Expr						{
		$$ = insert_node(NULL,"Ge",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	|Expr LT Expr						{
		$$ = insert_node(NULL,"Lt",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);}
	|Expr GT Expr						{
		$$ = insert_node(NULL,"Gt",NULL);
		if($1 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $1);
		if($3 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $3);
	}
	
	|PLUS Expr %prec NOT					{
		$$ = insert_node(NULL,"Plus",NULL);
		if ($2 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $2);
	}
	|MINUS Expr %prec NOT					{
		$$ = insert_node(NULL,"Minus",NULL);
		if ($2 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $2);
	}
	|NOT Expr								{
		$$ = insert_node(NULL,"Not",NULL);
		if ($2 == NULL)insert_son($$,insert_node(NULL,"Null",NULL));
		else insert_son($$, $2);
	}
	
	|ID LPAR RPAR							{
		$$ = insert_node(NULL,"Call",NULL);
		insert_son($$,insert_node($1,"Id",NULL));
	}                   
	|ID LPAR Expr Expr3 RPAR				{
		$$ = insert_node(NULL,"Call",NULL);
		insert_son($$,insert_node($1,"Id",NULL));
		if($3 != NULL)insert_son($$,$3);
		if($4 != NULL)insert_son($$,$4);
	}
	|ID LPAR error RPAR 					{$$ = NULL; syn_error = 1;}
	
	|ID										{$$ = insert_node($1,"Id",NULL);}
	|INTLIT									{$$ = insert_node($1,"IntLit",NULL);}
	|CHRLIT									{$$ = insert_node($1,"ChrLit",NULL);}
	|REALLIT								{$$ = insert_node($1,"RealLit",NULL);}
	|LPAR Expr2 RPAR						{$$ = $2;}
	|LPAR error RPAR 						{$$ = NULL; syn_error = 1;}
;

%%

