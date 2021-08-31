#include  "codegen.h"
#include <stdint.h>
#define LABEL_SIZE 20
#define STACK_BYTE_SIZE 960
#define INT_SIZE 4
#define REAL_SIZE 4

//SymbolTable * symbolTable = NULL;
size_t labelCounter = 0;
size_t constCounter = 4;
SymbolTable* currentSymTab=NULL;//The one that is active right now
FILE* ofile;
//This will coantian the half until the end of the constant pool
//While "ofile" will contian the latest stuff
FILE * oldFile;

int floatToDecRepresentation(float f){
    return *((int *)&f);
}
void generateCode(Node* astrootNode, SymbolTable* symTabArray){
    initializeCodeGen(&ofile);
    //currentSymTab = &symTabArray[0];
    //symbolTable = symTabArray;//Remmeber that this is an array of 100 symbol table
    genVisitor(astrootNode);
    finalizeCodeGen();
}
void genVisitor(Node* node){
    switch(node->type){
        case(NODE_ROOT)://Basically the program
                //Set the global symbolTable
                currentSymTab = node->assocTable;
                emitProgInit(ofile,node,currentSymTab);
                fprintf(ofile,"#Constant Pool:\n");
                //We have emitted the "predule" of sorts of the program. Now we following half is written
                oldFile = ofile;
                ofile = fopen("/tmp/secondHalf.s","w");
                emitStaticDeclarations(ofile,getNthChild(node,3),currentSymTab);//Declarations(Variables)//THis ought to be static variables
                emitMainFunctionPrelude(ofile,node,currentSymTab);//TODO implement it 
                genVisitor(getNthChild(node,5));//Statemnt lists
                emitMainFunctionPostlude(ofile,node,currentSymTab);//TODO implement it 
                genVisitor(getNthChild(node,4));//subp declarations
                //gen_loopThroughAllChildren(node);
            break;
        case(NODE_ID_LIST)://Handled by other functions
            break;
        case(NODE_DECLARATIONS_ROOT):
            //iterator = node->lMostChild;
            //while(iterator!=NULL){//This order is good
            //    semanticCheck(iterator);//decls,subpdcls,compound_statement
            //    iterator = iterator->rSibling;
            //}
            break;
        case(NODE_DECLARATIONS)://This is actually a single declaration typo on my part that im to lazy to fix
            cgHandle_declarations(node);             
            break;//Actually a single declaration
        case(NODE_SUBPDECLARATIONS)://Children can only be Procedures and Functions
            gen_loopThroughAllChildren(node);
            //i = 1;
            //while(getNthChild(node,i) != NULL){//Just loop through declarations
            //    semanticCheck(getNthChild(node,i));//decls,subpdcls,compound_statement
            //    i++;
            //}
            break;
        case(NODE_BINARY_EXPR):
            emitBinaryExpression(ofile, node, currentSymTab);
            break;
        case(NODE_SUBPDECLARATION)://Not Used because we deal with functions nad procedures directly
            break;
        case(NODE_ARGUMENTS)://We aslo deal with them directly from calls
            break;
        case(NODE_ARGUMENT)://Also handled somewhere else
            break;
        case(NODE_STATEMENT_LIST):
            gen_loopThroughAllChildren(node);
            break;
        case(NODE_STATEMENT)://Not even in the yacc file. Completeley useless
            break;
        case(NODE_VARREF):
            /** TODO not su sur of this because var references can occur on the left side and right side of an assignment  */
            /** and both cases merit different treatment */
            //I THINK THIS CAN ONLY OCCUR ON RHS IF PROPERLY HANDLED
            emitRHSVarRef(ofile,node,currentSymTab);
            //cg_varref(node);
            break;//This can also be used to reference an array
        case(NODE_ARR_SUFFIXES)://Handled somewhere else
            break;//Could be 0 or many
        case(NODE_FUNC_CALL)://Its in procedure_statement inside the yacc file 
            //MEGA TODO change symbol table here
            emitRoutineCall(ofile,node, currentSymTab);
            break;
        case(NODE_IN_STATEMENT_CALL)://Not actually a procedure call. but any call in statement  this could be both function and procedure
            //MEGA TODO change symbol table here
            //Put arguments in stack from left to right
            emitRoutineCall(ofile,node, currentSymTab);
            break;//Its in procedure_statement inside the yacc file 
        case(NODE_EXPR_LIST):
            break;
        case(NODE_EXPR)://Remvoed from yacc file. No node like this will ever exist
            break;
        case(NODE_ASSIGN_OP):
            //Handle RHS
            //Handle expression first so stuff is in the stack ready for load
            genVisitor(getNthChild(node,2));
            //Handle LHS
            emitLHSReference(ofile,getNthChild(node,1),currentSymTab);
            //genVisitor(getNthChild(node,1));
            break;
        case(NODE_IF_ELSE):
            //Since homework doesnt really talk about this much i will just do expression
            //and statement checking on them
            cdHandle_Conditional(ofile, node, currentSymTab);
            break;
        case(NODE_WHILE):
            emitWhileLoop(ofile, node, currentSymTab);
            break;
        case(NODE_UNARY_NOT_OP)://NOT using this anymore.(Deprecated)
            break;
        case(NODE_UNARY_EXPR):
            emitUnaryExpression(ofile, node, currentSymTab);
            break;
        case(NODE_STMNT)://This is just when a statment is empty so nothing to do with it really
            break;
        case(NODE_TYPE_INT)://Handled somewhere else
            break;
        case(NODE_TYPE_REAL)://Handled somewhere else
            break;
        case(NODE_TYPE_STRINGCONST)://Handled somewhere else
            printf("Emitting String\n");
            emitConstant(ofile, node, currentSymTab);
            break;
        case(NODE_TYPE_ARR)://Handled somewhere else
            break;
        case(NODE_FUNCTION):
            currentSymTab = node->assocTable;//We get this functions symbolt able this way
            //This means we will process sub declaraitons before the encompassing routine
            genVisitor(getNthChild(node,5)); //SubProgramDeclarations
            emitMethod(ofile,node,currentSymTab);//
            //genVisitor(getNthChild(node,4)); //Declarations (TODO: no need i think)
            emitParametersAlloc(ofile,getNthChild(node,2),currentSymTab);//Offload arguments from registers to local variable stack
            genVisitor(getNthChild(node,6)); //compoundStatement
            emitMethodPostlude(ofile, node, currentSymTab);
            break;
        case(NODE_PROCEDURE):
            //MEGA TODO make something similar to funciton here 
            currentSymTab = node->assocTable;//We get this functions symbolt able this way
            genVisitor(getNthChild(node,4)); //SubProgramDeclarations
            //This means we will process sub declaraitons before the encompassing routine
            emitMethod(ofile,node,currentSymTab);//
            //genVisitor(getNthChild(node,4)); //Declarations (TODO: no need i think)
            emitParametersAlloc(ofile,getNthChild(node,2),currentSymTab);//Offload arguments from registers to local variable stack
            genVisitor(getNthChild(node,5)); //compoundStatement
            emitMethodPostlude(ofile, node, currentSymTab);
            break;
        case(NODE_ID)://Somce this is just an non-terminal extension of a terminal then no need to process it
            break;
        case(NODE_NUM):
            emitConstant(ofile, node, currentSymTab);
            break;
        default:
            printf("One nodes is not being treated Properly\n");
            break;
    }
}
void initializeCodeGen(FILE** file){
    //Initialize Output file
    *file = fopen("/tmp/firstHalf.s","w");
}
void finalizeCodeGen(){
    //Grab both files and join them into a final output file
    FILE * finalFile = fopen("./output.s","w");
    fclose(oldFile);
    fclose(ofile);
    //TOOD I have no idea why i need to close them and re open them. If you have time then fix what my peabrain couldnt
    oldFile = fopen("/tmp/firstHalf.s","r");
    ofile = fopen("/tmp/secondHalf.s","r");

    if(finalizeCodeGen == NULL ||//If any of them present any errors
        oldFile == NULL||
        ofile == NULL
    ){
        fprintf(stderr,"There was en error when concatenating \
generated code files\n");
        exit(EXIT_FAILURE);
    }
    //Else all files should be available and we begin concatenation
    //Might want to set both files back to beggining
    //rewind(oldFile);
    //rewind(ofile);
    int ch;
    while((ch = fgetc(oldFile)) != EOF)
        fputc(ch,finalFile);
    while((ch = fgetc(ofile)) != EOF)
        fputc(ch,finalFile); 
    fclose(finalFile);
    fclose(oldFile);
    fclose(ofile);
}
void emitStaticDeclarations(FILE* file, Node* node, SymbolTable* symTab){
    //This will go thorugh the program variables and emmit them as static variables(using .COMM)
    int declCounter = 1;
    Node* declIt = NULL;
    SymbolTableEntry* symentIt = NULL;
    while((declIt = getNthChild(node,declCounter)) != NULL){//Just loop through declarations
        //ROOT here is DECARATIONS, So we have acces to both id list and type in this looop with declIt
        int idCounter = 1;
        Node* idNodeIt = NULL;
        while((idNodeIt = getNthChild(getNthChild(declIt,1),idCounter))!=NULL){
            //Now try to get their symboltables
            symentIt = retrieveSymbol(symTab,idNodeIt->stringVal);
            symentIt->attributes->isStatic = true;//Set static flag to true
            idCounter++;
            fprintf(file,".comm %s,",symentIt->name);
            printf("Evaluating static %s with type %s\n",symentIt->name,
                NameTypeStr[symentIt->attributes->nameType]);
            switch(symentIt->attributes->nameType){
                case TYPE_INT: case TYPE_REAL://TODO dont really know if real and int have same type though
                    fprintf(file,"4,4\n");//FOur bytes align 4
                break;
                case TYPE_CONST_STRING:
                    //TODO: not sure if right but i think isnce we are using
                    // 640bit architecture then we should use 8 bytes to store 
                    //the address of the string. Since of course we will only store 
                    //the address of the string in a variable and not the actual thing
                    fprintf(file,"8,8\n");//FOur bytes align 4
                break;
                case TYPE_ARRAY://Not sure about this on:
                break;
                case TYPE_VOID://Represents procedure return typ:
                break;
                case TYPE_ERR:
                break;
                case TYPE_UNFILLED://Null Basicall
                break;
            }
        }
        declCounter++;
    }

}
void emitProcedureArguments(FILE* file, Node* pnode, SymbolTable* symTab){
    Node * node = getNthChild(pnode,2);
    //MEGA TODO implement this properly. Im only doing this right now because i dont care about
    //  other function calls.
    int registerCounter = 0;
    Node* childIterator = node->rMostChild;
    while(childIterator != NULL){//Just loop through declarations
        genVisitor(childIterator);//decls,subpdcls,compound_statement
        childIterator=childIterator->lSibling;
    }//By the end of this call all arguments will be put in stack left->right(bottom->up)
    //Now we send them to registers
    if(strcmp(getNthChild(pnode,1)->stringVal,"printInt") == 0){
        fprintf(file,
            "lui a%d,%%hi(.LC0)\n"
            "addi a%d,a%d,%%lo(.LC0)\n"
            ,registerCounter,registerCounter,registerCounter);
        registerCounter++;
    }
    if(strcmp(getNthChild(pnode,1)->stringVal,"printReal") == 0){
        fprintf(file,
            "lui a%d,%%hi(.LC1)\n"
            "addi a%d,a%d,%%lo(.LC1)\n"
            ,registerCounter,registerCounter,registerCounter);
        registerCounter++;
    }
    if(strcmp(getNthChild(pnode,1)->stringVal,"printlnString") == 0){
        fprintf(file,
            "lui a%d,%%hi(.LC2)\n"
            "addi a%d,a%d,%%lo(.LC2)\n"
            ,registerCounter,registerCounter,registerCounter);
        registerCounter++;
    }
    childIterator = node->rMostChild;
    while(childIterator != NULL){//Just loop through declarations
        //At this point TOS should contain the result of the expression
        //Since we dont acrea but doing register targetting we just move them to the regiters here
        //Handle by type
        switch(childIterator->nodeStdType){
            case TYPE_INT:
                printf("\tNot doing this");
                fprintf(file,
                    "lw a%d, 0(s0)\n"
                    "addi s0,s0, -4\n"
                    ,registerCounter);
            break;
            case TYPE_REAL:
                fprintf(file,
                    "#Take Proper Steps to Move float to argument register\n"
                    "flw ft0,0(s0)\n"
                    "addi s0,s0, -4\n"
                    "fcvt.d.s ft0,ft0\n"
                    "fmv.x.d a%d, ft0\n"
                    ,registerCounter);
            break;
            case TYPE_CONST_STRING://TODO make sure you can send strings
                fprintf(file,
                    "lw a%d, 0(s0)\n"
                    "addi s0,s0,-4\n"
                    ,registerCounter);
                break;
            case TYPE_ARRAY://Not sure about this on:
            break;
            case TYPE_VOID://Represents procedure return typ:
            break;
            case TYPE_ERR:
            break;
            case TYPE_UNFILLED://Null Basicall
            break;
            }
            childIterator=childIterator->lSibling;
            registerCounter++;
    }
}
void emitFunction(Node* node){
    //YOu need to write this before any functions:
    const char * funcName = getNthChild(node,1)->stringVal;
   fprintf(ofile,"\
.text\n\
.align 1\n\
.glob1 %s\n\
.type %s, @function\n\
",funcName,funcName);

   fprintf(ofile,"%s\b:",funcName);
   //Now reserve some memory
   fprintf(ofile,"\
addi sp,sp,-1024]n\
sd  ra,1016(sp)\n\
sd  s0,1008(sp)\n\
sd  s1,1000(sp)\n\
addi s0,sp,40 #stack point pointer\n\
addi s1,sp,40 #12 bytes for local variables(each 2 bytes)\n\
");


   //TODO remember to clear the stack 
   fprintf(ofile,"\
ld  ra,1016(sp)\n\
ld  s0,1008(sp)\n\
ld  s1,1000(sp)\n\
addi sp,sp,1024\n\
");
}
void emitProgInit(FILE* file, Node* node,SymbolTable *  currentSymTab){
    fprintf(file,"\
.text\n\
.section .rodata\n\
.align 3\n\
\
.LC0: .string \"%%d\\n\"\n\
.LC1: .string \"%%f\\n\"\n\
.LC2: .string \"%%s\\n\"\n\
.LC3: .word 3212836864#This ought to be -1\n\
\n\
");
}
void emitMainFunctionPrelude(FILE* file, Node* node,SymbolTable *  currentSymTab){
    //TODO: remove the allocation of stack form tehre and use the symbol table for it
    //instead(i.e. dont waste space).
    fprintf(file,"\
.text\n\
.align 1\n\
.globl main\n\
.type main, @function\n\
main:\n\
addi sp,sp,-1024\n\
sd  ra,1016(sp)\n\
sd  s0,1008(sp)\n\
sd  s0,1000(sp)\n\
addi s0,sp, 40\n\
addi s1,sp,0\n\
\n\
");
}
void emitMainFunctionPostlude(FILE* file, Node* node,SymbolTable *  symbolTable){
//TODO make the size of allocation according to 
//With this symbol table we should be able to work
fprintf(file,"\
ld  ra,1016(sp)\n\
ld  s0,1008(sp)\n\
ld  s0,1000(sp)\n\
addi sp,sp,1024\n\
jr ra\n\
.size main, .-main\n\
    # END of main function\n\
");
}
void emitMethod(FILE* file, Node* node, SymbolTable* symTab){
    printf("Entering method oname %s\n",getNthChild(node,1)->stringVal);
    Node * idNode = getNthChild(node,1);
    fprintf(ofile,"\
.text\n\
.align 1\n\
.globl %s\n\
.type %s, @function\n\
%s:\n\
\n",idNode->stringVal,idNode->stringVal,idNode->stringVal);
    size_t offsetCounter = 0;
    //For allocate every local variable
    SymbolTableEntry* localIterator = symTab->scopeDisplay[symTab->curDepth];
    //We do this double while mess so we get the entries in the order they are declared :shrug to my previous design
    while(localIterator != NULL && localIterator->nextInSameScope != NULL)
        localIterator = localIterator->nextInSameScope;
    int offsetCountekr = 0;//This will tell use how far away from stack is the variable
    while(localIterator!=NULL){
        //Might as well clear the initition flag since we'll need it as such later
        localIterator->attributes->hasBeenInitialized = false;//Well i actually dont know if ill need it later, but i wont have and averse effect anyway
        //Now we allocate their space in the stack depending on their type
        printf("Local iterators %s is of type %s\n",localIterator->name,NameTypeStr[localIterator->attributes->nameType]);
        switch(localIterator->attributes->nameType){
            case(TYPE_INT): 
            case(TYPE_REAL)://Allocate 4 bytes
                localIterator->attributes->addressInStack = offsetCounter;
                printf("\tADdress in stack for %s is %d\n",localIterator->name,localIterator->attributes->addressInStack);
                localIterator->attributes->sizeInBytes = 4;
                offsetCounter+=4;
            break;
            case(TYPE_CONST_STRING)://TODO 
            break;
            case(TYPE_ARRAY)://MEGA TODO
            break;
            case(TYPE_VOID)://These three should not be reached 
            break;
            case(TYPE_ERR):
            break;
            case(TYPE_UNFILLED):
            break;
        }
        localIterator = localIterator->prevInSameScope;
    }
    int finStackSize = STACK_BYTE_SIZE + offsetCounter + 4;//Not sure if this is the appropriate number
    fprintf(file,"\
addi sp,sp,-%d\n\
sd ra,%d(sp)\n\
sd s0,%d(sp)\n\
sd s1,%d(sp)\n\
addi s0,sp,%d\n\
addi s1,sp,0\n\
    ",finStackSize,finStackSize-8,finStackSize-16,finStackSize-24,offsetCounter);
    retrieveSymbol(symTab,idNode->stringVal)->attributes->sizeInBytes = finStackSize;
}
void emitParametersAlloc(FILE* file, Node* node, SymbolTable* symTab){
    //node is of type Declarations Root
    Node * declarationsIt = NULL;
    fprintf(file,"\
\t# Start: Offloading argumnets\n\
");
    int argCounter = 0;
    declarationsIt = node->rMostChild;
    //MEGA TODO, consider when there are more arguments then the amount of argument registers
    while(declarationsIt != NULL){//Iterate through declarations
        //First child is ID list, second child is type
        Node * IdList = getNthChild(declarationsIt,1);
        Node * typeNode = getNthChild(declarationsIt,2);
        Node * idIt = NULL;
        size_t idNumIt = 1;
        while((idIt = getNthChild(IdList, idNumIt)) != NULL){//For every Id

            //Since we called emitMethod earlier then our arguments should have already been allocated in stack
            //Now we just send their values 
            SymbolTableEntry * syment = retrieveSymbol(symTab,idIt->stringVal);
            switch(syment->attributes->nameType){
                case TYPE_INT:
                    fprintf(file,
                        "#Offloading %s\n"
                        "sw a%d,%d(s1)\n"
                        ,syment->name,argCounter,syment->attributes->addressInStack);
                break;
                case TYPE_REAL:
                    fprintf(file,
                        "#Offloading %s\n"
                        "fmv.d.x ft0,a%d\n"
                        "fcvt.s.d ft0,ft0#Turn it back to word\n"
                        "fsw ft0,%d(s1)\n"
                        ,syment->name,argCounter,syment->attributes->addressInStack);
                break;
                default:
                printf("Unhandled Case in emitting parameters for a call\n");
                break;
            }

            argCounter++;
            idNumIt++;
        }
        declarationsIt = declarationsIt->lSibling;
    }
    fprintf(file,"\
\t# End: Offloading argumnets\n\
");

}
void emitMethodPostlude(FILE* file, Node* node, SymbolTable* symTab){
    Node * idNode = getNthChild(node,1);
    //Get Sytmtab
    SymbolTableEntry * syment = retrieveSymbol(symTab,idNode->stringVal);
    //printf("Got symbol table entry for func %s with stack size %d\n",syment->name,syment->attributes->sizeInBytes);
    size_t stackSize = syment->attributes->sizeInBytes;
    //Clean the Stack Before returning
    fprintf(file,"\
ld ra,%d(sp)\n\
ld s0,%d(sp)\n\
ld s1,%d(sp)\n\
addi sp,sp,%d\n\
jr ra\n\
.size %s, .-%s\n\
",stackSize-8,stackSize-16,stackSize-24,stackSize,syment->name,syment->name);
} 
//voidSymTable embolitAllocaEntry* syment =  Node* node, SymbolTable* symTab)
//{
//   fprintf(ofile,"\
//addi sp,sp-1024\n\
//sd  ra,1016(sp)\n\
//sd  s0,1008(sp)\n\
//sd  s0,100)(sp)\n\
//addi s0,sp 40\n\
//addi s1,sp,0\n\
//");

