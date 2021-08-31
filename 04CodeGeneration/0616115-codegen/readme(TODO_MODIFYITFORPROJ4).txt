How to run the program:

just run the script
"./buildFinal.sh"
this will compile everything for you. Afterwards the runt the executable
"./parser <inputfile>"
For example(in a single line)
"./buildFinal.sh && ./parser ./testcases/test-correct.p"

Additionally there is a script called ./buildWYacc.sh. This is for debug mode. It will output more verbose

Notes:

- IMPORTANT: I asked a TA via email when we should open scopes and the reply said that only on procedures and functions. Thus I ignore whiles and if statements. 
- VERY IMPORTANT: After running many of the tests here I noticed that some of my error messages take precedence over the ones the TAs expect. 
  For example my semantic check will first report an uninitialization of a variable before reporting if said variable was in a sum with another incompatible type
  For these cases i am adding //NOTE after the output of said cases to explain why thi is the case.
- VERY IMPORTANT: In the readme.txt it was not left clear what we should do when there is a redeclaration(in the same scope) of a name. 
  Thus what I decided(following C principles) was to simply not take in the  offending variable into the symbol table.
  Instead just leave the old one there. 
- VERY IMPORTANT: Please take error messages in consideration with previous error messages. As in any compilers if enough error messages are stacked then those that follow my not me as accurate.
  For the best results make sure that variables un functions used in an assignment have not caused errors earlier.
  For example:
    If a variable "A" was initialized but with wrong type of RHS value then dont use "A" later as RHS of an assignment because "A" will already be tainted by its previous error.
- VERY IMPORTANT: SYmbol tables will be printed *ONLY* after the scope closed. This means that the symbol table for the gobal scope will be the last to tbe printed
- Note: If a procedure or function contains now declarations of variables then their symbol table will not be printed(because there is none afterall)
- I couldnt find what type the program arguments are so i just put them as void
- THis is very likely not my final version as i have not done error checking on my program. But in case code is correct i wantto uploaded before the end of friday. The output files have not been included
  THose will be added later. The output can be confirmed by the TA. I'm just running out of time.
- I am using case insenstive as specified in the "Sematincs-of-mini-pacal.txt" file.
- If a function is redeclared I am still allowing semantic checking on its body since the aim of the semantic check phase is to catpure as many errors as possible.

