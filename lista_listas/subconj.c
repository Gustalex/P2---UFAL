#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *prox;
} node;

node* criar_lista() {
    return NULL;
}

node* add(node *head, int item) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = item;
    new_node->prox = head;
    return new_node;
}

node* procurar(node *head, int item) {
    while (head != NULL) {
        if (head->item == item) {
            return head;
        }
        head = head->prox;
    }
    return NULL;
}

node* add_final(node *head, int item) {
   
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = item;
    new_node->prox = NULL;

    if (head == NULL) return new_node;
    
    node *current = head;
    while (current->prox != NULL) current = current->prox;
       
    current->prox = new_node;   
    return head;
}

void free_lista(node *head) {
    node *aux;
    while (head != NULL) {
       aux = head;
       head = head->prox;
       free(aux);
    }
}

int main() {
    node *lista1 = criar_lista();
    node *lista2 = criar_lista();

    int qtd1, qtd2;
    scanf("%d", &qtd1);
    for(int i = 0; i < qtd1; i++){
        int item;
        scanf("%d", &item);
        lista1 = add_final(lista1, item);
    }

    scanf("%d", &qtd2);
    for(int i = 0; i < qtd2; i++){
        int item;
        scanf("%d", &item);
        lista2 = add_final(lista2, item);
    }

    int cont = 0;
    node *aux = lista2;
    while(aux != NULL){
        if(procurar(lista1, aux->item) != NULL) cont++;
    
        aux = aux->prox;
    }

    if(cont == qtd2) printf("1\n");
    else printf("0\n");
    
    free_lista(lista1);
    free_lista(lista2);
    
    return 0;
}