//}
void emitDeclarationDeallocation(FILE* file, Node* node, SymbolTable* symTab){
    fprintf(ofile,"\
addi sp,sp,-1024]n\
sd  ra,1016(sp)\n\
sd  s0,1008(sp)\n\
sd  s1,1000(sp)\n\
addi s0,sp,40 #stack point pointer\n\
addi s1,sp,40 #12 bytes for local variables(each 2 bytes)\n\
");
}
void emitUnaryExpression(FILE * file, Node* node, SymbolTable* symTab){
    genVisitor(getNthChild(node,1));
    if(node->nodeStdType == TYPE_INT){
        //Only one operator in this cases so:
        fprintf(file,
            "lw t0, 0(s0)        #pop from the top of stack\n"
            "addi s0,s0,-4       #move the pointer of stack \n"
            );
        switch(node->uoperation){
            case NODE_OP_POSSIGN:
            fprintf(file,"#Not really anythign to do for unary +\n");
            break;
            case NODE_OP_NEGSIGN:
            fprintf(file,
                "li t1,-1\n"
                "mul t0,t1,t0\n"
            );
            break;
            case NODE_OP_NOT:
            fprintf(file,
                "seqz t0,t0\n"
            );
            break;
        }
        fprintf(file,
            "addi s0,s0,4\n"
            "sw t0,0(s0)\n"
        );
    }else if(node->nodeStdType == TYPE_REAL){
        fprintf(file,
            "flw ft0, 0(s0)        #pop from the top of stack\n"
            "addi s0,s0,-4       #move the pointer of stack \n"
            );
        switch(node->uoperation){
            case NODE_OP_POSSIGN:
            fprintf(file,"#Not really anythign to do for unary +\n");
            break;
            case NODE_OP_NEGSIGN:
            fprintf(file,
                "li t1,-1\n"
                "mul t0,t1,t0\n"
            );
            fprintf(ofile,
                "\t#Start: Loading Neg Unary FP \n"
                "lui ft1,%%hi(.LC3)\n"
                "flw ft1,%%lo(.LC3)(ft1)\n"
                "fmul ft0,ft0,ft1"
                "\t#End: Loading Neg Unary FP \n"
                );
            break;
            case NODE_OP_NOT:
                printf("\"NOT\" operation not allowed on non-intger types.\n");
            break;
        }
        fprintf(file,
            "addi s0,s0,4\n"
            "sw t0,0(s0)\n"
        );

    }else{
        printf("Undefined behavior for this type\n");
    }
}
bool emitConcreteValue(FILE* file, Node * node){
    if(!node->hasConcreteValue)
        return false;
    if(node->nodeStdType == TYPE_INT){//Just place it in the stack then 
        fprintf(file,
            "li t0,%d\n"
            "addi s0,s0,4\n"
            "sw t0,0(s0)\n"
        ,(int)node->doubleVal);
    }else if(node->nodeStdType == TYPE_REAL){
        //For float we also have to emit the constant thingy
            char rstring[100];
            char * fstr = (char *)malloc(LABEL_SIZE*sizeof(char)+1+100);
            char * labelo = (char *)malloc(LABEL_SIZE*1);//+1 For null
            generateConstAddr(labelo);
            sprintf(rstring,": .word %d #%f\n",floatToDecRepresentation((float)node->doubleVal),(float)node->doubleVal);

            strcpy(fstr,labelo);
            strcat(fstr,rstring);
            //Print it here
            fprintf(oldFile,fstr);

            //With the label out of the way we must 
            //Also load the real into stack for future processing
            fprintf(file,
                "\t#Start: Loading FP Value to Stack\n"
                "lui t0,%%hi(%s)\n"
                "flw ft0,%%lo(%s)(t0)\n"
                "addi s0,s0,4\n"
                "fsw ft0,0(s0)\n"
                "\t#End: Loading FP Value to Stack\n"
                ,labelo,labelo);
            free(labelo);
            free(fstr);

    }else{
        printf("ERROR : Not considered type on concrete value\n");
        return false;
    }
    return true;
}
void emitBinaryExpression(FILE* file, Node* node, SymbolTable* symTab){//If we are here its because we are definitely a binary node so no bother checking on that
    //Generate code for each operand
    //Lets try to implement constant folding here
    if(!emitConcreteValue(file,node)){
        //If this node itself does not have concrete value then perhaps its children do 
        printf("On parent node of operation : %s\n",OpTypes[node->operation]);
        Node * leftNode = getNthChild(node,1);
        Node * rightNode = getNthChild(node,2);

        if(!emitConcreteValue(file,leftNode));
            genVisitor(leftNode);
        if(!emitConcreteValue(file,rightNode));
            genVisitor(rightNode);
        //This is just for the sake of being organized really
        BINARY_OPERATIONS op = node->operation;
        switch(op){
            case NODE_OP_ADD:
            case NODE_OP_SUBTRACT:
            case NODE_OP_MULT:
            case NODE_OP_DIV:
                emitBinaryArith(file,node,symTab);
                break;
            case NODE_OP_LESSTHAN:
            case NODE_OP_GREATERTHAN:
            case NODE_OP_EQUALS:
            case NODE_OP_LESSTHANEQ:
            case NODE_OP_GREATERTHANEQ:
            case NODE_OP_NEQUALS:
                emitBinaryRelative(file,node,symTab);
                break;
            case NODE_OP_AND:
            case NODE_OP_OR:
                emitBinaryLogical(file,node,symTab);
                break;
        }
    }
}
void emitBinaryRelative(FILE* file, Node* node, SymbolTable* symTab){
   //More specific actions
   //By the time we are here we should already have generated our operands and
   //their values should be at TOS
   node->nodeStdType = TYPE_INT;//After all relative operations we get a boolean(i.e. an integer)
    if(node->nodeStdType == TYPE_INT){
        //Pop operands from stack to registers
        fprintf(file,
            "lw t0, 0(s0)        #pop from the top of stack\n"
            "addi s0,s0,-4       #move the pointer of stack \n"
            "lw t1, 0(s0) \n"
            "addi s0,s0,-4   \n"
            );
        switch(node->operation) {
            case NODE_OP_LESSTHAN:
            fprintf(file,
                "slt t2,t1,t0\n"
                );
            break;
            case NODE_OP_GREATERTHAN:
            fprintf(file,
                "slt t2,t1,t0\n"
                "not t2,t2\n"
                "andi t2,t2,1\n"//that seems to fix that
                //Test Equality
                "sub t3,t0,t1\n"//MEGA TODO NOT SURE ABOUT THIS ONEEEE
                "snez t3,t3\n"
                "and t2,t2,t3#If either less or equal\n"
                );
            break;
            case NODE_OP_EQUALS:
            fprintf(file,
                //Test Equality
                "#Start: Testing equality\n"
                "sub t2,t0,t1\n"//MEGA TODO NOT SURE ABOUT THIS ONEEEE
                "seqz t2,t2\n"
                "#End: Testing equality\n"
                );
            break;
            case NODE_OP_LESSTHANEQ:
            fprintf(file,
                "slt t2,t1,t0\n"
                //Test Equality
                "sub t3,t0,t1\n"//MEGA TODO NOT SURE ABOUT THIS ONEEEE
                "seqz t3,t3\n"
                "and t2,t2,t3#If either less or equal\n"
                );
            break;
            case NODE_OP_GREATERTHANEQ:
            fprintf(file,
                "slt t2,t1,t0\n"
                "seqz t2,t2\n"
                );
            break;
            case NODE_OP_NEQUALS:
            fprintf(file,
                //Test Equality
                "sub t2,t0,t1\n"//MEGA TODO NOT SURE ABOUT THIS ONEEEE
                "senz t2,t2\n"
                );
            break;
        }
        //Store result in stack
        fprintf(file,
            "addi s0,s0,4\n"
            "sw t2,0(s0)\n"
            );
    }else if(node->nodeStdType == TYPE_REAL){
        //Agian we we assume that both our operands are surely floats and 
        //they are waiting for us on TOS
        //Pop from the Stack into float registers
        fprintf(file,
            "flw ft0, 0(s0)        #pop from the top of stack\n"
            "addi s0,s0,-4       #move the pointer of stack \n"
            "flw ft1, 0(s0) \n"
            "addi s0,s0,-4   \n"
        );
        //Again do switch to detect whic operation
        switch(node->operation){
            case NODE_OP_LESSTHAN:
            fprintf(file,
                "flt.s t0,ft1,ft0\n"
            );
            break;
            case NODE_OP_GREATERTHAN:
                fprintf(file,
                    "flt.s t0,ft1,ft0\n"
                    "seqz t0,t0\n"//This should have the complemented flag
                    "feq.s t1,ft1,ft0\n"
                    "seqz t1,r1\n"
                    "and t0,t0,t1\n"//Should have final answer
                );
            break;
            case NODE_OP_EQUALS:
                fprintf(file,
                    "feq.s t0,ft1,ft0\n"
                );
            break;
            case NODE_OP_LESSTHANEQ:
                fprintf(file,
                    "flt.s t0,ft1,ft0\n"
                    "feq.s t1,ft1,ft0\n"
                    "or t0,t0,t1\n"
                    "senz t0,t0\n"
                );
            break;
            case NODE_OP_GREATERTHANEQ:
                fprintf(file,
                    "flt.s t0,ft1,ft0\n"
                    "seqz t0,t0\n"
                );
            break;
            case NODE_OP_NEQUALS:
                fprintf(file,
                    "feq.s t0,ft1,ft0\n"
                    "seqz t0,t0\n"
                );
            break;
            default:
                printf("Invalid Relational Operation\n");
            break;
        }


    }
}
void emitBinaryLogical(FILE* file, Node* node, SymbolTable* symTab){
    //MEGA TODO
    if(node->nodeStdType == TYPE_INT){//Thought it should only be int
        fprintf(file,
            "lw t0, 0(s0)        #pop from the top of stack\n"
            "addi s0,s0,-4       #move the pointer of stack \n"
            "lw t1, 0(s0) \n"
            "addi s0,s0,-4   \n"
            );
        switch(node->operation){
            //By this point we know that we have the left
            //operand on t0 and the righ tone on t1
            case NODE_OP_AND:
                fprintf(file,
                    "AND t2,t0,t1\n"
                    "snez t2,t2\n"//This is just to limit the output to either 0 or 1, not nonzero or zer
                    );
            break;
            case NODE_OP_OR:
                fprintf(file,
                    "OR t2,t0,t1\n"
                    "snez t2,t2\n"//This is just to limit the output to either 0 or 1, not nonzero or zer
                    );
            break;
        }
        //Put the result in the stack
        fprintf(file,
            "addi s0,s0,4\n"
            "sw t2,0(s0)\n");
    }else{
        printf("ERROR: Performing Boolean Operations on non integer values\n"
            "This might result in undefined behavior\n" 
            );
    }
}
void emitBinaryArith(FILE* file, Node* node, SymbolTable* symTab){
    if(node->nodeStdType == TYPE_INT){
    switch(node->operation){
        case(NODE_OP_ADD):
        fprintf(ofile,"\
#Start of addition\n\
lw a1, 0(s0)        #pop from the top of stack\n\
addi s0,s0,-4       #move the pointer of stack \n\
lw a2, 0(s0) \n\
addi s0,s0,-4   \n\
add a3, a1, a2 \n\
addi s0,s0,4\n\
sw a3, 0(s0)        #store the result to stack \n\
#End of addition\n");
            break;
    case(NODE_OP_SUBTRACT):
        fprintf(file,"\
\t#START: ISUBB\n\
lw a1, 0(s0)\n\
addi s0,s0,-4\n\
lw a2, 0(s0)\n\
addi s0,s0,-4\n\
sub a3, a2, a1\n\
addi s0,s0,4\n\
sw a3, 0(s0)\n\
\t#END: ISUBB\n\
");
        break;
        case(NODE_OP_MULT):
            fprintf(file,"\
\t#START: IMULT\n\
lw a1, 0(s0)\n\
addi s0,s0,-4\n\
lw a2, 0(s0)\n\
addi s0,s0,-4\n\
mul a3, a1, a2\n\
addi s0,s0,4\n\
sw a3, 0(s0)\n\
\t#END: IMULT\n\
");
        break;
        case(NODE_OP_DIV):
        //I made a small lchange in the order of the operands
        //Because it seemed to be the other way around
        fprintf(file,"\
\t#START: IDIV\n\
lw a1, 0(s0)\n\
addi s0,s0,-4\n\
lw a2, 0(s0)\n\
addi s0,s0,-4\n\
div a3, a2, a1\n\
addi s0,s0,4\n\
sw a3, 0(s0)\n\
\t#END: IDIV\n\
");
        break;
    }
    }else if(node->nodeStdType == TYPE_REAL){
        //Get operands from stack
        fprintf(file,"\
flw ft1, 0(s0)        #pop from the top of stack\n\
addi s0,s0,-4       #move the pointer of stack \n\
flw ft2, 0(s0) \n\
addi s0,s0,-4   \n\
");
//Decide which operation to use
    switch(node->operation){
        case(NODE_OP_ADD):
        fprintf(file,"\
#Start of float addition\n\
fadd.s ft3, ft1, ft2 \n\
#End of addition\n");
            break;
    case(NODE_OP_SUBTRACT):
        fprintf(file,"\
#Start: FSUBB\n\
fsub.s ft3, ft2, ft1 \n\
#END: FSUBB\n");
        break;
        case(NODE_OP_MULT):
        fprintf(file,"\
#Start: FMULT\n\
fmul.s ft3, ft2, ft1 \n\
#END: FMULT\n");
        break;
        case(NODE_OP_DIV):
        fprintf(file,"\
#Start: FDIV\n\
fdiv.s ft3, ft2, ft1 \n\
#END: FDIV\n");
        break;
    }
    //Store result in stack
    fprintf(file,"\
addi s0,s0,4\n\
fsw ft3, 0(s0)        #store the result to stack \n\
");

    }else{
        printf("This hsould not be happening\n");
    }

}

