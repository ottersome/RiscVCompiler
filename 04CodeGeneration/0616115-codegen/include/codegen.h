#ifndef CODEGEN_H
#define CODEGEN_H
#include <stdio.h>
#include "ast.h"
#include "symboltable.h"
#include "semantics.h"
FILE * ofile;
void initializeCodeGen(FILE** file);
void finalizeCodeGen();
void generateCode(Node* astrootNode, SymbolTable* symTabArray);
void loopThroughAllChildrenCG(Node * node);

//Helpers
char * generateLabel();
void generateConstAddr(char *);
int floatToDecRepresentation(float f);
void emitOffsetCalculation(FILE* file, Node* node,SymbolTable *  currentSymTab);

//Handlers
void cg_varref(Node * node);
void cgHandle_declarations(Node * node);
void cdHandle_Conditional(FILE * file, Node *, SymbolTable*);

void genVisitor(Node* node); 
void gen_loopThroughAllChildren(Node* node);

//Emitters
void emitProgInit(FILE* file, Node* node,SymbolTable *  currentSymTab);
void emitMainFunctionPrelude(FILE* file, Node* node, SymbolTable* symTab);
void emitMainFunctionPostlude(FILE* file, Node* node, SymbolTable* symTab);
void emitFunction(Node* node);
void emitMethod(FILE* file, Node* node, SymbolTable* symTab);
void emitParametersAlloc(FILE* file, Node* node, SymbolTable* symTab);
void emitMethodPostlude(FILE* file, Node* node, SymbolTable* symTab);
void emitDeclarationAllocation(FILE* file, Node* node, SymbolTable* symTab);
void emitDeclarationDeallocation(FILE* file, Node* node, SymbolTable* symTab);
void emitBinaryExpression(FILE* file, Node* node, SymbolTable* symTab);
void emitBinaryArith(FILE* file, Node* node, SymbolTable* symTab);
void emitBinaryRelative(FILE* file, Node* node, SymbolTable* symTab);
void emitBinaryLogical(FILE* file, Node* node, SymbolTable* symTab);
void emitConstant(FILE* file, Node* node, SymbolTable* symTab);
void emitLHSReference(FILE* file, Node* node, SymbolTable* symTab);
void emitRHSVarRef(FILE* file, Node* node, SymbolTable* symTab);
void emitWhileLoop(FILE* file, Node* node, SymbolTable* symTab);
void emitRoutineCall(FILE* file, Node* node, SymbolTable* symTab);
void emitUnaryExpression(FILE * file, Node* node, SymbolTable* symTab);


void emitFunctionArguments(FILE* file, Node* node, SymbolTable* symTab);
void emitStaticDeclarations(FILE* file, Node* node, SymbolTable* symTab);
#endif
