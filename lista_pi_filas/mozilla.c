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
    node *topo = pilha->topo;
    pilha->topo = pilha->topo->prox;
    int item = topo->item;
    free(topo);
    return item;
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
    char *comando = (char *)malloc(10*sizeof(char));
    pilha *BACK = criar_pilha();
    pilha *FORWARD = criar_pilha();
    int cont_back = -1, cont_forward = 0;

    while(scanf(" %s", comando) != EOF){
        if(strcmp(comando, "ENTER") == 0){
            cont_back++;
            cont_forward = 0;
            push(BACK, cont_back);
            free_pilha(FORWARD);
            FORWARD = criar_pilha();
        }
        else if(strcmp(comando, "BACK") == 0){
            if(cont_back > 0){
                push(FORWARD, pop(BACK));
                cont_back--;
                cont_forward++;
            }
        }
        else{
            if(cont_forward > 0){
                push(BACK, pop(FORWARD));
                cont_back++;
                cont_forward--;
            }
        }
    }
    printf("BACK: %d\n", cont_back);
    printf("FORWARD: %d\n", cont_forward);
    free_pilha(BACK);
    free_pilha(FORWARD);
    free(comando);
    return 0;
}