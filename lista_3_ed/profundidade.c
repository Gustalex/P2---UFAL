#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nivel = 0;

typedef struct node{
    int item;
    struct node *left;
    struct node *right;
}node;

node *criar_node(int valor, int nivel, node *left, node *right){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->item = valor;
    new_node->left = NULL;
    new_node->right =NULL;
    return new_node;
}

node *criar_arvore(char **entrada){
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
    node *node = criar_node(item, 0, NULL, NULL);\
    node->left = criar_arvore(entrada);
    node->right = criar_arvore(entrada);
    if(**entrada == ')') (*entrada)++;
    free(num);
    return node;
}

int find_item_nivel(node *root, int item, int nivel){
    if(root == NULL) return 0;
    if(root->item == item){ 
        printf("ESTA NA ARVORE\n%d\n",nivel);
        return 1;
    }
    if(find_item_nivel(root->left, item, nivel+1)) return 1;
    if(find_item_nivel(root->right, item, nivel+1)) return 1;
    return 0;
}


int main(){

    char *entrada = (char*)malloc(100*sizeof(char));
    fgets(entrada,100,stdin);
    if(entrada[strlen(entrada)-1] == '\n') entrada[strlen(entrada)-1] = '\0';
    node *arvore = criar_arvore(&entrada);

    int item;
    scanf("%d",&item);

    if(!find_item_nivel(arvore, item, 0))printf("NAO ESTA NA ARVORE\n-1\n");
    return 0;
}