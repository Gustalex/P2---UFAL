#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int item;
    struct node *next;
} node;

typedef struct grafo {
    int *distancia;
    int *anterior;
    int qtd_vertices;
    node **matriz;
} grafo;

typedef struct _queue {
    int *itens;
    int head;
    int tail;
    int size;
    int capacity;
} queue;

queue *criar_fila(int size) {
    queue *new_queue = (queue*)malloc(sizeof(queue));
    memset(new_queue, 0, sizeof(queue));
    new_queue->itens = (int*)malloc(size * sizeof(int));
    memset(new_queue->itens, 0, size * sizeof(int));
    new_queue->capacity = size;
    return new_queue;
}

node *createnode(int item) {
    node *new_node = (node*)calloc(1, sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    return new_node;
}

grafo *criar_grafo(int size){
    grafo *new_grafo = (grafo*)malloc(sizeof(grafo));
    memset(new_grafo, 0, sizeof(grafo));
    new_grafo->matriz = (node**)malloc(size * sizeof(node*));
    new_grafo->distancia = (int*)malloc(size * sizeof(int));
    new_grafo->anterior = (int*)malloc(size * sizeof(int));
    memset(new_grafo->matriz, 0, size * sizeof(node*));
    memset(new_grafo->distancia, 0, size * sizeof(int));
    memset(new_grafo->anterior, 0, size * sizeof(int));
    new_grafo->qtd_vertices = size;
    return new_grafo;
}


void enfileira(queue *fila, int item) {
    fila->itens[fila->tail] = item;
    fila->tail++;
    fila->size++;
}

int vazia(queue *fila){
    return fila->size == 0;
}

int desenfileira(queue *fila){
    int item = fila->itens[fila->head];
    fila->head = (fila->head + 1) % fila->capacity;
    fila->size--;
    return item;
}

void add_aresta(grafo *grafo, int origem, int destino) {
    node *new_node = createnode(destino);
    new_node->item = destino;
    new_node->next = NULL;
    if (grafo->matriz[origem] == NULL || destino <= grafo->matriz[origem]->item) {
        new_node->next = grafo->matriz[origem];
        grafo->matriz[origem] = new_node;
        return;
    }
    node *prev = NULL;
    node *current = grafo->matriz[origem];
    while (current && destino > current->item) {
        prev = current;
        current = current->next;
    }
    new_node->next = current;
    prev->next = new_node;
    return;
}

void busca(grafo *grafo, int origem, int destino) {
    int n = grafo->qtd_vertices;
    queue *fila = criar_fila(n);
    for (int i = 0; i < n; i++) {
        grafo->distancia[i] = -1;
        grafo->anterior[i] = -1;
    }
    grafo->distancia[origem] = 0;
    enfileira(fila, origem);
    while (!vazia(fila)) {
        int currentvertex = desenfileira(fila);
        printf("Iniciando busca em largura a partir de %d\n", currentvertex);
        node *aux = grafo->matriz[currentvertex];
        while (aux != NULL) {
            int adjVertex = aux->item;
            if (grafo->distancia[adjVertex] == -1) {
                grafo->distancia[adjVertex] = grafo->distancia[currentvertex] + 1;
                grafo->anterior[adjVertex] = currentvertex;
                enfileira(fila, adjVertex);
            }
            aux = aux->next;
        }
    }
    printf("\n");
    free(fila->itens);
    free(fila);
}

void printar_caminho(int anterior[], int origem, int destino){
    if (origem == destino) printf("%d", origem); 
    else{
        printar_caminho(anterior, origem, anterior[destino]);
        printf(" => %d", destino);
    }
    return;
}

int main() {
    int casos, arestas, vertices;
    scanf("%d %d %d", &vertices, &arestas, &casos);
    grafo *grafo = criar_grafo(vertices);
    for (int i = 1; i <= arestas; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        add_aresta(grafo, vertex1, vertex2);
    }
    for (int i = 1; i <= casos; i++) {
        int origem, destino;
        scanf("%d %d", &origem, &destino);
        printf("\n");
        printf("--------\n");
        printf("\n");
        printf("Caso de Teste #%d - BFS(%d)\n\n", i, origem);
        busca(grafo, origem, destino);
        for (int i = 0; i < vertices; i++){
            if (grafo->distancia[i] == -1) printf("%d | - | -\n", i);
            else if (grafo->distancia[i] == 0) printf("%d | %d | -\n", i, grafo->distancia[i]);  
            else printf("%d | %d | %d\n", i, grafo->distancia[i], grafo->anterior[i]);  
        }
        if (grafo->distancia[destino] == -1) printf("\nSem caminho entre %d e %d\n", origem, destino);
        else {
            printf("\n");
            printf("Caminho entre %d e %d: ", origem, destino);
            printar_caminho(grafo->anterior, origem, destino);
            printf("\n");
        }
    }
    printf("\n--------\n");
    return 0;
}