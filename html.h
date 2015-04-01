#ifndef _HTMLH_
#define _HTMLH_

#include <stdio.h>
#include "listaligada.h"

void newHeader (char *tit, FILE *fp);

void endHtml(FILE * fp);

void addImg(char * nomeImg, char * descricao, FILE *fp);

void insertImg(struct listaLigada * a, FILE *fp);

#endif