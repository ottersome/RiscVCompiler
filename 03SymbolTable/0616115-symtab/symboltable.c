#include <stdio.h>
#include <stdlib.h>
#include "symboltable.h"
#include "ast.h"

void initializeSymbolTable(SymbolTable * symbolTable){
    //Initialize all pointers to null
    for(int i = 0 ; i < HASH_TABLE_SIZE;i++){
        symbolTable->HashTable[i] = NULL;//Lets nto waste space and just initialize to nullptr
    }
    symbolTable->curDepth = -1;//Since we we will openscope(for the program) as soon as we start this will be incread to 0
    symbolTable->size=0;
    symbolTable->savedTablesIndex = 0;
    symbolTable->safeKeeping =NULL;
    symbolTable->scopeMethodStackTop= NULL;
    symbolTable->scopeDisplay = (SymbolTableEntry**)malloc(sizeof(SymbolTableEntry*)*HASH_TABLE_SIZE);
    symbolTable->safeKeeping = (SymbolTableEntry**)malloc(sizeof(SymbolTableEntry*)*HASH_TABLE_SIZE);
    //Just call Process node on this root
}
unsigned long hashFunc(unsigned char* str){
    //Ref to djb2 I'm sorry but I was looking for an efficient hash func
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash%(HASH_TABLE_SIZE);//TODO i dont think i need a -1 here right?
}
SymbolTableEntry* createNewSymbleTableEntry(Attributes * attr){
        SymbolTableEntry* entry = (SymbolTableEntry*) malloc(sizeof(SymbolTableEntry));//TODO CLEANUP
        //Initialize Values
        entry->nextHash = NULL;
        entry->prevHash = NULL;
        entry->var = NULL;
        entry->nextInSameScope = NULL;
        entry->prevInSameScope = NULL;
        entry->attributes = attr;//REMEMBER this must be initialized outside
        entry->name = NULL;
        entry->entryDepth = 0;

        entry->nextInScopeStack=NULL;
        return entry;
}
SymbolTableEntry * retrieveSymbol(SymbolTable* symbolTable,char * name){//Hash table will contain the innermost declaration of the name. I belive this is why we will be removing it later
    unsigned long hash = hashFunc((unsigned char*)name);//TODO make sure this cast is face
    SymbolTableEntry * curIt = symbolTable->HashTable[hash];
    //Iterate through chain until you get the same name
    while(curIt != NULL){
        if(cmpInsensitive(curIt->name, name) == true)//If we find our name in the collision chain
            return curIt;

        curIt = curIt->nextHash;
    }
    return NULL;
}
void removeFromHashChain(SymbolTable* symbolTable,char * name){//Doesnt actually free the node just unlinks it form the hash table TODO figure out a way actually free it then
    SymbolTableEntry * oldSym = retrieveSymbol(symbolTable,name);
    SymbolTableEntry ** head =  &symbolTable->HashTable[hashFunc((unsigned char*)name)];
    /** if(oldSym!=NULL){ */
    /**     if(oldSym->prevHash != NULL) */
    /**         oldSym->prevHash->nextHash = oldSym->nextHash; */
    /**     if(oldSym->nextHash != NULL) */
    /**         oldSym->nextHash->prevHash = oldSym->prevHash; */
    /** } */
    if(*head == NULL || oldSym == NULL)
        return;
    //if the node is head
    if(*head == oldSym)
        *head = oldSym->nextHash;

    //change the next and prev only if they are not null
    if(oldSym->nextHash != NULL)
        oldSym->nextHash->prevHash = oldSym->prevHash;
    if(oldSym->prevHash != NULL)
        oldSym->prevHash->nextHash = oldSym->nextHash;
}
void addToHashChain(SymbolTable* symbolTable,unsigned long hash, SymbolTableEntry * newEntry){//By the time we run this we know that there is no entry in the collision chain for the same name because we mustve removed it previously
    SymbolTableEntry* colChainIt = symbolTable->HashTable[hash];//SUPER TODO check if there are errors similar to the one from removeFromHashChain earlier
    if(colChainIt ==NULL){//This hash points to an empty slot
        symbolTable->HashTable[hash] = newEntry;
    }else{//Of we get a collision
        while(colChainIt->nextHash!=NULL) colChainIt = colChainIt->nextHash;//Get the last valid value in the chain
        colChainIt->nextHash = newEntry;
        newEntry->prevHash = colChainIt;
    }
#ifdef DEBUG
    /** printf("NOTICE: Added an entry %s to memlcoation %p and hash %lu\n",newEntry->name,newEntry,hash); */
#endif
}
void freeSymTabEntry(SymbolTableEntry * entry){
    //Commented because we are still referencing the AST, uncomment if you decide to copy
    //strings
    /** if(entry->name != NULL) */
    /**     free(entry->name); */
    if(entry->attributes->methodSignature != NULL){
        //We must clear the parameters
        MethodParameter * currIt = entry->attributes->methodSignature->paramArrayHead;
        MethodParameter * next;
        while(currIt != NULL){
            next = currIt->nextParam;
            free(currIt);
            currIt = next;
        }
        free(entry->attributes->methodSignature);
    }
    if(entry->attributes->arrDimension>0){
        free(entry->attributes->boundsArray);
        free(entry->attributes->isInitialized);
    }
    /** if(entry->attributes->isInitialized !=NULL){ */
    /**     free(entry->attributes->isInitialized); */
    /** } */
    /** if(entry->attributes->methodSignature!=NULL){ */
    /**     //Free pramArray head */
    /**     if(entry->attributes->methodSignature->paramArrayHead!=NULL){ */
    /**         MethodParameter* paramIt = entry->attributes->methodSignature->paramArrayHead; */
    /**         MethodParameter* nextIt = NULL; */
    /**         while(paramIt!=NULL){ */
    /**             nextIt = paramIt->nextParam; */
    /**             free(paramIt); */
    /**             paramIt = nextIt; */
    /**         } */
    /**     } */
    /**     free(entry->attributes->methodSignature); */
    /** } */
    free(entry->attributes);
    free(entry);
}
void openScope(SymbolTable* symbolTable, SymbolTableEntry* entryForEnteredMethod){
    symbolTable->curDepth++;
    printf("NOTICE: Opening Scope as we perform semantic check\n");
    symbolTable->scopeDisplay[symbolTable->curDepth] = NULL;
    //Now for scopeMethodSctack
    if(entryForEnteredMethod!=NULL){
        if(symbolTable->scopeMethodStackTop==NULL){//If we are entering a method in global scope
            symbolTable->scopeMethodStackTop = entryForEnteredMethod;
        }else{
            entryForEnteredMethod->nextInScopeStack = symbolTable->scopeMethodStackTop;
            symbolTable->scopeMethodStackTop = entryForEnteredMethod; 
        }
    }
}
void closeScope(SymbolTable* symbolTable, SymbolTableEntry* entryForClosedMethod){//Since opening and closing of scopes is done only on methods
    printf("NOTICE: Closing Scope as we perform semantic check\n");
    printSymbolTableInClosedScope(symbolTable);
    //Clean un the scope
    SymbolTableEntry* symbolIt = symbolTable->scopeDisplay[symbolTable->curDepth];//Yeah i know its not last rn but it is in the enxt operation
    SymbolTableEntry* nextIt;
    SymbolTableEntry* outerName;
    while(symbolIt != NULL){
        nextIt = symbolIt->nextInSameScope;
        //Vas a hacer tus opernaciones
        outerName = symbolIt->var;
        removeFromHashChain(symbolTable,symbolIt->name);//If we find a name that means it is in this scope so we cant accidentaly remove something form an outer scope
        /** freeSymTabEntry(symbolIt); */
        if(outerName != NULL)
            addToHashChain(symbolTable,hashFunc((unsigned char*)outerName->name),outerName);//TODO Make sure this cast is not causing problems later
        symbolIt = nextIt;
    }
    //Again for method scope stack
    if(entryForClosedMethod!=NULL){
        if(symbolTable->scopeMethodStackTop==NULL){//If its null then dont touch it right? the only way it can be null if its we are leaving a scope that had a redeclared name
            /*symbolTable->scopeMethodStackTop = entryForEnteredMethod;*/
        }else{
            //Otherwise remove top of stack
            symbolTable->scopeMethodStackTop = symbolTable->scopeMethodStackTop->nextInScopeStack;//The freeing of the entry will be done when closing the entry that contains it
        }
    }
    //Done method scope stack
    symbolTable->scopeDisplay[symbolTable->curDepth] = NULL;
    symbolTable->curDepth--;
}

