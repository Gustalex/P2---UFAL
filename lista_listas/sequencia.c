#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int item;
    struct node *prox;
} node;

node* criar_lista() {
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
void maior_sequencia(node *head) {
    int cont_max = 0, cont = 0;
    int max_start = 0, curr_start = 0;
    int pos = 0;
    node *current = head;

    while (current != NULL) {
        if (current->item == 0) {
            if (cont == 0) {
                curr_start = pos;
            }
            cont++;
        } else {
            if (cont > cont_max) {
                cont_max = cont;
                max_start = curr_start;
            }
            cont = 0;
        }
        current = current->prox;
        pos++;
    }
    if (cont > cont_max) {
        cont_max = cont;
        max_start = curr_start;
    }

    printf("%d %d\n", max_start, max_start + cont_max - 1);
}

int main() {
    char *sequencia = (char*) malloc(sizeof(char) * 100);

    while (fgets(sequencia, 100, stdin)) {
        sequencia[strcspn(sequencia, "\n")] = 0;

        if (strcmp(sequencia, "0") == 0 && strlen(sequencia) == 1) {
            break;
        }

        node *lista = criar_lista();
        for (int i = 0; sequencia[i] != 0; i++) {
            if (sequencia[i] == '0' || sequencia[i] == '1') {
               lista = add_final(lista, sequencia[i] - '0');
            }
        }

        maior_sequencia(lista);
        free_lista(lista);

    }
        free(sequencia);
    return 0;
}