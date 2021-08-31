%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char const *s);
int yylex();
%}

//    %token AND ARRAY ASSIGNMENT CASE CHARACTER_STRING COLON COMMA CONST DIGSEQ
//    %token DIV DO DOT DOTDOT DOWNTO ELSE END EQUAL EXTERNAL FOR FORWARD FUNCTION
//    %token GE GOTO GT IDENTIFIER IF IN LABEL LBRAC LE LPAREN LT MINUS MOD NIL NOT
//    %token NOTEQUAL OF OR OTHERWISE PACKED PBEGIN PFILE PLUS PROCEDURE PROGRAM RBRAC
//    %token REALNUMBER RECORD REPEAT RPAREN SEMICOLON SET SLASH STAR STARSTAR THEN
//    %token TO TYPE UNTIL UPARROW VAR WHILE WITH

%token NUM STRINGCONST COMMENT PROGRAM ID PARLEFT PARRIGHT SEMICOLON PERIOD COMMA
%token VAR COLON ARRAY LSBRACKET RSBRACKET OF INTEGER REAL FUNCTION_TOK PROCEDURE 
%token BEGIN_TOK END ASSIGNOP IF THEN ELSE WHILE DO LESSTHAN GREATERTHAN LESSTHANEQ
%token GREATERTHANEQ EQUALS NEQUALS PLUS MINUS MULT DIV NOT LDOTS IDENTIFIER

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
        | STRINGCONST
        ;

subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
	| /* lambda */
    ;


subprogram_declaration :
	subprogram_head 
	declarations 			
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
	| /* lambda */
    ;


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


variable : IDENTIFIER tail {printf("Found a variable\n");}
         ;

tail     : LSBRACKET expression RSBRACKET tail
	| /* lambda */
    ;


procedure_statement : IDENTIFIER
	| IDENTIFIER PARLEFT expression_list PARRIGHT


expression_list : expression
	| expression_list COMMA expression
    ;


expression : simple_expression
	| simple_expression relop simple_expression
    ;


simple_expression : term
	| simple_expression addop term
    ;


term : factor {printf("Found afactor\n");}
	| term mulop factor
    ;


factor : IDENTIFIER tail
	| IDENTIFIER PARLEFT expression_list PARRIGHT
	| addop NUM
	| NUM
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
int yywrap(){return 1;}
void yyerror (char const *s) {
printf("There was an error");
fprintf (stderr, "%s\n", s);
}
int main (void){
    int parseResult = yyparse();
    fprinft("/---------------------------------/
            Parse Complete
            NO errors detected.
            /---------------------------------/
            ");
    return parseResult;
}
