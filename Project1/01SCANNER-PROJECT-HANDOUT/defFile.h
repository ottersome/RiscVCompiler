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
#define     IDENTIFIER      41
char * tokenNames[] = {
                        "NULL",
                        "NUM",
                        "STRING",
                        "COMMENT",
                        "PROGRAM",
                        "ID",
                        "LEFT PARENTHESIS",
                        "RIGHT PARENTHESIS",
                        "SEMICOLON",
                        "PERIOD",
                        "COMMA",
                        "VAR",
                        "COLON",
                        "ARRAY",
                        "LEFT SQUARE BRACKET",
                        "RIGTH SQUARE BRACKET",
                        "OF",
                        "INTEGER",
                        "REAL",
                        "FUNCTION",
                        "PROCEDURE",
                        "BEGIN",
                        "END",
                        "IF",
                        "THEN",
                        "ELSE",
                        "WHILE",
                        "DO",
                        "LESS THAN",
                        "GREATER THAN",
                        "LESS THAN OR EQ",
                        "GREATER THAN OR EQ",
                        "EQUALS TO",
                        "NOT EQUALS TO",
                        "PLUS",
                        "MINUS",
                        "MULTIPLICATION",
                        "DIVISION",
                        "NOT",
                        "LDOTS",
                        "ASSIGNOP",
                        "IDENTIFIER",
};
