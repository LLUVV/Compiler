/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 9 "y2.y"
#include <stdio.h>
#include <stdlib.h>
#include "code.h"
extern int lineno;
extern FILE *f_asm;
int    errcnt=0;
int    errline=0;
char   *install_symbol();
int exprStack = 0;
int tableOffset=0;
int cur_mode=GLOBAL_MODE;
int exprsCount=0;
int funcSymCounter=0;
#line 25 "y2.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
         int       token ;
         char      charv ;
         char      *ident;
       } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 86 "y2.y"
/* external function is defined here */
void error();
int TRACEON = 1;
#line 52 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDENTIFIER 257
#define INTEGER 258
#define FLOAT 259
#define SCSPEC 260
#define TYPESPEC 261
#define ENUM 262
#define STRUCT 263
#define UNION 264
#define TYPEMOD 265
#define CONSTANT 266
#define STRING 267
#define SIZEOF 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define DO 272
#define FOR 273
#define SWITCH 274
#define CASE 275
#define DEFAULT_TOKEN 276
#define BREAK 277
#define CONTINUE 278
#define RETURN 279
#define GOTO 280
#define ASM 281
#define ASSIGN 282
#define OROR 283
#define ANDAND 284
#define NE_OP 285
#define EQ_OP 286
#define ARITHCOMPARE 287
#define LSHIFT 288
#define RSHIFT 289
#define UNARY 290
#define PLUSPLUS 291
#define MINUSMINUS 292
#define HYPERUNARY 293
#define POINTSAT 294
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    5,    5,    6,    7,   10,   11,    6,    6,
    6,   12,   12,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    2,    2,    2,    2,    2,    2,
    1,    1,   13,   13,   14,   14,   15,    9,    9,   16,
   16,   17,   17,   18,   19,   17,   20,   21,   22,   17,
    4,   23,   24,    4,    8,    8,   25,   25,   26,   26,
};
static const YYINT yylen[] = {                            2,
    0,    1,    1,    2,    3,    0,    0,    0,    9,    2,
    1,    1,    3,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,    1,    2,    2,    2,    4,
    4,    1,    0,    1,    1,    3,    2,    0,    1,    1,
    2,    2,    3,    0,    0,   10,    0,    0,    0,   12,
    0,    0,    0,    7,    0,    1,    1,    2,    3,    5,
};
static const YYINT yydefred[] = {                         0,
    0,    0,   11,    0,    0,    3,   10,   32,    0,    4,
    5,    0,    0,    0,    0,    0,   35,    0,    0,   31,
    0,    0,    7,    0,   57,   36,    0,    0,   58,   59,
    0,    0,   25,   26,    0,    0,    0,    0,    0,    0,
    0,    0,    8,    0,   40,    0,    0,    0,   44,    0,
    0,    0,    0,   29,   42,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   41,   60,    0,    0,    0,    0,
   43,   23,    0,    0,    0,    0,    0,    0,   18,   19,
    9,    0,   30,   47,    0,   13,    0,    0,    0,    0,
   48,   45,    0,    0,   49,    0,    0,   46,    0,   52,
   50,    0,    0,   53,    0,    0,   54,
};
static const YYINT yydgoto[] = {                          4,
    9,   41,   42,  101,    5,    6,   13,   23,   43,   28,
   64,   68,   15,   16,   17,   44,   45,   70,   94,   87,
   93,   97,  102,  105,   24,   25,
};
static const YYINT yysindex[] = {                       -47,
  -16, -210,    0,    0,  -47,    0,    0,    0,  -17,    0,
    0, -200,  -46, -210,   47,   32,    0, -171,   55,    0,
 -200, -210,    0, -171,    0,    0,    5,   46,    0,    0,
  128,   57,    0,    0,   77,   78,   11,   11,  128,   11,
 -192,   79,    0,   46,    0,   85,  128,  128,    0,  -54,
 -192,   42, -192,    0,    0,  128,  128,  128,  128,  128,
  128,  128,  128,  -15,    0,    0,  -28,   92,   51,  128,
    0,    0,  -21,    7,    7,  141,   25,   25,    0,    0,
    0,  128,    0,    0,   59,    0,   12,   14, -171, -171,
    0,    0,   46,   46,    0,   16,   22,    0, -121,    0,
    0,   28, -171,    0,   46,   31,    0,
};
static const YYINT yyrindex[] = {                       153,
    0,    0,    0,    0,  162,    0,    0,    0,   41,    0,
    0,  144,    0,    0,    0,  146,    0,   18,   37,    0,
    0,    0,    0,   29,    0,    0,    0,   44,    0,    0,
    0,  -41,    0,    0,    0,    0,    0,    0,    0,    0,
  -34,    0,    0,   65,    0,    0,    0,    0,    0,    0,
  -13,    0,   -6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  150,    0,    0,    0,
    0,    0,  111,   98,  104,   75,   64,   70,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   18,   18,
    0,    0,   44,   44,    0,    0,    0,    0,   35,    0,
    0,    0,   18,    0,   44,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   43,  134,  119,    0,    0,  187,    0,  -30,  -23,    0,
    0,  112,    0,    0,  172,    0,  151,    0,    0,    0,
    0,    0,    0,    0,    0,  173,
};
#define YYTABLESIZE 395
static const YYINT yytable[] = {                         24,
   24,   24,   24,   24,   71,   24,   14,   14,   14,   14,
   14,    3,   14,   62,   60,   82,   61,   24,   63,   24,
   62,   60,   12,   61,   14,   63,   14,   27,   27,   27,
   27,   27,   56,   27,   28,   28,   28,   28,   28,   56,
   28,   11,    7,   40,   12,   27,    8,   27,   62,   60,
   55,   61,   28,   63,   28,   38,   19,   55,   91,   92,
   14,   56,   55,   30,   27,   31,   62,   51,   56,   95,
   96,   63,  104,   56,   51,   21,   18,   37,   40,   51,
   37,  106,   72,   62,   60,   39,   61,   20,   63,   22,
   38,   84,   62,   60,   12,   61,   47,   63,   54,   88,
   62,   60,   56,   61,   15,   63,   15,   15,   15,   81,
   16,   56,   16,   16,   16,   20,   48,   49,   20,   56,
   62,   60,   15,   61,   15,   63,   62,   60,   16,   61,
   16,   63,   83,   20,   89,   20,   90,   55,   22,   56,
   98,   22,   55,   66,   21,   56,   99,   21,  100,   46,
  103,   17,    1,   56,   17,  107,   22,   52,   22,   51,
   40,    2,   21,    6,   21,   67,   69,   39,   38,   17,
   50,   51,   38,   53,   73,   74,   75,   76,   77,   78,
   79,   80,   62,   60,   33,   61,   34,   63,   85,   39,
   12,   10,   26,   86,   65,    0,   29,    0,    0,    0,
   67,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   54,    0,    0,    0,
    0,    0,    0,   24,   24,   24,    0,    0,    0,   24,
   14,   14,   14,    0,    0,    0,   57,   58,   59,    0,
    0,    0,    0,   57,   58,   59,    0,   32,    0,    0,
    0,   27,   27,   27,   55,    0,   33,   34,   28,   28,
   28,    0,    0,   55,   55,   56,   55,    0,   55,    0,
    0,   51,    0,   59,   56,   56,   55,   56,    0,   56,
   51,   51,   32,   51,    0,   51,    0,   56,    0,    0,
    0,   33,   34,   51,   35,    0,   36,    0,    0,    0,
    0,    0,    0,    0,   37,    0,   57,   58,   59,    0,
    0,    0,    0,    0,    0,   57,   58,   59,    0,    0,
    0,    0,    0,   57,   58,   59,    0,    0,   15,   15,
   15,    0,    0,    0,   16,   16,   16,    0,    0,   20,
   20,   20,    0,   57,   58,   59,    0,    0,    0,   57,
   58,   59,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   22,   22,   32,    0,    0,    0,   21,   21,
    0,    0,    0,   33,   34,
};
static const YYINT yycheck[] = {                         41,
   42,   43,   44,   45,   59,   47,   41,   42,   43,   44,
   45,   59,   47,   42,   43,   44,   45,   59,   47,   61,
   42,   43,   40,   45,   59,   47,   61,   41,   42,   43,
   44,   45,   61,   47,   41,   42,   43,   44,   45,   61,
   47,   59,   59,   33,   40,   59,  257,   61,   42,   43,
   33,   45,   59,   47,   61,   45,   14,   40,   89,   90,
  261,   33,   45,   59,   22,   61,   42,   33,   40,   93,
   94,   47,  103,   45,   40,   44,  123,   41,   33,   45,
   44,  105,   41,   42,   43,   40,   45,   41,   47,  261,
   45,   41,   42,   43,   40,   45,   40,   47,  291,   41,
   42,   43,   61,   45,   41,   47,   43,   44,   45,  125,
   41,   61,   43,   44,   45,   41,   40,   40,   44,   61,
   42,   43,   59,   45,   61,   47,   42,   43,   59,   45,
   61,   47,   41,   59,  123,   61,  123,   59,   41,   61,
  125,   44,  125,   59,   41,   61,  125,   44,  270,   31,
  123,   41,    0,  125,   44,  125,   59,   39,   61,  125,
   33,    0,   59,  123,   61,   47,   48,   40,  125,   59,
   37,   38,   45,   40,   56,   57,   58,   59,   60,   61,
   62,   63,   42,   43,   41,   45,   41,   47,   70,  125,
   41,    5,   21,   82,   44,   -1,   24,   -1,   -1,   -1,
   82,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,   -1,  261,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  291,   -1,   -1,   -1,
   -1,   -1,   -1,  285,  286,  287,   -1,   -1,   -1,  291,
  285,  286,  287,   -1,   -1,   -1,  285,  286,  287,   -1,
   -1,   -1,   -1,  285,  286,  287,   -1,  257,   -1,   -1,
   -1,  285,  286,  287,  257,   -1,  266,  267,  285,  286,
  287,   -1,   -1,  266,  267,  257,  269,   -1,  271,   -1,
   -1,  257,   -1,  287,  266,  267,  279,  269,   -1,  271,
  266,  267,  257,  269,   -1,  271,   -1,  279,   -1,   -1,
   -1,  266,  267,  279,  269,   -1,  271,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  279,   -1,  285,  286,  287,   -1,
   -1,   -1,   -1,   -1,   -1,  285,  286,  287,   -1,   -1,
   -1,   -1,   -1,  285,  286,  287,   -1,   -1,  285,  286,
  287,   -1,   -1,   -1,  285,  286,  287,   -1,   -1,  285,
  286,  287,   -1,  285,  286,  287,   -1,   -1,   -1,  285,
  286,  287,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  285,  286,  257,   -1,   -1,   -1,  285,  286,
   -1,   -1,   -1,  266,  267,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#define YYUNDFTOKEN 323
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,
0,0,0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDENTIFIER","INTEGER",
"FLOAT","SCSPEC","TYPESPEC","ENUM","STRUCT","UNION","TYPEMOD","CONSTANT",
"STRING","SIZEOF","IF","ELSE","WHILE","DO","FOR","SWITCH","CASE",
"DEFAULT_TOKEN","BREAK","CONTINUE","RETURN","GOTO","ASM","ASSIGN","OROR",
"ANDAND","NE_OP","EQ_OP","ARITHCOMPARE","LSHIFT","RSHIFT","UNARY","PLUSPLUS",
"MINUSMINUS","HYPERUNARY","POINTSAT",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program :",
"program : extdefs",
"extdefs : extdef",
"extdefs : extdefs extdef",
"extdef : TYPESPEC notype_declarator ';'",
"$$1 :",
"$$2 :",
"$$3 :",
"extdef : TYPESPEC notype_declarator $$1 '{' xdecls $$2 stmts $$3 '}'",
"extdef : error ';'",
"extdef : ';'",
"exprs : expr_no_commas",
"exprs : expr_no_commas ',' exprs",
"expr_no_commas : primary",
"expr_no_commas : expr_no_commas '+' expr_no_commas",
"expr_no_commas : expr_no_commas '-' expr_no_commas",
"expr_no_commas : expr_no_commas '=' expr_no_commas",
"expr_no_commas : expr_no_commas '*' expr_no_commas",
"expr_no_commas : expr_no_commas '/' expr_no_commas",
"expr_no_commas : expr_no_commas ARITHCOMPARE expr_no_commas",
"expr_no_commas : expr_no_commas EQ_OP expr_no_commas",
"expr_no_commas : expr_no_commas NE_OP expr_no_commas",
"expr_no_commas : '(' expr_no_commas ')'",
"primary : IDENTIFIER",
"primary : CONSTANT",
"primary : STRING",
"primary : '-' primary",
"primary : '!' primary",
"primary : primary PLUSPLUS",
"primary : IDENTIFIER '(' exprs ')'",
"notype_declarator : notype_declarator '(' parmlist ')'",
"notype_declarator : IDENTIFIER",
"parmlist :",
"parmlist : parms",
"parms : parm",
"parms : parms ',' parm",
"parm : TYPESPEC notype_declarator",
"stmts :",
"stmts : stmtx",
"stmtx : stmt",
"stmtx : stmtx stmt",
"stmt : expr_no_commas ';'",
"stmt : RETURN primary ';'",
"$$4 :",
"$$5 :",
"stmt : WHILE '(' $$4 expr_no_commas ')' '{' xdecls $$5 stmts '}'",
"$$6 :",
"$$7 :",
"$$8 :",
"stmt : IF '(' expr_no_commas ')' $$6 '{' xdecls $$7 stmts $$8 '}' else_stmt",
"else_stmt :",
"$$9 :",
"$$10 :",
"else_stmt : ELSE $$9 '{' xdecls $$10 stmts '}'",
"xdecls :",
"xdecls : decls",
"decls : decl",
"decls : decls decl",
"decl : TYPESPEC notype_declarator ';'",
"decl : TYPESPEC notype_declarator '=' expr_no_commas ';'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 641 "y2.y"

int yylex();
void set_scope_and_offset_of_param(char *s);
void set_global_vars(char *s);
void code_gen_func_header(char *functor);
void set_local_vars(char *functor);
void pop_up_symbol(int scope);
void code_gen_at_end_of_function_body(char *functor);
int look_up_symbol(char *s);

/*
 *	  s - the error message to be printed
 */


 void err(s)
 char   *s;
 {
 	if (! errcnt++)
 		errline = lineno;
          fprintf(stderr,"Error on line %d \n",lineno);

 	exit(1);
 }

void
yyerror(s)
	char   *s;
{
	err(s);
}
#line 431 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 95 "y2.y"
	{ if (TRACEON) printf("1\n ");}
break;
case 2:
#line 97 "y2.y"
	{ if (TRACEON) printf("2\n ");}
break;
case 3:
#line 102 "y2.y"
	{ if (TRACEON) printf("3\n ");}
break;
case 4:
#line 104 "y2.y"
	{ if (TRACEON) printf("4\n ");}
break;
case 5:
#line 109 "y2.y"
	{ if (TRACEON) printf("7 ");
            set_global_vars(yystack.l_mark[-1].ident);
          }
break;
case 6:
#line 113 "y2.y"
	{ if (TRACEON) printf("10 ");
                    cur_scope++;
                    funcSymCounter++;
                    cur_mode=LOCAL_MODE;
                    tableOffset=0;
                    set_scope_and_offset_of_param(yystack.l_mark[0].ident);
		                code_gen_func_header(yystack.l_mark[0].ident);
                  }
break;
case 7:
#line 122 "y2.y"
	{ if (TRACEON) printf("10.5 ");
                    set_local_vars(yystack.l_mark[-3].ident);
                  }
break;
case 8:
#line 126 "y2.y"
	{
                  if (TRACEON) printf("11 ");
                  pop_up_symbol(cur_scope);
                  cur_scope--;
                  code_gen_at_end_of_function_body(yystack.l_mark[-5].ident);
                }
break;
case 10:
#line 134 "y2.y"
	{ if (TRACEON) printf("8 "); }
break;
case 11:
#line 136 "y2.y"
	{ if (TRACEON) printf("9 "); }
break;
case 12:
#line 144 "y2.y"
	{
         ++exprsCount;
     }
break;
case 13:
#line 147 "y2.y"
	{
         ++exprsCount;
     }
break;
case 14:
#line 155 "y2.y"
	{ if (TRACEON) printf("15 ") ;
 	     yyval.ident= yystack.l_mark[0].ident;
           }
break;
case 15:
#line 159 "y2.y"
	{
                  if (TRACEON) printf("16 ") ;

                  /*fprintf(f_asm,"        pop  cx\n");*/
                  /*fprintf(f_asm,"        pop  bx\n");*/
                  /*fprintf(f_asm,"        add  bx, cx\n");*/
                  /*fprintf(f_asm,"        push bx\n");*/
                  fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  fprintf(f_asm, "\tld\tt4, %d(s0)\n", tableOffset*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  fprintf(f_asm, "\tadd\tt5, t3, t4\n");
                  ++exprStack;
                  ++tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, -8\n");
                  fprintf(f_asm, "\tsd\tt5, %d(s0)\n", tableOffset*-8);
		  yyval.ident= NULL;
                }
break;
case 16:
#line 182 "y2.y"
	{
                  if (TRACEON) printf("116 ") ;

                  /*fprintf(f_asm,"        pop  cx\n");*/
                  /*fprintf(f_asm,"        pop  bx\n");*/
                  /*fprintf(f_asm,"        add  bx, cx\n");*/
                  /*fprintf(f_asm,"        push bx\n");*/
                  fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  fprintf(f_asm, "\tld\tt4, %d(s0)\n", tableOffset*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  fprintf(f_asm, "\tsub\tt5, t4, t3\n");
                  ++exprStack;
                  ++tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, -8\n");
                  fprintf(f_asm, "\tsd\tt5, %d(s0)\n", tableOffset*-8);
              		yyval.ident= NULL;
                }
break;
case 17:
#line 205 "y2.y"
	{ char *s;
		  int index;

		  if (TRACEON) printf("17 ") ;
		  s= yystack.l_mark[-2].ident;
		  if (!s) err("improper expression at LHS");
		  index = look_up_symbol(s);
                  /*fprintf(f_asm,"        pop  bx\n");*/
                  /*fprintf(f_asm,"        pop  cx\n");*/
		  switch(table[index].mode) {
                  case ARGUMENT_MODE:
		    fprintf(f_asm,"        mov  word ptr [bp-%d], bx\n",table[index].offset*2+2);
		    fprintf(f_asm,"        push bx\n");
                    break;
		  case LOCAL_MODE:
		    /*fprintf(f_asm,"        mov  word ptr [bp+%d], bx\n",table[index].offset*2);*/
		    /*fprintf(f_asm,"        push bx\n");*/
        printf("index: %s, %d\n",yystack.l_mark[-2].ident,table[index].offset);
        fprintf(f_asm,"\tld\tt3, %d(s0)\n",-8 * (tableOffset));
        --exprStack;
        --tableOffset;
        printf("index2: %s, %d\n",yystack.l_mark[-2].ident,table[index].offset);
        fprintf(f_asm, "\taddi\tsp, sp, 8\n");
		    fprintf(f_asm,"\tsd\tt3, %d(s0)\n",(table[index].offset)*-8);
                    break;
		  default: /* Global Vars */
		    fprintf(f_asm,"        mov  word ptr DGROUP:_%s,0, bx\n",table[index].name);
		    fprintf(f_asm,"        push bx\n");
		  }
                }
break;
case 18:
#line 236 "y2.y"
	{ if (TRACEON) printf("11 ") ;

                  /*fprintf(f_asm,"        pop  cx\n");*/
                  /*fprintf(f_asm,"        pop  bx\n");*/
                  /*fprintf(f_asm,"        mul  bx, cx\n");*/
                  /*fprintf(f_asm,"        push bx\n");*/
                  fprintf(f_asm, "    ld      t3, %d(s0)\n", tableOffset*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  fprintf(f_asm, "\tld\tt4, %d(s0)\n", tableOffset*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  fprintf(f_asm, "\tmul\tt5, t3, t4\n");
                  ++exprStack;
                  ++tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, -8\n");
                  fprintf(f_asm, "\tsd\tt5, %d(s0)\n", tableOffset*-8);
              		  yyval.ident= NULL;
                              }
break;
case 19:
#line 258 "y2.y"
	{ if (TRACEON) printf("114 ") ;
                  /*fprintf(f_asm,"        pop  cx\n");*/
                  /*fprintf(f_asm,"        pop  bx\n");*/
                  /*fprintf(f_asm,"        div  bx, cx\n");*/
                  /*fprintf(f_asm,"        push bx\n");*/
                  fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  fprintf(f_asm, "\tld\tt4, %d(s0)\n", tableOffset*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  fprintf(f_asm, "\tdiv\tt5, t4, t3\n");
                  ++exprStack;
                  ++tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, -8\n");
                  fprintf(f_asm, "\tsd\tt5, %d(s0)\n", tableOffset*-8);
                  yyval.ident= NULL;
              }
break;
case 20:
#line 279 "y2.y"
	{
    if (TRACEON) printf("19 ") ;
    fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);
    --exprStack;
    --tableOffset;
    fprintf(f_asm, "\taddi\tsp, sp, 8\n");
    fprintf(f_asm, "\tld\tt4, %d(s0)\n", tableOffset*-8);
    --exprStack;
    --tableOffset;
    fprintf(f_asm, "\taddi\tsp, sp, 8\n");
    /*char *s = $2;*/
    /*if(s == "<")*/
    /*{*/
      fprintf(f_asm, "\tbeq\tt4, t3, ENDWHILE\n");
      fprintf(f_asm, "\tbge\tt4, t3, ENDWHILE\n");
    /*}*/
  }
break;
case 21:
#line 297 "y2.y"
	{
    if (TRACEON) printf("119 ") ;
    fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);
    --exprStack;
    --tableOffset;
    fprintf(f_asm, "\taddi\tsp, sp, 8\n");
    fprintf(f_asm, "\tld\tt4, %d(s0)\n", tableOffset*-8);
    --exprStack;
    --tableOffset;
    fprintf(f_asm, "\taddi\tsp, sp, 8\n");
    fprintf(f_asm, "\tbne\tt4, t3, NOT");
  }
break;
case 22:
#line 310 "y2.y"
	{
    if (TRACEON) printf("120 ") ;
    fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);
    --exprStack;
    --tableOffset;
    fprintf(f_asm, "\taddi\tsp, sp, 8\n");
    fprintf(f_asm, "\tld\tt4, %d(s0)\n", tableOffset*-8);
    --exprStack;
    --tableOffset;
    fprintf(f_asm, "\taddi\tsp, sp, 8\n");
    fprintf(f_asm, "\tbeq\tt4, t3, NOT\n");
  }
break;
case 23:
#line 323 "y2.y"
	{
    { if (TRACEON) printf("189 ") ; }
  }
break;
case 24:
#line 332 "y2.y"
	{    	  int index;

                  if (TRACEON) printf("20 ") ;

		  index =look_up_symbol(yystack.l_mark[0].ident);
		  switch(table[index].mode) {
                  case ARGUMENT_MODE:
		    /* fprintf(f_asm,"        mov  bx, word ptr [bp-%d]\n",table[index].offset*2+2);*/
		    /* fprintf(f_asm,"        push bx\n");*/
                    break;
		  case LOCAL_MODE:
		    /*fprintf(f_asm,"        mov  bx, word ptr [bp+%d]\n",table[index].offset*2);*/
		    /*fprintf(f_asm,"        push bx\n");*/
        fprintf(f_asm,"\tld\tt3, %d(s0)\n",(table[index].offset)*-8);
        ++exprStack;
        ++tableOffset;
        fprintf(f_asm, "\taddi\tsp, sp, -8\n");
		    fprintf(f_asm,"\tsd\tt3, %d(s0)\n",-8 * (tableOffset));
                    break;
		  default: /* Global Vars */
        fprintf(f_asm, "Not Support\n");
		    /* fprintf(f_asm,"        mov  bx, word ptr DGROUP:_%s,0\n",table[index].name);*/
		    /* fprintf(f_asm,"        push bx\n");*/
		  }
		  yyval.ident=yystack.l_mark[0].ident;
         }
break;
case 25:
#line 359 "y2.y"
	{ if (TRACEON) printf("21 ") ;
      int a = yystack.l_mark[0].token;
		  /*fprintf(f_asm,"        mov  bx, %d\n",$1);*/
		  /*fprintf(f_asm,"        push bx\n",$1);*/
      ++exprStack;
      ++tableOffset;
      fprintf(f_asm, "\taddi\tsp, sp, -8\n");
      if(a < 2048)       fprintf(f_asm,"\taddi\tt3, zero, %d\n", a);
      /*else if(a < 4096) fprintf(f_asm,"\taddiu\tt3, zero, %d\n", a);*/
      else
      {
        int c = a >> 11;
        fprintf(f_asm,"\tlui\tt3, %d\n", c);
        fprintf(f_asm,"\taddi\tt4, zero, %d\n", a - c * 4096);
        fprintf(f_asm,"\tadd\tt5, t4, t3\n");
        fprintf(f_asm,"\tmv\tt3, t5\n");
        /*++exprStack;*/
        /*++tableOffset;*/
        /*fprintf(f_asm, "\taddi\tsp, sp, -8\n");*/
        /*fprintf(f_asm, "\tsd\t%d, %d(s0)\n", a,tableOffset*-8);*/
        /*fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);*/
        /*--exprStack;*/
        /*--tableOffset;*/
      }

      fprintf(f_asm,"\tsd\tt3, %d(s0)\n",-8 * (tableOffset));
                }
break;
case 26:
#line 387 "y2.y"
	{
		  if (TRACEON) printf("22 ") ;
                }
break;
case 27:
#line 391 "y2.y"
	{
    if (TRACEON) printf("118 ") ;
    fprintf(f_asm, "ld      t3, %d(s0)\n", tableOffset*-8);
    --exprStack;
    --tableOffset;
    fprintf(f_asm, "\taddi\tsp, sp, 8\n");
    fprintf(f_asm,"\taddi\tt4, zero, -1\n");
    fprintf(f_asm, "\tmul\tt5, t3, t4\n");
    ++exprStack;
    ++tableOffset;
    fprintf(f_asm, "\taddi\tsp, sp, -8\n");
    fprintf(f_asm, "\tsd\tt5, %d(s0)\n", tableOffset*-8);
    yyval.ident= NULL;
  }
break;
case 28:
#line 406 "y2.y"
	{
    char *s = yystack.l_mark[0].ident;
    int a = atoi(s);
    if(a == 0)
    {
      /*fprintf(f_asm,"\taddi\tt3, zero, 1\n");*/
      /*fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);*/
    }
    else
    {
      fprintf(f_asm,"\tbeq\tzero, zero , NOT\n");
      /*fprintf(f_asm,"\taddi\tt3, zero, zero\n");*/
      /*fprintf(f_asm, "\tld\tt3, %d(s0)\n", tableOffset*-8);*/
    }
  }
break;
case 29:
#line 422 "y2.y"
	{
		  if (TRACEON) printf("23 ") ;
                }
break;
case 30:
#line 426 "y2.y"
	{
      int pNum = exprsCount;
      int i;
      for (i = 0; i < exprsCount; ++i) {
        fprintf(f_asm,"    lwi     $r%d, [$fp + (%d)]\n", pNum-i-1, - 4 * (tableOffset));
        --exprStack;
        --tableOffset;
        fprintf(f_asm, "    addi    $sp, $sp, 4\n");
      }
      exprsCount=0;
      fprintf(f_asm, "    bal     %s\n", yystack.l_mark[-3].ident);
      ++exprStack;
      ++tableOffset;
      fprintf(f_asm, "    addi    $sp, $sp, -4\n");
      fprintf(f_asm, "    swi     $r0, [$fp + (%d)]\n", - 4 * (tableOffset));
      --exprStack;
      --tableOffset;
      fprintf(f_asm, "    addi    $sp, $sp, 4\n");


    }
break;
case 31:
#line 451 "y2.y"
	{   if (TRACEON) printf("24 ") ;
		    yyval.ident=yystack.l_mark[-3].ident;
                }
break;
case 32:
#line 456 "y2.y"
	{   if (TRACEON) printf("25 ") ;
                    yyval.ident=install_symbol(yystack.l_mark[0].ident,cur_mode);

                }
break;
case 33:
#line 466 "y2.y"
	{ if (TRACEON) printf("26 ") ; }
break;
case 34:
#line 469 "y2.y"
	{ if (TRACEON) printf("27 ") ;  }
break;
case 35:
#line 476 "y2.y"
	{ if (TRACEON) printf("28 ") ;  }
break;
case 36:
#line 478 "y2.y"
	{ if (TRACEON) printf("29 ") ;  }
break;
case 37:
#line 483 "y2.y"
	{ if (TRACEON) printf("30 ") ;  }
break;
case 38:
#line 492 "y2.y"
	{ if (TRACEON) printf("31 ") ;  }
break;
case 39:
#line 494 "y2.y"
	{ if (TRACEON) printf("32 ") ;  }
break;
case 40:
#line 499 "y2.y"
	{ if (TRACEON) printf("31 ") ;  }
break;
case 41:
#line 501 "y2.y"
	{ if (TRACEON) printf("32 ") ;  }
break;
case 42:
#line 508 "y2.y"
	{
	  /*fprintf(f_asm,"        pop  cx\n");*/
	  /*fprintf(f_asm,"   ;\n");*/
  }
break;
case 43:
#line 513 "y2.y"
	{
    fprintf(f_asm, "\tld      a0, %d(s0)\n", tableOffset*-8);
    --exprStack;
    --tableOffset;
  }
break;
case 44:
#line 519 "y2.y"
	{
    cur_scope++;
    cur_mode=LOCAL_MODE;
    fprintf(f_asm,"\tKNOW : \n");
  }
break;
case 45:
#line 524 "y2.y"
	{}
break;
case 46:
#line 526 "y2.y"
	{
    if (TRACEON) printf("11 ");
    pop_up_symbol(cur_scope);
    cur_scope--;
    fprintf(f_asm, "\tbeq\tzero, zero, KNOW\n");
    fprintf(f_asm,"\tENDWHILE : \n");
    /*code_gen_at_end_of_function_body("IF");*/
  }
break;
case 47:
#line 535 "y2.y"
	{
    cur_scope++;
    /*funcSymCounter++;*/
    cur_mode=LOCAL_MODE;
    /*tableOffset=0;*/
    /*set_scope_and_offset_of_param("IF");*/
    /*code_gen_func_header("IF");*/
  }
break;
case 48:
#line 544 "y2.y"
	{
    if (TRACEON) printf("10.5 ");
    /*set_local_vars("IF");*/
  }
break;
case 49:
#line 549 "y2.y"
	{
    if (TRACEON) printf("11 ");
    pop_up_symbol(cur_scope);
    cur_scope--;
    /*code_gen_at_end_of_function_body("IF");*/
  }
break;
case 50:
#line 555 "y2.y"
	{}
break;
case 51:
#line 560 "y2.y"
	{
    /*fprintf(f_asm, "\tbeq\tzero, zero, YES\n");*/
    fprintf(f_asm,"\tNOT : \n");
  }
break;
case 52:
#line 565 "y2.y"
	{
      fprintf(f_asm, "\tbeq\tzero, zero, YES\n");
      fprintf(f_asm,"\tNOT : \n");
      if (TRACEON) printf("211 ");
      cur_scope++;
      cur_mode=LOCAL_MODE;
      if (TRACEON) printf("200 ");

  }
break;
case 53:
#line 575 "y2.y"
	{
      if (TRACEON) printf("10.5 ");
  }
break;
case 54:
#line 579 "y2.y"
	{
      if (TRACEON) printf("11 ");
      pop_up_symbol(cur_scope);
      cur_scope--;
      fprintf(f_asm,"\tYES : \n");
  }
break;
case 55:
#line 590 "y2.y"
	{ if (TRACEON) printf("102 ") ; }
break;
case 56:
#line 592 "y2.y"
	{ if (TRACEON) printf("103 ") ; }
break;
case 57:
#line 597 "y2.y"
	{ if (TRACEON) printf("104 ") ;
           }
break;
case 58:
#line 600 "y2.y"
	{ if (TRACEON) printf("106 ") ;
           }
break;
case 59:
#line 605 "y2.y"
	{ if (TRACEON) printf("110 ") ;}
break;
case 60:
#line 607 "y2.y"
	{ char *s;
          		  int index;

          		  if (TRACEON) printf("17.5 ") ;
          		  s= yystack.l_mark[-3].ident;
          		  if (!s) err("improper expression at LHS");
          		  index = look_up_symbol(s);
                /*fprintf(f_asm,"        pop  bx\n");*/
                /*fprintf(f_asm,"        pop  cx\n");*/
          		  switch(table[index].mode) {
                            case ARGUMENT_MODE:
          		    fprintf(f_asm,"        mov  word ptr [bp-%d], bx\n",table[index].offset*2+2);
          		    fprintf(f_asm,"        push bx\n");
                              break;
          		  case LOCAL_MODE:
          		    /*fprintf(f_asm,"        mov  word ptr [bp+%d], bx\n",table[index].offset*2);*/
          		    /*fprintf(f_asm,"        push bx\n");*/
                  printf("indexTrace: %s, %d\n",table[index].name,table[index].offset);
                  fprintf(f_asm, "\tld\tt3, %d(s0)\n",(tableOffset)*-8);
                  --exprStack;
                  --tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, 8\n");
                  ++tableOffset;
                  fprintf(f_asm, "\taddi\tsp, sp, -8\n");
                  fprintf(f_asm, "\tsd\tt3, %d(s0)\n",(table[index].offset+1-funcSymCounter)*-8);
                              break;
          		  default: /* Global Vars */
          		    fprintf(f_asm,"        mov  word ptr DGROUP:_%s,0, bx\n",table[index].name);
          		    fprintf(f_asm,"        push bx\n");
          		  }
                          }
break;
#line 1231 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
