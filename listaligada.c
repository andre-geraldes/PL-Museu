#include "listaligada.h"


void sortedInsert(struct listaLigada** head_ref, struct listaLigada* new_node)
{
    struct listaLigada* atual;
    /* Special case for the head end */
    if (*head_ref == NULL || (comparaDatas((*head_ref)->datay, new_node->datay) == 1))
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        atual = *head_ref;
        while (atual->next != NULL &&
               (comparaDatas(atual->next->datay, new_node->datay) != 1))
        {
            atual = atual->next;
        }
        new_node->next = atual->next;
        atual->next = new_node;
    }
}

struct listaLigada *novoNodo(struct data d, char * n, char * q, char * f){
    struct listaLigada * new = (struct listaLigada *) malloc(sizeof(struct listaLigada));
	new->datay = d;
	new->nome = n;
	new->quem = q;
	new->fato = f;
	new->next = NULL;

	return new;
}


/** Função que compara duas datas, retorna 1 se a data1 for mais recente **/
int comparaDatas(struct data data1, struct data data2){
	if(data1.ano > data2.ano)return 1;
	else if(data1.ano < data2.ano) return -1;
	else {
		if(data1.mes > data2.mes)return 1;
		else if(data1.mes < data2.mes)return -1;
		else {
			if(data1.dia > data2.dia)return 1;
			else if(data1.dia <= data2.dia) return -1;
		}
    }
    return -1;
}

/** Função para utilização do qsort */
int compare (const void * a, const void * b)
{
    return strcmp (*(const char **) a, *(const char **) b);
}

/** Função que retira os nomes da lista ligada, ordena e guarda num array de strings */
char ** getNames(struct listaLigada* l, int k){
	int maior = 0;
	int i;
	struct listaLigada * n = l;
	while(n != NULL){
		if(strlen(n->quem) > maior) maior = strlen(n->quem);
		n = n->next;
	}
	char ** new;
	new = malloc(k * maior * sizeof(char*)); 
	for(i = 0; i < k; i++) {
		new[i] = malloc(maior* sizeof(l->quem));
		strcpy(new[i],l->quem);
		if(new[i][0] == ' ') {
			for(int h = 0; h < strlen(new[i]); h++) new[i][h] = new[i][h+1];
		}
		l = l->next;
	}
	qsort(new, k, sizeof(const char *), compare);
	return new;
}
