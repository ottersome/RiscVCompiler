PROGRAM foo(input, output, error) ;
   // This test checks duplicated identifier.
   var abc,v: real;
   var sval:string;

   function noParamReturn: integer;
   begin
    noParamReturn := 2; 
   end;
   function funcWithParameter(var x: integer): integer;
   begin
        funcWithParameter := 2; 
   end;

   procedure modifyAbc(var plusVal:real);
   begin
       //We can asee here that we can modify static variables form inside a procedure
       //Using procedures argument
       printString("abc value before modification : ");
       printReal(abc);
        abc := abc+plusVal;
   end;
   begin
      abc := 8.3;
      abc := abc + 21.1;
      abc := abc*12.2;//~358.68
      abc := abc-0.4;//~358.28
      abc := abc/2.1;//170.60
      printlnString("This is the result of abc:");
      printReal(abc);
      //sval := "This is the string2m"
      printlnString("now workign with modifyAbc");
      modifyAbc(4.01);
      printString("Result of abc is : ");
      printReal(abc);
      printString("Printing static ");
      printInt(1+funcWithParameter(1));
   end.   // this is the end of the program
