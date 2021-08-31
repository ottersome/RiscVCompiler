PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

FUNCTION tt : INTEGER;
BEGIN
  a:=1;
  tt := 3//THis hsould be okay because its the funcitons return value
END;

FUNCTION bb (a,b : REAL) : INTEGER;
VAR c : INTEGER;
VAR d : ARRAY[1..2] of INTEGER;
BEGIN
  c:=1;
  bb:=c;
  bb := tt+3;
  tt := a   // function can not appear in LHS
END;

BEGIN
    a := 3
END.
