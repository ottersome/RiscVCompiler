%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>
#define     EXPLICIT_HANDLING -1
#define     NUM             1
#define     STRING          2
#define     COMMENT         3

#define     PROGRAM         4
#define     ID              5        
#define     PARLEFT         6         
#define     PARRIGHT        7         
#define     SEMICOLON       8         
#define     PERIOD          9         
#define     COMMA           10         
#define     VAR             11           
#define     COLON           12
#define     ARRAY           13
#define     LSBRACKET       14         
#define     RSBRACKET       15         
#define     OF              16
#define     INTEGER         17
#define     REAL            18
#define     FUNCTION_TOK         19
#define     PROCEDURE       20
#define     BEGIN_TOK           21
#define     END             22
#define     ASSIGNOP             40
#define     IF              23
#define     THEN            24
#define     ELSE            25
#define     WHILE           26
#define     DO              27
#define     LESSTHAN        28
#define     GREATERTHAN     29   
#define     LESSTHANEQ      30  
#define     GREATERTHANEQ   31     
#define     EQUALS          32 
#define     NEQUALS         33 
#define     PLUS            34 
#define     MINUS           35 
#define     MULT            36
#define     DIV             37
#define     NOT             38
#define     LDOTS           39
#define     NUMI            41
#define     STRINGI         42


int line_no = 1;
int tokenCounter = 0;
int commentNestingCounter = 0;

/* Start Conditions */

%}

%x SC_COMMENT

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']
%%

    /* NUM Needs some good ol fixing*/
[-+]?[0-9]+"."?[0-9]?+(E[-+]?[0-9]+)?               return(NUM);
    /* Strings */
\"[^"]*\"                                           return(STRING);

    /* We could probably use `yycoment` for this instead */
    /* Comments */
"/*"    {
        printf("Beggining heavy pero \n");
        tokenCounter--;
        yymore();
        BEGIN(SC_COMMENT);
        commentNestingCounter = 0;
        return(EXPLICIT_HANDLING);
        }
<SC_COMMENT>[.]*  { printf("Found Random Stuff\n");tokenCounter--; yymore();return(EXPLICIT_HANDLING);}
<SC_COMMENT>"/*" {tokenCounter--; yymore(); commentNestingCounter++; return(EXPLICIT_HANDLING);}
<SC_COMMENT>"*/" {
            if(commentNestingCounter == 0){
                printf("Finish the comment");
                BEGIN(0);
                return(COMMENT);
            }
            else{
                commentNestingCounter--;
                tokenCounter--;
                yymore();
                return(EXPLICIT_HANDLING);
            }
        }
"//".*/\n                                                   return(COMMENT);

    /* List of tokens */
{P}{R}{O}{G}{R}{A}{M}        return(PROGRAM);
{I}{D} return(ID);
"(" return(PARLEFT);
")" return(PARRIGHT);
";" return(SEMICOLON);
"." return(PERIOD);
"," return(COMMA);
{V}{A}{R}                    return(VAR);
":" return(COLON);
{A}{R}{R}{A}{Y}              return(ARRAY);
"[" return(LSBRACKET);
"]" return(RSBRACKET);
    /* num return(NUMI); */
    /* stringconst return(stringconst); */
{O}{F}                       return(OF); 
{I}{N}{T}{E}{G}{E}{R}        return(INTEGER);
{R}{E}{A}{L}                 return(REAL);
{F}{U}{N}{C}{T}{I}{O}{N}     return(FUNCTION_TOK);
{P}{R}{O}{C}{E}{D}{U}{R}{E}  return(PROCEDURE);
{B}{E}{G}{I}{N}              return(BEGIN_TOK);
{E}{N}{D}                    return(END);
":=" return(ASSIGNOP);
{I}{F}                       return(IF);
{T}{H}{E}{N}                 return(THEN);
{E}{L}{S}{E}                 return(ELSE);
{W}{H}{I}{L}{E}              return(WHILE);
{D}{O}                       return(DO);
"<" return(LESSTHAN);
">" return(GREATERTHAN);
"<=" return(LESSTHANEQ);
">=" return(GREATERTHANEQ);
"=" return(EQUALS);
"!=" return(NEQUALS);
"+" return(PLUS);
"-" return(MINUS);
"*" return(MULT);
"/" return(DIV);
{N}{O}{T}                    return(NOT);
".." return(LDOTS);



[ \t\n]                                                              ;
    /*The following is a DEBUG line please delete it*/
^"~".*$  ;
%%

char * tokenNames[] = {"NULL","NUM","STRING","COMMENT",""};

int main(int argc, char** argv) {
  int i, tok;
  yyin = fopen("test.txt", "r");
  for (tokenCounter = 0; 1==1; tokenCounter ++) {
    tok = yylex();
    if(tok != EXPLICIT_HANDLING)
        fprintf(stderr, "\n%3d-th token(type:%d) on line %d :\n%s\n", tokenCounter+1,tok,line_no, yytext);
  }
  return(0);
} /* end of main */

yywrap() {
  fclose(yyin);
  exit(1);
}


