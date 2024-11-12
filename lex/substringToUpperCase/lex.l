%{
  #include <stdio.h>
  #include <stdlib.h>
  
  int i;
%}

%%

[a-zA-z]* {
  for (i=0; i<=yyleng; i++) {
    if ((yytext[i] == 'a') && (yytext[i+1] == 'b') && (yytext[i+2] == 'c')) {
      yytext[i] = 'A';
      yytext[i+1] = 'B';
      yytext[i+2] = 'C';
    }
  }
  printf("\n%s\n", yytext);
}

[\t]* {
    return 1;
}

.* {
  ECHO;
}

\n {
  printf("%s", yytext);
}

%%

int main() {
  yylex();
}

int yywrap() {
  return 1;
}
