PROGRAM foo(input, output, error) ;
   // variable declaraions
   var a, b, c: integer;
   var d, e: array [ 1 .. 10 ] of integer; 
   var g, h: real;
   var k: array [ 23 .. 57 ] of array [ 23 .. 57 ] of real; 

   // procedure and function declarations
   procedure sort(a: array [ 1 .. 10 ] of integer);
      var a, b, c: integer; // duplicated declaration
      begin
        //a[1] := 10; //NOTE: uncomment this so the next line works
        e := a   // array assignment, global variable//NOTE: a is not intializeddd.
      end;

   function  addition(a, b: integer) : integer;
      var c: integer;  // local declaration
      begin
         //a:=1;Uncomment these two lines so addition works
         //b:=1;
         addition := a + b   // this is the return value//NOTE: again a and b have not been initialized
      end;

   begin
      a := 1;
      while a < 10 do
      begin
         sum := sum + a;//Undeclared
         a   := a + 1 
      end;
      begin  // nested compound statement
         b := 1;
         while b < 11 do
         begin  // array initialization
            d[b] := b + b * (b - 1);
            b := b +1
         end;
         sort(d)   // a procedure call          
      end;
      k[25][26] := 3;        // wrong element type
      k[25][26] := 3.14;     // good
      k[25][26] := k[25][26] + 3;     // good//NOTE wrong because 3 is int and k is real
      k[25][126]  := 3.14;   // index out of bound, can your compiler find this error?
      k[125][26]  := 3.14;   // index out of bound, can your compiler find this error?
      k[125][126] := 3.14    // index out of bound, can your compiler find this error?

   end.   // this is the end of the program
