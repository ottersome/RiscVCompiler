# Notes

Email from professor

> In Project 3, you need to build the abstract syntax tree, build the symbol table during traversing the symbol table, and check the types of various expressions.
The rules for checking types are stated in the file semantics-of-mini-pascal.txt.  Please follow the rules in the third project.

About what \$\$ is exactly:

> This states that the data that accompanies an L_NUM token is numeric whilst the data for L_STRING and L_ID is string data. It also tells yacc that it should use the numVal member as an int whenever it sees a token of type L_NUM and that it should use the stringVal member as a char * whenever it sees tokens of type L_STRING or L_ID. numVal member of what? You don't care - because you'll be referring to the data using yacc specific syntax and letting yacc take care of exactly where the data is.

The Bison construct %type is used for declaring nonterminal symbols, just as %token is used for declaring token types. Previously we did not use %type before because nonterminal symbols are normally declared implicitly by the rules that define them. But exp must be declared explicitly so we can specify its value type. 

About the program 

WHere i diverge i do //DIV


# Reference

- [Bison 3.4](https://www.gnu.org/software/bison/manual/bison.html#Using-Mid_002dRule-Actions)

