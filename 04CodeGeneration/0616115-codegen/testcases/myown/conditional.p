PROGRAM aaa(aaa,bb,ccc);
VAR a,b,resulto: INTEGER;
BEGIN
    a := 6;
    b := a * 15;  

    printInt(a);
    printInt(b);
    if a >= 4 then begin
                printlnString("Here boi");
        if b < a - 2 then
            begin
            a := a * 5 
        end
        else a := a * 7 
        end
    else begin
    a := a / 11 * a;
end;

    printInt(a);
END.

