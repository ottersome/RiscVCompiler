PROGRAM foo(input, output, error) ;
   // This test checks duplicated identifier.
   var abc,v: integer;
   function func0(x: integer; y:integer) : integer;
    var funcloc:integer;
      begin
          funcloc:=1;//This is working
          printInt(funcloc);
          printInt(2211);
          x:= x+24;
          printInt(x);
          printInt(y);
          printInt(1122);
          func0 := x + 1 + 2 + 3;
      end;
   begin
      abc := 8+2+3;
      printInt(12);
      abc := func0(12+12,abc);//24,13
      printString("This is the result : ");
      printInt(abc+12);
      printlnString("About to enter the composite");
      printInt(func0(1,3)+12);
   end.   // this is the end of the program
