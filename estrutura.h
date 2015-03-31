#ifndef _ESTRUTURAH_
#define _ESTRUTURAH_

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct nodo_avl {
    struct data datay;
    char *nome;
    char *quem;
    char *fato;
    struct nodo_avl *esq;
    struct nodo_avl *dir;
};

/** Função que calcula a altura de um nodo **/
int altura (struct nodo_avl *nodo);

/** Função que calcula o fator de balanceamento de um nodo **/
int fator (struct nodo_avl *nodo);

/** Rotação Dir Dir **/
struct nodo_avl* rotacao_dir_dir(struct nodo_avl *pai);

/** Rotação Esq Esq **/
struct nodo_avl* rotacao_esq_esq(struct nodo_avl *pai);

/**Rotação Dir Esq */
struct nodo_avl* rotacao_dir_esq(struct nodo_avl * pai);

/** Rotação Esq Dir **/
struct nodo_avl* rotacao_esq_dir(struct nodo_avl * pai);

/** Função para balancear a AVL **/
struct nodo_avl* balancear(struct nodo_avl *nodo);

/** Função para inserir um elemento na AVL **/
struct nodo_avl* inserir(struct nodo_avl *raiz, struct data val, char* nom, char*que, char* fat);

/** Função que compara duas datas **/
int comparaDatas(struct data data1, struct data data2);

/** Travessia inorder da AVL **/
void inorder(struct nodo_avl *arvore);

struct list * insertList(struct list * no);

#endif