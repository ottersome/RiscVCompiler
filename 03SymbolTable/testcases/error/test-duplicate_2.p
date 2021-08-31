PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

FUNCTION aaa(a, b: INTEGER) : INTEGER;
BEGIN
    aaa := 3//Setting up a return value
END;

FUNCTION bb : INTEGER;
VAR a, b, c : INTEGER;
VAR d, a, e : REAL;     // Duplicate declaration of a
BEGIN
END;

FUNCTION aaa(a, b: INTEGER) : REAL;  // Duplicate declaration of aaa
BEGIN
    aaa := 3.3//Since we didnt add aaa to symbol table(because it was redeclared) it thinks it is assigning to th function outside
END;

BEGIN
    a := 333
END.
