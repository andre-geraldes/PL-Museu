#include "html.h"


void criaHeader(char *tit, FILE *fp) {
	fputs("<!DOCTYPE html><html lang=\"pt\"><head>",fp);
	fprintf(fp, "<title>%s</title>", tit);
	fputs("</head>",fp);
}