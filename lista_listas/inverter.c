#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *prox;
} node;

node* criar_lista() {
    return NULL;
}

void free_lista(node *head) {
    node *aux;
    while (head != NULL) {
       aux = head;
       head = head->prox;
       free(aux);
    }
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

void printar_lista(node *head) {
    while (head != NULL) {
        printf("%d ", head->item);
        head = head->prox;
    }
}

node* inverter_lista(node *head){
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while(current != NULL){
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }
    head = prev;
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

int main(){

    node *lista = criar_lista();
    int item;

    while(scanf("%d",&item) != EOF){
        lista = add_final(lista, item);
    }

    lista = inverter_lista(lista);
    printar_lista(lista);
    free_lista(lista);

    return 0;
}