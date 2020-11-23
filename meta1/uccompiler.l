%{	

	#include <stdio.h>
  	#include <string.h>
  	int column = 1;
	int line = 1;
  	int print = 0;
	int error_lex= 0;
  	int comment_line = 1;
	int comment_column = 1;
	
	int error_flag = 1;
	char chars[1000];

	//   Ana Beatriz Marques 2018274233
	//   Ivo Mendes 2018283892

	// lex uccompiler.l
	 // clang-3.9 -o uccompiler lex.yy.c
	//  ./uccompiler -l <testes/comments.uc > comments.out
	// diff testes/comments.out comments.out

%}

%option yylineno
%X COMMENT
%X CHAR

ID          	[a-zA-Z_][a-zA-Z0-9_]*
NUM         	[0-9]+
EXP         	[eE]("+"|"-")?[0-9]+
ESCAPE        	\\(n|t|\\|\'|\"|[0-7]{1,3})
INVALIDESCAPE	\\[^nt\\\'\"]|\\[^[0-7]{1,3}]
CHRLIT		\'([^\n\r\'\\]|(\\(n|t|\\|\'|\"|[0-7]{1,3})))\'
INVALID     \'([^\n\r\'\\]*|(\\[^\n\r]))*\'
UNTERMINATED \'([^\n\r\'\\]|\\([^\n\r]))*(\\)?
REALLIT		{NUM}"."|"."{NUM}|{NUM}"."{NUM}|{NUM}"."{NUM}[eE][-+]{NUM}|{NUM}[eE][-+]{NUM}|"."{NUM}[eE][-+]{NUM}


chr         	[^\'\n\\]|{ESCAPE}

reserved    "++"|"--"|"["|"]"|"inline"|"auto"|"else"|"long"|"switch"|"break"|"enum"|"register"|"typedef"|"case"|"extern"|"return"|"union"|"char"|"float"|"short"|"unsigned"|"const"|"for"|"signed"|"void"|"continue"|"goto"|"sizeof"|"volatile"|"default"|"if"|"static"|"while"|"do"|"int"|"struct"|"double"|"_Bool"|"_Complex"|"_Imaginary"|"__"[a-zA-Z][a-zA-Z0-9]*
tab		" "|"\t"
%%
"&"					{if (print){printf("BITWISEAND\n");} column += yyleng;}
"|"					{if (print){printf("BITWISEOR\n");} column += yyleng;}
"^"					{if (print){printf("BITWISEXOR\n");} column += yyleng;}
";"	      			{if (print){printf("SEMI\n");} column += yyleng;}
"&&"	      			{if (print){printf("AND\n");} column += yyleng;}
"="	      			{if (print){printf("ASSIGN\n");} column += yyleng;}
"*"	      			{if (print){printf("MUL\n");} column += yyleng;}
","	      			{if (print){printf("COMMA\n");} column += yyleng;}
"=="	      			{if (print){printf("EQ\n");} column += yyleng;}
">="	      			{if (print){printf("GE\n");} column += yyleng;}
">"	      			{if (print){printf("GT\n");} column += yyleng;}
"{"	      			{if (print){printf("LBRACE\n");} column += yyleng;}
"<="	      			{if (print){printf("LE\n");} column += yyleng;}
"("	      			{if (print){printf("LPAR\n");} column += yyleng;}
"<"	      			{if (print){printf("LT\n");} column += yyleng;}
"-"	      			{if (print){printf("MINUS\n");} column += yyleng;}
"%"	      			{if (print){printf("MOD\n");} column += yyleng;}
"!="	      			{if (print){printf("NE\n");} column += yyleng;}
"!"	      			{if (print){printf("NOT\n");} column += yyleng;}
"||"	      			{if (print){printf("OR\n");} column += yyleng;}
"+"	      			{if (print){printf("PLUS\n");} column += yyleng;}
"}"	      			{if (print){printf("RBRACE\n");} column += yyleng;}
")"	      			{if (print){printf("RPAR\n");} column += yyleng;}
return      			{if (print){printf("RETURN\n");} column += yyleng;}
else	      			{if (print){printf("ELSE\n");} column += yyleng;}
if	      			{if (print){printf("IF\n");} column += yyleng;}
while					{if (print){printf("WHILE\n");} column += yyleng;}
bool	      			{if (print){printf("BOOL\n");} column += yyleng;}
char	      			{if (print){printf("CHAR\n");} column += yyleng;}
int         			{if(print){printf("INT\n");}  column += yyleng;}
void					{if(print){printf("VOID\n");}  column += yyleng;}
double				{if(print){printf("DOUBLE\n");} column += yyleng;}
short					{if(print){printf("SHORT\n");} column += yyleng;}
\n|\r|\n\r|\r\n			{line = yylineno; column = 1;}
\/\/.* 	{;}



{reserved}		{if(print){printf("RESERVED(%s)\n", yytext);} column+= yyleng; }
										
{REALLIT}+ 			{if(print){printf("REALIT(%s)\n",yytext);} column += yyleng; }

{NUM}			{if(print){printf("INTLIT(%s)\n",yytext);} column += yyleng; }

{ID}				{if(print){printf("ID(%s)\n", yytext);} column += yyleng;	}


"//".*\n		{column = 1;line = yylineno;}
"/*"					{BEGIN COMMENT;comment_line = line;comment_column =column;line = yylineno;column += yyleng;}

<COMMENT>.				{column += yyleng;}
<COMMENT>\n|\r|\n\r|\r\n	{line = yylineno;column =1;}

<COMMENT><<EOF>>			{if(error_lex)
						printf("Line %d, col %d: unterminated comment\n", comment_line, comment_column);
						BEGIN 0;
					}
<COMMENT>"*/"			{BEGIN 0;
						line = yylineno;
						column += yyleng;}

"/"	      			{if (print){printf("DIV\n");} column += yyleng;}





{CHRLIT}			{if(print){
					printf("CHRLIT(%s)\n",yytext);} 			
					column += yyleng; }

{UNTERMINATED}		{column += yyleng;  
					printf("Line %d, col %d: unterminated char constant\n", line, column-yyleng);}
					
{INVALID}     		{column += yyleng; 
					printf("Line %d, col %d: invalid char constant (%s)\n", line, column-yyleng, yytext);}











{tab}			{column += yyleng;}
.				{if(error_lex) printf("Line %d, col %d: illegal character (%s)\n", yylineno, column, yytext); column += yyleng;}




%%
int main(int argc, char *argv[])
{	
	if(argc ==2) {
		if(strcmp(argv[1], "-l")==0){
			print = 1;
			error_lex=1;
		}
		if(strcmp(argv[1], "-e1")==0){
			print = 0;
			error_lex=1;
		}
	
	}
	error_lex=1;
	yylex();
	return 0;
}

int yywrap() {
  return 1;
}






