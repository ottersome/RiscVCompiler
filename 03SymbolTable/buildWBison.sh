#!/usr/bin/env bash
lex lexSource.l &&  bison -d miniPascal.y && gcc -o parser lex.yy.c miniPascal.tab.c  ast.c -I./include/ -ly
