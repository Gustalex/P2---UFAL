#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
} LISTA;



void inicializar(LISTA *l)
{
    l->cabeca = NULL;
}


NO* criarNo(ITEM item, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
    pNovo->prox = prox;
    return pNovo;
}


int tamanho(LISTA *l)
{
    NO* p = l->cabeca;
    int tam = 0;
    while (p)
    {
        tam++;
        p = p->prox;
    }
    return tam;
}


bool vazia(LISTA *l)
{
    return l->cabeca == NULL;
}


void exibirLista(LISTA *l)
{
    NO* p = l->cabeca;
    while (p) 
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}


void destruir(LISTA *l)
{
    NO* atual = l->cabeca;
    while (atual) {
        NO* prox = atual->prox; 
        free(atual);       
        atual = prox;
    }
    l->cabeca = NULL;
}


void imprimirLista(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}

bool inserirNaOrdem(ITEM item, LISTA *l)
{

    NO* novo = criarNo(item, NULL);
    NO* anterior = NULL;
    NO* atual = l->cabeca;

    while (atual != NULL && atual->item.chave < item.chave){
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->item.chave == item.chave){
        free(novo);
        return false;
    }

    if (anterior == NULL){
        novo->prox = l->cabeca;
        l->cabeca = novo;
    }
    else{
        anterior->prox = novo;
        novo->prox = atual;
    }

    return true;
}


void lerItens(LISTA *l)
{
    int n;
    scanf("%d", &n);

    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        inserirNaOrdem(item, l);
    }
}


int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l);
    
  lerItens(&l);
  imprimirLista(&l);

  destruir(&l);
  return 0;
}
