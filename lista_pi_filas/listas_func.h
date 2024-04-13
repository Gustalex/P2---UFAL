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

node* remover_node(node *head, int item) {
    node *prev = NULL;
    node *current = head;
    while (current != NULL && current->item != item) {
        prev = current;
        current = current->prox;
    }

    if (current == NULL) return head;
       
    if (prev == NULL)  head = current->prox;
       
    else prev->prox = current->prox;
    
    free(current);
    return head;
}

int check_vazia(node *head) {
    return (head == NULL);
}

void printar_lista(node *head) {
    while (head != NULL) {
        printf("%d\n", head->item);
        head = head->prox;
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

void free_lista(node *head) {
    node *aux;
    while (head != NULL) {
       aux = head;
       head = head->prox;
       free(aux);
    }
}

node* ordenar_lista(node *head){
    node *i, *j;
    int aux;
    for(i = head; i != NULL; i = i->prox){
        for(j = i->prox; j != NULL; j = j->prox){
            if(i->item > j->item){
                aux = i->item;
                i->item = j->item;
                j->item = aux;
            }
        }
    } 
    return head;
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

node* remover_repetidos(node *head){
    node *i, *j, *aux;
    for(i = head; i != NULL; i = i->prox){
        for(j = i->prox; j != NULL; j = j->prox){
            if(i->item == j->item){
                aux = j;
                j = j->prox;
                i->prox = j;
                free(aux);
            }
        }
    }
    return head;
}
