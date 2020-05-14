%{
	#define YYDEBUG 1
	#include <stdio.h>
	#include <string.h>
    int yylex();
    int yyerror();
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
%}

%union {
int       token ;
char      charv ;
char      *ident;
}

%token <stringval> IDENTIFIER CONSTANT STRING_LITERAL
%token <stringval> INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token <stringval> AND_OP OR_OP

%token <stringval> CHAR INT FLOAT DOUBLE CONST VOID

%token <stringval> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR CONTINUE BREAK RETURN

%type <stringval> func_def
%type <stringval> jump_stmt
%type <stringval> iter_stmt
%type <stringval> for_stmt
%type <stringval> expr_stmt
%type <stringval> stmt_list
%type <stringval> decl_list
%type <stringval> compound_stmt
%type <stringval> labeled_stmt
%type <stringval> stmt
%type <stringval> case_list
%type <stringval> ident_list
%type <stringval> para_decl
%type <stringval> para_list
%type <stringval> constant_expr
%type <stringval> expr
%type <stringval> argument_expr_list
%type <stringval> postfix_expr
%type <stringval> primary_expr
%type <stringval> selection_stmt

%type <stringval> and_expr
%type <stringval> equality_expr
%type <stringval> relational_expr
%type <stringval> shift_expr
%type <stringval> additive_expr
%type <stringval> multiplicative_expr
%type <stringval> unary_expr
%type <stringval> logical_and_expr
%type <stringval> inclusive_or_expr
%type <stringval> exclusive_or_expr
%type <stringval> logical_or_expr
%type <stringval> conditional_expr
%type <stringval> assignment_expr
%type <stringval> init
%type <stringval> direct_decl
%type <stringval> init_decl
%type <stringval> init_decl_list
%type <stringval> type_spec
%type <stringval> decl_spec
%type <stringval> decl
%type <stringval> extern_decl
%type <stringval> trans_unit
%type <stringval> program

%nonassoc UMINUS




%start program

%%

