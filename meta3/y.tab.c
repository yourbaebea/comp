/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "uccompiler.y"



    //   Ana Beatriz Marques 2018274233
    //   Ivo Mendes 2018283892

    


    #include "uccompiler.h"

    extern int syn_error;
    extern int flag;
    extern Node * node;



    struct Node * insert_node(char* id, char* type,  struct Node * son){ 

    
    	struct Node* aux = (struct Node*) malloc(sizeof(struct Node));
        if(id==NULL && type==NULL){ return aux;}
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
        print(node);
        return;
        }

        struct Node* aux = (struct Node*) malloc(sizeof(struct Node));
        aux = node;
      
        while(aux->brother != NULL)    aux = aux->brother;
        

        if(brother!=NULL) aux->brother= brother;
 
    }


    void addSonFirst(struct Node* father, struct Node* son){
        if (father == NULL || son == NULL){
            return;
        }
        struct Node * uncle = father->brother;
        if(father->son == NULL){
            father->son=(struct Node*) malloc(sizeof(struct Node));
            father->son = son;
        }
        else{
            struct Node * oldSon = (struct  Node*) malloc(sizeof( struct Node));
            oldSon = father->son;
            father->son = son;
            father->son->brother = oldSon; 
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


    void clear(struct Node * node){
        if (node == NULL){
            return;
        }
        if (node->son != NULL){
            clear(node->son);
        }
        if (node->brother != NULL){
            clear(node->brother);
        }
        free(node);
    }
        


    

    

    void print_tree(struct Node *node, int dots){


    if(node == NULL)
        return;


    
    for (int i = 0; i < dots; ++i) {
        printf("..");
    }
    print(node);
    
    if(node->son != NULL){
    	print_tree(node->son, dots+1);
    	}

    if(node->brother != NULL)
        print_tree(node->brother, dots);

	}



#line 205 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INTLIT = 259,
    REALLIT = 260,
    CHRLIT = 261,
    CHAR = 262,
    ELSE = 263,
    WHILE = 264,
    IF = 265,
    INT = 266,
    SHORT = 267,
    DOUBLE = 268,
    RETURN = 269,
    VOID = 270,
    BITWISEAND = 271,
    BITWISEOR = 272,
    BITWISEXOR = 273,
    AND = 274,
    ASSIGN = 275,
    MUL = 276,
    COMMA = 277,
    DIV = 278,
    EQ = 279,
    GE = 280,
    GT = 281,
    LBRACE = 282,
    LE = 283,
    LPAR = 284,
    LT = 285,
    MINUS = 286,
    MOD = 287,
    NE = 288,
    NOT = 289,
    OR = 290,
    PLUS = 291,
    RBRACE = 292,
    RPAR = 293,
    SEMI = 294,
    RESERVED = 295
  };
#endif
/* Tokens.  */
#define ID 258
#define INTLIT 259
#define REALLIT 260
#define CHRLIT 261
#define CHAR 262
#define ELSE 263
#define WHILE 264
#define IF 265
#define INT 266
#define SHORT 267
#define DOUBLE 268
#define RETURN 269
#define VOID 270
#define BITWISEAND 271
#define BITWISEOR 272
#define BITWISEXOR 273
#define AND 274
#define ASSIGN 275
#define MUL 276
#define COMMA 277
#define DIV 278
#define EQ 279
#define GE 280
#define GT 281
#define LBRACE 282
#define LE 283
#define LPAR 284
#define LT 285
#define MINUS 286
#define MOD 287
#define NE 288
#define NOT 289
#define OR 290
#define PLUS 291
#define RBRACE 292
#define RPAR 293
#define SEMI 294
#define RESERVED 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 137 "uccompiler.y"

    struct Node * node;
    char * id;

#line 342 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   433

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   200,   200,   204,   205,   206,   207,   208,   209,   213,
     217,   218,   222,   224,   225,   226,   230,   234,   239,   240,
     246,   250,   251,   258,   259,   262,   263,   267,   268,   274,
     275,   276,   277,   278,   286,   287,   288,   289,   290,   297,
     311,   335,   341,   343,   348,   349,   353,   354,   360,   371,
     376,   377,   381,   386,   387,   388,   389,   390,   391,   392,
     393,   398,   399,   400,   401,   402,   406,   407,   408,   409,
     410,   414,   415,   416,   417,   418,   419,   423,   424,   425,
     429,   431,   438,   439,   440,   441,   442
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTLIT", "REALLIT", "CHRLIT",
  "CHAR", "ELSE", "WHILE", "IF", "INT", "SHORT", "DOUBLE", "RETURN",
  "VOID", "BITWISEAND", "BITWISEOR", "BITWISEXOR", "AND", "ASSIGN", "MUL",
  "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LT", "MINUS",
  "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "SEMI", "RESERVED",
  "$accept", "Program", "FunctionsAndDeclarations", "FunctionDefinition",
  "FunctionBody", "DeclarationsAndStatements", "FunctionDeclaration",
  "FunctionDeclarator", "ParameterDeclaration", "ParameterList",
  "ParameterList2", "Declarator", "Declaration", "Declaration2",
  "TypeSpec", "Statement", "StatementERROR", "Statement2", "Expr2",
  "Expr3", "Expr", "ExprOperations", "ExprLogical", "ExprRelation",
  "ExprUnary", "ExprFunction", "ExprPrimary", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     411,   -34,   -85,   -85,   -85,   -85,   -85,    11,   235,   -85,
     -85,   -85,     9,   -85,   -85,   -85,   -85,   -85,    38,   -19,
     -85,   -16,   234,   418,    81,   -85,   -85,    16,   -85,     0,
     -85,   -85,   -85,   228,   234,   234,   234,   -85,   278,   -85,
     -85,   -85,   -85,   -85,   -85,    39,    24,    60,    35,    37,
     222,   134,   -85,   -85,   118,   -85,    16,   -85,   -15,    45,
     -85,    73,    31,   255,   -85,   -85,   -85,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   418,   -85,   -85,   -85,   234,
     234,   -85,   -12,   -21,   -85,   -85,   -85,   171,   -85,   -85,
     -85,   -85,    32,   -85,   278,   -85,   -85,   278,   371,   339,
     357,   320,   278,   -85,   -85,   385,   161,   161,   161,   161,
      36,   -85,   385,   299,    36,    39,    -8,    -7,   -85,   -85,
     -85,    34,   -85,   -85,   -85,    -5,   -85,   185,   185,   234,
     -85,   -85,    67,   278,   185,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    29,    30,    32,    33,    31,     0,     0,     3,
       4,     5,     0,    26,     1,     6,     7,     8,    23,     0,
      28,     0,     0,     0,     0,    16,     9,     0,    25,    82,
      83,    84,    85,     0,     0,     0,     0,    24,    49,    55,
      56,    57,    58,    59,    60,    22,     0,    18,     0,     0,
       0,     0,    10,    34,     0,    15,     0,    14,     0,    23,
      27,     0,     0,     0,    78,    79,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    17,    19,     0,
       0,    42,     0,     0,    36,    44,    47,     0,    11,    13,
      12,    35,     0,    80,    51,    53,    86,    48,    68,    69,
      70,    67,    52,    63,    64,    71,    74,    76,    73,    75,
      62,    65,    72,    66,    61,    22,     0,     0,    43,    37,
      45,     0,    38,    46,    54,     0,    21,     0,     0,     0,
      81,    41,    39,    50,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -85,    72,   -85,   -85,    89,   -85,    -4,   -85,
     -36,    71,     1,   -85,    -2,     2,   -84,   -85,   -18,   -85,
     -33,   -85,   -85,   -85,   -85,   -85,   -85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    26,    54,    10,    19,    45,    46,
      86,    20,    11,    21,    12,    95,    96,    97,    58,   135,
      38,    39,    40,    41,    42,    43,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    64,    65,    66,    37,    13,    27,    67,    24,    17,
      67,    14,    18,   133,    67,    67,   129,   139,   130,    59,
      25,    47,    56,    28,   101,    55,    57,   128,   104,    61,
     137,   138,    92,   140,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    56,   141,   142,    99,   100,    73,    22,    74,
     145,    85,    87,    88,    89,    22,    90,    23,    81,   105,
     134,   126,   127,   130,   102,   144,    29,    30,    31,    32,
      15,   125,     1,    47,    29,    30,    31,    32,     2,   136,
      48,    49,     3,     4,     5,    50,     6,    16,    60,     0,
       0,     0,    33,     0,    34,     0,   143,    35,    51,    36,
      33,   103,    34,     0,     0,    35,     0,    36,    52,     1,
      53,    29,    30,    31,    32,     2,     0,    48,    49,     3,
       4,     5,    50,     6,     0,    93,     0,    29,    30,    31,
      32,     0,     0,    48,    49,    51,     0,    33,    50,    34,
       0,     0,    35,     0,    36,    98,     0,    53,     0,     0,
       0,    51,     0,    33,     0,    34,     0,     0,    35,     0,
      36,    94,   131,    53,    29,    30,    31,    32,     0,     0,
      48,    49,    73,     0,    74,    50,   131,     0,    29,    30,
      31,    32,    80,    81,    48,    49,     0,    84,    51,    50,
      33,     0,    34,     0,     0,    35,     0,    36,   132,     0,
      53,     0,    51,     0,    33,     0,    34,     0,     0,    35,
       0,    36,     0,     0,    53,    29,    30,    31,    32,    62,
       0,    29,    30,    31,    32,    -2,     1,    29,    30,    31,
      32,     0,     2,     0,     0,     0,     3,     4,     5,     0,
       6,    33,     0,    34,     0,     0,    35,    33,    36,    34,
       0,    91,    35,    33,    36,    34,     0,     0,    35,     0,
      36,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,    77,     0,    78,     0,    79,    80,    81,    82,     0,
      83,    84,     0,   106,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,    77,     0,    78,     0,    79,    80,
      81,    82,     0,    83,    84,    68,    69,    70,    71,     0,
      73,     0,    74,    75,    76,    77,     0,    78,     0,    79,
      80,    81,    82,     0,     0,    84,    68,    69,    70,     0,
       0,    73,     0,    74,    75,    76,    77,     0,    78,     0,
      79,    80,    81,    82,     0,    68,    84,    70,     0,     0,
      73,     0,    74,    75,    76,    77,     0,    78,     0,    79,
      80,    81,    82,    68,     0,    84,     0,     0,    73,     0,
      74,    75,    76,    77,     0,    78,     0,    79,    80,    81,
      82,     0,    73,    84,    74,    75,    76,    77,     0,    78,
       0,    79,    80,    81,    82,     0,    73,    84,    74,     0,
      76,    77,     1,    78,     0,    79,    80,    81,     2,     0,
       0,    84,     3,     4,     5,     2,     6,     0,     0,     3,
       4,     5,     0,     6
};

