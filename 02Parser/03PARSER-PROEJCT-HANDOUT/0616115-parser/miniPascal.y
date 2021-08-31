%{
#include <stdio.h>
#include <stdlib.h>

extern const char * yytext;
extern const int line_no;
void yyerror(const char * charo){
    //fprintf(stderr,"There was an error on line : %d\n",line_no);
    fprintf(stderr,"line %d error token: %s\n",line_no,yytext);
    exit(-1);
}
%}

%token NUM STRINGCONST COMMENT PROGRAM ID PARLEFT PARRIGHT SEMICOLON PERIOD COMMA
%token VAR COLON ARRAY LSBRACKET RSBRACKET OF INTEGER REAL FUNCTION_TOK PROCEDURE 
%token BEGIN_TOK END ASSIGNOP IF THEN ELSE WHILE DO 
%token NOT LDOTS IDENTIFIER
%token STRING 

%left PLUS MINUS
%left OR
%left AND
%left LESSTHAN LESSTHANEQ EQUALS GREATERTHANEQ GREATERTHAN NEQUALS
%left MULT DIV 

%%
prog : PROGRAM IDENTIFIER PARLEFT identifier_list PARRIGHT SEMICOLON
  	    declarations
	    subprogram_declarations
	    compound_statement
	    PERIOD 
        ;


identifier_list : IDENTIFIER
	| identifier_list COMMA IDENTIFIER
    ;


declarations : declarations VAR identifier_list COLON type SEMICOLON 
	| /* lambda */
    ;

type : standard_type
	| ARRAY LSBRACKET NUM LDOTS NUM RSBRACKET OF type
    ;

standard_type : INTEGER
	    | REAL
        | STRING
        ;

subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
	| /* lambda */
    ;


subprogram_declaration :
	subprogram_head 
	declarations 			
    subprogram_declarations
    compound_statement
        ;

subprogram_head : FUNCTION_TOK IDENTIFIER arguments COLON standard_type SEMICOLON
	| PROCEDURE IDENTIFIER arguments SEMICOLON
    ;


arguments : PARLEFT parameter_list PARRIGHT
	| /* lambda */
    ;


parameter_list : optional_var identifier_list COLON type
	| optional_var identifier_list COLON type SEMICOLON parameter_list 
    ;


optional_var   : VAR
        | /* lambda */
        ;


compound_statement : BEGIN_TOK
		       optional_statements
		       END
               ;


optional_statements : statement_list
    ;/* There was a lambda as an option here before. Removed due to conflict*/


statement_list : statement
	| statement_list SEMICOLON statement
    ;


statement : variable ASSIGNOP expression
	| procedure_statement
	| compound_statement
	| IF expression THEN statement ELSE statement
	| WHILE expression DO statement
    | /* lambda */
    ;


variable : IDENTIFIER tail 
         ;

tail     : LSBRACKET expression RSBRACKET tail
	| /* lambda */
    ;


procedure_statement : IDENTIFIER
	| IDENTIFIER PARLEFT expression_list PARRIGHT


expression_list : expression
	| expression_list COMMA expression
    ;

expression : boolexpression 
        | boolexpression AND boolexpression
        | boolexpression OR  boolexpression
        ;

boolexpression : simple_expression 
    | simple_expression relop simple_expression
    ;

simple_expression : term 
	| simple_expression addop term
    ;

term : factor 
	| term mulop factor
    ;


factor : IDENTIFIER tail 
	| IDENTIFIER PARLEFT expression_list PARRIGHT 
	| NUM 
    | addop NUM
    | STRINGCONST
	| PARLEFT expression PARRIGHT
	| NOT factor
    ;

addop : PLUS 
      | MINUS
      ;

mulop : MULT 
      | DIV
      ; 

relop : LESSTHAN
	| GREATERTHAN
	| EQUALS
	| LESSTHANEQ
	| GREATERTHANEQ
	| NEQUALS
    ;
%%
//int yywrap(){return 1;}
int main (void){
    int parseResult = yyparse();
    if(parseResult==0)
        fprintf(stdout,"OK");
    return parseResult;
}
