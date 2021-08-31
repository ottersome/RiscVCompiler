# include <stdio.h>
#include <math.h>
#include "ast.h"
#include "symboltable.h"
#include "semantics.h"
#include "codegen.h"

SymbolTable * symbolTable;//This will actually be an array where the 0-element will be the uppermost table
size_t* tabIndex = 0;//This should modify the one in miniPacal.y.
FILE * ofile;
bool thereWasSemanticError = false;

void printSemanticError(char * str,int lineNo){
    thereWasSemanticError = true;
    fprintf(stdout,"Semantic Error at or around Line(%d):%s\n",lineNo,str);
}
bool buildTable(SymbolTable * table,Node * node,size_t * tabIn){
    tabIndex = tabIn;
    symbolTable = table;
    initializeCodeGen(&ofile);
    semanticCheck(node);
    return thereWasSemanticError;
}
void semanticCheck(Node * node){
    /** printf("Starting Semantic Check...\n"); */
    int i =0;// iterator
    Node* iterator;//Pointer iterator
    switch(node->type){
        case(NODE_ROOT)://Basically the program
            openScope(symbolTable,NULL);//So you can put the arguments in this scope
                i = 2;//We start from declarations
                while(getNthChild(node,i) != NULL){
                    semanticCheck(getNthChild(node,i));//decls,subpdcls,compound_statement
                    i++;
                }
            closeScope(symbolTable,NULL,node,tabIndex);
            break;
        case(NODE_ID_LIST)://Handled by other functions
            break;
        case(NODE_DECLARATIONS_ROOT):
            iterator = node->lMostChild;
            while(iterator!=NULL){//This order is good
                semanticCheck(iterator);//decls,subpdcls,compound_statement
                iterator = iterator->rSibling;
            }
           /*i = 1;*/
             /*while(getNthChild(node,i) != NULL){//Just loop through declarations */
                 /*semanticCheck(getNthChild(node,i));//decls,subpdcls,compound_statement */
                 /*i++; */
             /*} */
            break;
        case(NODE_DECLARATIONS)://This is actually a single declaration typo on my part that im to lazy to fix
            handleVarDeclaration(node,false);
            break;//Actually a single declaration
        case(NODE_SUBPDECLARATIONS)://Children can only be Procedures and Functions
            i = 1;
            while(getNthChild(node,i) != NULL){//Just loop through declarations
                semanticCheck(getNthChild(node,i));//decls,subpdcls,compound_statement
#ifdef DEBUG
                printf("Finished Semantic Check for one of them with i=%d %d sda \n",i,node->type);
#endif
                i++;
            }
            break;
        case(NODE_BINARY_EXPR):
            /** printf("Found Binary Expr\n"); */
            handleBinaryExpression(node);
            break;
        case(NODE_SUBPDECLARATION)://Not Used because we deal with functions nad procedures directly
            break;
        case(NODE_ARGUMENTS)://We aslo deal with them directly from calls
            break;
        case(NODE_ARGUMENT)://Also handled somewhere else
            break;
        case(NODE_STATEMENT_LIST):
#ifdef DEBUG
            printf("NOW WORKING WITH STATEMENT LIST !\n\n");
#endif 
            loopThroughAllChildren(node);
            break;
        case(NODE_STATEMENT)://Not even in the yacc file. Completeley useless
            break;
        case(NODE_VARREF):
            /** TODO not su sur of this because var references can occur on the left side and right side of an assignment  */
            /** and both cases merit different treatment */
            handleVarReferences(node);
            break;//This can also be used to reference an array
        case(NODE_ARR_SUFFIXES)://Handled somewhere else
            break;//Could be 0 or many
        case(NODE_FUNC_CALL)://Its in procedure_statement inside the yacc file 
            handleMethodCall(node);
            break;
        case(NODE_IN_STATEMENT_CALL)://Not actually a procedure call. but any call in statement  this could be both function and procedure
            handleMethodCall(node);//Expressions can be handled through this switch
            break;//Its in procedure_statement inside the yacc file 
        case(NODE_EXPR_LIST):
            loopThroughAllChildren(node);
            break;
        case(NODE_EXPR)://Remvoed from yacc file. No node like this will ever exist
            break;
        case(NODE_ASSIGN_OP):
            handleAssignOp(node);
            break;
        case(NODE_IF_ELSE):
            //Since homework doesnt really talk about this much i will just do expression
            //and statement checking on them
            loopThroughAllChildren(node);
            break;
        case(NODE_WHILE):
            loopThroughAllChildren(node);//same as with if nodes
            break;
        case(NODE_UNARY_NOT_OP)://NOT using this anymore.(Deprecated)
            break;
        case(NODE_UNARY_EXPR):
            handleUnaryExpr(node);
            break;
        case(NODE_STMNT)://This is just when a statment is empty so nothing to do with it really
            break;
        case(NODE_TYPE_INT)://Handled somewhere else
            break;
        case(NODE_TYPE_REAL)://Handled somewhere else
            break;
        case(NODE_TYPE_STRINGCONST)://Handled somewhere else
            break;
        case(NODE_TYPE_ARR)://Handled somewhere else
            break;
        case(NODE_FUNCTION):
            handleFunction(node);
            printf("Yes? nothing \n");
            break;
        case(NODE_PROCEDURE):
            handleProcedure(node);
            break;
        case(NODE_ID)://Somce this is just an non-terminal extension of a terminal then no need to process it
            break;
        case(NODE_NUM):
            handleNumTerminal(node);
            break;
        default:
            printf("One nodes is not being treated Properly\n");
            break;
    }
}
Attributes * createNewAttrib(){
    Attributes * attr = (Attributes*) malloc(sizeof(Attributes));
    attr->nameType = TYPE_UNFILLED;
    attr->nameClass = CLASS_UNFILLED;
    attr->nameClass = CLASS_UNFILLED;

    attr->lowerBoundArray = 0;
    attr->upperBoundArray = 0;
    attr->arrDimension = 0;

    attr->isParam = false;
    attr->hasBeenInitialized = false;
    attr->hasConcreteValue=false;

//    attr->isInitialized = NULL;//This is the one for array entries i believe

    attr->methodSignature=NULL;
    attr->boundsArray = NULL;
    //Code Generation
    attr->addressInStack = 0;
    attr->isStatic = false;

    attr->sizeInBytes = 0;
    return attr;
}
void handleFunction(Node * node){
    //Open Scope here
    Node * idNode = getNthChild(node,1); //Id, We leave this outside because id of the func belongs in the outer scope(i think ;})
    Node * typeNode = getNthChild(node,3); //Id, We leave this outside because id of the func belongs in the outer scope(i think ;})
    //Put it into the symbolTable
    Attributes * attr = createNewAttrib();
    attr->nameType = getTypeForSymTab(typeNode->type);
    attr->nameClass = CLASS_FUNCTION;

    SymbolTableEntry* funcentry = addSymbol(symbolTable,idNode->stringVal,attr);
    if(funcentry==NULL){
        fprintf(stdout, "Semantic Error: Redeclaration on Function %s at depth %d\n\
                We will proceed by deleting this new name from the table and leaving the old one.\n\
                Furthermore, although the function name is not being added to the table we will do semantic check\n\
                on its body to catch as many errors as possible.\n",idNode->stringVal,symbolTable->curDepth);
    }else{
        printf("NOTICE: We have added function \"%s\" in line %d to symbol table. At depth %d \n",idNode->stringVal,node->lineInCode,symbolTable->curDepth);
    }

    openScope(symbolTable,funcentry);//OPENING SCOPE
        /** semanticCheck(getNthChild(node,2)); // Arguments */
        MethodSignature * methodSignature = handleParameters(getNthChild(node,2),getTypeForSymTab(typeNode->type));//Send arguments nod
        if(funcentry!=NULL)
            attr->methodSignature = methodSignature;
        else{
                //We must clear the parameters
            MethodParameter * currIt = methodSignature->paramArrayHead;
            MethodParameter * next;
            while(currIt != NULL){
                next = currIt->nextParam;
                free(currIt);
                currIt = next;
            }
            free(methodSignature);
        }
        /** semanticCheck(getNthChild(node,2)); // stdtype */

        semanticCheck(getNthChild(node,3)); //declarations var declarations
        semanticCheck(getNthChild(node,4)); //submprogramDeclarations stuff like other funcs
        semanticCheck(getNthChild(node,5)); //compoundStatement
        semanticCheck(getNthChild(node,6)); //compoundStatement
    if(funcentry != NULL){//Was not redeclared
        if(!funcentry->attributes->hasBeenInitialized){
            size_t msgsize = strlen(funcentry->name)+100;
            char msg[msgsize];
            sprintf(msg,"The function \"%s\" has no return value\n",funcentry->name);
            printSemanticError(msg,node->lineInCode);
        }
    }
    closeScope(symbolTable,funcentry,node,tabIndex);//CLOSING SCOPE
    
}
void handleProcedure(Node * node){
    Node * idNode = getNthChild(node,1); //Id, We leave this outside because id of the func belongs in the outer scope(i think ;})
    Node * typeNode = getNthChild(node,3); //Id, We leave this outside because id of the func belongs in the outer scope(i think ;})
    //Put it into the symbolTable
    Attributes * attr = createNewAttrib();
    attr->nameType = getTypeForSymTab(typeNode->type);
    attr->nameClass = CLASS_PROCEDURE;

    SymbolTableEntry* entry = addSymbol(symbolTable,idNode->stringVal,attr);
    if(entry==NULL){
        fprintf(stdout, "Semantic Error: Redeclaration on Procedure %s at depth %d\n\
                We will proceed by deleting this new name from the table and leaving the old one.\n",idNode->stringVal,symbolTable->curDepth);
    }else{
        printf("NOTICE: We have added procedure \"%s\" in line %d to symbol table. At depth %d \n",idNode->stringVal,node->lineInCode,symbolTable->curDepth);
    }
    /*semanticCheck(getNthChild(node,1)); //Id, We leave this outside because id of the func belongs in the outer scope(i think ;})*/
    openScope(symbolTable,entry);
        MethodSignature * methodSignature = handleParameters(getNthChild(node,2),TYPE_VOID);//Send arguments nod
        /*semanticCheck(getNthChild(node,2)); // Arguments*/
        if(entry!=NULL)
            attr->methodSignature = methodSignature;
        else{
            //We must clear the parameters
            MethodParameter * currIt = methodSignature->paramArrayHead;
            MethodParameter * next;
            while(currIt != NULL){
                next = currIt->nextParam;
                free(currIt);
                currIt = next;
            }
            free(methodSignature);
        }
        /** semanticCheck(getNthChild(node,1)); // stdtype *///No type for this one

        semanticCheck(getNthChild(node,3)); //declarations var declarations
        semanticCheck(getNthChild(node,4)); //submprogramDeclarations stuff like other funcs
        semanticCheck(getNthChild(node,5)); //compoundStatement
    closeScope(symbolTable,entry,node,tabIndex);
}
size_t countChildren(Node * parNode){
    size_t counter = 0;
    Node * childIterator = parNode->lMostChild;
    while(childIterator!=NULL){
        counter++;
        childIterator = childIterator->rSibling;
    }
    return counter;
}
MethodSignature* handleParameters(Node * argumentsNode,NAME_TYPE nameType){
    //Should share similarities with vairable declarations
    //Add Symbols to table
    //If type declarations were allowed then we would do them here.
    //SUPER TODO check if no argument
    MethodSignature * methSignature = (MethodSignature*) malloc(sizeof(MethodSignature));//TODO CLEANUP
    methSignature->amountOfParams = 0;
    methSignature->returnType = nameType;
    methSignature->paramArrayHead = NULL;//By default no params, will chagne later

    Node * singArgumentNode  = argumentsNode->rMostChild;
    MethodParameter** currIt = &methSignature->paramArrayHead;
    MethodParameter* newParam = NULL;
    MethodParameter* oldParam = NULL;
    //Start adding them to the symbol table and to the meth signature
    while(singArgumentNode !=NULL){//I think ARUGMENS should have no children if no params were found
        //Order of this should be okay.
        handleVarDeclaration(singArgumentNode,true);//Since scope was opened then dump all the arguments to the new symbol table
        //Iterate through every Argument node which includes a list of identifiers
        //with ids
        //Before adding stuff to symbol table we must record the parameters in the
        //signature
        //TODO check if its actually considering empty arguments
        //We should add this to the symbol table in the new scope.
        Node * idList = getNthChild(singArgumentNode,1);
        Node * typeForList = getNthChild(singArgumentNode,2);
        Node * singleId = getNthChild(idList,1);

        singleId = getNthChild(getNthChild(singArgumentNode,1),1);
        size_t paramDimen = countChildren(typeForList);
        /** printf("THESE PAREMETERS HAVE %lu dimensions\n",paramDimen);  */

        //SUPER TODO handle how to store array parameters in method signature
        for(int i = 0;singleId!=NULL;i++){//Two types of loops for basically the same operation huh luis. What a way to stay consistent
            methSignature->amountOfParams++;
            //Check if there are argumetns
            newParam = (MethodParameter* )malloc(sizeof(MethodParameter));//TODO CLEANUP
            newParam->nextParam=NULL;//Just fill default value
            newParam->nameOfParam = singleId->stringVal;//TODO consider copying this, same old AST persistency yada yada
            /** printf("\t\tTHIS IS THE VALUE %s\n",singleId->stringVal); */
            newParam->typeOfParam = getTypeForSymTab(typeForList->type);
            newParam->parDimensions = paramDimen;
            /** printf("New param type : %s\n",NameTypeStr[newParam->typeOfParam]); */
            if(*currIt == NULL){//FIrst argument
                methSignature->paramArrayHead = newParam;
            }else{
                oldParam->nextParam = newParam;
            }
            //
            singleId = singleId->rSibling;
            oldParam = newParam;
        }
        //Just call this as if they were variables TODO try to see if  you cans set a flag
        //that indicates they are parameters
        singArgumentNode = singArgumentNode->lSibling;//EXPERIMENTAL
    }
    return methSignature;
}

