How to run the program:

You can run the program by running the following commands in order while being in the root directory of the unzipped folder:

1. flex lexSource.l
2. cc lex.yy.c
3. ./a.out < Input/MyOwn.p
    - Of course you can substitute Input/MyOwn.p for any of your input cases

More about the program:

1. Because of how the string had multiple contradictory instructions on the string I ended up asking the professor and he said that newlines are illegal unless escaped.
Therefore in Input/String.p the las few Strings will throw an error(as per my decision) because they are not escaped. In contrast the first string that I put in that file has properly escaped new lines and works fine.
If that is not the case there is a comment regex inside the start condition that should negate the error throwing concerning the unescaped new line.
2. Concerning the comments, I didnt  understand whether nested comments are requisite or not. So i ended up implementing them. This however will not account for comments that have unclosed nested comments. Such as /* /* */. These type of comments are considered as erros in my scanner.
    - EDIT: Since we received comment from the professor telling us we dont need it then I commented out the implemetation.
3. The content of output.txt wont be ordered exactly as the output  you would get from your termina. This is because bash can only redirect one kind of stream to another. In my case that is stdout to stderr. This causes stderror messages to show a little earlier in the output.txt but they show normally when you run the program for the output.
4. In regards to identifiers: I the "intended output" thinks an indentifier with underscored is a wrong identifier. However the FAQ says that the identifiers may include underscored. Thus i included them.
5. In the input there are some symbols that are labeld as wrong  yet in the 00README.txt file they are said to be tokens within pascal to be implimented. SO i ended up implementing them
6. Because the file was full of carraige returns(\t) and nothing was specified about them I simply treated them like blankspace
7. I set the limit buffer for strings to be 1000 but this can be adjusted in the source file. If this limit is reached the parser will throw a warning and stop parsing all-together.
