How to run the program

just run the script
"./buildWYacc.sh"

TODO

Notes:

- VERY IMPORTANT: In the readme.txt it was not left clear what we should do when there is a redeclaration(in the same scope) of a name. 
  Thus what I decided(following C principles) was to simply not take in the  offending variable into the symbol table.
  Instead just leave the old one there. 
- VERY IMPORTANT: Please take error messages in consideration with previous error messages. As in any compilers if enough error messages are stacked then those that follow my not me as accurate.
  For the best results make sure that variables un functions used in an assignment have not caused errors earlier.
  For example:
    If a variable "A" was initialized but with wrong type of RHS value then dont use "A" later as RHS of an assignment because "A" will already be tainted by its previous error.
- VERY IMPORTANT: SYmbol tables will be printed *ONLY* after the scope closed. This means that the symbol table for the gobal scope will be the last to tbe printed
- I am using case insenstive as specified in the "Sematincs-of-mini-pacal.txt" file.
- If a function is redeclared I am still allowing semantic checking on its body since the aim of the semantic check phase is to catpure as many errors as possible.

