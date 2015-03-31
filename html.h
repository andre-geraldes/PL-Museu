#ifndef _HTMLH_
#define _HTMLH_

#include <stdio.h>

void newHeader (char *tit, FILE *fp);

void endHtml(FILE * fp);

void addImg(char * nomeImg, char * descricao, FILE *fp);

#endif