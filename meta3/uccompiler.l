%{	

	#include "uccompiler.h"
	#include "y.tab.h"
	#include "symbol_table.c"
	#include "semantic.h"


	Node * node;
	int column = 1;
    int line = 1;
    int flag = 0;
    int syn_error=0;
    int error_lex= 0;
    int error_syn=0;
    int comment_line = 1;
    int comment_column = 1;

	//   Ana Beatriz Marques 2018274233
	//   Ivo Mendes 2018283892

	// lex uccompiler.l
	 // clang-3.9 -o uccompiler lex.yy.c
	//  ./uccompiler -l <testes/comments.uc > comments.out
	// diff testes/comments.out comments.out

%}

%option yylineno
%X COMMENT


CHAR char
ELSE else
WHILE while
IF if
INT int
SHORT short
DOUBLE double
RETURN return
VOID void
BITWISEAND      "&"
BITWISEOR       "|"
BITWISEXOR      "^"
AND "&&"
ASSIGN "="
MUL "*"
COMMA ","
DIV "/"
EQ "=="
GE ">="
GT ">"
LBRACE "{"
LE "<="
LPAR "("
LT "<"
MINUS "-"
MOD "%"
NE "!="
NOT "!"
OR "||"
PLUS "+"
RBRACE "}"
RPAR ")"
SEMI            ";"
PLICA	"\'"


