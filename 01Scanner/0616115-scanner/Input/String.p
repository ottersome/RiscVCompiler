" Multi-Line\
  With comment \
  /* \
    This is a comment\
    \tWe are using tab here see. More space\
    We are using written newline \n here see. More space\
  */ " 
"This String contains an escaped double quote here -> \" did it tokenize it? "
""
"Single String"
"Double" "Strings"
"double quote->""<-double quote"
"Your string should ignore these reserved words -> program var array not"
"This String contains an escaped double quote \" Will it tokenize it?"
array program ..
" Test whether you can ignore comments // This is a comment "
" Test whether you can ignore comments /* This is a comment */ "
" Test whether you can ignore comments // This is a comment /* This is a comment */ "
" Multi-Line
  String Can you tokenize it"
" Multi-Line
  With comment // This is a comment "
" Multi-Line
  With comment 
  /* 
    This is a comment
  */ "
" Properly escaped Multi-Line\
  With comment \
  /* \
    This is a comment\
  */ "
