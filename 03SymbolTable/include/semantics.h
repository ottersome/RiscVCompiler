#pragma once
#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "symboltable.h"

void buildTable(SymbolTable *,Node* ASTRoot);
void semanticCheck(Node * node);

//Helper fuincs
//Translate Type from AST to Symbol Table
NAME_TYPE getTypeForSymTab(NodeType);
void loopThroughAllChildren(Node* node);
void printSemanticError(char * str,int lineNo);
bool areTypesCompatible(Node *,Node *);
bool isThisAReal(double num);

void handleLHSVarRef(Node* varref);
void handleRHSVarRef(Node* varref);

void handleVarDeclaration(Node* node);
void handleAssignOp();
// void handleSubProgram(Node * node);//SubprogramIncludes Both Procedures and Functions
void handleProgram(Node * node);//(Root)
void handleFunction(Node * node);
MethodSignature* handleParameters(Node * argumentsNode,NAME_TYPE type);
void handleProcedure(Node * node);
void handleInStatementCall(Node*node);//Probably not even needed
void handleMethodCall(Node*node);
void handleVarReferences(Node* varref);
void handleAssignOp(Node * assignNode);
void handleBinaryExpression(Node * binaryExpNode);
void handleUnaryExpr(Node* varref);
void handleNumTerminal(Node *);
#endif
