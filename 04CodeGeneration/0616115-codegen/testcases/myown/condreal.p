PROGRAM aaa(aaa,bbb,ccc);
VAR aa,bb,resulto,bbcc: real;

   function addthem(xr: real; yr:real) : real;
   var aa,bbcc:real;
   begin
       bbcc:=1212.12;
       printString("Value of bbcc inside func : ");
       printReal(bbcc);
       printlnString("Value of xr inside func is :");
       printReal(xr);
       printString("Value of y is :");
       printReal(yr);
       printReal(xr+yr);
       printReal(5.5);
       addthem :=  xr+yr;
   end;
   function addInt(xi:integer;yi:integer): integer;
   var aa:integer;
   begin
        printInt(xi+yi);
        addInt :=214;
   end;
BEGIN
    aa:= 4.1;
    printReal(aa);
    printReal(21.121);
    aa:= aa-1.0;
    bb:= 12.1;
    resulto := 0.0;

    bbcc:=69.69;
    printString("Global bbcc is : ");
    printReal(bbcc);

    printReal(aa);
    printReal(bb);
    if aa >= 4.0 or bb=12.1 then 
        resulto := 1.1
    else 
        resulto := 0.1;
    printReal(aa+bb);
    printInt(addInt(2,5));
    printReal(resulto);
    printlnString("Calling add them");
    printReal(addthem(12.1,13.1));
    printString("Global bbcc after call is : ");
    printReal(bbcc);
END.

