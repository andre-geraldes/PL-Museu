
/** Estrutura que guarda uma data **/

struct data {
struct nodo_avl {
    int data;
    char *nome;
    char *quem;
    char *fato;
    struct nodo_avl *esq;
    struct nodo_avl *direita;
};

/** Função que calcula a altura de um nodo **/
int altura (struct nodo_avl *nodo){
	int altura=0;
    if (nodo !=NULL){
        int altura_esq= altura(nodo ->esq);
        int altura_dir= altura(nodo -> dir);
        int max=0;
        if(altura_esq > altura_dir) max = altura_dir;
        altura = 1+ max;
    }
    return altura;
}

/** Função que calcula o fator de balanceamento de um nodo **/
int fator (struct nodo_avl *nodo){
	int altura_esq = altura(nodo->esq);
	int altura_dir = altura(nodo->dir);
	int dif = altura_esq - altura_dir;
	return dif;
}

/** Rotação Dir Dir **/
struct nodo_avl* rotacao_dir_dir(struct nodo_avl *pai){
	struct nodo_avl * nodo1;
	nodo1=pai->dir;
	pai->dir = nodo1->esq;
	nodo1->esq=pai;
	return nodo1;
}

/** Rotação Esq Esq **/
struct nodo_avl* rotacao_esq_esq(struct nodo_avl *pai){
	struct nodo_avl *nodo1;
	nodo1 = pai->esq;
	pai->esq = nodo1 ->dir;
	nodo1->dir = pai;
	return nodo1;
}

/**Rotação Dir Esq */
struct nodo_avl* rotacao_dir_esq(struct nodo_avl * pai)
{
	struct nodo_avl * nodo1;
	nodo1 = pai->dir;
	pai->dir = rotacao_esq_esq(nodo1);
	return rotacao_dir_dir(pai);
}

/** Rotação Esq Dir **/
struct nodo_avl* rotacao_esq_dir(struct nodo_avl * pai){

	struct nodo_avl *nodo1;
	nodo1 = pai->esq;
	pai->esq = rotacao_dir_dir(nodo1);
	return rotacao_esq_esq(pai);
}

/** Função para balancear a AVL **/
struct nodo_avl* balancear(struct nodo_avl *nodo)
{
    int bfator= fator(nodo);
    if (bfator >1) {
        if (fator(nodo->esq) >0)
            nodo=rotacao_esq_esq(nodo);
        else
            nodo=rotacao_esq_dir(nodo);
    }
    else if(bfator < -1) {
        if(fator(nodo ->dir) >0)
            nodo=rotacao_dir_esq(nodo);
        else
            nodo=rotacao_dir_dir(nodo);
    }
    return nodo;
}  

/** Função para inserir um elemento na AVL **/
struct nodo_avl* inserir(struct nodo_avl *raiz,int val, char* nom, char*que, char* fat)
{
    if (raiz==NULL) {
        raiz = (struct nodo_avl*) malloc(sizeof(struct nodo_avl));
        raiz -> data = val;
        raiz -> nome = nom;
        raiz -> quem = que;
        raiz -> fato = fat;
        raiz -> left = NULL;
        raiz -> right = NULL;
        return raiz;
    }
    else if (comparaDatas(val,raiz->data)==-1) {
        raiz->esq = inserir(raiz->esq, val);
        raiz=balancear(raiz);
    }
    else if (comparaDatas(val,raiz->data)==1) {
        raiz->dir = insert(raiz->dir, val);
        raiz=balancear(raiz);
    }
    return raiz;
}

/** Função que compara duas datas **/
int comparaDatas(data data1, data data2){
	if(data1->ano > data2->ano)return 1;
	else if(data1->ano < data2->ano) return -1;
	else {
		if(data1->mes > data2->mes)return 1;
		else if(data1->mes < data2->mes)return -1;
		else {
			if(data1->dia > data2->dia)return 1;
			else if(data1->dia <= data2->dia) return -1;
		}

}

/** Travessia inorder da AVL **/
void inorder(struct nodo_avl *arvore)
{
    if(arvore == NULL)
        return;
    else {
         inorder(arvore -> esq);
         printf("%d\t",esq ->data);
         inorder(arvore ->dir);
    }
}