void emitConstant(FILE* file, Node* node, SymbolTable* symTab){//Lets try to fit doubles and 
    char * labelo;
    char * fstr;//This will write the final label
    int rsize = (node->nodeStdType == TYPE_CONST_STRING)? strlen(node->stringVal)+30 : 100;
    char rstring[rsize];//Shouldnt need more than 100 chars
    switch(node->nodeStdType){//This can be either int or real
        case(TYPE_INT):
        fprintf(ofile,"\
#Emitting Num Constant\n\
li t1,%d\n\
addi s0,s0,4\n\
sw t1,0(s0)\n\
#DONE Emitting Num Constant\n",(int)node->doubleVal);
        break;
        case(TYPE_REAL):
            //First write to pool
            fstr = (char *)malloc(LABEL_SIZE*sizeof(char)+1+rsize);
            labelo = (char *)malloc(LABEL_SIZE*1);//+1 For null
            generateConstAddr(labelo);
            sprintf(rstring,": .word %d #%f\n",floatToDecRepresentation((float)node->doubleVal),(float)node->doubleVal);

            strcpy(fstr,labelo);
            strcat(fstr,rstring);
            //Print it here
            fprintf(oldFile,fstr);

            //With the label out of the way we must 
            //Also load the real into stack for future processing
            fprintf(ofile,
                "\t#Start: Loading FP Value to Stack\n"
                "lui t0,%%hi(%s)\n"
                "flw ft0,%%lo(%s)(t0)\n"
                "addi s0,s0,4\n"
                "fsw ft0,0(s0)\n"
                "\t#End: Loading FP Value to Stack\n"
                ,labelo,labelo);
            free(labelo);
            free(fstr);
        break;
        case(TYPE_CONST_STRING):
            fstr = (char *)malloc(LABEL_SIZE*sizeof(char)+1+rsize);
            labelo = (char *)malloc(LABEL_SIZE*+1);//+1 For null
            generateConstAddr(labelo);
            sprintf(rstring,": .string %s\n",node->stringVal);
            strcpy(fstr,labelo);
            strcat(fstr,rstring);
            //Print it here
            fprintf(oldFile,fstr);

            //Emit The address to TOS
            fprintf(ofile,//ICOAP: Maybe theres a problem here because we are using 4 bytes for an addres ??
                "\t#Start: Loading String Address Value to Stack\n"
                "lui t0,%%hi(%s)\n"
                "addi t0,t0,%%lo(%s)\n"
                "addi s0,s0,4\n"//I think this should be 8 because iits an addres right?
                "sw t0,0(s0)\n"
                "\t#End: Loading String Address Value to Stack\n"
                ,labelo,labelo);

            free(labelo);
            free(fstr);
        break;
    }
    fseek(ofile,0,SEEK_END);//Restore back to end
}
void gen_loopThroughAllChildren(Node* node){
    int i = 1;
    while(getNthChild(node,i) != NULL){//Just loop through declarations
        genVisitor(getNthChild(node,i));//decls,subpdcls,compound_statement
        /** printf("Finished Semantic Check for one of them with i=%d\n",i); */
        i++;
    }
}