static const yytype_int16 yycheck[] =
{
      33,    34,    35,    36,    22,    39,    22,    22,    27,     8,
      22,     0,     3,    97,    22,    22,    37,    22,    39,     3,
      39,    23,    24,    39,    39,    24,    24,    39,    61,    29,
      38,    38,    50,    38,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    54,   137,   138,    54,    54,    21,    20,    23,
     144,    22,    38,     3,    29,    20,    29,    29,    32,    38,
      38,    89,    90,    39,     1,     8,     3,     4,     5,     6,
       8,    85,     1,    85,     3,     4,     5,     6,     7,   125,
       9,    10,    11,    12,    13,    14,    15,     8,    27,    -1,
      -1,    -1,    29,    -1,    31,    -1,   139,    34,    27,    36,
      29,    38,    31,    -1,    -1,    34,    -1,    36,    37,     1,
      39,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    10,    27,    -1,    29,    14,    31,
      -1,    -1,    34,    -1,    36,    37,    -1,    39,    -1,    -1,
      -1,    27,    -1,    29,    -1,    31,    -1,    -1,    34,    -1,
      36,    37,     1,    39,     3,     4,     5,     6,    -1,    -1,
       9,    10,    21,    -1,    23,    14,     1,    -1,     3,     4,
       5,     6,    31,    32,     9,    10,    -1,    36,    27,    14,
      29,    -1,    31,    -1,    -1,    34,    -1,    36,    37,    -1,
      39,    -1,    27,    -1,    29,    -1,    31,    -1,    -1,    34,
      -1,    36,    -1,    -1,    39,     3,     4,     5,     6,     1,
      -1,     3,     4,     5,     6,     0,     1,     3,     4,     5,
       6,    -1,     7,    -1,    -1,    -1,    11,    12,    13,    -1,
      15,    29,    -1,    31,    -1,    -1,    34,    29,    36,    31,
      -1,    39,    34,    29,    36,    31,    -1,    -1,    34,    -1,
      36,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    -1,    28,    -1,    30,    31,    32,    33,    -1,
      35,    36,    -1,    38,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    -1,    28,    -1,    30,    31,
      32,    33,    -1,    35,    36,    16,    17,    18,    19,    -1,
      21,    -1,    23,    24,    25,    26,    -1,    28,    -1,    30,
      31,    32,    33,    -1,    -1,    36,    16,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    25,    26,    -1,    28,    -1,
      30,    31,    32,    33,    -1,    16,    36,    18,    -1,    -1,
      21,    -1,    23,    24,    25,    26,    -1,    28,    -1,    30,
      31,    32,    33,    16,    -1,    36,    -1,    -1,    21,    -1,
      23,    24,    25,    26,    -1,    28,    -1,    30,    31,    32,
      33,    -1,    21,    36,    23,    24,    25,    26,    -1,    28,
      -1,    30,    31,    32,    33,    -1,    21,    36,    23,    -1,
      25,    26,     1,    28,    -1,    30,    31,    32,     7,    -1,
      -1,    36,    11,    12,    13,     7,    15,    -1,    -1,    11,
      12,    13,    -1,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,    11,    12,    13,    15,    42,    43,    44,
      47,    53,    55,    39,     0,    44,    47,    53,     3,    48,
      52,    54,    20,    29,    27,    39,    45,    22,    39,     3,
       4,     5,     6,    29,    31,    34,    36,    59,    61,    62,
      63,    64,    65,    66,    67,    49,    50,    55,     9,    10,
      14,    27,    37,    39,    46,    53,    55,    56,    59,     3,
      52,    29,     1,    61,    61,    61,    61,    22,    16,    17,
      18,    19,    20,    21,    23,    24,    25,    26,    28,    30,
      31,    32,    33,    35,    36,    22,    51,    38,     3,    29,
      29,    39,    59,     1,    37,    56,    57,    58,    37,    53,
      56,    39,     1,    38,    61,    38,    38,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    49,    59,    59,    39,    37,
      39,     1,    37,    57,    38,    60,    51,    38,    38,    22,
      38,    57,    57,    61,     8,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    44,
      45,    45,    46,    46,    46,    46,    47,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      66,    66,    67,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     3,
       2,     3,     2,     2,     1,     1,     3,     4,     1,     2,
       2,     3,     0,     1,     3,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     5,
       7,     5,     2,     3,     1,     2,     2,     1,     3,     1,
       3,     0,     3,     3,     4,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     5,     1,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 200 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Program",(yyvsp[0].node));if (flag==2 && syn_error==0){print_tree((yyval.node),0);}}
#line 1678 "y.tab.c"
    break;

  case 3:
#line 204 "uccompiler.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1684 "y.tab.c"
    break;

  case 4:
#line 205 "uccompiler.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1690 "y.tab.c"
    break;

  case 5:
#line 206 "uccompiler.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1696 "y.tab.c"
    break;

  case 6:
#line 207 "uccompiler.y"
                                                    {if ((yyvsp[-1].node) != NULL){(yyval.node) = (yyvsp[-1].node); insert_brother((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1702 "y.tab.c"
    break;

  case 7:
#line 208 "uccompiler.y"
                                                    {if ((yyvsp[-1].node) != NULL){(yyval.node) = (yyvsp[-1].node); insert_brother((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1708 "y.tab.c"
    break;

  case 8:
#line 209 "uccompiler.y"
                                                    {if ((yyvsp[-1].node) != NULL){(yyval.node) = (yyvsp[-1].node); insert_brother((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1714 "y.tab.c"
    break;

  case 9:
#line 213 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"FuncDefinition", (yyvsp[-2].node)); insert_brother((yyvsp[-2].node),(yyvsp[-1].node)); insert_brother((yyvsp[-1].node),(yyvsp[0].node));}
#line 1720 "y.tab.c"
    break;

  case 10:
#line 217 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"FuncBody",NULL);}
#line 1726 "y.tab.c"
    break;

  case 11:
#line 218 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"FuncBody", (yyvsp[-1].node));}
#line 1732 "y.tab.c"
    break;

  case 12:
#line 222 "uccompiler.y"
                                                    {
        if((yyvsp[-1].node) != NULL){(yyval.node) = (yyvsp[-1].node); insert_brother((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1739 "y.tab.c"
    break;

  case 13:
#line 224 "uccompiler.y"
                                                    {if ((yyvsp[-1].node) != NULL){(yyval.node) = (yyvsp[-1].node); insert_brother((yyval.node),(yyvsp[0].node));}else (yyval.node)=(yyvsp[0].node);}
#line 1745 "y.tab.c"
    break;

  case 14:
#line 225 "uccompiler.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1751 "y.tab.c"
    break;

  case 15:
#line 226 "uccompiler.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1757 "y.tab.c"
    break;

  case 16:
#line 230 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"FuncDeclaration", (yyvsp[-2].node)); insert_brother((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1763 "y.tab.c"
    break;

  case 17:
#line 234 "uccompiler.y"
                                                    {(yyval.node) = insert_node((yyvsp[-3].id),"Id",NULL); insert_brother((yyval.node),(yyvsp[-1].node));}
#line 1769 "y.tab.c"
    break;

  case 18:
#line 239 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"ParamDeclaration",(yyvsp[0].node));}
#line 1775 "y.tab.c"
    break;

  case 19:
#line 240 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL, "ParamDeclaration", (yyvsp[-1].node)); insert_brother((yyval.node)->son, insert_node((yyvsp[0].id),"Id", NULL));}
#line 1781 "y.tab.c"
    break;

  case 20:
#line 246 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"ParamList",(yyvsp[-1].node)); insert_brother((yyval.node)->son, (yyvsp[0].node));}
#line 1787 "y.tab.c"
    break;

  case 21:
#line 250 "uccompiler.y"
                                                 {(yyval.node)=(yyvsp[-1].node); insert_brother((yyval.node),(yyvsp[0].node));}
#line 1793 "y.tab.c"
    break;

  case 22:
#line 251 "uccompiler.y"
                                                   { (yyval.node)=NULL;}
#line 1799 "y.tab.c"
    break;

  case 23:
#line 258 "uccompiler.y"
                                  {(yyval.node) = insert_node(NULL,"Declaration", insert_node((yyvsp[0].id),"Id",NULL));}
#line 1805 "y.tab.c"
    break;

  case 24:
#line 259 "uccompiler.y"
                                            {(yyval.node) = insert_node(NULL,"Declaration",insert_node((yyvsp[-2].id),"Id",NULL)); insert_brother((yyval.node)->son,(yyvsp[0].node));}
#line 1811 "y.tab.c"
    break;

  case 25:
#line 262 "uccompiler.y"
                                          {(yyval.node) = (yyvsp[-1].node); addSonFirst((yyval.node), (yyvsp[-2].node));}
#line 1817 "y.tab.c"
    break;

  case 26:
#line 263 "uccompiler.y"
                                       {syn_error = 1;(yyval.node) = NULL;}
#line 1823 "y.tab.c"
    break;

  case 27:
#line 267 "uccompiler.y"
                                              {if ((yyvsp[-2].node) != NULL) {(yyval.node) = (yyvsp[-2].node); insert_brother((yyval.node),(yyvsp[0].node));} else (yyval.node) = (yyvsp[0].node);}
#line 1829 "y.tab.c"
    break;

  case 28:
#line 268 "uccompiler.y"
                                           {(yyval.node) = (yyvsp[0].node);}
#line 1835 "y.tab.c"
    break;

  case 29:
#line 274 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Char", NULL);}
#line 1841 "y.tab.c"
    break;

  case 30:
#line 275 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Int", NULL);}
#line 1847 "y.tab.c"
    break;

  case 31:
#line 276 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Void", NULL);}
#line 1853 "y.tab.c"
    break;

  case 32:
#line 277 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Short", NULL);}
#line 1859 "y.tab.c"
    break;

  case 33:
#line 278 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Double", NULL);}
#line 1865 "y.tab.c"
    break;

  case 34:
#line 286 "uccompiler.y"
                                                    {(yyval.node) = NULL;}
#line 1871 "y.tab.c"
    break;

  case 35:
#line 287 "uccompiler.y"
                                                                                    {(yyval.node) = (yyvsp[-1].node);}
#line 1877 "y.tab.c"
    break;

  case 36:
#line 288 "uccompiler.y"
                                                    {(yyval.node) = NULL;}
#line 1883 "y.tab.c"
    break;

  case 37:
#line 289 "uccompiler.y"
                                                    {(yyval.node) = NULL;syn_error=1;}
#line 1889 "y.tab.c"
    break;

  case 38:
#line 290 "uccompiler.y"
                                                    {(yyval.node) = (yyvsp[-1].node);
                                                    if ((yyvsp[-1].node)!=NULL && (yyvsp[-1].node)->brother!=NULL) (yyval.node) = insert_node(NULL,"StatList",(yyvsp[-1].node));
                                                    else (yyval.node)=(yyvsp[-1].node);
                                                    }
#line 1898 "y.tab.c"
    break;

  case 39:
#line 297 "uccompiler.y"
                                                 {
                                    (yyval.node) = insert_node(NULL,"If",(yyvsp[-2].node)); 
                                    if((yyvsp[0].node) == NULL){insert_brother((yyvsp[-2].node), insert_node(NULL,"Null",NULL));}
                                    else if((yyvsp[0].node)->brother != NULL){ 
                                        struct Node * aux = (struct Node*) malloc(sizeof(struct Node));
                                        aux= insert_node(NULL,"StatList",NULL);
                                        insert_brother((yyval.node)->son,aux);
                                        insert_brother(aux->son,(yyvsp[0].node));
                                        }
                                    else insert_brother((yyval.node)->son, (yyvsp[0].node));
                                    insert_brother((yyval.node)->son, insert_node(NULL,"Null", NULL));
        }
#line 1915 "y.tab.c"
    break;

  case 40:
#line 311 "uccompiler.y"
                                                             {
                                    (yyval.node) = insert_node(NULL,"If",(yyvsp[-4].node)); 
                                    if((yyvsp[-2].node) == NULL){insert_brother((yyval.node)->son, insert_node(NULL,"Null",NULL));}
                                    else if((yyvsp[-2].node)->brother != NULL){
                                        struct Node * aux = (struct Node*) malloc(sizeof(struct Node));
                                        aux= insert_node(NULL,"StatList",NULL);
                                        insert_brother((yyval.node)->son, aux);
                                        insert_brother(aux->son,(yyvsp[-2].node));
                                        }
                                    else insert_brother((yyval.node)->son, (yyvsp[-2].node));
                                    if((yyvsp[0].node) == NULL){insert_brother((yyval.node)->son, insert_node(NULL,"Null",NULL));}
                                    else if((yyvsp[0].node)->brother != NULL){
                                        struct Node * aux = (struct Node*) malloc(sizeof(struct Node));
                                        aux= insert_node(NULL,"StatList",NULL);
                                        insert_brother((yyval.node)->son,aux);
                                        insert_brother(aux->son,(yyvsp[0].node));}
                                    else insert_brother((yyval.node)->son, (yyvsp[0].node));

        }
#line 1939 "y.tab.c"
    break;

  case 41:
#line 335 "uccompiler.y"
                                                     {
    	(yyval.node) = insert_node(NULL,"While",(yyvsp[-2].node));
    	if((yyvsp[0].node) == NULL){insert_brother((yyval.node)->son, insert_node(NULL,"Null",NULL));}
    	else insert_brother((yyval.node)->son,(yyvsp[0].node));}
#line 1948 "y.tab.c"
    break;

  case 42:
#line 341 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Return",insert_node(NULL,"Null",NULL));
                                                    }
#line 1955 "y.tab.c"
    break;

  case 43:
#line 343 "uccompiler.y"
                                                     {(yyval.node) = insert_node(NULL,"Return",(yyvsp[-1].node));
                                                    }
#line 1962 "y.tab.c"
    break;

  case 44:
#line 348 "uccompiler.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1968 "y.tab.c"
    break;

  case 45:
#line 349 "uccompiler.y"
                                                    {(yyval.node) = NULL; syn_error = 1;}
#line 1974 "y.tab.c"
    break;

  case 46:
#line 353 "uccompiler.y"
                                                  {if ((yyvsp[-1].node) != NULL) {(yyval.node) = (yyvsp[-1].node); insert_brother((yyval.node),(yyvsp[0].node));}else (yyval.node) = (yyvsp[0].node);}
#line 1980 "y.tab.c"
    break;

  case 47:
#line 354 "uccompiler.y"
                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1986 "y.tab.c"
    break;

  case 48:
#line 360 "uccompiler.y"
                                                        {(yyval.node) = insert_node(NULL, "Comma",NULL); 
    if((yyvsp[-2].node)!=NULL) insert_brother((yyval.node)->son, (yyvsp[-2].node));
    else {
    insert_brother((yyval.node)->son, insert_node(NULL, "Null",NULL));
    } 
    if((yyvsp[0].node) != NULL) {insert_brother((yyval.node)->son, (yyvsp[0].node));}
    else {insert_brother((yyval.node)->son, insert_node(NULL, "Null",NULL));} 


    insert_brother((yyval.node),(yyvsp[0].node));}
#line 2001 "y.tab.c"
    break;

  case 49:
#line 371 "uccompiler.y"
                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2007 "y.tab.c"
    break;

  case 50:
#line 376 "uccompiler.y"
                                 {if((yyvsp[-2].node) != NULL){(yyval.node) = (yyvsp[-2].node); insert_brother((yyval.node)->son,(yyvsp[0].node));}else if((yyvsp[0].node) != NULL)(yyval.node) = (yyvsp[0].node);else {(yyval.node) = insert_node(NULL,"Null",NULL);}}
#line 2013 "y.tab.c"
    break;

  case 51:
#line 377 "uccompiler.y"
                                    {(yyval.node) = NULL;}
#line 2019 "y.tab.c"
    break;

  case 52:
#line 381 "uccompiler.y"
                                                    {
                                                    (yyval.node) = insert_node(NULL,"Store",(yyvsp[-2].node));
                                                    insert_brother((yyvsp[-2].node),(yyvsp[0].node));}
#line 2027 "y.tab.c"
    break;

  case 53:
#line 386 "uccompiler.y"
                                                    {(yyval.node) = NULL;syn_error=1;}
#line 2033 "y.tab.c"
    break;

  case 54:
#line 387 "uccompiler.y"
                                                    {(yyval.node) = NULL;syn_error=1;}
#line 2039 "y.tab.c"
    break;

  case 61:
#line 398 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Add",(yyvsp[-2].node));}
#line 2045 "y.tab.c"
    break;

  case 62:
#line 399 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Sub",(yyvsp[-2].node));}
#line 2051 "y.tab.c"
    break;

  case 63:
#line 400 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Mul",(yyvsp[-2].node));}
#line 2057 "y.tab.c"
    break;

  case 64:
#line 401 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Div",(yyvsp[-2].node));}
#line 2063 "y.tab.c"
    break;

  case 65:
#line 402 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Mod",(yyvsp[-2].node));}
#line 2069 "y.tab.c"
    break;

  case 66:
#line 406 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Or",(yyvsp[-2].node));}
#line 2075 "y.tab.c"
    break;

  case 67:
#line 407 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"And",(yyvsp[-2].node));}
#line 2081 "y.tab.c"
    break;

  case 68:
#line 408 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"BitWiseAnd",(yyvsp[-2].node));}
#line 2087 "y.tab.c"
    break;

  case 69:
#line 409 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"BitWiseOr",(yyvsp[-2].node));}
#line 2093 "y.tab.c"
    break;

  case 70:
#line 410 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"BitWiseXor",(yyvsp[-2].node));}
#line 2099 "y.tab.c"
    break;

  case 71:
#line 414 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Eq",(yyvsp[-2].node));}
#line 2105 "y.tab.c"
    break;

  case 72:
#line 415 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Ne",(yyvsp[-2].node));}
#line 2111 "y.tab.c"
    break;

  case 73:
#line 416 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Le",(yyvsp[-2].node));}
#line 2117 "y.tab.c"
    break;

  case 74:
#line 417 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Ge",(yyvsp[-2].node));}
#line 2123 "y.tab.c"
    break;

  case 75:
#line 418 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Lt",(yyvsp[-2].node));}
#line 2129 "y.tab.c"
    break;

  case 76:
#line 419 "uccompiler.y"
                                                    {insert_brother((yyvsp[-2].node),(yyvsp[0].node));(yyval.node) = insert_node(NULL,"Gt",(yyvsp[-2].node));}
#line 2135 "y.tab.c"
    break;

  case 77:
#line 423 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Plus",(yyvsp[0].node));}
#line 2141 "y.tab.c"
    break;

  case 78:
#line 424 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Minus",(yyvsp[0].node));}
#line 2147 "y.tab.c"
    break;

  case 79:
#line 425 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Not",(yyvsp[0].node));}
#line 2153 "y.tab.c"
    break;

  case 80:
#line 429 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Call", insert_node((yyvsp[-2].id),"Id",NULL));
                                                    }
#line 2160 "y.tab.c"
    break;

  case 81:
#line 431 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Call", insert_node((yyvsp[-4].id),"Id",NULL));
                                                    insert_brother((yyval.node)->son,(yyvsp[-2].node));
                                                    insert_brother((yyvsp[-2].node),(yyvsp[-1].node));
                                                    }
#line 2169 "y.tab.c"
    break;

  case 82:
#line 438 "uccompiler.y"
                                                    {(yyval.node) = insert_node((yyvsp[0].id),"Id",NULL);}
#line 2175 "y.tab.c"
    break;

  case 83:
#line 439 "uccompiler.y"
                                                    {(yyval.node) = insert_node((yyvsp[0].id),"IntLit",NULL);}
#line 2181 "y.tab.c"
    break;

  case 84:
#line 440 "uccompiler.y"
                                                    {(yyval.node) = insert_node((yyvsp[0].id),"RealLit",NULL);}
#line 2187 "y.tab.c"
    break;

  case 85:
#line 441 "uccompiler.y"
                                                    {(yyval.node) = insert_node((yyvsp[0].id),"ChrLit",NULL);}
#line 2193 "y.tab.c"
    break;

  case 86:
#line 442 "uccompiler.y"
                                                    {(yyval.node) = insert_node(NULL,"Aux",(yyvsp[-1].node));}
#line 2199 "y.tab.c"
    break;


#line 2203 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 446 "uccompiler.y"


