#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#pragma once
#include "ast.h"
//255 In case the int is only 8 bits. Which is not normal but whatever. Better safe than
//sorry
#define HASH_TABLE_SIZE 255
typedef struct MethodParameter{
    char * nameOfParam;//If point to ast string This should be cleared by the ast
    NAME_TYPE typeOfParam;
    size_t parDimensions;

    struct MethodParameter* nextParam;
}MethodParameter;
struct SymbolTableEntry;
typedef struct MethodSignature{
    NAME_TYPE returnType;
    size_t amountOfParams;
    MethodParameter* paramArrayHead;

} MethodSignature;//A bit redudnant but whatever
typedef struct Attributes{
    NAME_TYPE nameType;
    NAME_CLASS nameClass;

    //Only used for arrays
    int lowerBoundArray;
    int upperBoundArray;
    int arrDimension;
    //Initialized Array. This array be dynamically allcated once we know the dimensions of
    //the array.
    bool *isInitialized;

    bool isParam;
    bool hasBeenInitialized;

    //I think we can just use name type for functions too
    //NAME_TYPE returnType;

    int * boundsArray;//TODO cleanup
    bool hasConcreteValue;
    union{
        int intVal;//Maybe put more stuff here
        char * strPtr;//For a string, not identifeir
        double doubleVal;
        //Not sure if this is the best palce for it but ill put it here anyyways
    };
    MethodSignature * methodSignature;
} Attributes;

typedef struct SymbolTableEntry{
    char * name;//TODO maybe do a namespace but athat is reaally not urgent
    Attributes* attributes;
    //"Name" And "Type" Are alredy taken care of by the "Attributes" Structure above.
    
    //These members willfacilitate the implementation of the table.
        //These will facilitate the implementation of the doubly linked list. For
        //collision managemetn. A la hora de free el hash table lo hacemos con esto
        struct SymbolTableEntry * nextHash;
        struct SymbolTableEntry * prevHash;//I dont think we really ended up using this boi. Im just leaving it in case its deletion break something *shrug*

        //Reference to the next outer declaration(In terms fo scope
        struct SymbolTableEntry * var;//This is *essentialy* a stack for symbol declarations of same name.(not in the physical sense though)

        struct SymbolTableEntry * nextInSameScope;//They call it "Level" in the book
        struct SymbolTableEntry * prevInSameScope;//This facilitates navigation when processing of some nodes is backwards

    size_t entryDepth;//Useful for checking if a symbol at a given depth has been entered
    //This is a stack for the methods we are nested in. This is used for determinining
    //whether we are setting a return value for a method
    struct SymbolTableEntry* nextInScopeStack;
    
    //int scopeId;//Dont know why but i want to keep this outside of my Attributes
} SymbolTableEntry;
typedef struct SymbolTable{//We will be using the hash table used in the book
    //Symbol table will contain a hash table and a "Scope Display" that will index it
    //Symbol Table allows efficient look up and entry of names.
    SymbolTableEntry* HashTable[HASH_TABLE_SIZE];//CLEANUP
    //List of symbols taht are declared at the same level.
    //The i-th enry of the scope display references a *list* of symbols currently active
    //at sope depth *i*. The list we link to is linked itself by their
    //level(nextInSameScope( field)
    SymbolTableEntry** scopeDisplay;
    
    //This will point to the top of the stack. i.e. the latest
    //method will be at the top
    SymbolTableEntry* scopeMethodStackTop;
    int curDepth;
    int size;

    size_t savedTablesIndex;
    SymbolTableEntry** safeKeeping;//For printing at the end

} SymbolTable;

// void buildSymbolTable(Node * ASTRoot);
void initializeSymbolTable(SymbolTable * table);
SymbolTableEntry* createNewSymbleTableEntry(Attributes * attr);//Simply initializes while below adds to hash table
SymbolTableEntry* addSymbol(SymbolTable*,char * str,Attributes * attr);//Will return NULL when we have a collision in same scope
SymbolTableEntry* retrieveSymbol(SymbolTable*,char * name);

unsigned long hashFunc(unsigned char * name);
void removeFromHashChain(SymbolTable *,char * name);
void addToHashChain(SymbolTable*,unsigned long hash,SymbolTableEntry * entry); 
void freeSymTabEntry(SymbolTableEntry* symEntry);
Attributes * createNewAttrib();


void openScope(SymbolTable * symbolTable,SymbolTableEntry * entryForEnteredMethod);
void closeScope(SymbolTable *,SymbolTableEntry * entryForClosingMethod);
void enterSymbol(Node * symbol);//They should have reference to their type in the node
void enterSymbolList(Node * symbolList);//They should have reference to their type in the node
SymbolTableEntry *  getEntryDeclaredLocally(SymbolTable*,char * name);//Wil return NULL scope does not have the name locally 
SymbolTableEntry * findInnerMostEntry(char * name);//This will always take O(taleSize)

//Functions for the important processings i think
void processDeclaration(Node * node);
void printSymbolTableInClosedScope(SymbolTable *);
void terminateSymbolTable(SymbolTable *);

//
#endif
