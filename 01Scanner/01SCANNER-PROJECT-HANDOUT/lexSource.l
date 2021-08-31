%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>
 #include "defFile.h"


int line_no = 1;
int line_no_buffer = 0;
int tokenCounter = 0;
int commentNestingCounter = 0;


char buffForStrings[1000];
char * buffPtr;
/* Start Conditions */

%}

%x SC_COMMENT
%x SC_STRING

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
[-+]?[0-9]+(\.[0-9]+)?([eE][-+]?[0-9]+)?               return(NUM);
    /* Strings */
    /*\"([^\"]|\n)*\"                                           return(STRING);*/

    /*<SC_STRING> "\"\[]  */
\"                      {BEGIN(SC_STRING); buffPtr=buffForStrings; *buffPtr++=*yytext; return(EXPLICIT_HANDLING);}
<SC_STRING>{
    \\\n         {line_no++; *buffPtr++='\n'; return(EXPLICIT_HANDLING);}
    \\\"         {*buffPtr++='"'; return(EXPLICIT_HANDLING);}
    \n           { *buffPtr=0;fprintf(stderr,"ERROR Line(%d): End of line in String: %s\nPlease escape new lines if you want to include them in your string.\n",line_no,buffForStrings); BEGIN(0);line_no++;}
                 {BEGIN(0); *buffPtr++=*yytext; *buffPtr=0; return(STRING);}/*\n           {line_no++; *buffPtr++='\n'; return(EXPLICIT_HANDLING);}*/
    \"           {BEGIN(0); *buffPtr++=*yytext; *buffPtr=0; return(STRING);}
    .            {*buffPtr++ = *yytext; return(EXPLICIT_HANDLING);}
    <<EOF>>      fprintf(stderr,"ERROR: EOF reached and string not terminated\n");
}


    /* We could probably use `yycoment` for this instead */
    /* Comments */
"/*" { commentNestingCounter = 0;yymore(); BEGIN(SC_COMMENT); }
<SC_COMMENT>{
    "/*" {yymore(); commentNestingCounter++;}
    "*/" {
        if(commentNestingCounter == 0){
            BEGIN(INITIAL);
            printf("Found Comment in Line(%d): \n%s\n",line_no,yytext);
            //return(COMMENT); 
        }else{
            yymore();
            commentNestingCounter--;
        }
    <<EOF>> { printf("EOF in comment\n"); }
    }
    . {yymore();}
    \n {yymore(); line_no++;}
}
"//".*\n                                                   {printf("Found Comment in Line(%d): %s\n",line_no, yytext); line_no++;}

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
[_]*[a-zA-Z]+[a-zA-Z0-9_]*       return(IDENTIFIER);

[ \t]                     ;
\n line_no++;
.       {
            char *yycopy = strdup(yytext);
            fprintf(stderr,"ERROR LINE(%d): Illegal Character : %c\n",line_no,yytext[0]);
        }
%%



int main(int argc, char** argv) {
  int i, tok;
  yyin = fopen("test.txt", "r");
  for (tokenCounter = 0; 1==1; ) {
    tok = yylex();
    //IF
    if(tok == STRING){
        printf("\n%d-th token(type:%s) on line %d :\n%s\n", tokenCounter+1,tokenNames[tok],line_no, buffForStrings);
        printf("End of token %d \n",tokenCounter+1);
        tokenCounter ++;

    }else if(tok != EXPLICIT_HANDLING){
        //fprintf(stderr, "\n%d-th token(type:%d) on line %d :\n%s\n", tokenCounter+1,tok,line_no, yytext);
        printf("\n%d-th token(type:%s) on line %d :\n%s\n", tokenCounter+1,tokenNames[tok],line_no, yytext);
        printf("End of token %d \n",tokenCounter+1);
        tokenCounter ++;
    }
  }
  return(0);
} /* end of main */

yywrap() {
    printf("End of File reached. Exiting...");
    fclose(yyin);
    exit(1);
}

