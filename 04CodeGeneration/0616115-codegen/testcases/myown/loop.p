PROGRAM aaa(aaa,bbb,ccc);
VAR aa,bb,cc : INTEGER;
VAR more,ifthis:INTEGER;
BEGIN
    aa:= 5;
    bb:=5;
    while bb >= 0 do
    begin
        printInt(aa);
        aa:=aa*2;
        bb:=bb-1;
    end;
    printInt(aa);
END.

