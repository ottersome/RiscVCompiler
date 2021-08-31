%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugheader.h"
#include "symboltable.h"
#include "semantics.h"

Node* ASTROOT;//Just declaring it atm.

extern const char * yytext;
extern const int line_no;
void yyerror(const char * charo){
    //fprintf(stderr,"There was an error on line : %d\n",line_no);
    fprintf(stderr,"line %d error token: %s\n",line_no,yytext);
    exit(-1);
}
bool isInt(char* s){
    for(int i = 0; i < strlen(s);i++) {
        if(!(s[i] >= '0' && s[i]<='9')) return false;
    }
    return true;
}
%}

%union{
    struct Node* node;
    //int num;//esto puede ser both real o stirng
    /* char * num; */
    char* num;
    /* double real; */
    char character;
    char * string;
}



%token<node> COMMENT PROGRAM ID PARLEFT PARRIGHT SEMICOLON PERIOD COMMA
%token VAR COLON ARRAY LSBRACKET RSBRACKET OF INTEGER REAL FUNCTION_TOK PROCEDURE 
%token BEGIN_TOK END ASSIGNOP IF THEN ELSE WHILE DO 
%token NOT LDOTS 
%token STRING 
%token<string> NUM
%token<string> STRINGCONST IDENTIFIER

%type <node> prog identifier_list declarations type standard_type
%type <node> subprogram_declarations subprogram_declaration subprogram_head
%type <node> arguments parameter_list optional_var compound_statement optional_statements
%type <node> statement_list statement variable tail procedure_statement expression_list
%type <node> expression boolexpression simple_expression term factor  
%type <node> relop 
%type <node> mulop /*addop*/ id num

//These follow c++ Operator Precedence
//%left MULOP (?)
%left OR
%left AND
%left EQUALS
%left LESSTHAN LESSTHANEQ GREATERTHANEQ GREATERTHAN NEQUALS//Are these int the right place?. I think they ahve to go below mult and div
%left PLUS MINUS//In order of increasing precedence. Meaning Plus and MINUS have least precedence
%left MULT DIV 

%%
prog : PROGRAM id PARLEFT identifier_list PARRIGHT SEMICOLON
  	    declarations
	    subprogram_declarations
	    compound_statement
	    PERIOD 
        {
        ASTROOT = makeNode(NODE_ROOT);
        $$ = ASTROOT;
            adoptChild($$,$2);
            adoptChild($$,$4);
            adoptChild($$,$7);
            adoptChild($$,$8);
            adoptChild($$,$9);
        /* Logg("Parse Succesful\n"); */
        }
        ;


identifier_list : id
    {//Create first instance of identifier list
        /* Logg("Initializing Id\n"); */
        $$ = makeNode(NODE_ID_LIST);
        $$->lineInCode = $1->lineInCode;
        /* Logg("Done  Id\n"); */
        adoptChild($$,$1);
        /* Logg("Adopted  Id\n"); */
    }
	| identifier_list COMMA id
    {
        $$ = $1;
        $$->lineInCode = $3->lineInCode;
        //Logg("Adding To IdentifierList %s\n");
        adoptChild($$,$3);
    }
    ;


declarations : declarations VAR identifier_list COLON type SEMICOLON 
    {//DIVE
        //Copy from the previous node
        $$ = $1;
        Node* thisDecl = makeNode(NODE_DECLARATIONS);
        thisDecl->lineInCode = $3->lineInCode;
        adoptChild($$,thisDecl);
        adoptChild(thisDecl, $3);
        adoptChild(thisDecl, $5);
    }
	| /* lambda */
    {//On empty rule create new NODE_ADD
    //IF we do not have this rulle then we are 
    //forcing every  program and eveyr subprogram to have declared at least one variable.
    //THis(having atleast one) of course is not necessary
    //DIVE
        $$ = makeNode(NODE_DECLARATIONS_ROOT);
        //No Children
    }
    ;

