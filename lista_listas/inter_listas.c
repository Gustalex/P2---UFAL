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

void printar_lista(node *head) {
    while (head != NULL) {
        printf("%d\n", head->item);
        head = head->prox;
    }
}

int check_vazia(node *head) {
    return (head == NULL);
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

void free_lista(node *head) {
    node *aux;
    while (head != NULL) {
       aux = head;
       head = head->prox;
       free(aux);
    }
}

int main(){

    node *lista1 = criar_lista();
    node *lista2 = criar_lista();
    node *intersec = criar_lista();

    int num;
    for(int i = 0; i < 20; i++){
        scanf("%d",&num);
        if(procurar(lista1,num)==NULL) lista1 = add(lista1,num);
    } 

    for(int i = 0; i < 20; i++){
        scanf("%d",&num);
        if(procurar(lista2,num) == NULL) lista2 = add(lista2,num);
    }

    node *aux = lista1;
    while(aux != NULL){
        if(procurar(lista2, aux->item) != NULL  && procurar(intersec, aux->item) == NULL) intersec = add(intersec, aux->item);
        aux = aux -> prox;
    }

    intersec = ordenar_lista(intersec);

    if(check_vazia(intersec)) printf("VAZIO\n");
    else printar_lista(intersec);

    free_lista(lista1);
    free_lista(lista2);
    free_lista(intersec);

    return 0;
}