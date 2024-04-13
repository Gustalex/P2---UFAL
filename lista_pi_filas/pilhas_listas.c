#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LISTA{
    int num;
    struct LISTA* next;
} LISTA;

typedef struct node{
    LISTA* lista;
    struct node* next;
} node;

typedef struct pilha{
    node* top;
} pilha;

LISTA *criar_lista(){
    return NULL;
}

pilha* criar_pilha(){
    pilha* nova_pilha = (pilha*)malloc(sizeof(pilha));
    nova_pilha->top = NULL;
    return nova_pilha;
}

void PUSH(pilha* pilha, LISTA* lista){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->lista = lista;
    newNode->next = pilha->top;
    pilha->top = newNode;
}

void POP(pilha* pilha) {
    if (pilha->top == NULL) {
        printf("EMPTY STACK\n");
        return;
    }
    node* temp = pilha->top;
    pilha->top = pilha->top->next;

    LISTA* lista_temp = temp->lista;
    while (lista_temp != NULL) {
        if(lista_temp->next == NULL) printf("%d", lista_temp->num);
        else printf("%d ", lista_temp->num);
        LISTA* lixo = lista_temp;
        lista_temp = lista_temp->next;
        free(lixo);
    }
    printf("\n");

    free(temp);
}

void freepilha(pilha* pilha){
    while (pilha->top != NULL){
        node* temp = pilha->top;
        pilha->top = pilha->top->next;

        LISTA* lista_temp = temp->lista;
        while (lista_temp != NULL){
            LISTA* lixo = lista_temp;
            lista_temp = lista_temp->next;
            free(lixo);
        }
        free(temp);
    }
    free(pilha);
}

int main(){
    pilha* pilha = criar_pilha();
    char *comando = (char*)malloc(5 * sizeof(char));

    while(scanf(" %s", comando) != EOF){
        if(strcmp(comando, "PUSH") == 0){
            LISTA *lista = criar_lista();
            LISTA **lista_pntr = &lista;
            int num;
            while(scanf("%d", &num) == 1){
                *lista_pntr = (LISTA*)malloc(sizeof(LISTA));
                (*lista_pntr)->num = num;
                (*lista_pntr)->next = NULL;
                lista_pntr = &((*lista_pntr)->next);
            }
            PUSH(pilha, lista);
        }
            else POP(pilha);
    }
    free(comando);
    freepilha(pilha);
    return 0;
}