type : standard_type
     {
     $$ = $1;
     $$->lineInCode = line_no;
     }
	| ARRAY LSBRACKET num LDOTS num RSBRACKET OF type
    {//DEVI
       $$ = $8;
       $$->lineInCode = line_no;
       Node* arrNode = makeNode(NODE_TYPE_ARR);         
       adoptChild(arrNode,$3);
       adoptChild(arrNode,$5);
       /* arrNode->lowerBound = $3->doubleVal; */
       /* arrNode->upperBound = $5->doubleVal; */
       /* deleteNodeTree($3); */
       /* deleteNodeTree($5); */
       adoptChild($$,arrNode);

       /* adoptChild(arrNode,$3); */
       /* adoptChild(arrNode,$5); */
       /* adoptChild($$,arrNode); */
       /* $$->lowerBound = $3->intVal; */
       /* deleteNodeTree($3); */
       /* $$->upperBound = $5->intVal; */
       /* deleteNodeTree($5); */
       //
       //TODO remove this as a child. We are only doing it here because our 
       //free algorithm causes memory leak otherwise. Make sure if you remove the
       //following line you have handled that.
    }
    ;

standard_type : INTEGER 
        {
        $$ = makeNode(NODE_TYPE_INT);
        $$->typeRef = $$;//Reference  to itself so we know its a primitive type.
        } 
	    | REAL {
        $$ = makeNode(NODE_TYPE_REAL);
        $$->typeRef = $$;
        }
        | STRING{
        $$ = makeNode(NODE_TYPE_STRINGCONST);
        $$->typeRef = $$;
        }
        ;

subprogram_declarations :
	subprogram_declarations subprogram_declaration SEMICOLON
    {
        $$ = $1;//Keep Sending the root to the next subpdeclaration
        adoptChild($$,$2);
    }
	| /* lambda */
    {
    //DIVE
        $$ = makeNode(NODE_SUBPDECLARATIONS);
    }
    ;


subprogram_declaration :
	subprogram_head 
	declarations 			
    subprogram_declarations
    compound_statement
    {
       //$$ = makeNode(subprogram_declaration);  NVM we only need can create the node from suprogram
       //even better since they have the information there
       /* $$ = makeNode(NODE_SUBPDECLARATION); */
       /* adoptChild($$,$1); */
       $$ = $1;//Changed so we can treat all SUBP (proc and func) as one later on
       adoptChild($$,$2);
       adoptChild($$,$3);
       adoptChild($$,$4);
    }
    ;

subprogram_head : FUNCTION_TOK id arguments COLON standard_type SEMICOLON
    {
        $$ = makeNode(NODE_FUNCTION); 
        //We could actually copy the id to the node str 
        //value itself but for sake of just makign it work ill leave it like that for now
        $$->lineInCode = $2->lineInCode;
        adoptChild($$,$2);//1
        adoptChild($$,$3);//2
        adoptChild($$,$5);//3
    }
	| PROCEDURE id arguments SEMICOLON
    {
        $$ = makeNode(NODE_PROCEDURE);
        $$->lineInCode = $2->lineInCode;
        adoptChild($$,$2);//1
        adoptChild($$,$3);//2
    }
    ;


arguments : PARLEFT parameter_list PARRIGHT
    {
        $$ = $2;//Just pass it along
        $$->lineInCode = $2->lineInCode;
    }
	| /* lambda */
        {$$ = makeNode(NODE_ARGUMENTS);}
    ;


parameter_list : optional_var identifier_list COLON type
    {
        $$ = makeNode(NODE_ARGUMENTS);
        Node* argument = makeNode(NODE_ARGUMENT);
        argument->lineInCode = $2->lineInCode;
        $$->lineInCode = $2->lineInCode;

        adoptChild(argument,$2);
        adoptChild(argument,$4);//Remove only when your freeing algorithm can handle it
        argument->typeRef = $4;
    

        adoptChild($$,argument);
    }
	| optional_var identifier_list COLON type SEMICOLON parameter_list 
    {
        $$ = $6;
        Node* argument = makeNode(NODE_ARGUMENT);
        argument->lineInCode = $2->lineInCode;
        $$->lineInCode = $2->lineInCode;

        adoptChild(argument,$2);
        adoptChild(argument,$4);//Remove only when your freeing algorithm can handle it
        argument->typeRef = $4;

        adoptChild($$,argument);
    }
    ;


optional_var   : VAR
        | /* lambda */
        ;//TODO This is only syntax I dont think it is necessary information for the tree


compound_statement : BEGIN_TOK
		       optional_statements
		       END
               {
               $$ = $2;//TODO how should we use this for opening scopes
               }
               ;


optional_statements : statement_list
    {
    $$ = $1;
    }
    ;/* There was a lambda as an option here before. Removed due to conflict*/


