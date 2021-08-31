PROGRAM aa(input, output, error); 
VAR a, b, c: INTEGER;
VAR arr : ARRAY[0..10] of INTEGER;
BEGIN
    a := b;         // use b before initialization
    arr[3+5-c] := 8 // use c before initialization. It will also throw an error saying incomaptible LHS and RHS size but this is only because of the uninitialized c
END.
