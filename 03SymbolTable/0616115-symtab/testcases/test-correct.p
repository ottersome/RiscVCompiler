PROGRAM aaa(aaa,bbb,ccc);
VAR aa,bb,cc : INTEGER;
BEGIN
    aa := aa+3*bb-(4/cc);//NOTE: aa and bb and cc are not initialized and thus will throw an error here.j
    bb := aa+cc//NOTE: same here.. If you fixed the uninitialization of these it will be fixed(tried it myself)
END.

