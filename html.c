void newHeader(char *tit, FILE *fp) {
	fputs("<!DOCTYPE html>",fp);
	fputs("<html>",fp);
	fprintf(fp, "<title>%s</title>", tit);
	fputs("<h1>Museu da Pessoa</h1>",fp);
	fputs("</head>",fp);
}

void endHtml(FILE * fp) {
	fputs("</html>");
}