ID          	[a-zA-Z_][a-zA-Z0-9_]*
INTLIT         	[0-9]+
EXP         	[eE]("+"|"-")?[0-9]+
ESCAPE        	\\(n|t|\\|\'|\"|[0-7]{1,3})
TAB		" "|"\t"
INVALIDESCAPE	\\[^nt\\\'\"]|\\[^[0-7]{1,3}]
CHRLIT		[^\n\r\'\\]|(\\(n|t|\\|\'|\"|[0-7]{1,3}))
CHRLIT2	[a-zA-Z0-9]|\(\n|\t|\\|\'|\"|\[0-7]{1,3})
INVALID     \'([^\n\r\'\\]*|(\\[^\n\r]))*\'
INVALID2	\\[^[0-7]{1,3}]
UNTERMINATED \'([^\n\r\'\\]|\\([^\n\r]))*(\\)?
REALLIT		{INTLIT}"."|"."{INTLIT}|{INTLIT}"."{INTLIT}|{INTLIT}"."{INTLIT}[eE][-+]{INTLIT}|{INTLIT}[eE][-+]{INTLIT}|"."{INTLIT}[eE][-+]{INTLIT}
CHR         	[^\'\n\\]|{ESCAPE}
END			<<EOF>>

RESERVED    "++"|"--"|"["|"]"|"inline"|"auto"|"else"|"long"|"switch"|"break"|"enum"|"register"|"typedef"|"case"|"extern"|"return"|"union"|"char"|"float"|"short"|"unsigned"|"const"|"for"|"signed"|"void"|"continue"|"goto"|"sizeof"|"volatile"|"default"|"if"|"static"|"while"|"do"|"int"|"struct"|"double"|"_Bool"|"_Complex"|"_Imaginary"|"__"[a-zA-Z][a-zA-Z0-9]*




%%


{BITWISEAND}		{if (flag==1){printf("BITWISEAND\n");} column += yyleng; return BITWISEAND;}

{BITWISEOR}		{if (flag==1){printf("BITWISEOR\n");} column += yyleng; return BITWISEOR;}

{BITWISEXOR}		{if (flag==1){printf("BITWISEXOR\n");} column += yyleng; return BITWISEXOR;}

{SEMI}	      			{if (flag==1){printf("SEMI\n");} column += yyleng;return SEMI;}
{AND}	      			{if (flag==1){printf("AND\n");} column += yyleng;return AND;}
{ASSIGN}	      			{if (flag==1){printf("ASSIGN\n");} column += yyleng;return ASSIGN;}
{MUL}	      			{if (flag==1){printf("MUL\n");} column += yyleng;return MUL;}
{COMMA}	      			{if (flag==1){printf("COMMA\n");} column += yyleng;return COMMA;}
{EQ}	      			{if (flag==1){printf("EQ\n");} column += yyleng;return EQ;}
{GE}	      			{if (flag==1){printf("GE\n");} column += yyleng;return GE;}
{GT}	      			{if (flag==1){printf("GT\n");} column += yyleng;return GT;}
{LBRACE}	      			{if (flag==1){printf("LBRACE\n");} column += yyleng;return LBRACE;}
{LE}	      			{if (flag==1){printf("LE\n");} column += yyleng;return LE;}
{LPAR}	      			{if (flag==1){printf("LPAR\n");} column += yyleng;return LPAR;}
{LT}	      			{if (flag==1){printf("LT\n");} column += yyleng;return LT;}
{MINUS}	      			{if (flag==1){printf("MINUS\n");} column += yyleng;return MINUS;}
{MOD}	      			{if (flag==1){printf("MOD\n");} column += yyleng;return MOD;}
{NE}	      			{if (flag==1){printf("NE\n");} column += yyleng;return NE;}
{NOT}	      			{if (flag==1){printf("NOT\n");} column += yyleng;return NOT;}
{OR}	      			{if (flag==1){printf("OR\n");} column += yyleng;return OR;}
{PLUS}	      			{if (flag==1){printf("PLUS\n");} column += yyleng;return PLUS;}
{RBRACE}	      			{if (flag==1){printf("RBRACE\n");} column += yyleng;return RBRACE;}
{RPAR}	      			{if (flag==1){printf("RPAR\n");} column += yyleng;return RPAR;}
{RETURN}      			{if (flag==1){printf("RETURN\n");} column += yyleng;return RETURN;}
{ELSE}	      			{if (flag==1){printf("ELSE\n");} column += yyleng;return ELSE;}
{IF}	      			{if (flag==1){printf("IF\n");} column += yyleng;return IF;}
{WHILE}					{if (flag==1){printf("WHILE\n");} column += yyleng;return WHILE;}

{CHAR}	      			{if (flag==1){printf("CHAR\n");} column += yyleng;return CHAR;}
{INT}         			{if(flag==1){printf("INT\n");}  column += yyleng;return INT;}
{VOID}					{if(flag==1){printf("VOID\n");}  column += yyleng;return VOID;}
{DOUBLE}				{if(flag==1){printf("DOUBLE\n");} column += yyleng;return DOUBLE;}
{SHORT}					{if(flag==1){printf("SHORT\n");} column += yyleng;return SHORT;}
\n|\r|\n\r|\r\n			{line = yylineno; column = 1;}
\/\/.* 	{;}




"//".*\n		{column = 1;line = yylineno;}

"/*"					{BEGIN COMMENT;comment_line = line;comment_column =column;line = yylineno;column += yyleng;}

<COMMENT>.				{column += yyleng;}
<COMMENT>\n|\r|\n\r|\r\n	{line = yylineno;column =1;}

<COMMENT><<EOF>>			{if(error_lex){printf("Line %d, col %d: unterminated comment\n", comment_line, comment_column);};
						BEGIN 0;
					}
<COMMENT>"*/"			{BEGIN 0;
						line = yylineno;
						column += yyleng;}

"/"	      			{if (flag==1){printf("DIV\n");}; column += yyleng; return DIV;}


{PLICA}{PLICA} {if(error_lex){printf("Line %d, col %d: unterminated char constant ('')\n", line, column);}; column += yyleng;}
					
{PLICA}{CHRLIT}{PLICA}		{if(flag==1){printf("CHRLIT(%s)\n",yytext); column += yyleng;};
							yylval.id= strdup(yytext);
							return CHRLIT;}
					
					
{PLICA}{CHRLIT}{INVALID2}"'"	{if(error_lex){printf("Line %d, col %d: unterminated char constant (%s)\n", line, column, yytext);}; column += yyleng;}



{PLICA}{CHRLIT}\n|\r|\n\r|\r\n		{if(error_lex){printf("Line %d, col %d: unterminated char constant\n", line, column);}; line = yylineno; column = 1;}
			

{PLICA}{CHRLIT}.	{if(error_lex){printf("Line %d, col %d: unterminated char constant\n", line, column);}; column += yyleng;}		

{RESERVED}		{if(flag==1){printf("RESERVED(%s)\n", yytext);}
				column+= yyleng;
				return RESERVED;}
										
{REALLIT}+ 			{if(flag==1){printf("REALLIT(%s)\n",yytext);}
					column += yyleng;
					yylval.id= strdup(yytext);
					return REALLIT;}

{INTLIT}			{if(flag==1){printf("INTLIT(%s)\n",yytext);}
					column += yyleng; 
					yylval.id= strdup(yytext);
					return INTLIT;}

{ID}				{if(flag==1){printf("ID(%s)\n", yytext);}
					column += yyleng;
					yylval.id= strdup(yytext);
					return ID;}



{TAB}			{column += yyleng;}
.				{if(error_lex) {printf("Line %d, col %d: illegal character (%s)\n", line, column-(int)strlen(yytext)+ 1, yytext);}; column += yyleng;}




%%
void yyerror (char *s)
{
	
		if (error_lex || error_syn) printf("Line %d, col %d: %s: %s\n", line, column-(int)strlen(yytext), s, yytext);
    
}

int yywrap() {
  return 1;
}


int main(int argc, char *argv[])
{	
	if(argc ==2) {


		if(strcmp(argv[1], "-l")==0){  // -l é print dos erros lexicais + tokens
			flag = 1; // print dos tokens
			error_lex=1; // print dos erros lexicais
			error_syn=0;
			yyparse();
		}
		if(strcmp(argv[1], "-t")==0){ // -t é print da arvore
			flag = 2; //print da arvore
			error_lex=1; // nao queremos print dos erros lexicais
			error_syn=1;
			yyparse();
		}
		
		if(strcmp(argv[1], "-e1")==0){ // -e1 é erros lexicais
			flag = 0; // sem print
			error_lex=1; // print dos erros lexicais
			error_syn=0;
			yyparse();
		}
		
		if(strcmp(argv[1], "-e2")==0){ // -e2 são erros lexicais e sintaticos
			flag = 0; // sem print
			error_lex=1; // print dos erros lexicais
			error_syn=1;
			
			yyparse();
			
		}
		if(strcmp(argv[1], "-s")==0){ // -s tabela de simbolos
			flag = 0;
			//error_lex=1; // print dos erros lexicais
			//error_syn=1;
			yyparse();
			check_program(node);
			check_tree(node);
			print_tables();
			if (syn_error==0){
				print_tree(node);
			}
			
			
		}



	}
	else{
		flag = 0; // sem print
		error_lex=1; // print dos erros lexicais
		error_syn=1;
		yyparse();



	}

	
	clear(node);
	return 0;
}