void cgHandle_declarations(Node * node){//Handle variable declarations
    //Loop through every declared variable. Check Type and size and give corresponding
    //address 
}
void emitOffsetCalculation(FILE* file, Node* varref,SymbolTable *  currentSymTab){
    Node * suffiterator = getNthChild(varref,2)->lMostChild; 
    while(suffiterator != NULL){
        
        
        suffiterator = suffiterator->rSibling;
    }
}
void emitLHSReference(FILE* file, Node* node, SymbolTable* symTab){
    //Node is VARREF which has ID and ARR_SUFFIXES as its two children
    Node * idNode = getNthChild(node,1);
    Node * varrStuff = getNthChild(node,2);
    //Again, we will have 2*2 4 cases. Each wheter variable is static and whether its array
    //Get Symbol Table Entry. This should be guaranteed
    SymbolTableEntry* syment = retrieveSymbol(symTab,idNode->stringVal);
    //Check if its a return value
    if(syment->attributes->nameClass == CLASS_FUNCTION){//Rember that procedures have not return value
    //Shoudl be the case that class function, static and local are all mutually exclusive
        switch(syment->attributes->nameType){
            case TYPE_INT:
               fprintf(file,
                    "lw a0,0(s0)\n"
                    "addi s0,s0,-4\n"
               ); 
            break;
            case TYPE_REAL://MEGA TODO
            //Store floating point value properly inside a0
            //If we pass semantioc check then that means RHS is also float, meaning we can expect TOS to be float 
                fprintf(file,
                    "flw ft0,0(s0)\n"
                    "addi s0,s0, -4\n"
                    //"fcvt.d.s ft0,ft0\n"
                    "fmv.x.d a0, ft0\n"
                );
            break;
            default://TODO
                printf("There are still other types to work out on return of a function\n");//Either string or array at this point
            break;
        }
        fprintf(file,
            ""
        );
    }else if(syment->attributes->isStatic){
        //MEGA TODO handle arrays
        //This will load the static variable into t0 and then load TOS into it
        printf("This variables dimension is %d\n",syment->attributes->arrDimension);
        /*int numOfDimensions = syment->attributes->arrDimension;
        if(numOfDimensions > 0){
            //Calculate offset into it then
            int * boundsArray = syment->attributes->boundsArray;
            size_t offset = 0;
            size_t multProp = 1;
            for(int i = numOfDimensions-1;i>=0;i--){
                int lbound = *(boundsArray+(i*2));
                int ubound = *(boundsArray+(i*2)+1);

                printf(" Couple is be  is : (%d,%d)\n",lbound,ubound);

                multProp *= (ubound-lbound+1)
            }
                printf("Offset would be : %lu\n",offset);
        }*/
        switch(syment->attributes->nameType){
            case(TYPE_INT):
                fprintf(file,
                    "\t#LOADING STATIC VAR\n"
                    "lui t0,%%hi(%s)\n"
                    "addi t0,t0,%%lo(%s)\n"
                    "lw t1,0(s0)\n"
                    "add s0,s0,-4\n"
                    "sw t1,(t0)\n"
                    "\t#END: LOADING STATIC VAR\n",syment->name,syment->name);//I think this should work fine
            break;
            case(TYPE_REAL):
                fprintf(file,
                    "\t#LOADING STATIC Float VAR\n"
                    "lui t0,%%hi(%s)\n"
                    "addi t0,t0,%%lo(%s)\n"
                    "flw ft0,0(s0)\n"
                    "add s0,s0,-4\n"
                    "fsw ft0,(t0)\n"
                    "\t#END: LOADING STATIC Float VAR\n",syment->name,syment->name);//I think this should work fine
            break;
        }
    }else{//Not static(i.e. local)
        if(syment->attributes->upperBoundArray==0){//If non-array variable
            //I believe it doesnt really matter if its float or not, since we are just moving out of stack and into value
            fprintf(file,
                "\t#Start: Store Local Var\n"
                "lw t1,0(s0)\n"
                "add s0,s0,-4\n"
                "sw t1,%d(s1)#Get from local variable\n"
                "\t#End: Store Local Var\n"
                ,syment->attributes->addressInStack);
        }else{//Is array

        }
    

    //MEGA TODO handle local arrays
    }
}


