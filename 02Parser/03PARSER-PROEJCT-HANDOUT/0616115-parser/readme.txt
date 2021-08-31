How to run he program

1. First make the lex file:
    lex lexSource.l
2. Then run our gramar file through yacc:
    yacc -d miniPascal.y
3. Finally compile everything together:
   `gcc -o parser y.tab.c lex.yy.c -ly`
4. This will output the executable named 'parser'.
    If you wish to run it then just feed the input as such
    ./parser < path/to/input 
    for example: ./parser < ./testcases/no-parsing-error/test-function.p
    

NOTE 1:
    All I did was copy the grammar and fix where I can until the "correct" test cases work.
    I am afraid to do  any modifications besides the one that I already have bacause 
    I dont want my language to be different then the one set by the TAs.

NOTE 2:
    The comments are not printing because the README txt file says that we should 
    turn of all of the scanners output. I just uncommented them but if you wish for 
    them to me printed you can uncomment them from the lex file.
NOTE 3:
    I dont know if we were meant to considere precedence or not but I did. 
    If not I can show in a git a copy of a file where precedence is removed.
NOTE 4:
    I added a test of my own call `testcases/additional/myOwn.p' here i test all conditions placed for 評分項目. 
    They all showed to be working



