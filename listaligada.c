#include "data.h"
#include "listaligada.h"

/*void insertElem (struct listaLigada l, struct data d, char * n, char * q, char * f){
	
	if( l == NULL){
		struct listaLigada * new = (struct listaLigada *) malloc(sizeof(struct listaLigada));
		new->nome = n;
		new->quem = q;
		new->fato = f;
		new->next = NULL;
	}
	else {
		if (comparaDatas(d, l->data) == 1){
			insertElem(l->next, d, n, q, f);
		}
		else {
			if( )
		}
	}
	return new;
}*/

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

/* Function to print linked list */
void printList(struct listaLigada* head)
{
    struct listaLigada* temp = head;
    while(temp != NULL)
    {
        printf("%s\n", temp->quem);
        temp = temp->next;
    }
}