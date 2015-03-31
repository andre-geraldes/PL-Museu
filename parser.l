%{
/* Declaracoes C diversas */
#include <stdio.h>
#include <string.h>
//#include "data.h"
//#include "estrutura.h"
#include "listaLigada.h"
#include "html.h"
char * foto;
char * facto;
char * quem;
char * quando;
struct data da;
struct listaLigada * dados = NULL ;
struct listaLigada * nodo;

/* Funçao que converte uma string num tipo de dados struct data */
struct data breakFoto (char * d){
	struct data new;
	char ano[5];
	char mes[3];
	char dia[3];
	int i = 0, j = 0;
	for(i=0; i < 4; i++) ano[i] = d[j++];
	ano[i] = '\0';
	j++;
	for(i=0; i < 2 ; i++) mes[i] = d[j++];
	j++;
	mes[i] = '\0';
	for(i=0; i < 2 ; i++) dia[i] = d[j++];
	dia[i] = '\0';
	new.ano = atoi(ano);
	new.mes = atoi(mes);
	new.dia = atoi(dia);
	return new;
}

char * trim(char * q){
	int i;
	for(i=0; q[i] != '\0'; i++){
		if(q[i] == '\n' || q[i] == '\t') q++;
	}
	return q;
}

%}


%x QUEM1
%x FACTO1
%x FOTO1
%x QUANDO1

%%
"<"(?i:QUEM)">" 					{ BEGIN QUEM1; }
<QUEM1>"<"	 						{ BEGIN INITIAL; } 
<QUEM1>[^<]+						{ quem = strdup(yytext); quem = trim(quem); }

"<"(?i:FACTO)">"					{ BEGIN FACTO1; }
<FACTO1>"<"	 						{ BEGIN INITIAL; } 
<FACTO1>[^<]+	 					{ facto = strdup(yytext); }

"<"(?i:FOTO)" "(?i:FICHEIRO)"=\""	{ BEGIN FOTO1; }
<FOTO1>"\""	 						{ BEGIN INITIAL; } 
<FOTO1>[^\"]+						{ foto = strdup(yytext); }

"<"(?i:QUANDO)" "(?i:DATA)"=\""		{ BEGIN QUANDO1; }
<QUANDO1>"\""						{ BEGIN INITIAL; } 
<QUANDO1>[^\"]+ 					{ quando = strdup(yytext); 
									  da = breakFoto(quando); 
									  nodo = novoNodo(da, foto, quem, facto);
									  sortedInsert(&dados, nodo); }

.|\n								{ ; }
%%

int yywrap()
{ 
	return(1); 
}

int main()
{ 
	FILE * html;
	html = fopen("new.html","w");
	newHeader("Museu da Pessoa", html);
	yylex(); 
	printList(dados);
	endHtml(html);
	fclose(html);
	return 0; 
}