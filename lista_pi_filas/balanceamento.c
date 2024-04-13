#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int item;
    struct node *prox;
} node;

typedef struct pilha {
    node *topo;
} pilha;

pilha *criar_pilha(int tamanho) {
    pilha *nova_pilha = (pilha *)malloc(sizeof(pilha));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

void push(pilha *pilha, int item) {
    node *novo_topo = (node *)malloc(sizeof(node));
    novo_topo->item = item;
    novo_topo->prox = pilha->topo;
    pilha->topo = novo_topo;
}

int isempty(pilha *pilha) {
    return pilha->topo == NULL;
}

int pop(pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return -1;
    }
    node *topo = pilha->topo;
    pilha->topo = pilha->topo->prox;
    int item = topo->item;
    free(topo);
    return item;
}

int peek(pilha *pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return -1;
    }
    return pilha->topo->item;
}

void free_pilha(pilha *pilha) {
    node *atual = pilha->topo;
    while (atual != NULL) {
        node *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pilha);
}

int comparar_expressao(char *expressao) {
    pilha *p = criar_pilha(strlen(expressao) + 1);
    int i = 0;

    while (expressao[i] != '\0') {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            push(p, expressao[i]);
        } else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            if (isempty(p)) return 0;
            if (expressao[i] == ')' && peek(p) == '(') pop(p);
            else if (expressao[i] == ']' && peek(p) == '[') pop(p);
            else if (expressao[i] == '}' && peek(p) == '{') pop(p);
            else return 0;
        }
        i++;
    }

    if (isempty(p)) {
        free_pilha(p);
        return 1;
    } else {
        free_pilha(p);
        return 0;
    }
}

int main() {
    int qtd;
    char *expressao = (char *)malloc(100 * sizeof(char));

    scanf("%d\n", &qtd);

    for (int i = 0; i < qtd; i++) {
        fgets(expressao, 100, stdin);
        expressao[strcspn(expressao, "\n")] = 0;

        int j = 0;
        while (expressao[j] != '\0') {
            if (expressao[j] != ' ') break;
            j++;
        }
        if (expressao[j] == '\0') printf("Yes\n");
        else {
            if (comparar_expressao(expressao)) printf("Yes\n");
            else printf("No\n");
        }
    }

    free(expressao);
    return 0;
}