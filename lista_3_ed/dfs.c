#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int item;
    struct lista *next;
} lista;

typedef struct lista_nomes{
    int index;
    char name[16];
    struct lista_nomes *next;
} lista_nomes;

typedef struct grafo{
    int size;
    int *visitado;
    lista **list_adj;
} grafo;

grafo *criar_grafo(){
    grafo *grf = (grafo *)malloc(sizeof(grafo));
    grf->size = 100;
    grf->list_adj = (lista **)malloc(grf->size * sizeof(lista *));
    grf->visitado = (int *)malloc(grf->size * sizeof(int));
    memset(grf->visitado, 1, grf->size * sizeof(int));
    memset(grf->list_adj, 0, grf->size * sizeof(lista *));
    return grf;
}

lista *add_node(lista *head, int item){
    lista *new_node = (lista *)malloc(sizeof(lista));
    new_node->item = item;
    new_node->next = head;
    return new_node;
}

int verificar_nomes(const char *name1, const char *name2){
    return strcmp(name1, name2) <= 0;
}

lista_nomes *add_lista_nome(lista_nomes *head, const char name[16], int item){
    lista_nomes *new_node = (lista_nomes *)malloc(sizeof(lista_nomes));
    new_node->index = item;
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (head == NULL || verificar_nomes(name, head->name)){
        new_node->next = head;
        return new_node;
    }
    lista_nomes *current = head;
    lista_nomes *prev = NULL;
    while (current != NULL && verificar_nomes(current->name, name)){
        prev = current;
        current = current->next;
    }
    prev->next = new_node;
    new_node->next = current;

    return head;
}

lista *remove_node(lista *head, int item){
    if (head == NULL) return head;
    lista *current = head;
    lista *prev = NULL;
    while (current != NULL && current->item != item){
        prev = current;
        current = current->next;
    }
    if (current == NULL) return head;
    if (prev == NULL)  head = head->next;
    else prev->next = current->next;
    free(current);
    return head;
}

lista_nomes *remover_lista_nomes(lista_nomes *head, int item){
    if (head == NULL) return head;
    lista_nomes *current = head;
    lista_nomes *prev = NULL;
    while (current != NULL && current->index != item){
        prev = current;
        current = current->next;
    }
    if (current == NULL) return head;
    if (prev == NULL) head = head->next;
    else prev->next = current->next;
    free(current);
    return head;
}

int nomes_index(lista_nomes *head, const char name[]){
    lista_nomes *aux = head;
    while (aux != NULL && strcmp(aux->name, name) != 0) aux = aux->next;
    if (aux != NULL) return aux->index;
    return -1;
}

void rmv_aresta(grafo *grf, int size, int index){
    for (int i = 0; i < size; i++) {
        grf->list_adj[i] = remove_node(grf->list_adj[i], index);
    }
}

void print_lista_nomes(lista_nomes *head){
    lista_nomes *aux = head;
    while (aux != NULL){
        printf("%s\n", aux->name);
        aux = aux->next;
    }
}

void dfs(grafo *grf, lista_nomes *in, int size){
    while (in != NULL) {
        lista_nomes *aux = in;
        lista_nomes *xesquedele = NULL;
        while (aux != NULL){
            int index = nomes_index(in, aux->name);
            if(grf->list_adj[index] == NULL) xesquedele = add_lista_nome(xesquedele, aux->name, index);
            aux = aux->next;
        }
        print_lista_nomes(xesquedele);
        aux = xesquedele;
        while (aux != NULL) {
            rmv_aresta(grf, size, aux->index);
            in = remover_lista_nomes(in, aux->index);
            aux = aux->next;
        }
    }
}

void add_aresta(grafo *grf, int x, int y){
    grf->list_adj[x] = add_node(grf->list_adj[x], y);
}

int main(){
    while(1){
        int num_entrada, size = 0;
        if (scanf("%d", &num_entrada) == EOF) return 0;
        grafo *grf = criar_grafo();
        lista *lista = NULL;
        lista_nomes *lista_nomes = NULL;
        char str1[16], str2[16];
        for (int i = 0; i < num_entrada; i++){
            scanf("%s %s", str1, str2);
            int index1 = nomes_index(lista_nomes, str1);
            if (index1 == -1){
                lista_nomes = add_lista_nome(lista_nomes, str1, size);
                index1 = size;
                size++;
            }
            int index2 = nomes_index(lista_nomes, str2);
            if (index2 == -1){
                lista_nomes = add_lista_nome(lista_nomes, str2, size);
                index2 = size;
                size++;
            }
            add_aresta(grf, index1, index2);
        }
        dfs(grf, lista_nomes, size);
    }
    return 0;
}
