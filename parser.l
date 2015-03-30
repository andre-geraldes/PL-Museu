%{
/* Declaracoes C diversas */
#include <stdio.h>
#include <string.h>
char * foto;
char * facto;
char * quem;
char * quando;
%}



%x QUEM1
%x FACTO1
%x FOTO1
%x QUANDO1

%%
"<"(?i:QUEM)">" 					{ BEGIN QUEM1; }
<QUEM1>"<"	 						{ BEGIN INITIAL; } 
<QUEM1>[^<]+						{ quem = strdup(yytext); printf("%s\n", quem);}

"<"(?i:FACTO)">"					{ BEGIN FACTO1; }
<FACTO1>"<"	 						{ BEGIN INITIAL; } 
<FACTO1>[^<]+	 					{ facto = strdup(yytext); printf("%s\n", facto); }

"<"(?i:FOTO)" "(?i:FICHEIRO)"=\""	{ BEGIN FOTO1; }
<FOTO1>"\""	 						{ BEGIN INITIAL; } 
<FOTO1>[^\"]+						{ foto = strdup(yytext); printf("%s\n", foto); }

"<"(?i:QUANDO)" "(?i:DATA)"=\""		{ BEGIN QUANDO1; }
<QUANDO1>"\""						{ BEGIN INITIAL; } 
<QUANDO1>[^\"]+ 					{ quando = strdup(yytext); printf("%s\n", quando); }

.|\n								{ ; }
%%

int yywrap()
{ 
	return(1); 
}

int main()
{ 
	yylex(); 
	return 0; 
}