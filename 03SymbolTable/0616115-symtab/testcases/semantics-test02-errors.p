// This test program includes many errors.
// Check if your compiler can catch all the errors and the quality of the error messages.
// 20142021

PROGRAM foo(input, output, error) ;
   // variable declaraions
   var a, b, c: integer;
   var d, e: array [ 1 .. 10 ] of integer; 
   var g, h: real;
   var k: array [ 23 .. 57 ] of array [ 23 .. 57 ] of real; 
   var a: array [ 23 .. 57 ] of array [ 23 .. 57 ] of real;  // WRONG 1: redefined variables


   // procedure and function declarations
   procedure sort(a: array [ 1 .. 10 ] of integer);
      var a, b, c: integer; // duplicated declaration
      begin
        e := a + d;        // WRONG 2: a is an int variable while d is an array.//NOTE fixed this because it didnt end in semicolon.//NOTE again this error wont be printed because both variables are not initizalized and because a is redeclared and my design favors the variable that was declared first. In this case an array
a := qqq - rrr;   // WRONG 3: qqq and rrr are undefined variables
        d := f(k, e);     // WRONG 4: f is undefined function
      end;


   function  addition(a, b: integer) : integer;
      var c: integer;  // local declaration
      begin
         addition := a + b   // this is the return value//NOTE again, this is not initialized thus a + b cause an error and it will complain that the return value "addition" was not intialized(because it was an erroneous operation to begin with)
      end;


   function  addition(c, d: integer) : integer;
   // WRONG 5: redefine a function, even though the arguments have different names
      var e: integer;  // local declaration
      begin
         addition := c + d   // this is the return value//NOTE: Again c and d have notbeen initialized. In this case however it will think that "Addition" belowngs to another function because this function was detected as redeclared. Changing the name of this function should fix it
      end;


   function  addition(a, b: real) : real;
   // WARNING 6: Does you compiler allow over-loading? 
      var c: integer;  // local declaration
      begin
         addition := a + b   // this is the return value//NOTE same exact thing as for previous case will happen here
      end;


   begin
      a := 1;
      while a < 10 do
      begin
         sum := sum + a;
         a   := a + 1 
      end;
      begin  // nested compound statement
         b := 1;
         while b < 11 do
         begin  // array initialization
            d[b] := b + b * (b - 1);
            b := b +1
         end;
         sort(d)   // a procedure call          //NOTE this should be fine right ?  both d and the argument are int arrays of one dimension?. It would be like sending an array through c and getting a pointer
      end;
      k[25][26] := 3;        // wrong element type
      k[25][26] := 3.14;     // good
      k[25][26] := k[25][26] + 3;     // good//NOTE this is bad because k is of type real while 3 is of type int
      k[25][126]  := 3.14;   // index out of bound
      k[125][26]  := 3.14;   // index out of bound
      k[125][126] := 3.14;    // index out of bound//NOTE also added a semicolon here otherwise it goes against the language
      a := extf(20, sum);    // WARNING 7: can your compiler handle external functions?



      // Warning 8: Can you compiler handle #include
   //#include <abc.h>     // include NOTE i wont cover compielr directives so ill comment them out
      a := bbb(20, sum);//NOTE adding lack of colon before equals sign. Otherwise goes agains alnguage



       // Warning 9: How do your compiler handle conditional compilation?
 
      //#if !defined(__unix__)
      //#include Long40.h¡¨
       k[25][26] := k[25][26] + 5;     // good, //NOTE: NOT good because "k" is a real
      //#elif defined(_TMS320C6200)
      //#define assert(a)
       k[25][26] := k[25][26] + 333;     // good //NOTE: same as abvoe
      //#else
      //#include ¡¨Long40.h¡¨
       k[25][26] := k[25][26] + 6666;     // good//NOTE: same same
      //#include <assert.h>
      //#endif




       // Warning 9: How do your compiler handle pragma?
       //#pragma    __promise((k % 16) == 0);
       b := 1;
       while b <= k do//NOTE: WRONG because comparison betweeninteger and real
       begin
         sum := sum + a[b];//NOTE not initialized
         b   := b + 1 
       end;


   end.   // this is the end of the program
