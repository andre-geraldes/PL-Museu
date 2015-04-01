#include "html.h"

void newHeader(char *tit, FILE *fp) {
	fputs("<!DOCTYPE html>",fp);
	fputs("<html>",fp);
	fputs("<meta charset=utf-8>",fp);
	fputs("<link rel=stylesheet type=text/css href=mystyle.css>",fp);
	//fprintf(fp,"<body bgcolor=#CCFF99>");
	fprintf(fp, "<title>%s</title>", tit);
	fputs("<font color=#006699><font face=arial><font size=5><h1><center>Museu da Pessoa</center></h1></font></font></font>",fp);
	fputs("</head>",fp);
}

void endHtml(FILE * fp) {
	fputs("</html>",fp);
}

void addImg(char * nomeImg, char * descricao, FILE *fp){
	fputs("<body>",fp);
	fprintf(fp, "<center><font face=arial><font size=2><font color=#006600><h2>%s</h2></font></font></font>", descricao);
	fprintf(fp, "<img class=resize src=\"%s\" alt=\"%s\" style=\"width:354px;height:508px\"></center>", nomeImg, descricao);
	fputs("</body>",fp);
}

void insertImg(struct listaLigada * a, FILE *fp) {
	struct listaLigada* temp = a;
    while(temp != NULL)
    {
        addImg(temp->nome, temp->quem, fp);
        temp = temp->next;
    }
}
