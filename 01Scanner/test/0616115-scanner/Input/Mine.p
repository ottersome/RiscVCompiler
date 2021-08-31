//This is a comment with a div / will it 
12 + 4 // What about this 
12 + 4 //And about this 
//Im Testing Scientific Notation and floats
19.32
19.E+21//Should be wrong since theres nothing after the decimal point 
+12E+21//Should be alright
12.121EA // SHould be wrong
1234567890
23ThisisNotAGoodIdentifier//Should be two tokens
"This string \
should be alright\
Since we are escaping the\
New lines"
"However this
line should throw an error"
"This String \" escapes \" multiple double qutoes. Should be ok"
"We can explicitly use \n to create new line"
"Same goes for \t tabs"
"What about random escapes \are just random escapes"
//What about / division inside a comment ?
/* Multii line commetns should be ok
 * Right? / 
 */ program
array
//Concerning identifiers
thisisOk
_underscoresarealsoOkay; // I think they are fine because c allows them to
_12NumbersAfterUnderscoresarenotPermitted
_WeNeedAtLeastALetterBeforeAdding12Numbers
_whatifweembedkeywordslikearrayandprograminsideanIdentifier
//Do keywords care about caps or not?
pRogRAm
..12..23 //Ldots in action
12.32..12.1
"Honestly Im running\
Out of 
Tests here"
10E21
10E-+21