void emitRHSVarRef(FILE * file,Node * varref,SymbolTable * symtab){
    //AGAIN, Remember there can be four cases. Depending on Whether static and/or array
    //Yet Again, VARREF Has two children: ID and ARR_SUFFIXES
    Node * idNode = getNthChild(varref,1);
    Node * arrsuff = getNthChild(varref,2);

    SymbolTableEntry* syment = retrieveSymbol(symtab, idNode->stringVal);
    if(syment->attributes->isStatic){
       if(syment->attributes->arrDimension==0) {
           switch(syment->attributes->nameType){
               case TYPE_INT:
                fprintf(file,"\
\t#START: Load Static Var RHS\n\
lui t0, %%hi(%s)\n\
addi t0,t0, %%lo(%s)\n\
lw t1,(t0)\n\
addi s0,s0,4\n\
sw t1, 0(s0)\n\
\t#END: Load Static Var RHS\n\
",syment->name,syment->name);
            break;
                case TYPE_REAL:
                fprintf(file,"\
\t#START: Load Static Float Var RHS\n\
lui t0, %%hi(%s)\n\
addi t0,t0, %%lo(%s)\n\
flw ft0,(t0)\n\
addi s0,s0,4\n\
fsw ft0, 0(s0)\n\
\t#END: Load Static Float Var RHS\n\
",syment->name,syment->name);
                break;
           }
       }else{//MEGA TODO: the other 3 cases

       }
    }else{//Local Variable
        if(syment->attributes->arrDimension == 0){//Local Variable
            switch(syment->attributes->nameType){
                case TYPE_INT:
                    fprintf(file,
                        "\t#START: Load Local Var RHS\n"
                        "lw t1,%d(s1)\n"
                        "addi s0,s0,4\n"
                        "sw t1, 0(s0)\n"
                        "\t#END: Load Local Var RHS\n"
                        ,syment->attributes->addressInStack);
                break;
                case TYPE_REAL:
                    fprintf(file,
                        "\t#START: Load Local Float Var RHS\n"
                        "flw ft0,%d(s1)\n"
                        "addi s0,s0,4\n"
                        "fsw ft0, 0(s0)\n"
                        "\t#END: Load Local Float Var RHS\n"
                        ,syment->attributes->addressInStack);
                break;
                default:
                    printf("Unhandled case in RHS local switch\n");
                break;
            }
        }else{//Local Array

        }

    }
}
void cdHandle_Conditional(FILE * file, Node * ifnode, SymbolTable* symtab){
    //1st child: is conditional expression(binary)
    //2nd child: is a statemnt(which can also become a compound statement)
    //3nd child: same as 2nd
    char * falseLabel = generateLabel();
    char * endLabel  = generateLabel();
    //Proces Predicate
    genVisitor(getNthChild(ifnode,1));//Process the Predicate. Hopefully the result will bet at TOS by the end of this
    //With the result at TOS we can pull it to decide whether to jump
    fprintf(file,"\
\t#Start: IFEV\n\
lw t0, 0(s0)\n\
addi s0,s0,-4\n\
beq t0, zero, %s\n\
\t#End: IFEV\n\
",falseLabel);
    //Handle the true statements
    genVisitor(getNthChild(ifnode,2));//Process the Predicate. Hopefully the result will bet at TOS by the end of this
    fprintf(file,"\
j %s\n\
%s:\n\
",endLabel,falseLabel);
    //Now Generate Statements for False case
    genVisitor(getNthChild(ifnode,3));//Process the Predicate. Hopefully the result will bet at TOS by the end of this
    fprintf(file,"\
%s:\n\
",endLabel);
    free(falseLabel);
    free(endLabel);
}
void emitWhileLoop(FILE * file, Node * whilenode, SymbolTable * symtab){
    char * doneLabel = generateLabel();
    char * loopLabel = generateLabel();
    fprintf(file,"%s:\n",loopLabel);
    printf("asasasa\n");
    //Process Predicate
    genVisitor(getNthChild(whilenode,1));//Process the Predicate. Hopefully the result will bet at TOS by the end of this
    //Jump out if false
    fprintf(file,
        "\t#Start: WHILELOOP\n"
        "lw t0, 0(s0)\n"
        "addi s0,s0,-4\n"
        "beq t0, zero, %s\n"
        "\t#End: WHILELOOP\n"
        ,doneLabel);
    //Emit Loop Body
    genVisitor(getNthChild(whilenode,2));//Process the Predicate. Hopefully the result will bet at TOS by the end of this
    fprintf(file,"j %s\n%s:\n",loopLabel,doneLabel);
    free(doneLabel);
    free(loopLabel);
}