void handleVarDeclaration(Node * node, bool isParam){
    //Add Symbols to table
    //If type declarations were allowed then we would do them here.
    Node * idList = getNthChild(node,1);
    Node * typeForList = getNthChild(node,2);
    /** Node * singleId = getNthChild(idList,1); */
    Node* singleId = idList->lMostChild;

    /** for(int i = 0;singleId!=NULL;i++){ */
    while(singleId!=NULL){
        Attributes * attr = createNewAttrib();
        //Deal with the case that it is an array
        int arrayDimCounter = 0;
        Node* arrDimIterator = typeForList->lMostChild;
        if(isParam)
            attr->hasBeenInitialized=true;//If this is parameter we can assume it has been initialized by the caller
        if(arrDimIterator != NULL){//This means we are dealing with an array
            //Count the dimensions
            while(arrDimIterator!=NULL){
                arrayDimCounter++;
                arrDimIterator=arrDimIterator->rSibling;
            }
#ifdef DEBUG
            printf("ARRAY DIMENSIONS : %d\n",arrayDimCounter);
#endif
            //Now alllocate for that amount
            //Since we store arrays subscripts as children of type then this means this is an array
            attr->boundsArray = (int*) malloc(sizeof(int)*arrayDimCounter*2);
            attr->arrDimension = arrayDimCounter;
            arrDimIterator=typeForList->lMostChild;
            int index = attr->arrDimension*2-1;
            size_t totAmonutOfElements = 1;

            Node* lbNode; Node* ubNode;
            while(arrDimIterator!=NULL){
                lbNode = getNthChild(arrDimIterator,1);
                ubNode = getNthChild(arrDimIterator,2);
                semanticCheck(lbNode);//Get their values
                semanticCheck(ubNode);//Get theri values
                arrDimIterator->lowerBound= lbNode->doubleVal;
                arrDimIterator->upperBound= ubNode->doubleVal;
                if(ubNode->nodeStdType == TYPE_REAL)
                    printSemanticError("Using Real as index for array.Will round down to continue with semantic check.",typeForList->lineInCode);
                attr->boundsArray[index] = (int)(arrDimIterator->upperBound);
                if(ubNode->nodeStdType == TYPE_REAL)
                    printSemanticError("Using Real as index for array.Will round down to continue with semantic check.",typeForList->lineInCode);
                attr->boundsArray[index-1] = (int)arrDimIterator->lowerBound;

                if(arrDimIterator->upperBound < arrDimIterator->lowerBound){
                    printSemanticError("Upperbound is less then lowerbound in array declaration.\
                            This error is FATAL. Semantic check will inverse the bounds to continue\
                            looking for other errors but this *NEEDS* to be fixed by the mini-pascal programmer.",
                            typeForList->lineInCode);
                    attr->boundsArray[index] = (int)(arrDimIterator->lowerBound);
                    attr->boundsArray[index-1] = (int)arrDimIterator->upperBound;
                }
                totAmonutOfElements = totAmonutOfElements*(attr->boundsArray[index] - attr->boundsArray[index-1] + 1);//That one is because in pacal [1..10] means you can acces both 1 and 10
                index = index-2;
                arrDimIterator=arrDimIterator->rSibling;
            }
#ifdef DEBUG
            printf("Total amount of elements in this array is : %lu\n",totAmonutOfElements);
#endif
            //Allocate teh array of initializations
            /** attr->isInitialized = (bool*) malloc(sizeof(bool)*totAmonutOfElements); */
            /** for(size_t i = 0;i<totAmonutOfElements;i++) */
                /** attr->isInitialized[0]=false; */
            //Purely for debuggin purposes
            /** for(int i = 0;i<attr->arrDimension*2;i=i+2){ */
            /**     printf("Lower and upper bounds %d %d\n",attr->boundsArray[i],attr->boundsArray[i+1]); */
            /** } */
        }
        //Done with array checking

        attr->nameType = getTypeForSymTab(typeForList->type);
        //SUPER TODO if this type is array then collects its dimension and ranges
        //Since this function only handles variables we know the class is variable:
        attr->nameClass = CLASS_VAR;

        //ATr completed now we add if there is no redeclaration. If there is redeclaration
        //addSymbol will free the attriutes along with the entry that it wouldve created
        SymbolTableEntry* entry =addSymbol(symbolTable,singleId->stringVal,attr);
        if(entry==NULL){
            fprintf(stdout, "Semantic Error: Redeclaration on Variable %s at depth %d\n\
            We will proceed by deleting this new name from the table and leaving the old one.\n",singleId->stringVal,symbolTable->curDepth);
        }else{
            printf("NOTICE: We have added variable \"%s\" in line %d to symbol table. At depth %d \n",singleId->stringVal,node->lineInCode,symbolTable->curDepth);
        }
        singleId = singleId->rSibling;
    }
}
NAME_TYPE getTypeForSymTab(NodeType type){
        switch(type){//This can be int real string or Array
            case(NODE_TYPE_INT):
                return TYPE_INT;
                break;
            case(NODE_TYPE_REAL):
                return TYPE_REAL;
                break;
            case(NODE_TYPE_STRINGCONST):
                return TYPE_CONST_STRING;//Sorry for bad naming
                break;
            case(NODE_TYPE_ARR)://SUPER TODO add limits here and dimensions as well
                return TYPE_ARRAY;//Sorry for bad naming
                break;
            case(NODE_TYPE_PROG_ARG):
                return TYPE_VOID;
                break;
        }
        return TYPE_VOID;//TODO check this is correct im just doing it on they fly
}
bool checkIfArrRefIllegal(SymbolTableEntry* entry, Node * varrefNode){
        Node * tailNode = getNthChild(varrefNode,2);
        //count amount of dereferencing
        Node * tailIt = tailNode->rMostChild;//Thisis a expr but we want to see if it has a concrete value
        int boundsIndex = 0;
        bool wasThereSemanticError = false;
        size_t derefAmount = 0;
#ifdef DEBUG
        printf("Before calling tail iterator dimen %d\n",entry->attributes->arrDimension);
#endif
        while(tailIt!=NULL){//For each pair of square brackets
#ifdef DEBUG
        printf("After calling tail iterator\n");
#endif
            semanticCheck(tailIt);//This is extermely important. Otherwise we wont get the right values for the indices
#ifdef DEBUG
            printf("Bounds index is %d while dims is  %d\n",boundsIndex,entry->attributes->arrDimension*2-1);
#endif
            if(tailIt->nodeStdType == TYPE_REAL){
                printSemanticError("Using real as array index.",varrefNode->lineInCode);
                wasThereSemanticError=true;
                tailIt = tailIt->lSibling;
                continue;
            }
            if(boundsIndex > entry->attributes->arrDimension*2-1){
                printSemanticError("Referencing more dimensions than the array was declared with.",varrefNode->lineInCode);
                wasThereSemanticError=true;
                break;
            }
            if(tailIt->hasConcreteValue){//TODO check if its real
                derefAmount++;
#ifdef DEBUG
                printf("Comparing : (%d,%f,%d)\n",entry->attributes->boundsArray[boundsIndex] , tailIt->doubleVal, entry->attributes->boundsArray[boundsIndex+1]);
#endif
                if(!(entry->attributes->boundsArray[boundsIndex] <= tailIt->doubleVal && (int)tailIt->doubleVal <= entry->attributes->boundsArray[boundsIndex+1])){
                    printSemanticError("Array out of bounds\n",varrefNode->lineInCode);
                    wasThereSemanticError=true;
                }
                /** printf("This what they are using to access the array%f\n",tailIt->doubleVal); */
            } 
            tailIt = tailIt->lSibling;
            boundsIndex = boundsIndex+2;
        }
#ifdef DEBUG
        printf("Deref amount %lu\n",derefAmount);
#endif
        varrefNode->derefLevel = entry->attributes->arrDimension-derefAmount;
        return wasThereSemanticError;
}
void handleLHSVarRef(Node* varrefNode){
    //Since it is a an LVALUE we dont care if it has been initialized. But we do set it as initialized.
    //Check if its array. If so we must check that it is not out of bounds 
    //If not oout of bounds then we check how many dereferences we make(via pair of
    //square brackets. And add this information to the var node so the assign op can
    //handle whether it matcheos. 
    //You cannot treat a var like an array but you can treat an arraly like a var
    Node * idNode = getNthChild(varrefNode,1);
    SymbolTableEntry* entry = retrieveSymbol(symbolTable,idNode->stringVal);
    bool wasThereSemanticError = false;
    //dont know if the RHS is copatible or not
    if(entry->attributes->nameClass == CLASS_FUNCTION){
        //We are going to check if this LHS can be the return value of a function we are
        //nested on.
        bool isReturnValueForFunc = false;
        SymbolTableEntry* nestStackIterator = symbolTable->scopeMethodStackTop;//We begin at top of stack. i.e. innermost func
        while(nestStackIterator!=NULL){
            if(cmpInsensitive(idNode->stringVal,nestStackIterator->name) == true){
                isReturnValueForFunc = true;
                break;
            }
            nestStackIterator = nestStackIterator->nextInScopeStack;
        }
        if(!isReturnValueForFunc){
            size_t msgsize = strlen(idNode->stringVal)+100;
            char msg[msgsize];
            sprintf(msg,"The name %s is for a function outside this scope and thus cannot be set as LHS .",idNode->stringVal);
            printSemanticError(msg,varrefNode->lineInCode);
            wasThereSemanticError = true;
        }
    }else if(entry->attributes->nameClass != CLASS_VAR){//If identifier on lhs is not a variable
        //TODO we have to find a way to let the function we are in through.
        wasThereSemanticError = true;
        size_t msgsize = strlen(entry->name)+100;
        char msg[msgsize];
        sprintf(msg,"LHS identifier \"%s\" is NOT a variable\n",entry->name);
        printSemanticError(msg,varrefNode->lineInCode);
    }else{
        if(entry->attributes->arrDimension > 0){
            wasThereSemanticError = checkIfArrRefIllegal(entry,varrefNode);
        }else{//This means this a normal variable
            //This is not an array
            varrefNode->derefLevel=0;//Non-arrays should always have that
        }
    }
    //Handle initialization:
    //TODO handle the statement below. Make sure its compatible
    //If all goes well we call this Remember that in assign op you check both
    //native type and dereference amount
    if(wasThereSemanticError)
        varrefNode->nodeStdType = TYPE_ERR;
    else
        varrefNode->nodeStdType = entry->attributes->nameType;
}
int checkArguments(SymbolTableEntry* methodEntry,Node * idNode,Node* exprNode){//If int = -1 then thre was an error. By method we mean either procedure or function
    //CHeck if the arguments are legal
    //Get the Signature of the function
    //Assuming we got the right signature here. If we are doing overlaoding then we
    //implement so above.
    MethodSignature * methodSignature  = methodEntry->attributes->methodSignature;//We assume this signature is correct
    size_t amountOfParams = methodSignature->amountOfParams;
    //Lets cound amount of expressions
    size_t amountofArgs = 0;

    Node * expressionIt;
    if(exprNode !=NULL)//If this expression is NULL. Meaning there are no arguents
        expressionIt = exprNode->lMostChild;
    else
        expressionIt=NULL;

    MethodParameter * methParam = methodSignature->paramArrayHead;
    int returnState = 0;
    while(expressionIt!=NULL){//Loop through arguments, In funciton calls arguments can only be separated by comma
        amountofArgs++;
        if(amountOfParams<amountofArgs){
            int msgSize = strlen(idNode->stringVal)+100;
            char msg[msgSize];
            sprintf(msg,"Too many arguments passed for the method %s.",idNode->stringVal);
            printSemanticError(msg,idNode->lineInCode);
            returnState =-1;
            break;
        }
        //This order is correct
        semanticCheck(expressionIt);
        //Check fo rdimension compatibility
        if((size_t)expressionIt->derefLevel != methParam->parDimensions){//TODO get amount size of parameter if parameter is array 
            printSemanticError("Incompatible array size between argument and parameter.",idNode->lineInCode);
            returnState =-1;
        }
#ifdef DEBUG
        printf("Comparing Argument and Param Types %s and %s\n",NameTypeStr[expressionIt->nodeStdType],NameTypeStr[methParam->typeOfParam]);
#endif
        //Check for type compatibility
        if(expressionIt->nodeStdType != methParam->typeOfParam){
            printSemanticError("Incompatible type between Argument and Parameter.",idNode->lineInCode);
            returnState =-1;
        }
        /** printf("EXpresison aint null\n"); */
        /** printf("This is the value %f\n",expressionIt->doubleVal); */
        expressionIt= expressionIt->rSibling;
        methParam = methParam->nextParam;
    }
    if(amountOfParams>amountofArgs){
        //Mismatch between amount of args and params
        int msgSize = strlen(idNode->stringVal)+100;
        char msg[msgSize];
        sprintf(msg,"Amount of Arguments passed in call for method %s are insufficient.",idNode->stringVal);
        printSemanticError(msg,idNode->lineInCode);
        returnState =-1;
    }
    return returnState;
}
void handleRHSVarRef(Node* varrefNode){//By the time this is called its because there is an entry for it in the symbol table
    //This can also be detected as function. WRONG. THIS CAN BE A FUNCTION
    //Check if declared
    Node * idNode = getNthChild(varrefNode,1);
    SymbolTableEntry* entry = retrieveSymbol(symbolTable,idNode->stringVal);
    bool wasThereSemanticError = false;
    if(entry->attributes->nameClass == CLASS_FUNCTION){//This is when the function has no vars
        //Check if the function exists
        if(checkArguments(entry,idNode,NULL)==-1){
            varrefNode->nodeStdType=TYPE_ERR;
        }else{
            //Correct Call of argument
            varrefNode->nodeStdType = entry->attributes->nameType;
        }
    }else if(entry->attributes->nameClass == CLASS_VAR){//If this is indeed a var
        //If it is actually declared
        printf("Entry %s depth %d and curdepth is %d\n",entry->name,entry->entryDepth,symbolTable->curDepth);
        if(entry->attributes->hasBeenInitialized || entry->entryDepth < symbolTable->curDepth){
            if(entry->attributes->arrDimension > 0){//IF it is an aarray
                //If we can initialize it succesfully
                wasThereSemanticError = checkIfArrRefIllegal(entry,varrefNode); 
            }else{//This is a variable
                varrefNode->derefLevel = 0;
                if(entry->attributes->hasConcreteValue){
                    if(entry->attributes->nameType == TYPE_INT || entry->attributes->nameType == TYPE_REAL){
                        varrefNode->hasConcreteValue = true;
                        varrefNode->doubleVal = entry->attributes->doubleVal;
                    }else if(entry->attributes->nameType == TYPE_CONST_STRING){
                        varrefNode->hasConcreteValue = true;
                        varrefNode->stringVal = entry->attributes->strPtr;
                    }
                }
                wasThereSemanticError = false;
            }
        }else{//Not initialized
            wasThereSemanticError = true;
            char errmsg[150];
            sprintf(errmsg,"Use of RHS variable with name:%s that has not been initialized",idNode->stringVal);
            printSemanticError(errmsg,varrefNode->lineInCode);
        }
        //CODEGEN: Add type on varref
        varrefNode->nodeStdType = entry->attributes->nameType;
    }else{
        size_t msgsize = strlen(entry->name)+200;
        char msg[msgsize];
        sprintf(msg,"A non-variable %s or a non-funcition was called on RHS.(Probably Procedure on RHS)",entry->name);
        printSemanticError(msg,varrefNode->lineInCode); 
        wasThereSemanticError = true;
    }
    if(wasThereSemanticError)
        varrefNode->nodeStdType = TYPE_ERR;
    else
        varrefNode->nodeStdType = entry->attributes->nameType;
    //Since we could be called above by an expression or a sum or operation we need to set
    //a type to this node
}
void handleVarReferences(Node* varrefNode){

    Node * idNode = getNthChild(varrefNode,1);
    SymbolTableEntry* entry = retrieveSymbol(symbolTable,idNode->stringVal);
    if(entry == NULL){
    //TODO We should check if var and function are the same. If their types are also the
    //same tan that means tha variable is declared
        //THen it has not been decalred
        char errmsg[150];
        sprintf(errmsg,"Undeclared Variable %s",idNode->stringVal);
        printSemanticError(errmsg,varrefNode->lineInCode);
        varrefNode->nodeStdType = TYPE_ERR;
        varrefNode->hasConcreteValue = false;
    }else{
        //Contains two children id and tail
        if(varrefNode->assignPos == POS_LHS){
            handleLHSVarRef(varrefNode); 
        }else if(varrefNode->assignPos == POS_RHS){
            handleRHSVarRef(varrefNode); 
        }else{
            printf("This should not be happening\n");
        }
    }
}
void loopThroughAllChildren(Node* node){
    int i = 1;
    while(getNthChild(node,i) != NULL){//Just loop through declarations
        printf("\n\n");
        semanticCheck(getNthChild(node,i));//decls,subpdcls,compound_statement
        /** printf("Finished Semantic Check for one of them with i=%d\n",i); */
        i++;
    }
}
void handleAssignOp(Node * assignNode){
    Node * varNode = getNthChild(assignNode,1);
    Node * rhs = getNthChild(assignNode,2);
    semanticCheck(varNode);//Evaluate the LHS name if its declared or not and what type is it
    semanticCheck(rhs);//Evaluate the expression
    /** printf("Inside assignop with var of type %s and RHS of type %s\n",NameTypeStr[varNode->nodeStdType],NameTypeStr[rhs->nodeStdType]); */
    //Once the expression is evaluated we can decide wheter the both sides share type
    if(varNode->nodeStdType == TYPE_ERR ||
        rhs->nodeStdType == TYPE_ERR){
        //Noassignmetn or anything just stkip it
    }else if(varNode->nodeStdType != rhs->nodeStdType ){
        char msg[150];
        sprintf(msg,"Incompatible LHS and RHS Types for assignment(%s=%s).",NameTypeStr[varNode->nodeStdType],NameTypeStr[rhs->nodeStdType]);
        printSemanticError(msg,assignNode->lineInCode);
    }else if(varNode->derefLevel != rhs->derefLevel){//TODO check for deref dimensions as well not just type. Maybe a bit more sophisticated??
        printSemanticError("Incompatible LHS and RHS Array Sizes for assignment.",assignNode->lineInCode);
    }else{//If assign operations is valid then we can say that this variable has been initialized
        SymbolTableEntry* varEntry = retrieveSymbol(symbolTable,varNode->lMostChild->stringVal);
        varEntry->attributes->hasBeenInitialized = true;
        if(rhs->hasConcreteValue){//THen just copy the value to the var
            varEntry->attributes->hasConcreteValue=true;
            //TODO make space for string
            if(varEntry->attributes->nameType==TYPE_INT || varEntry->attributes->nameType==TYPE_REAL)
                varEntry->attributes->doubleVal=rhs->doubleVal;
            else
                varEntry->attributes->strPtr=rhs->stringVal;
        }
        printf("NOTICE at around Line(%d): The var \"%s\" is now initialized \n",varNode->lineInCode,varNode->lMostChild->stringVal);
    }
}
void handleBinaryExpression(Node * binaryExpNode){
    Node * subexp1 = getNthChild(binaryExpNode,1);
    Node * subexp2 = getNthChild(binaryExpNode,2);
    /** printf("Handling Binary expression between : %s and %s, Initial type is %s\n",EnumNameRef[subexp1->type],EnumNameRef[subexp2->type],NameTypeStr[binaryExpNode->nodeStdType]); */
    semanticCheck(subexp1);
    semanticCheck(subexp2);
    if(subexp1->derefLevel != 0 || subexp2->derefLevel!=0 ){
        printSemanticError("Trying to perform a binary operation(Arithmetic, Relational, or Logical) on an array. This is illegal.",binaryExpNode->lineInCode);
        binaryExpNode->nodeStdType=TYPE_ERR;
    }else{
        /** printf("\tResulting types of subexp1: %s and subexp2:%s\n",NameTypeStr[subexp1->nodeStdType],NameTypeStr[subexp2->nodeStdType]); */
        //Deal with arithmetic Operations
        if(binaryExpNode->operation == NODE_OP_ADD ||
                binaryExpNode->operation == NODE_OP_SUBTRACT ||
                binaryExpNode->operation == NODE_OP_MULT ||
                binaryExpNode->operation == NODE_OP_DIV){//Then we are dealing with arithmetic operations where we can have either a real or a num at either side but not both
            if((subexp1->nodeStdType == TYPE_INT && subexp2->nodeStdType==TYPE_INT)
                    || (subexp1->nodeStdType == TYPE_REAL && subexp2->nodeStdType==TYPE_REAL)
              ){
                if(subexp1->nodeStdType == TYPE_INT && subexp2->nodeStdType==TYPE_INT)
                    binaryExpNode->nodeStdType = TYPE_INT;
                if(subexp1->nodeStdType == TYPE_REAL && subexp2->nodeStdType==TYPE_REAL)
                    binaryExpNode->nodeStdType = TYPE_REAL;
                //Now handle Concrete Values
                if(subexp1->hasConcreteValue == true && subexp2->hasConcreteValue==true){
                    //Then so will the binary exp.
                    switch(binaryExpNode->operation){
                        case(NODE_OP_ADD):
                            binaryExpNode->doubleVal = subexp1->doubleVal+subexp2->doubleVal;
                            break;
                        case(NODE_OP_SUBTRACT):
                            binaryExpNode->doubleVal = subexp1->doubleVal-subexp2->doubleVal;
                            break;
                        case(NODE_OP_MULT):
                            binaryExpNode->doubleVal = subexp1->doubleVal*subexp2->doubleVal;
                            break;
                        case(NODE_OP_DIV):
                            binaryExpNode->doubleVal = subexp1->doubleVal/subexp2->doubleVal;
                            break;
                    }
                    binaryExpNode->hasConcreteValue=true;
                }else{
                    binaryExpNode->hasConcreteValue=false;
                }
            }else{
                binaryExpNode->nodeStdType = TYPE_ERR;//Using these we can keep parsing
                binaryExpNode->hasConcreteValue = false;
                if(!(subexp1->nodeStdType==TYPE_ERR || subexp2->nodeStdType==TYPE_ERR))
                    printSemanticError("Arithmetic Operation on Incompatible Types",binaryExpNode->lineInCode);
            }
        }
        if(binaryExpNode->operation == NODE_OP_LESSTHAN ||
                binaryExpNode->operation == NODE_OP_GREATERTHAN ||
                binaryExpNode->operation == NODE_OP_EQUALS ||
                binaryExpNode->operation == NODE_OP_LESSTHANEQ ||
                binaryExpNode->operation == NODE_OP_GREATERTHANEQ ||
                binaryExpNode->operation == NODE_OP_NEQUALS)
        {
            if((subexp1->nodeStdType == TYPE_INT && subexp2->nodeStdType==TYPE_INT) ||
                    (subexp1->nodeStdType == TYPE_REAL && subexp2->nodeStdType==TYPE_REAL)
              ){//By design im setting the result of these oeprations to integer
                if(subexp1->nodeStdType == TYPE_INT && subexp2->nodeStdType==TYPE_INT){
                    binaryExpNode->nodeStdType = TYPE_INT;
                }else{
                    binaryExpNode->nodeStdType = TYPE_INT;
                }//TODO i dont think we need to do synthesis here.
                binaryExpNode->hasConcreteValue=false;
                //THen its good lol
            }else{//"For relative operations, you only need to handle the situation between integer and real values in this project."
                binaryExpNode->nodeStdType = TYPE_ERR;//Using these we can keep parsing
                binaryExpNode->hasConcreteValue=false;
                printSemanticError("Relative Operation on Incompatible Types",binaryExpNode->lineInCode);
            }
        }
        if(binaryExpNode->operation == NODE_OP_AND ||
                binaryExpNode->operation == NODE_OP_OR)
        {
            if((subexp1->nodeStdType == TYPE_INT && subexp2->nodeStdType==TYPE_INT) ||
                    (subexp1->nodeStdType == TYPE_REAL && subexp2->nodeStdType==TYPE_REAL)
              ){
                binaryExpNode->nodeStdType = TYPE_INT;
                binaryExpNode->hasConcreteValue=false;
            }else{
                binaryExpNode->nodeStdType = TYPE_ERR;//Using these we can keep parsing
                printSemanticError("Logical Operation on Incompatible Types",binaryExpNode->lineInCode);
            }
        }
    }
    /** printf("The resulting binaryExp with id %lu is of type%s\n",binaryExpNode->id,NameTypeStr[binaryExpNode->nodeStdType]); */
}
void handleNumTerminal(Node * num){
    //TODO For now just do this lol  
    num->hasConcreteValue=true;
    /** if(isThisAReal(num->doubleVal)) */
    /**     num->nodeStdType= TYPE_REAL; */
    /** else */
    /**     num->nodeStdType= TYPE_INT; */
}
void handleMethodCall(Node* funcNode){
    //TODO return a type for this node 
    //First Child is id, Second Child is expression list(arguments)
    //Func Call Node Children :
    //  1:ID
    Node * idNode = getNthChild(funcNode,1);
    //  2:expresion list(arguments)
    Node * expressionList = getNthChild(funcNode,2);//This expression list should be handled by the already declared stuff for expressio 
    //Check if the function exists
    //check if its print 
    if(!(strcmp(idNode->stringVal,"printlnString") == 0 ||
         strcmp(idNode->stringVal,"printInt") == 0 || 
         strcmp(idNode->stringVal,"printReal") == 0 ||
         strcmp(idNode->stringVal,"printString") == 0 
      )){
        SymbolTableEntry* funcEntry = retrieveSymbol(symbolTable,idNode->stringVal);
        if(funcEntry!=NULL){//If this symbols name does exist in the table
            if(checkArguments(funcEntry,idNode,expressionList)==-1){
                funcNode->nodeStdType=TYPE_ERR;
            }else{
                //Correct Call of argument
                funcNode->nodeStdType = funcEntry->attributes->nameType;
            }
        }else{//This function name does not exits
            int msgSize = strlen(idNode->stringVal)+100;
            char msg[msgSize];
            sprintf(msg,"Undeclared Function/Procedure \"%s\"",idNode->stringVal);
            printSemanticError(msg,funcNode->lineInCode);
            funcNode->nodeStdType = TYPE_ERR;
        }
    }else{//MEGA TODO might want to restructure this. It is too much of a hack
        //CODEGEN: This is simply to populate the ast nodes of the arguments
        loopThroughAllChildren(expressionList);
    }
}
void handleUnaryExpr(Node * unaryNode){
    Node * subexp = getNthChild(unaryNode,1);
#ifdef DEBUG
    printf("Handling Unary expression between : %s and, Initial type is %s\n",EnumNameRef[subexp->type],NameTypeStr[subexp->nodeStdType]);
#endif
    semanticCheck(getNthChild(unaryNode,1));//AFter this this node should have a concrete value and a type
    //Deal with arithmetic Operations
    switch(unaryNode->uoperation){
        case(NODE_OP_POSSIGN):
            unaryNode->hasConcreteValue=true;
            unaryNode->nodeStdType=subexp->nodeStdType;
            unaryNode->doubleVal=subexp->doubleVal;//Because possign really doesnt do much
            break;
        case(NODE_OP_NEGSIGN):
            unaryNode->hasConcreteValue=true;
            unaryNode->nodeStdType=subexp->nodeStdType;
            unaryNode->doubleVal=-1*subexp->doubleVal;//Because possign really doesnt do much
            break;
        case(NODE_OP_NOT):
            if(subexp->nodeStdType==TYPE_CONST_STRING){
                printSemanticError("Illegal Operation of Negating a String",unaryNode->lineInCode);
                unaryNode->hasConcreteValue=false;
                unaryNode->nodeStdType=TYPE_ERR;
            }else if(subexp->nodeStdType==TYPE_INT||subexp->nodeStdType==TYPE_REAL){//THen it is either int or real
                //Then it is a legal operation
                if(subexp->hasConcreteValue){
                    //THen now so do we 
#ifdef DEBUG
                    printf("Dealing with unary value\n");
#endif
                    unaryNode->hasConcreteValue = true;
                    unaryNode->doubleVal = (subexp->doubleVal!=0)?0:1;
                    unaryNode->nodeStdType = subexp->nodeStdType;
                }else{
                    unaryNode->nodeStdType = subexp->nodeStdType;
                    unaryNode->hasConcreteValue = false;
                }
            }
            break;
    }
}

