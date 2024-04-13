#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct binary_tree{
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
}binary_tree;

binary_tree *criar_vazia(){
    return NULL;
}

binary_tree *criar_arvore(int item, binary_tree *left, binary_tree *right){
    binary_tree *new_tree = (binary_tree*)malloc(sizeof(binary_tree));
    new_tree->item = item;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}

binary_tree *construir(char **entrada){
    if(**entrada == '(') (*entrada)++;
    if(**entrada == ')'){
        (*entrada)++;
        return NULL;
    }
    char *num = (char*)malloc(100*sizeof(char));
    int i = 0;
    while(**entrada != '(' && **entrada != ')' && **entrada != '\0'){
        num[i++] = **entrada;
        (*entrada)++;
    }
    num[i] = '\0';
    int item = atoi(num);
    binary_tree *node = criar_arvore(item, NULL, NULL);
#
    node->left = construir(entrada);
    node->right = construir(entrada);

    if(**entrada == ')') (*entrada)++;
    free(num);
    return node;
}

int is_valid(binary_tree *root, int min, int max){
    if(root == NULL) return 1;
    if(root->item < min || root->item > max) return 0;
    return is_valid(root->left, min, root->item) && is_valid(root->right, root->item, max);
    // && so retorna 1 se os dois retornarem 1
}
int main(){

    char *entrada = (char*)malloc(100*sizeof(char));
    
    fgets(entrada, 100, stdin);
    if(entrada[strlen(entrada)-1] == '\n') entrada[strlen(entrada)-1] = '\0';

    binary_tree *arvore = construir(&entrada); 
    
    if(is_valid(arvore, INT_MIN, INT_MAX)) printf("VERDADEIRO\n");
    else printf("FALSO\n");
    return 0;
}