statement_list : statement
    {//THere should be at least one statement
        $$ = makeNode(NODE_STATEMENT_LIST);
        adoptChild($$,$1);
    }
	| statement_list SEMICOLON statement
        {
            $$ = $1;
            adoptChild($$,$3);
        }
    ;


statement : variable ASSIGNOP expression
    {
        $$ = makeNode(NODE_ASSIGN_OP); 
        $1->assignPos = POS_LHS;
        $$->lineInCode = line_no;
        adoptChild($$,$1);
        adoptChild($$,$3);//TODO DEVI Might want to denote that this expression belongs to the variable somehow
    }
	| procedure_statement
        {
        $$ = $1;
        $$->lineInCode=line_no;
        }
	| compound_statement
        {$$ = $1;}
	| IF expression THEN statement ELSE statement
        {
        $$ = makeNode(NODE_IF_ELSE);
        adoptChild($$,$2);
        adoptChild($$,$4);
        adoptChild($$,$6);
        }
	| WHILE expression DO statement
    {
       $$ = makeNode(NODE_WHILE); 
       adoptChild($$,$2);
       adoptChild($$,$4);
    }
    | /* lambda */
    {
        $$ = makeNode(NODE_STMNT);
    }
    ;


variable : id tail //Take in mind that tail may be empty 
         {
            $$ = makeNode(NODE_VARREF);
            $$->lineInCode = $1->lineInCode;
            adoptChild($$,$1);
            adoptChild($$,$2);//This could be INVALID_VALUE which means it doesnt specify a subscript(because it doesnt have to).
         }
         ;

tail  : LSBRACKET expression RSBRACKET tail//Well use a single node of tail as parent of all expresions
    {//Making sure recursivity is taken care of
        //Just do it always
        $4->valValidity = VALID_VALUE;//Means we have found atleast a single expression thus we can have a vlid array
        $$ = $4;
        adoptChild($$,$2);
    }
	| /* lambda */
       {
        $$ = makeNode(NODE_ARR_SUFFIXES);
        $$->valValidity=INVALID_VALUE;
       } 
    ;


procedure_statement : id
    {//TODO DEVI
        $$ = makeNode(NODE_IN_STATEMENT_CALL);
        $$->lineInCode = $1->lineInCode;
        adoptChild($$,$1);
    }
	| id PARLEFT expression_list PARRIGHT
    {
       $$ = makeNode(NODE_IN_STATEMENT_CALL);
       adoptChild($$,$1);
       adoptChild($$,$3);
    }
    ;


expression_list : expression
    {
        $$  = makeNode(NODE_EXPR_LIST);
        adoptChild($$,$1);
    }
	| expression_list COMMA expression
    {
        $$ = $1;
        adoptChild($$,$3); 
    }
    ;

//SUPER TODO : FINISH THE 4 Nodes below
expression : boolexpression 
        {
         /* $$ = makeNode(NODE_EXPR);  */
        $$ =$1;
            /* adoptChild($$,$1); */
        }
        | boolexpression AND boolexpression
        {
        $$ =  makeNode(NODE_BINARY_EXPR);
        $$->operation=NODE_OP_AND;
        $$->lineInCode=line_no;
            adoptChild($$,$1);
            adoptChild($$,$3);
        }
        | boolexpression OR  boolexpression
        {
        $$ = makeNode(NODE_BINARY_EXPR);
        $$->lineInCode=line_no;
        $$->operation = NODE_OP_OR;
            adoptChild($$,$1);
            adoptChild($$,$3);
        }
        ;

boolexpression : simple_expression 
        {$$ = $1;}
    | simple_expression relop simple_expression
    {
        $$ = $2;
        adoptChild($$,$1);
        adoptChild($$,$3);
    }
    ;

//For these recursions of additions and multiplications we have already created mul and add nods
simple_expression : term 
        {$$ = $1;}
	/*| simple_expression addop term*/
    | simple_expression PLUS term
    {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_ADD;
      adoptChild($$,$1);
      adoptChild($$,$3);
      }
    | simple_expression MINUS term
    {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_SUBTRACT;
      adoptChild($$,$1);
      adoptChild($$,$3);
       /*$$ = $2; */
       /*adoptChild($$,$1);*/
       /*adoptChild($$,$3);*/
    }
    ;

