#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int valor;
    struct node* left;
    struct node* right;
} node;

typedef struct entrada {
    int valor;
    int key_left;
    int key_right;
} entrada;

node* criar_no(int valor) {
    node* novo_no = (node*)malloc(sizeof(node));
    novo_no->valor = valor;
    novo_no->left = NULL;
    novo_no->right = NULL;
    return novo_no;
}

node* criar_arvore(entrada* entradas, int indice) {
    if (indice == -1) return NULL;

    node* novo_no = criar_no(entradas[indice].valor);
    novo_no->left = criar_arvore(entradas, entradas[indice].key_left);
    novo_no->right = criar_arvore(entradas, entradas[indice].key_right);

    return novo_no;
}

void preencher(node* arvore, int* max, int* min, int nivel) {
    if (arvore == NULL) return;
    
    max[nivel] = (max[nivel] > arvore->valor) ? max[nivel] : arvore->valor;
    min[nivel] = (min[nivel] < arvore->valor) ? min[nivel] : arvore->valor;

    preencher(arvore->left, max, min, nivel + 1);
    preencher(arvore->right, max, min, nivel + 1);
}

int calcular_altura(node* arvore) {
    if (arvore == NULL) return 0;

    int altura_esquerda = calcular_altura(arvore->left);
    int altura_direita = calcular_altura(arvore->right);

    return (altura_esquerda > altura_direita ? altura_esquerda : altura_direita) + 1;
}

int main() {
    int num_entradas;
    scanf("%d", &num_entradas);
    entrada* entradas = (entrada*)malloc(num_entradas * sizeof(entrada));
    for (int i = 0; i < num_entradas; i++) {
        scanf("%d %d %d", &entradas[i].valor, &entradas[i].key_left, &entradas[i].key_right);
    }

    node* arvore = criar_arvore(entradas, 0);

    int altura = calcular_altura(arvore);

    int* max = (int*)malloc(altura * sizeof(int));
    int* min = (int*)malloc(altura * sizeof(int));
    for (int i = 0; i < altura; i++) {
        max[i] = INT_MIN;
        min[i] = INT_MAX;
    }

    preencher(arvore, max, min, 0);

    for (int i = 0; i < altura; i++) {
        printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, max[i], min[i]);
    }

    free(entradas);
    free(max);
    free(min);
    return 0;
}