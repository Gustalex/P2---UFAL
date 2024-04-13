#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int item;
    struct node *left;
    struct node *right;
}node;

node *criar_node(int valor){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->item = valor;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *criar_arvore (char **entrada){
    if(**entrada =='(') (*entrada)++;
    if(**entrada == ')'){
        (*entrada)++;
        return NULL;
    }
    char *num = (char*)malloc(100*sizeof(char));
    int i =0;
    while(**entrada != '(' && **entrada != ')' && **entrada != '\0'){
        num[i++] = **entrada;
        (*entrada)++;
    }
    num[i] = '\0';
    int item = atoi(num);
    node *new_node = criar_node(item);
    new_node->left = criar_arvore(entrada);
    new_node->right = criar_arvore(entrada);
    if(**entrada == ')') (*entrada)++;
    return new_node;
}

int completa(node *root, int *total_nodes, int *filhos_unicos, int *cont){
    if(root == NULL) return 1;
    if(root->left == NULL && root->right == NULL){
        (*total_nodes)++;
        return 1;
    }
    (*total_nodes)++;
    int left = root->left ? completa(root->left, total_nodes, filhos_unicos, cont) : 1;
    int right = root->right ? completa(root->right, total_nodes,filhos_unicos, cont) : 1;
    if(root->left == NULL || root->right == NULL){
        filhos_unicos[(*cont)++] = root->item;
        return 0;
    }
    return left && right;
}

int check_linear(node *root) {
    while (root != NULL) {
        if (root->left != NULL && root->right != NULL) {
            return 0;
        }
        root = root->left ? root->left : root->right;
    }
    return 1;
}

void print_result(int esta_completa, int total_nodes, int *filhos_unicos, int count, node *root){
    if(esta_completa){
        printf("completa\n");
        printf("total de nos: %d\n", total_nodes);
    }
    else{
        printf("nao completa\n");
        printf("nos com um filho:");
        if(check_linear(root)){
            for(int i = count - 1; i >= 0; i--){
                printf(" %d", filhos_unicos[i]);
            }
        }
        else{
            for(int i = 0; i < count; i++){
                printf(" %d", filhos_unicos[i]);
            }
        }
        printf("\n");
    }
}

int main(){
    int total_nodes = 0, cont = 0;
    int *filhos_unicos = (int*)malloc(100*sizeof(int));

    node *root = NULL;
    char *entrada = (char*)malloc(100*sizeof(char));
    scanf("%s", entrada);
    root = criar_arvore(&entrada);

    int esta_completa = completa(root, &total_nodes, filhos_unicos, &cont);
    print_result(esta_completa, total_nodes, filhos_unicos, cont, root);

    return 0;
}