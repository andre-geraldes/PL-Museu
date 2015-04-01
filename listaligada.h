#ifndef _LISTALIGADAH_
#define _LISTALIGADAH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

struct listaLigada {
	struct data datay;
    char *nome;
    char *quem;
    char *fato;
    struct listaLigada * next;
};

void sortedInsert(struct listaLigada** head_ref, struct listaLigada* new_node);

struct listaLigada *novoNodo(struct data d, char * n, char * q, char * f);

int comparaDatas(struct data data1, struct data data2);

int compare (const void * a, const void * b);

char ** getNames(struct listaLigada* l, int k);

#endif