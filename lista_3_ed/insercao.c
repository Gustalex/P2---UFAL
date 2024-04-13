#include <stdio.h>
#include <stdlib.h>

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

binary_tree *add(binary_tree *bt, int item){
    if(bt == NULL) bt = criar_arvore(item,NULL,NULL); 
    else if(bt->item > item)  bt->left = add(bt->left,item);
    else  bt->right = add(bt->right,item);
    return bt;
}

void print_tree(binary_tree *bt){
    if(bt == NULL) printf("  ()");
       
    else{
        printf("  ( %d", bt->item);
        print_tree(bt->left);
        print_tree(bt->right);
        printf(" )");
    }
}

int main(){
    binary_tree *bt = criar_vazia();
    int item;
    puts("----");
    while(scanf("%d", &item) == 1)
    {
        printf("Adicionando %d\n ", item);
        bt = add(bt, item);
        print_tree(bt);
        puts(" \n----");
    }
    return 0;
}