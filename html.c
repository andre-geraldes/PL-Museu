#include "html.h"

void newHeader(char *tit, FILE *fp) {
	fputs("<!DOCTYPE html>",fp);
	fputs("<html>",fp);
	fprintf(fp, "<title>%s</title>", tit);
	fputs("<h1>Museu da Pessoa</h1>",fp);
	fputs("</head>",fp);
}

void endHtml(FILE * fp) {
	fputs("</html>",fp);
}

void addImg(char * nomeImg, char * descricao, FILE *fp){
	fputs("<body>",fp);
	fprintf(fp, "<h2>%s</h2>", descricao);
	fprintf(fp, "<img src=\"%s\" alt=\"%s\" style=\"width:354px;height:508px\">", nomeImg, descricao);
	fputs("</body>",fp);
}

/*void insertImg(struct nodo_avl * a) {
	while (a != NULL){

	}
}*/