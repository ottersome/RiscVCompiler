PROGRAM foo(input, output, error) ;
   var a, b,c: integer;
   var ar,br:real;
   
   // test simple, non-recursive functions
   function  simplesum(a: integer) : integer;
      begin
         simplesum := a * b
         // simplesum is the return value
      end;

   begin  
      a := 7; b := 13;
      printString("Value for A: ");
      printInt(a);
      printString("Value for B: ");
      printInt(b);

      c:=10;
      a := 3 + simplesum(10);   // the result is . CORRRECT
      b := 3+ simplesum(c);   // the result is . 
      printString("After Value for A: ");
      printInt(a);
      printString("After Value for B: ");
      printInt(b);


   end.   // this is the end of the program
