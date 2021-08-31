PROGRAM aaa(aaa,bbb,ccc);
VAR aa,bb,cc,c : integer;
var e,y,h:real;
var f,g: array [1..7] of array[5..10] of real;
var a:array [-11 .. 3] of  real;
   function funco(var k:integer;var b,c:real):integer;//I dont really knwo why this is not working
      var besa, c: integer; // redeclaration within same scope -> error
      var BESA:integer;//Since it is case insensitive then this must be deemed an overload
      var tesa:integer;//Since it is case insensitive then this must be deemed an overload
      var sa:integer;
      var a:integer;//Redeclaration
      var yeeeet:integer;
      begin
          e:= 1.2;
          funco:=1.2;
          funco:=1;
          b := 2;//Wrong: int to real
          funco := 2+3;//right
          funco := b+3;
      end;
   function funca(var k:array[1..10] of integer):integer;//I dont really knwo why this is not working
      var yeeeet:integer;
        procedure doNothing;
        var e:integer;
        var sup:real;
        begin
            e:=11;
            c:=10+e;
        end;
      begin
      end;
   procedure presort;
   begin
       h:=y;//This should Not work because y is not initializeed
       h:=e;//This should work because e was initialized above.
   end;
   procedure sort(l: array [ 1 .. 10 ] of integer);
      var b, c: integer; // redeclaration
      var sa:integer;
      begin
        presort;
        l[1]:=1;
        b:=funco(1,2,3);
        b:=11.1;
        b := 3 + funca(l[-1]);   // the result is .
        b:= funco(l);
        c:=10;
      end;

   function aver:integer;
   begin
   end;
BEGIN
    bb:=aa+1;
    aa:=42.0;
    e:=21;
    aa:=42;
    f[2][bb][2] := 2.2;//Using synthesize values we can evaluate this is out of bounds
    bb:=aa+1;
    f[2][bb][2] := 2.2;//Using synthesize values we can evaluate this is out of bounds
    f[aa][8] := 2.2;
    g[5][5] :=1.2;
    a[-5] := 2.1;
    a[-5.5] := 2.1;
    sort;
    f[5] := g[5.5];
    f[5][5] := 2.1;
    der := 2;
    e := 2+1;//Wrong because e is real
    e := 2.1;//All good
    e := 2.1+e;//Should be right
    aa:=a;//This should be an error yet imn ot picking it up
    a[1] := 2;
    a[1] := 2.2;
    aa:=a;
    c := ---5;   // Is this allowed?
    c := -3+2;
    bb := 1;
    bb := -1;
    bb := 1-1;
    bb := 1-1;
    bb :=-1;
    bb := 2*2;
    while 11*1*2+bb-1 do
    begin  // array initialization
        bb:= bb +1
    end;
    while CC AND bb < 11*1*2+bb-1 do
    begin  // array initialization
        bb:= bb +1
    end;
    aa := aa+3*bb-(4/cc);
    bb := aa+cc
END.

