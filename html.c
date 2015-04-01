#include "html.h"

void newHeader(char *tit, FILE *fp) {
	fputs("<!DOCTYPE html>\n",fp);
	fputs("<html>\n",fp);
	fputs("<meta charset=utf-8>\n",fp);
	fputs("<link rel=stylesheet type=text/css href=mystyle.css>\n",fp);
	fprintf(fp,"<body bgcolor= #0C090A>\n");
	fprintf(fp, "<title>%s</title>\n", tit);
	fputs("<font color=##95B9C7><font face=arial><font size=5><h1><center>Museu da Pessoa</center></h1></font></font></font>\n",fp);
	fputs("</head>\n",fp);
}

void endHtml(FILE * fp) {
	fputs("</html>\n",fp);
}

void addImg(char * nomeImg, char * descricao, FILE *fp){
	fputs("<body>\n",fp);
	fprintf(fp, "<center><div class=polaroid><font face=arial><font size=2><font color=#F0FFFF><h2>%s</h2></font></font></font>\n", descricao);
	fprintf(fp, "<img src=\"%s\" alt=\"%s\" style=\"width:354px;height:508px\"><br></div></center>\n", nomeImg, descricao);
	fputs("</body>\n",fp);
}

void insertImg(struct listaLigada * a, FILE *fp) {
	struct listaLigada* temp = a;
    while(temp != NULL)
    {
        addImg(temp->nome, temp->quem, fp);
        temp = temp->next;
    }
}