SymbolTableEntry* addSymbol(SymbolTable * symbolTable, char * name, Attributes* attr){//SUPER TODO think about actually copying the str value here instead of pointing to the value in the AST. Because if for some reason you delete teh AST before thsi you are in for hell bruv
    /** printf("Adding symbol  to table %s..\n",name); */
    unsigned long depth = symbolTable->curDepth;
    SymbolTableEntry* oldNameEntry = retrieveSymbol(symbolTable,name);
    SymbolTableEntry* newEntry = createNewSymbleTableEntry(attr);
    if(oldNameEntry != NULL && oldNameEntry->entryDepth == depth){//Then there are no 
        //We have redeclaration !!! DING DING DING DING DING DING DING 
        //If redeclaration then we quit the process of adding it to symtab
        freeSymTabEntry(newEntry);//Let the caller handle the error message
        //We do free this one because it wont be of use in the final symbol table.
        return NULL;
    }
    newEntry->nextInSameScope = symbolTable->scopeDisplay[depth];
    newEntry->entryDepth= depth;
    newEntry->name = name;//add name
    //If we are not first in scope then 
    if(symbolTable->scopeDisplay[depth]!=NULL)
        symbolTable->scopeDisplay[depth]->prevInSameScope = newEntry;
    //This is for printing at the end
    if(symbolTable->scopeDisplay[depth]==NULL){//If we are the first 
       symbolTable->safeKeeping[symbolTable->savedTablesIndex++] = newEntry;
    }

    symbolTable->scopeDisplay[depth] = newEntry;
    unsigned long hash = hashFunc((unsigned char*) name);
    if(oldNameEntry != NULL){//Keep the old entry around but remove it form the table so we can continue checking for errors
        printf("NOTICE: We have found the same variable \"%s\" in an outer scope. This is not an error.\
just letting you know\n",name);
        removeFromHashChain(symbolTable,oldNameEntry->name);
        printf("Removed from chain\n");
    }

    addToHashChain(symbolTable,hash, newEntry);
    /** printf("Having Problems adding it to chain\n"); */
    newEntry->var = oldNameEntry;//This will be null if pointing outside 
    symbolTable->size++;
    //Then we proceed to add it to the hash collision list
    return newEntry;
}