primary_expr
	: IDENTIFIER {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| CONSTANT {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| IDENTIFIER ident_list {
		sprintf(tmp, "( %s %s )", $1,$2);
		strcpy($$, tmp);
	}
	;
ident_list
	: ident_list '[' expr ']'{
		sprintf(tmp, "%s [ %s ]", $1,$3);
		strcpy($$, tmp);
	}
	| '[' expr ']'{
		sprintf(tmp, "[ %s ]", $2);
		strcpy($$, tmp);
	}
	| '[' ']'{
		sprintf(tmp, "[ ]");
		strcpy($$, tmp);
	}
	;
postfix_expr
	: primary_expr{
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| primary_expr INC_OP{
		sprintf(tmp, "( %s %s )", $1,$2);
		strcpy($$, tmp);
	}
	| primary_expr DEC_OP{
		sprintf(tmp, "( %s %s )", $1,$2);
		strcpy($$, tmp);
	}
	| INC_OP primary_expr{
		sprintf(tmp, "( %s %s )", $1,$2);
		strcpy($$, tmp);
	}
	| DEC_OP primary_expr{
		sprintf(tmp, "( %s %s )", $1,$2);
		strcpy($$, tmp);
	}
	;

argument_expr_list
	: expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| argument_expr_list ',' expr{
		sprintf(tmp, "%s , %s", $1,$3);
		strcpy($$, tmp);
	}
	;

unary_expr
	: postfix_expr {
			sprintf(tmp, "%s", $1);
			strcpy($$, tmp);
	}
	| '!' postfix_expr {
		sprintf(tmp, "( !%s )", $2);
		strcpy($$, tmp);
	}
	| '+' postfix_expr %prec UMINUS{
		sprintf(tmp, "( +%s )", $2);
		strcpy($$, tmp);
	}
	| '-' postfix_expr %prec UMINUS{
		sprintf(tmp, "( -%s )", $2);
		strcpy($$, tmp);
	}
	;

multiplicative_expr
	: unary_expr {
			sprintf(tmp, "%s", $1);
			strcpy($$, tmp);
		}
	|	multiplicative_expr '*' unary_expr {
		sprintf(tmp, "( %s * %s )", $1,$3);
		strcpy($$, tmp);
	}
	| multiplicative_expr '/' unary_expr {
		sprintf(tmp, "( %s / %s )", $1,$3);
		strcpy($$, tmp);
	}
	| multiplicative_expr '%' unary_expr {
		sprintf(tmp, "( %s %% %s )", $1,$3);
		strcpy($$, tmp);
	}
	;

additive_expr
	: multiplicative_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| additive_expr '+' multiplicative_expr {
		sprintf(tmp, "( %s + %s )", $1, $3);
		strcpy($$, tmp);
	}
	| additive_expr '-' multiplicative_expr {
		sprintf(tmp, "( %s - %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

shift_expr
	: additive_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| shift_expr RIGHT_OP additive_expr {
		sprintf(tmp, "( %s >> %s )", $1, $3);
		strcpy($$, tmp);
	}
	| shift_expr LEFT_OP additive_expr {
		sprintf(tmp, "( %s << %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

relational_expr
	: shift_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| relational_expr LE_OP shift_expr {
		sprintf(tmp, "( %s <= %s )", $1, $3);
		strcpy($$, tmp);
	}
	| relational_expr GE_OP shift_expr {
		sprintf(tmp, "( %s >= %s )", $1, $3);
		strcpy($$, tmp);
	}
	| relational_expr '<' shift_expr {
		sprintf(tmp, "( %s < %s )", $1, $3);
		strcpy($$, tmp);
	}
	| relational_expr '>' shift_expr {
		sprintf(tmp, "( %s > %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

equality_expr
	: relational_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| equality_expr NE_OP relational_expr {
		sprintf(tmp, "( %s != %s )", $1, $3);
		strcpy($$, tmp);
	}
	| equality_expr EQ_OP relational_expr {
		sprintf(tmp, "( %s == %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

and_expr
	: equality_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| and_expr '&' equality_expr {
		sprintf(tmp, "( %s & %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

exclusive_or_expr
	: and_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| exclusive_or_expr '^' and_expr {
		sprintf(tmp, "( %s ^ %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

inclusive_or_expr
	: exclusive_or_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| inclusive_or_expr '|' exclusive_or_expr {
		sprintf(tmp, "( %s | %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

logical_and_expr
	: inclusive_or_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| logical_and_expr AND_OP inclusive_or_expr {
		sprintf(tmp, "( %s && %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

logical_or_expr
	: logical_and_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| logical_or_expr OR_OP logical_and_expr {
		sprintf(tmp, "( %s || %s )", $1, $3);
		strcpy($$, tmp);
	}
	;

conditional_expr
	: logical_or_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	;

assignment_expr
	: conditional_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| unary_expr '=' assignment_expr {
		sprintf(tmp, "%s = %s", $1, $3);
		strcpy($$, tmp);
	}
	;

decl
	: decl_spec ';' {
		sprintf(tmp, "( %s ; )", $1);
		strcpy($$, tmp);
	}
	| decl_spec init_decl_list ';' {
		sprintf(tmp, "( %s %s ; )", $1, $2);
		strcpy($$, tmp);
	}
	;

decl_spec
	: type_spec decl_spec {
	 sprintf(tmp, "%s %s", $1, $2);
	 strcpy($$, tmp);
 	}
 	| type_spec {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	;

init_decl_list
	: init_decl {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| init_decl_list ',' init_decl {
		sprintf(tmp, "%s , %s", $1, $3);
		strcpy($$, tmp);
	}
	;

init_decl
	: direct_decl {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| direct_decl '=' init {
		sprintf(tmp, "%s = %s", $1, $3);
		strcpy($$, tmp);
	}
	;

type_spec
	: INT {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| DOUBLE {
	 sprintf(tmp, "%s", $1);
	 strcpy($$, tmp);
 	}
	| VOID {
	 sprintf(tmp, "%s", $1);
	 strcpy($$, tmp);
	}
	| CHAR {
	 sprintf(tmp, "%s", $1);
	 strcpy($$, tmp);
	}
	| CONST {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	;
constant_expr
	: CONSTANT{
	  sprintf(tmp, "%s", $1);
	  strcpy($$, tmp);
	}
	| constant_expr ',' CONSTANT{
	  sprintf(tmp, "%s , %s", $1,$3);
	  strcpy($$, tmp);
	}
	;
direct_decl
	: IDENTIFIER {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| IDENTIFIER ident_list {
		sprintf(tmp, "%s %s", $1,$2);
		strcpy($$, tmp);
	}
	;

init
	: expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| '{' constant_expr '}'{
		sprintf(tmp, "{ %s }", $2);
		strcpy($$, tmp);
	}
	;

program
	: trans_unit {
		sprintf(tmp, "( %s )", $1);
		strcpy($$, tmp);
		printf("%s\n", $$);
	}
	;

trans_unit
	: extern_decl {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| extern_decl stmt_list {
		sprintf(tmp, "%s %s", $1, $2);
		strcpy($$, tmp);
	}
	;
stmt_list
	: stmt_list jump_stmt {
		sprintf(tmp, "%s %s", $1, $2);
		strcpy($$, tmp);
	}
	| stmt_list stmt {
		sprintf(tmp, "%s %s", $1, $2);
		strcpy($$, tmp);
	}
	| stmt_list selection_stmt{
		sprintf(tmp, "%s %s", $1, $2);
		strcpy($$, tmp);
	}
	| stmt_list for_stmt{
		sprintf(tmp, "%s %s", $1, $2);
		strcpy($$, tmp);
	}
	| stmt_list iter_stmt{
		sprintf(tmp, "%s %s", $1, $2);
		strcpy($$, tmp);
	}
	| stmt_list expr_stmt{
		sprintf(tmp, "%s ( %s )", $1, $2);
		strcpy($$, tmp);
	}
	| stmt_list BREAK{
		sprintf(tmp, "%s ( %s )", $1, $2);
		strcpy($$, tmp);
	}
	| stmt_list CONTINUE{
		sprintf(tmp, "%s ( %s )", $1, $2);
		strcpy($$, tmp);
	}
	| stmt_list labeled_stmt{
		sprintf(tmp, "%s ( %s )", $1, $2);
		strcpy($$, tmp);
	}
	| stmt {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| jump_stmt {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| selection_stmt{
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| for_stmt{
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| iter_stmt{
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| expr_stmt{
		sprintf(tmp, "( %s )", $1);
		strcpy($$, tmp);
	}
	| BREAK{
		sprintf(tmp, "( %s )", $1);
		strcpy($$, tmp);
	}
	| CONTINUE{
		sprintf(tmp, "( %s )", $1);
		strcpy($$, tmp);
	}
	| labeled_stmt{
		sprintf(tmp, "( %s )", $1);
		strcpy($$, tmp);
	}
	;
jump_stmt
	: RETURN expr ';' {
		sprintf(tmp, "( return %s ; )", $2);
		strcpy($$, tmp);
	}
	;
stmt
  : IDENTIFIER ident_list '=' assignment_expr ';' {
 		sprintf(tmp, "( ( %s %s ) = %s ; )", $1,$2,$4);
 		strcpy($$, tmp);
  }
	| IDENTIFIER '=' assignment_expr ';' {
 		sprintf(tmp, "( %s = %s ; )", $1,$3);
 		strcpy($$, tmp);
  }
  ;
extern_decl
	: decl {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| extern_decl decl {
		sprintf(tmp, "%s %s", $1,$2);
		strcpy($$, tmp);
	}
	| extern_decl func_def {
			sprintf(tmp, "%s %s", $1,$2);
			strcpy($$, tmp);
	}
	| func_def {
			sprintf(tmp, "%s", $1);
			strcpy($$, tmp);
	}
	;
func_def
	: decl_spec IDENTIFIER '(' para_list ')' '{' compound_stmt '}' {
		sprintf(tmp,"( %s %s ( %s ) { %s } )",$1,$2,$4,$7);
		strcpy($$, tmp);
	}
	| decl_spec IDENTIFIER '(' ')' '{' compound_stmt '}' {
		sprintf(tmp,"( %s %s ( ) { %s } )",$1,$2,$6);
		strcpy($$, tmp);
	}
	;
para_list
	: para_list ',' para_decl {
		sprintf(tmp, "%s , %s", $1,$3);
		strcpy($$, tmp);
	}
	| para_decl {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	;
para_decl
	: type_spec direct_decl {
		sprintf(tmp, "%s %s", $1,$2);
		strcpy($$, tmp);
	}
compound_stmt
	: %empty {}
	| decl_list {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| stmt_list {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| decl_list stmt_list {
		sprintf(tmp, "%s %s", $1, $2);
		strcpy($$, tmp);
	}
	;
decl_list
	: decl_list decl {
		sprintf(tmp, "%s %s", $1 ,$2);
		strcpy($$, tmp);
	}
	| decl {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	;
expr
	: assignment_expr {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	| IDENTIFIER '(' argument_expr_list ')' {
		sprintf(tmp, "( %s ( %s ) )", $1,$3);
		strcpy($$, tmp);
	}
	| STRING_LITERAL {
		sprintf(tmp, "%s", $1);
		strcpy($$, tmp);
	}
	;
selection_stmt
	: IF '(' expr ')' '{' compound_stmt '}' ELSE '{' compound_stmt '}'{
		sprintf(tmp, "( if ( %s ) { %s } else { %s } )", $3,$6,$10);
		strcpy($$, tmp);
	}
	| IF '(' expr ')' '{' compound_stmt '}' {
		sprintf(tmp, "( if ( %s ) { %s } )", $3,$6);
		strcpy($$, tmp);
	}
	;
for_stmt
	: FOR '(' expr ';' expr ';' expr ')' '{' compound_stmt '}' {
		sprintf(tmp, "( for ( %s ; %s ; %s ) ( { %s } ) )", $3,$5,$7,$10);
		strcpy($$, tmp);
	}
	| FOR '(' expr ';' expr ';' ')' '{' compound_stmt '}' {
		sprintf(tmp, "( for ( %s ; %s  ; ) ( { %s } ) )", $3,$5,$9);
		strcpy($$, tmp);
	}
	| FOR '(' expr ';' ';' expr ')' '{' compound_stmt '}' {
		sprintf(tmp, "( for ( %s ; ; %s ) ( { %s } ) )", $3,$6,$9);
		strcpy($$, tmp);
	}
	| FOR '(' ';' expr ';' expr ')' '{' compound_stmt '}' {
		sprintf(tmp, "( for ( ; %s ; %s ) ( { %s } ) )", $4,$6,$9);
		strcpy($$, tmp);
	}
	| FOR '(' expr ';'  ';'  ')' '{' compound_stmt '}' {
		sprintf(tmp, "( for ( %s ; ; ) ( { %s } ) )", $3,$8);
		strcpy($$, tmp);
	}
	| FOR '(' ';' expr ';' ')' '{' compound_stmt '}' {
		sprintf(tmp, "( for ( ; %s ; ) ( { %s } ) )", $4,$8);
		strcpy($$, tmp);
	}
	| FOR '(' ';' ';' expr ')' '{' compound_stmt '}' {
		sprintf(tmp, "( for ( ; ; %s ) ( { %s } ) )", $5,$8);
		strcpy($$, tmp);
	}
	| FOR '(' ';' ';' ')' '{' compound_stmt '}' {
		sprintf(tmp, "( for ( ; ; ) ( { %s } ) )",$7);
		strcpy($$, tmp);
	}
	;
iter_stmt
	: WHILE '(' expr ')' '{' compound_stmt '}' {
		sprintf(tmp, "( while ( %s ) ( { %s } ) )", $3,$6);
		strcpy($$, tmp);
	}
	| DO '{' compound_stmt '}' WHILE '(' expr ')' ';' {
		sprintf(tmp, "( do ( { %s } ) while ( %s ) ; )", $3,$7);
		strcpy($$, tmp);
	}
	;
expr_stmt
	: primary_expr INC_OP ';' {
		sprintf(tmp, "( %s %s ) ;", $1,$2);
		strcpy($$, tmp);
	}
	| primary_expr DEC_OP ';' {
		sprintf(tmp, "( %s %s ) ;", $1,$2);
		strcpy($$, tmp);
	}
	| INC_OP primary_expr ';' {
		sprintf(tmp, "( %s %s ) ;", $1,$2);
		strcpy($$, tmp);
	}
	| DEC_OP primary_expr ';' {
		sprintf(tmp, "( %s %s ) ;", $1,$2);
		strcpy($$, tmp);
	}
case_list
	: CASE CONSTANT ':' {
		sprintf(tmp, "%s :", $1);
		strcpy($$, tmp);
	}
	| CASE CONSTANT ':' stmt_list {
		sprintf(tmp, "%s : %s", $1,$2);
		strcpy($$, tmp);
	}
labeled_stmt
	: SWITCH '(' IDENTIFIER ')' '{' case_list  DEFAULT ':' stmt_list '}' {
		sprintf(tmp, "%s ( %s ) { %s %s : %s }", $1,$3,$6,$7,$9);
		strcpy($$, tmp);
	}
	| SWITCH '(' IDENTIFIER ')' '{' case_list  DEFAULT ':' '}' {
		sprintf(tmp, "%s ( %s ) { %s %s : }", $1,$3,$6,$7);
		strcpy($$, tmp);
	}
%%
