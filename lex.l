
%option noyywrap
%option noinput
%option nounput

%{ 
#include "lex.tab.h"
%}

/*Definitions*/
NUMBERS		 ([0-9]*)|0x[0-9a-fA-F]+|[0-9]*[eE][0-9]* 
WORDS        [a-zA-Z]([a-zA-Z0-9]|_)*
COMMENT     "/*"([^*]|[*]+[^*/])*"*/"
ENDLINE      [ ]*\n


/*Rules*/
%%
" " 


"void"      { return tVOID; }
"if"        { return tIF; }
"else"      { return tELSE; }
"while"     { return tWHILE; }
"printf"     { return tPRINT; }
"return"    { return tRETURN; }
"int"       { return tINT; }
"const"     { return tCONST; }
"main"     { return tMain;} 

"("         { return tLPAR; }
")"         { return tRPAR; }
"{"         { return tLBRACE; }
"}"         { return tRBRACE; }

";"         { return tSEMI; }
","         { return tCOMMA; }

"="         { return tASSIGN ; }
"=="        { return tEQ; }
"<"         { return tLT; }
">"         { return tGT; }
"!="        { return tNE; }
">="        { return tGE; }
"<="        { return tLE; }

"+"         { return tADD; }
"*"         { return tMUL; }
"/"         { return tDIV; }
"-"         { return tSUB; }
{ENDLINE}

{COMMENT}
{WORDS}     { yylval.c= strdup(yytext); return tID; }
{NUMBERS}   { yylval.num= atoi(yytext);return tNB;}


.           { return tERROR ; }

%%
