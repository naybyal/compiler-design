%{
  #include <stdio.h>
  #include <stdlib.h>
%}

identifier [a-zA-Z][a-zA-Z0-9]*
operator [+|-|/|*]
symbol [,()]

%%
#.* {
  printf("\n%s is a preprocessor directive\n", yytext);
}

"int" |
"float" |
"char" |
"double" |
"while" |
"for" |
"struct" |
"typedef" |
"do" |
"if" |
"break" |
"continue" |
"void" |
"switch" |
"return" |
"else" |
"goto" {
  printf("\n%s is a keyword.\n", yytext);
}

{identifier}(\[[0-9]*\])? {
  printf("\n%s is an identifier\n", yytext);
}

"=" {
  printf("\n%s is an assignment operator\n", yytext);
}

"<=" |
">=" |
"<" |
">" |
"==" {
  printf("\n%s is a relational operator\n", yytext);
}

{operator} {
  printf("\n%s is a binary operator\n", yytext);
}

{symbol} {
  printf("\n%s is a symbol\n", yytext);
}

\"[^\"]*\" {
  printf("\n%s is a string\n", yytext);
}

[0-9]+ {
  printf("\n%s is a number\n", yytext);
}

%%

int main() {
  FILE *file;
  file = fopen("var.c", "r");
  if (!file) {
    printf("No file found\n");
    return 1;
  }

  yyin = file;
  yylex();
  fclose(file);
  printf("\n");
  return 0;
}

int yywrap() {
    return 1;
}

