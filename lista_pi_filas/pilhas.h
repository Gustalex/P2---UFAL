#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
   struct node *prox;
}node;

typedef struct pilha{
    node *topo;
}pilha;

pilha *criar_pilha(){
    pilha *nova_pilha = (pilha*)malloc(sizeof(pilha));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

void push(pilha *pilha, int item){
    node *novo_topo = (node*)malloc(sizeof(node));
    novo_topo->item = item;
    novo_topo->prox = pilha->topo;
    pilha->topo = novo_topo;
}
int isempty(pilha *pilha){
    return pilha->topo == NULL;
}

int pop(pilha *pilha){
    if(pilha->topo == NULL){
        printf("Pilha vazia\n");
        return -1;
    }
    node *topo = pilha->topo;
    pilha->topo = pilha->topo->prox;
    int item = topo->item;
    free(topo);
    return item;
}

int peek(pilha *pilha){
    if(pilha->topo == NULL){
        printf("Pilha vazia\n");
        return -1;
    }
    return pilha->topo->item;
}

int top(pilha *pilha){
    if(isempty(pilha)){
        printf("Pilha vazia\n");
        exit(1);
    }
    return pilha->topo->item;
}

void imprimir_pilha(pilha *pilha){
    node *atual = pilha->topo;
    while(atual != NULL){
        printf("%d ",atual->item);
        atual = atual->prox;
    }
    printf("\n");
}

void free_pilha(pilha *pilha){
    node *atual = pilha->topo;
    while(atual != NULL){
        node *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pilha);
}