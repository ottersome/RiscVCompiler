#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast.h"

const char *OpTypes[] = {
    "ADD",
    "SUBTRACT",
    "MULTIPLY",
    "DIVIDE",
    "LESSTHAN",
    "GREATERTHAN",
    "EQUALS",
    "LESSTHANEQ",
    "GREATERTHANEQ",
    "NEQUALS",
    "AND", 
    "OR"
};
const char *NameTypeStr[] = {//This should actually be something like a type descritopr maybe but we cannot define types in mini pascal. So this will do
    "TYPE_INT",
    "TYPE_REAL",
    "TYPE_CONST_STRING",
    "TYPE_ARRAY",
    "TYPE_VOID",
    "TYPE_ERR",
    "TYPE_UNFILLED"//Null Basically
}; 
const char *NameClassStr[] = {
    "CONSTANT",
    "VAR",
    "TYPE",
    "FUNCTION",
    "PROCEDURE",
    "ENUM",
    "CLASS",
    "PACKAGE",
    "UNFILLED"
}; 
const char *UOpTypes[] = {
    "OP_POSSIGN",
    "OP_NEGSIGN",
    "OP_NOT"
};
const char *EnumNameRef[] = {
    "Root",
    "ID_LIST",
    "DECLARATIONS_ROOT",
    "DECLARATIONS",
    "SUBPDECLARATIONS",
    "SUBPDECLARATION",
    "ARGUMENTS",
    "ARGUMENT",
    "STATEMENT_LIST",
    "STATEMENT",
    "VARREF",
    "ARR_SUFFIXES",
    "IN_STATEMENT_CALL",
    "EXPR_LIST",
    "EXPR",
    "BINARY_EXPR",
    "UNARY_EXPR",
    "ASSIGN_OP",
    "IF_ELSE",
    "WHILE",
    "NOTOP",
    "STMT",
    "TYPE_INT",
    "TYPE_REAL",
    "TYPE_STRINGCONST",
    "TYPE_ARR",
    "FUNCTION",
    "PROCEDURE",
    "ID",
    "NUMBER",
    "FUNC_CALL",//Its in procedure_statement inside the yacc file 
    "TYPE_PROGRAM_ARG",
};
size_t nodeId = 0;
size_t indexOfNextAvTab = 0;//Index of the next available table
struct Node* makeNode(NodeType type){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->type = type;
    node->parent = NULL;
    node->lMostChild = NULL;
    node->rMostChild = NULL;
    node->lMostSibling = NULL;
    node->rSibling = NULL;
    node->lSibling = NULL;
    node->valValidity = VALID_VALUE;
    node->stringVal = NULL;
    node->id= nodeId++;
    node->nodeStdType=TYPE_UNFILLED;
    node->assignPos=POS_UNFILLED;
    node->hasConcreteValue = false;
    node->derefLevel = 0;

