#ifndef AST_H
#define AST_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//#include "symboltable.h"
// Thisis the header file that will help us in the construction of 
// our AST
extern const char *EnumNameRef[];
extern const char *NameTypeStr[];
extern const char *NameClassStr[];
extern const char *OpTypes[];

struct SymbolTable;
typedef struct SymbolTable SymbolTable;
typedef struct ArrayDimList{//Used mainly in symbol table for saving the dimensions  of an array
    //I think since our original grammar was only to take numers we are okay using
    //integer.
    //Pascal allows any number(including negatives) except reals. Thus this should be
    //enough
    int lowerBound;
    int upperBound;
}ArrayDimList;//Not going to use it
enum ISVALID_VALUE{
    VALID_VALUE,
    INVALID_VALUE
};
//Mainly used for SEMANTIC phase
typedef enum NAME_TYPE{//This should actually be something like a type descritopr maybe but we cannot define types in mini pascal. So this will do
    TYPE_INT,
    TYPE_REAL,
    TYPE_CONST_STRING,
    TYPE_ARRAY,//Not sure about this one
    TYPE_VOID,//Represents procedure return type
    TYPE_ERR,
    TYPE_UNFILLED//Null Basically
} NAME_TYPE;
typedef enum NAME_CLASS{
    CLASS_CONSTANT,
    CLASS_VAR,
    CLASS_TYPE,
    CLASS_FUNCTION,
    CLASS_PROCEDURE,
    CLASS_ENUM,
    CLASS_CLASS,
    CLASS_PACKAGE,//NAH
    CLASS_UNFILLED//NULL basically
} NAME_CLASS;
typedef enum BINARY_OPERATIONS{
    //Arithmetic Operations 
    NODE_OP_ADD,
    NODE_OP_SUBTRACT,
    NODE_OP_MULT,
    NODE_OP_DIV,
    //
    //Relative Operations
    NODE_OP_LESSTHAN,
    NODE_OP_GREATERTHAN,
    NODE_OP_EQUALS,
    NODE_OP_LESSTHANEQ,
    NODE_OP_GREATERTHANEQ,
    NODE_OP_NEQUALS,
    //
    //Logical Operations 
    NODE_OP_AND, 
    NODE_OP_OR,
    //
}BINARY_OPERATIONS;
typedef enum UNARY_OPERATIONS{
    //Unary Arithmetic Operations
    NODE_OP_POSSIGN,
    NODE_OP_NEGSIGN,
    //Unary Logical
    NODE_OP_NOT

}UNARY_OPERATIONS;

typedef enum NodeType{//Expression such as add and stuff like taht are deprecated here
    NODE_ROOT,
    NODE_ID_LIST,
    NODE_DECLARATIONS_ROOT,
    NODE_DECLARATIONS,//Actually a single declaration

    NODE_SUBPDECLARATIONS,//Not the Plural
    NODE_SUBPDECLARATION,//Not the Singular

    NODE_ARGUMENTS,
    NODE_ARGUMENT,

    NODE_STATEMENT_LIST,
    NODE_STATEMENT,
   
    NODE_VARREF,//This can also be used to reference an array
    NODE_ARR_SUFFIXES,//Could be 0 or many

    NODE_IN_STATEMENT_CALL,//Its in procedure_statement inside the yacc file 
    
    NODE_EXPR_LIST,
    NODE_EXPR,
    NODE_BINARY_EXPR,
    NODE_UNARY_EXPR,

    NODE_ASSIGN_OP,
    NODE_IF_ELSE,
    NODE_WHILE,
    NODE_UNARY_NOT_OP,

    NODE_STMNT,

    NODE_TYPE_INT,
    NODE_TYPE_REAL,
    NODE_TYPE_STRINGCONST,
    NODE_TYPE_ARR,

    NODE_FUNCTION,
    NODE_PROCEDURE,

    NODE_ID,
    NODE_NUM,

    //Operations

    NODE_FUNC_CALL,//Its in procedure_statement inside the yacc file 
    NODE_TYPE_PROG_ARG

} NodeType;
typedef enum ASSIGN_POS{
   POS_LHS,
   POS_RHS,
   POS_UNFILLED
}ASSIGN_POS;
typedef struct Node{
    NodeType type;
    struct Node* parent;
    struct Node* lMostChild;
    struct Node* rMostChild;
    struct Node* lMostSibling;
    struct Node* rSibling;
    struct Node* lSibling;//NOT left most

    struct Node* typeRef;

    //For Array TODO: We might want to move this out
    //TODO cleanup
    double lowerBound;//Because NUM can be both REAL and INT then we will store it as string
    double upperBound;//and then in semantic checking check if real -> throw semantic error
    
    int valValidity;//A boolean flag decribing whether this value is invalid

    //TODO we could make a union out of this
    //Values For General Purpose
    char * stringVal;//Usually for identifiers anda strings.
    int intVal;
    double doubleVal;
    bool hasConcreteValue;//If false then that means the expression or whatever caannot give a concrete value like 3 or 2 but it is dependenant of the return of something

    int lineInCode;

    //This is for counting how many levels of array it has after dereferencign
    //It is more like the amount of dimensions represented after considering the amount of
    //square bracket pairs
    int derefLevel;//Non-vars will have this as zero as well as arrays that have dereferences the same amount of times as their dimensions

    //This is for a variable. It determins its position in an assignment(LHS/RHS)
    ASSIGN_POS assignPos;

    //For expressions
    union{
        enum BINARY_OPERATIONS operation; 
        enum UNARY_OPERATIONS uoperation; 
    };
    //THIS IS THE STDTYPE THE expression represetns, will very likely be filled in
    //semantic check
    NAME_TYPE nodeStdType;//THIS IS THE ENUM NAME_TYPE from symbolTable
    SymbolTable* assocTable;//This is mostly used for functions and procedures where they have their own scopes

    size_t id;//This uniquely identifies this node
} Node;
Node* makeNode(NodeType type);
void adoptChild(Node*, Node*);
void freeTree();//Should be used for cleaning up tree.
void copyStr(Node *, const char*);
void deleteNode(Node * node);
void deleteNodeTree(Node * node);
void traverseTree(Node* root, bool deleteAsTraversed, bool printInfo,int level);
Node* getNthChild(Node * node, int i );//Index begins at 1
bool cmpInsensitive(const char* a, const char* b);
#endif
