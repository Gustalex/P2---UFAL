#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int item;
    struct node *left;
    struct node *right;
    struct node *pai;
}node;

node *criar_node(int valor){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->item = valor;
    new_node->left = NULL;
    new_node->right =NULL;
    new_node->pai = NULL;
    return new_node;
}

node *criar_arvore(char **entrada, node *pai){
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
    node *new_node = criar_node(item);
    new_node->pai = pai;
    new_node->left = criar_arvore(entrada, new_node);
    new_node->right = criar_arvore(entrada, new_node);
    if(**entrada == ')') (*entrada)++;
    return new_node;
}

void dfs(node* current, node* tree2){
    if (current == NULL) return;
    if (current->item == tree2->item && current->pai != NULL) {
        if (current->pai->left == current) current->pai->left = tree2;
        else current->pai->right = tree2;
        tree2->pai = current->pai;
        return;
    }
    dfs(current->left, tree2);
    dfs(current->right, tree2);
}

node* concatenar(node* tree1, node* tree2) {
    if (tree1 == NULL) return tree2;
    if (tree2 == NULL) return tree1;
    if (tree1->item == tree2->item) return tree2;
    dfs(tree1, tree2);
    if (tree2->pai == NULL) { 
        node *current = tree1;
        while (current->right != NULL) current = current->right; 
        current->right = tree2;
        tree2->pai = current;
    }
    return tree1;
}

void print_tree(node *bt){
    if(bt == NULL) printf("()");
    else{
        printf("(%d",bt->item);
        print_tree(bt->left);
        print_tree(bt->right);
        printf(")");
    }
}

int main(){
    char *entrada = (char*)malloc(100*sizeof(char));
    node *arvore_concatenada = NULL;

    while (1) {
        scanf(" %s",entrada);
        if (strcmp(entrada, "()") == 0)  break;
        node *arvore = criar_arvore(&entrada, NULL);
        arvore_concatenada = concatenar(arvore_concatenada, arvore);
    }
    print_tree(arvore_concatenada);
    
    return 0;
}