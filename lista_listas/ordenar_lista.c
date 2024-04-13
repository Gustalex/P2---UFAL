#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void printar_lista(node *head) {
    while (head != NULL) {
        printf("%d ", head->item);
        head = head->prox;
    }
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

    node *head = criar_lista();
    int item;
    while(scanf("%d", &item) != EOF){
    head = add(head, item);
    }
    head = ordenar_lista(head);
    printar_lista(head);
    free_lista(head);
    return 0;
}