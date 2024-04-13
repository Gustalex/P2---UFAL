#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

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

int pop(pilha *pilha){
    if(pilha->topo == NULL){
        printf("Pilha vazia\n");
        return -1;
    }
    node *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
}

void imprimir_pilha(pilha *pilha){
    node *atual = pilha->topo;
    while(atual != NULL){
        if(atual->prox == NULL) printf("%d",atual->item);

        else printf("%d ",atual->item);
        
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


int main(){

    char *comando = (char*)malloc(30*sizeof(char));
    pilha *pilha = criar_pilha();
    int valor;

    while(strcmp(comando, "Finalizar") != 0){

        scanf(" %s %d", comando, &valor);

        if(strcmp(comando,"Empilhar") == 0)  push(pilha, valor);

        else if(strcmp(comando,"Desempilhar") == 0) pop(pilha);

        else if(strcmp(comando,"Imprimir") == 0) imprimir_pilha(pilha);

    }

    free(comando);
    free_pilha(pilha);

    return 0;
}