char * generateLabel(){
    //TODO maybe generate this in a better way ?
    char * genLabel = (char *)malloc(LABEL_SIZE*sizeof(char)+1);//+1 For null
    sprintf(genLabel,".L%d",labelCounter++);
    return genLabel;
}
void generateConstAddr(char * genLabel){//Must make sure input string is big enough
    //TODO maybe generate this in a better way ?
    sprintf(genLabel,".LC%d",constCounter++);
}
void emitRoutineCall(FILE* file, Node* node, SymbolTable* symTab){
    fprintf(ofile,"\t#START: EMIT PROC\n");
    //Deal with the arguments sent
    //Allocate resource if not void
    emitProcedureArguments(ofile,node,currentSymTab);
    if(strcmp(getNthChild(node,1)->stringVal,"printInt") == 0 || 
        strcmp(getNthChild(node,1)->stringVal,"printString") == 0 ||
        strcmp(getNthChild(node,1)->stringVal,"printlnString") == 0 ||
        strcmp(getNthChild(node,1)->stringVal,"printReal") == 0){
        fprintf(ofile,"call printf\n");
    }else{

        fprintf(ofile,"call %s\n",getNthChild(node,1)->stringVal);

        //Return value stuff
        bool isVoid = false;
        SymbolTableEntry* syment = retrieveSymbol(symTab,getNthChild(node,1)->stringVal);
        //Offload the a0 return value into stack
        switch(syment->attributes->nameType){
            case TYPE_INT: //MEGA TODO finish this
            case TYPE_REAL://Both will be taken from a0 to top of the stack. Any expresson 
            //...that may need the float should already know its expecting a float and do the appropriate conversions
                fprintf(file,
                    "addi s0,s0,4\n"
                    "sw a0,0(s0)\n"
                );
            case TYPE_VOID:
                isVoid = true;//TODO dont remember what this one here was for
            break;
            default: 
            printf("There are still return values left to handle");
            break;
        }
    }
    fprintf(ofile,"\t#END: EMIT PROC\n");
}