    return node;
}
void adoptChild(struct Node* parentNode, struct Node* childNode){

    if(parentNode->lMostChild != NULL){
        struct Node* rmostc = parentNode->lMostChild;
        //Find Right Most Child for this parent node
        while(rmostc->rSibling != NULL) rmostc = rmostc->rSibling;
        //Put the child at the right
        rmostc->rSibling = childNode;
        childNode->lMostSibling = parentNode->lMostChild;
        childNode->parent = parentNode;
        //ALso add left sibling for ease of use later
        childNode->lSibling = rmostc;
        parentNode->rMostChild=childNode;
    }else{
        parentNode->lMostChild = childNode;
        childNode->parent = parentNode;
        //This next statemetn im not su sure of lol
        parentNode->rMostChild = childNode;
    }
    //TODO clean this up if no longer necessary
    /*if (parentNode->child != NULL){*/
        /*childNode->lSibling = parentNode->child->lSibling;*/
        /*childNode->rSibling = parentNode->child;*/
        /*parentNode->child->lSibling->rSibling = childNode;*/
        /*parentNode->child->lSibling = parentNode;*/
    /*}else{*/
        /*parentNode->child = childNode;*/
    /*}*/
    /*childNode->parent = parentNode;*/
}
void copyStr(struct Node * node, const char* string)
{
    node->stringVal = (char *)malloc(strlen(string)*sizeof(char)+1);//Stuff like this will cause memory leaks unless properly handled. */
    //printf("Size of this string is %d\n",strlen(string));
    strcpy(node->stringVal, string);
}
void deleteNode(struct Node * node)
{
    //free NULL is guarateed to be safe so I wont bother to check if stringVal was
    //allocated
    if(node->stringVal != NULL)//NVM Valgrind is reporting this soo...
        free(node->stringVal);
    free(node);
}
void printTab(int level){
    while(level-->0)printf("\t");
}
void traverseTree(struct Node* root, bool deleteAsTraversed, bool printInfo, int level){
    if(printInfo){
        printTab(level);
        if(root->type == NODE_ID){
            printf("L%d:NodeType: %s val:%s\n",level,EnumNameRef[root->type],root->stringVal);
        }else if(root->type == NODE_BINARY_EXPR){
            printf("L:%d,Id:%lu,BinaryExpr,oprtr: %s\n",level,root->id,OpTypes[root->operation]);
        }else if(root->type == NODE_UNARY_EXPR){
            printf("L%d:UnaryExpr,oprtr: %s\n",level,UOpTypes[root->uoperation]);
        }else if(root->type == NODE_NUM){
            printf("L%d:NodeType: Number,Val: %f\n",level,root->doubleVal);
        }else{
            printf("L%d:NodeType: %s\n",level,EnumNameRef[root->type]);
        }

    }
    if(root->lMostChild !=NULL){//Then we visit the children
        Node* curIteratedChild = root->lMostChild;
        Node* nextIteratedChild;
        while(curIteratedChild!=NULL){
            nextIteratedChild = curIteratedChild->rSibling;//We do this so we dont deal with freed pointers
            traverseTree(curIteratedChild,deleteAsTraversed,printInfo,level+1);//SUPER TODO This thing here should end up with a null value when coming back and yet we call its right sibling befoer
            curIteratedChild = nextIteratedChild;
        }
    }
    //printTab(level);
    //printf("Deleting node %s\n",EnumNameRef[root->type]);
    if(deleteAsTraversed)
        deleteNode(root);
}
void deleteNodeTree(struct Node * root)
{
    //free NULL is guarateed to be safe so I wont bother to check if stringVal was
    //allocated
    if(root->lMostChild !=NULL){//Then we visit the children
        Node* curIteratedChild = root->lMostChild;
        Node* nextIteratedChild;
        while(curIteratedChild!=NULL){
            nextIteratedChild = curIteratedChild->rSibling;//We do this so we dont deal with freed pointers
            deleteNodeTree(curIteratedChild);//SUPER TODO This thing here should end up with a null value when coming back and yet we call its right sibling befoer
            curIteratedChild = nextIteratedChild;
        }
    }
    deleteNode(root);
}
Node* getNthChild(Node * node,int nth){
    if(node == NULL){
        return NULL;
#ifndef DEBUG
        printf("getNthChild() received a NULL parent\n");
#endif
    }
    
    Node* childIterator = node->lMostChild;
    for(int i = 0;i<nth-1;i++){
        if(childIterator->rSibling == NULL){
            //We reached an unexisting chidl
            /** fprintf(stderr,"Tried to reach an unexisting child\n"); */
            return NULL;
        }
            childIterator = childIterator->rSibling;
    }
    /** if(childIterator == NULL) */
        /** fprintf(stderr,"The tree %s looking for children is empty\n",EnumNameRef[node->type]); */
    return childIterator;
}
bool cmpInsensitive(const char* a, const char* b){
    unsigned int size1 = strlen(a);
    if (strlen(b) != size1)
        return false;
    for (unsigned int i = 0; i < size1; i++)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}
