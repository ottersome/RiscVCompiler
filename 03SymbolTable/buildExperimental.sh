#!/usr/bin/env bash
lex lexSource.l &&  yacc -d ./miniPascal_experimental.y && gcc -g -o parser lex.yy.c y.tab.c ast.c symboltable.c semantics.c -I./include/ -ly -DDEBUG
