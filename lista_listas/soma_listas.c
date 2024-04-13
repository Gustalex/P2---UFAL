#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *prox;
} node;

node* add(node **head, int item) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->item = item;
    new_node->prox = *head;
    *head = new_node;
    return *head;
}

node* inverter_lista(node* head) {
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current != NULL) {
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printar_lista(node* head) {
    head = inverter_lista(head); 
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (head != NULL && head->item == 0)  head = head->prox;
    
    if (head == NULL) printf("0");
    
    while (head != NULL) {
        printf("%d ", head->item);
        head = head->prox;
    }

    printf("\n");
}

node* criar_lista() {
    return NULL;
}

node* somar_listas(node* lista1, node* lista2) {
    node* result = NULL;
    node* prev = NULL;
    int vai_um = 0;

    while (lista1 != NULL || lista2 != NULL) {
        
        int sum = vai_um + (lista1 ? lista1->item : 0) + (lista2 ? lista2->item : 0);
        vai_um = sum / 10;
        sum = sum % 10;

        node* new_node = (node*)malloc(sizeof(node));
        new_node->item = sum;
        new_node->prox = NULL;

        if (result == NULL) result = new_node;
           
        else  prev->prox = new_node;
           
        prev = new_node;

        if (lista1) lista1 = lista1->prox;
        
        if (lista2) lista2 = lista2->prox;
           
    }

    if (vai_um > 0) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->item = vai_um;
        new_node->prox = NULL;
        prev->prox = new_node;
    }

    return result;
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

    int num;
    char sinal;

    while (scanf("%d%c", &num, &sinal) == 2) {
        lista1 = add(&lista1, num);
        if (sinal == '+') break;
    }

    while (scanf("%d%c", &num, &sinal) == 2) {
       lista2 = add(&lista2, num);
        if (sinal == '=') break;
    }

    node* result = somar_listas(lista1, lista2);
    
    printar_lista(result);
    free_lista(result);
    return 0;
}