term : factor 
     {
     $$ = $1;
     }
	| term mulop factor
    {
        $$ = $2;
        adoptChild($$, $1);
        adoptChild($$, $3);
    }
    ;

factor : id tail //Should we be able to replace these two non-terminals with a simple var
    {
       //Same as the one we did vefore 
        $$ = makeNode(NODE_VARREF);
        $$->lineInCode = $1->lineInCode;
        //Since factor is part of an expression this means that this var ref is RHS
        $$->assignPos = POS_RHS;
        adoptChild($$,$1);
        adoptChild($$,$2);//This could be INVALID_VALUE which means it doesnt specify a subscript(because it doesnt have to).
    }
	| id PARLEFT expression_list PARRIGHT 
    {
        $$ = makeNode(NODE_FUNC_CALL);
        $$->assignPos = POS_RHS;
        $$->lineInCode = line_no;
        adoptChild($$,$1);
        adoptChild($$,$3);
    }
	| num 
    {
        $$ = $1;//Just pass it along
    }
    | STRINGCONST
    {
        $$ = makeNode(NODE_TYPE_STRINGCONST); 
        copyStr($$,$1);
    }
	| PARLEFT expression PARRIGHT
        {$$ = $2;}
	| NOT factor
        {
        $$ = makeNode(NODE_UNARY_EXPR);
        $$->lineInCode = line_no;
        $$->uoperation = NODE_OP_NOT;
        adoptChild($$,$2);
        }
    ;
mulop : MULT 
      {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_MULT;
      }
      | DIV
      {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_DIV;
      }
      ; 
relop : LESSTHAN
      {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_LESSTHAN;
      }
	| GREATERTHAN
      {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_GREATERTHAN;
      }
	| EQUALS
      {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_EQUALS;
      }
	| LESSTHANEQ
      {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_LESSTHANEQ;
      }
	| GREATERTHANEQ
      {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_GREATERTHANEQ;
      }
	| NEQUALS
      {
      $$ = makeNode(NODE_BINARY_EXPR);
      $$->lineInCode=line_no;
      $$->operation = NODE_OP_NEQUALS;
      }
    ;
id : IDENTIFIER
    {
    $$ = makeNode(NODE_ID);
    $$->lineInCode = line_no;
    copyStr($$,$1);
}
;
num : 
    NUM//THis should hacve both reall numbers and digit sequence
    {
        //We have received a string. Nowe we have to convert this 
        //string into a double while detecting if its an int or oreal
        $$ = makeNode(NODE_NUM);
        $$->doubleVal = atof($1);
        $$->nodeStdType = (isInt($1))?TYPE_INT:TYPE_REAL;
        $$->hasConcreteValue = true;
        //Nah nah we are sending num as adouble and we are gonig to sort it out here
        /* copyStr($$,$1); */
        /* $$->intVal =  $1;//SUPER TODO deal with this */
    }
    | PLUS num
    {
      $$ = makeNode(NODE_UNARY_EXPR);
      $$->lineInCode=line_no;
      $$->uoperation = NODE_OP_POSSIGN;
     /* $$->hasConcreteValue= true; */
      /* $$->doubleVal = $2->doubleVal; */
      adoptChild($$,$2);
    }
    | MINUS num
    {
      $$ = makeNode(NODE_UNARY_EXPR);
      $$->lineInCode=line_no;
      $$->uoperation = NODE_OP_NEGSIGN;
      /* $$->doubleVal = -1*$2->doubleVal; */
      /* $$->hasConcreteValue= true; */
      adoptChild($$,$2);
    }
;
%%
//d
//int yywrap(){return 1;}
int main (int argc, char **argv){
    if(argc!= 2){
        fprintf(stderr,"Please Use File dir as argument\n");
        return -1;
    }
    FILE *fp = freopen(argv[1],"r",stdin);

    int parseResult = yyparse();
    if(parseResult==0)
        printf("********************************\n"
         "*       No syntax error!       *\n"
         "********************************\n");

    traverseTree(ASTROOT,false,true,0);

    SymbolTable symTable;
    initializeSymbolTable(&symTable);
    buildTable(&symTable,ASTROOT);
    terminateSymbolTable(&symTable);
        printf("********************************\n"
               "*    Semantic Check Done!      *\n"
               "********************************\n");

    traverseTree(ASTROOT,true,false,0);
    //We should have our tree by this point
    return parseResult;
}