//MOving semantics to its own file
/** // Functions for Nodes we want to focus on  */
/** void processDeclaration(Node * node){ */
/**     //TODO send type to be checked  */
/**     //Loop Through the Identifier List  */
/**     //We know the first child is the identifier list */
/**     Node * identifier = node->lMostChild->lMostChild; */
/**     Node * typeNode = node->lMostChild->rSibling; */
/**     while(identifier != NULL){ */
/**         //Check if its declared locally */
/**         addSymbol(); */
/**  */
/**         identifier = identifier- s>rSibling; */
/**     } */
/** } */

//END
//Rest of helper functions
SymbolTableEntry* getEntryDeclaredLocally(SymbolTable* symbolTable,char * name){
    //Search Table
    SymbolTableEntry * scopeIt =  symbolTable->scopeDisplay[symbolTable->curDepth];
    do{
        if(cmpInsensitive(scopeIt->name,name) == true)
            return scopeIt;
       scopeIt = scopeIt->nextInSameScope;
    }while(scopeIt->nextInSameScope != NULL);

    return scopeIt;
}
void printSymbolTableInClosedScope(SymbolTable * symbolTable){
    //Get The scope list thinger
    printf("\
****************************************\n\
*    Open Scope SymbolTable            *\n\
****************************************\n");
    SymbolTableEntry* symbolIt = symbolTable->scopeDisplay[symbolTable->curDepth];//Yeah i know its not last rn but it is in the enxt operation
    SymbolTableEntry* prevIt;
    //Get to the end of the scope list. This is because at the end of said list
    //is where we have the variables that were declared first
    if(symbolIt!=NULL){
        while(symbolIt->nextInSameScope!=NULL)symbolIt = symbolIt->nextInSameScope;
        while(symbolIt != NULL){
            prevIt = symbolIt->prevInSameScope;
            printf("Name : %s, Type:%s, Class %s, Depth %d, Dimension:%d ",
                    symbolIt->name,
                    NameTypeStr[symbolIt->attributes->nameType],
                    NameClassStr[symbolIt->attributes->nameClass],
                    symbolTable->curDepth,
                    symbolIt->attributes->arrDimension 
                  );
            //Check for Array Ranges
            if(symbolIt->attributes->arrDimension>0){
                printf("Ranges:");
                for(int i = 0;i<symbolIt->attributes->arrDimension*2;i=i+2){
                    printf("(%d,%d),",symbolIt->attributes->boundsArray[i],symbolIt->attributes->boundsArray[i+1]);
                }
            }
            if(symbolIt->attributes->methodSignature!=NULL){
                printf("Params: ");
                MethodParameter * methParam = symbolIt->attributes->methodSignature->paramArrayHead;
                while(methParam!=NULL){
                    printf("%s(Type:%s)(Dim:%lu)",methParam->nameOfParam,NameTypeStr[methParam->typeOfParam],methParam->parDimensions);
                    methParam = methParam->nextParam;
                }
            }
            //Check For Parameters
            printf("\n");
            /** printParameters() */
            //Vas a hacer tus opernaciones
            symbolIt = prevIt;
        }
    }
    printf("\
****************************************\n\
*   Closed Scope SymbolTable           *\n\
****************************************\n");
}
void terminateSymbolTable(SymbolTable * symbolTable){
    printf("We are now printing all the symbol tables encountered\n");
    for(size_t i=0;i<symbolTable->savedTablesIndex;i++){
        printf("\
****************************************\n\
*    Open Scope SymbolTable            *\n\
****************************************\n");
        SymbolTableEntry* symbolIt = symbolTable->safeKeeping[i];//Yeah i know its not last rn but it is in the enxt operation
        SymbolTableEntry* prevIt;
        //Get to the end of the scope list. This is because at the end of said list
        //is where we have the variables that were declared first
        if(symbolIt!=NULL){
            while(symbolIt != NULL){
                prevIt = symbolIt->prevInSameScope;
                printf("Name : %s, Type:%s, Class %s, Depth %lu, IsArray:%s,",
                        symbolIt->name,
                        NameTypeStr[symbolIt->attributes->nameType],
                        NameClassStr[symbolIt->attributes->nameClass],
                        symbolIt->entryDepth,
                        (symbolIt->attributes->arrDimension > 0)?"YES":"NO"
                      );
                //Check for Array Ranges
                if(symbolIt->attributes->arrDimension>0){
                    printf("Ranges:");
                    for(int i = 0;i<symbolIt->attributes->arrDimension*2;i=i+2){
                        printf("(%d,%d),",symbolIt->attributes->boundsArray[i],symbolIt->attributes->boundsArray[i+1]);
                    }
                }
                if(symbolIt->attributes->methodSignature!=NULL){
                    printf("Params: ");
                    MethodParameter * methParam = symbolIt->attributes->methodSignature->paramArrayHead;
                    while(methParam!=NULL){
                        printf("%s(Type:%s)(Dim:%lu)",methParam->nameOfParam,NameTypeStr[methParam->typeOfParam],methParam->parDimensions);
                        methParam = methParam->nextParam;
                    }
                }
                //Check For Parameters
                printf("\n");
                /** printParameters() */
                //Vas a hacer tus opernaciones
                freeSymTabEntry(symbolIt);
                symbolIt = prevIt;
            }
        }
        printf("\
****************************************\n\
*   Closed Scope SymbolTable           *\n\
****************************************\n");
    }
    free(symbolTable->scopeDisplay); 
    /** free(symbolTable->HashTable);  */
    free(symbolTable->safeKeeping); 
}
