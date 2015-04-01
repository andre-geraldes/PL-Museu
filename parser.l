%{
/* Declaracoes C diversas */
#include <stdio.h>
#include <string.h>
#include "data.h"
#include "listaligada.h"
#include "html.h"
char * foto;
char * facto;
char * quem;
char * quando;
int k = 0;
struct data da;
struct listaLigada * dados;
struct listaLigada * nodo;

/* Função que verifica se um determinado char é um digito*/
int digito(char d){
	int x = 0;
	if (d >= '0' && d <= '9') x = 1;
	return x;
}

/* Funçao que converte uma string num tipo de dados struct data */
struct data breakFoto (char * d){
	struct data new;
	char ano[5], mes[3], dia[3];
	if(!digito(quando[0])) {
		new.ano = 1;
		new.mes = 1;
		new.dia = 1;
		return new;
	}

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

/* Função para remover tabs e espaços seguidos de uma string */
char * trim(char * q){
	int i, j;
	for(i=0; q[i] != '\0'; i++){
		if(q[i] == '\n' || q[i] == '\t') q[i] = ' ';
		if((q[i] == ' ') && (q[i+1] == ' ')){
			for(j=i; q[j] != '\0'; j++) q[j] = q[j+1];
		} 
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
<QUEM1>[^<]+						{ quem = strdup(yytext); quem = trim(quem); k++; }

"<"(?i:FACTO)">"					{ BEGIN FACTO1; }
<FACTO1>"<"	 						{ BEGIN INITIAL; } 
<FACTO1>[^<]+	 					{ facto = strdup(yytext); }

"<"(?i:QUANDO)" "(?i:DATA)"=\""		{ BEGIN QUANDO1; }
<QUANDO1>"\""						{ BEGIN INITIAL; } 
<QUANDO1>[^\"]+ 					{ quando = strdup(yytext); 
									  da = breakFoto(quando); }

"<"(?i:FOTO)" "(?i:FICHEIRO)"=\""	{ BEGIN FOTO1; }
<FOTO1>"\""	 						{ BEGIN INITIAL; } 
<FOTO1>[^\"]+						{ foto = strdup(yytext); }
									  
"</foto>"							{	nodo = novoNodo(da, foto, quem, facto);
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
	html = fopen("museu.html","w");
	newHeader("Museu da Pessoa", html);
	yylex(); 
	insertImg(dados, html);
	endHtml(html);
	fclose(html);
	return 0; 
}