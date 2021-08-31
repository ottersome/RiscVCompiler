********************************
*       No syntax error!       *
********************************
L0:NodeType: Root
	L1:NodeType: ID val:aa
	L1:NodeType: DECLARATIONS
		L2:NodeType: ID_LIST
			L3:NodeType: ID val:input
			L3:NodeType: ID val:output
			L3:NodeType: ID val:error
		L2:NodeType: TYPE_PROGRAM_ARG
	L1:NodeType: DECLARATIONS_ROOT
		L2:NodeType: DECLARATIONS
			L3:NodeType: ID_LIST
				L4:NodeType: ID val:a
				L4:NodeType: ID val:b
				L4:NodeType: ID val:c
			L3:NodeType: TYPE_INT
		L2:NodeType: DECLARATIONS
			L3:NodeType: ID_LIST
				L4:NodeType: ID val:arr
			L3:NodeType: TYPE_INT
				L4:NodeType: TYPE_ARR
					L5:NodeType: Number,Val: 0.000000
					L5:NodeType: Number,Val: 10.000000
	L1:NodeType: SUBPDECLARATIONS
	L1:NodeType: STATEMENT_LIST
		L2:NodeType: ASSIGN_OP
			L3:NodeType: VARREF
				L4:NodeType: ID val:a
				L4:NodeType: ARR_SUFFIXES
			L3:NodeType: VARREF
				L4:NodeType: ID val:b
				L4:NodeType: ARR_SUFFIXES
		L2:NodeType: ASSIGN_OP
			L3:NodeType: VARREF
				L4:NodeType: ID val:arr
				L4:NodeType: ARR_SUFFIXES
					L5:NodeType: Number,Val: 1.000000
			L3:NodeType: Number,Val: 8.000000
		L2:NodeType: ASSIGN_OP
			L3:NodeType: VARREF
				L4:NodeType: ID val:arr
				L4:NodeType: ARR_SUFFIXES
					L:5,Id:41,BinaryExpr,oprtr: SUBTRACT
						L:6,Id:37,BinaryExpr,oprtr: ADD
							L7:NodeType: Number,Val: 3.000000
							L7:NodeType: Number,Val: 5.000000
						L6:NodeType: VARREF
							L7:NodeType: ID val:c
							L7:NodeType: ARR_SUFFIXES
			L3:NodeType: Number,Val: 8.000000
NOTICE: Opening Scope as we perform semantic check
NOTICE: We have added variable "input" in line 0 to symbol table. At depth 0 
NOTICE: We have added variable "output" in line 0 to symbol table. At depth 0 
NOTICE: We have added variable "error" in line 0 to symbol table. At depth 0 
NOTICE: We have added variable "a" in line 2 to symbol table. At depth 0 
NOTICE: We have added variable "b" in line 2 to symbol table. At depth 0 
NOTICE: We have added variable "c" in line 2 to symbol table. At depth 0 
NOTICE: We have added variable "arr" in line 3 to symbol table. At depth 0 


Semantic Error at or around Line(5):Use of RHS varibale with name:b that has not been initialized


NOTICE at around Line(7): The var "arr" is now initialized 


Semantic Error at or around Line(9):Use of RHS varibale with name:c that has not been initialized
Semantic Error at or around Line(10):Incompatible LHS and RHS Array Sizes for assignment.
NOTICE: Closing Scope as we perform semantic check
****************************************
*    Open Scope SymbolTable            *
****************************************
Name : input, Type:TYPE_VOID, Class VAR, Depth 0, Dimension:0 
Name : output, Type:TYPE_VOID, Class VAR, Depth 0, Dimension:0 
Name : error, Type:TYPE_VOID, Class VAR, Depth 0, Dimension:0 
Name : a, Type:TYPE_INT, Class VAR, Depth 0, Dimension:0 
Name : b, Type:TYPE_INT, Class VAR, Depth 0, Dimension:0 
Name : c, Type:TYPE_INT, Class VAR, Depth 0, Dimension:0 
Name : arr, Type:TYPE_INT, Class VAR, Depth 0, Dimension:1 Ranges:(0,10),
****************************************
*   Closed Scope SymbolTable           *
****************************************



We are now printing all the symbol tables encountered
****************************************
*    Open Scope SymbolTable            *
****************************************
Name : input, Type:TYPE_VOID, Class VAR, Depth 0, IsArray:NO,
Name : output, Type:TYPE_VOID, Class VAR, Depth 0, IsArray:NO,
Name : error, Type:TYPE_VOID, Class VAR, Depth 0, IsArray:NO,
Name : a, Type:TYPE_INT, Class VAR, Depth 0, IsArray:NO,
Name : b, Type:TYPE_INT, Class VAR, Depth 0, IsArray:NO,
Name : c, Type:TYPE_INT, Class VAR, Depth 0, IsArray:NO,
Name : arr, Type:TYPE_INT, Class VAR, Depth 0, IsArray:YES,Ranges:(0,10),
****************************************
*   Closed Scope SymbolTable           *
****************************************
********************************
*    Semantic Check Done!      *
********************************
