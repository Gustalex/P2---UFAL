#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int key;
    int valor;
    struct elemento *next;
}elemento;

typedef struct hash_table{
    int size;
    elemento **table;
}hash_table;

int hash_func(int key, int size){
    return key % size;
}

hash_table *ciar_hash_table(int size){
    hash_table *new_table = (hash_table*)malloc(sizeof(hash_table));
    new_table->size = size;
    new_table->table = (elemento**)malloc(size * sizeof(elemento*));
    for(int i = 0; i < size; i++){
        new_table->table[i] = NULL;
    }
    return new_table;
}

void put(hash_table *ht, int key, int valor){
    int h = hash_func(key, ht->size);
    elemento *new_element = (elemento*)malloc(sizeof(elemento));
    new_element->key = key;
    new_element->valor = valor;
    new_element->next = NULL;
    if(ht->table[h] == NULL) ht->table[h] = new_element;
    else{
        elemento *current = ht->table[h];
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_element;
    }
}

void print_table(hash_table *ht){
    for(int i = 0; i < ht->size; i++){
        printf("%d -> ",i);
        if(ht->table[i] != NULL){
            elemento *current = ht->table[i];
            while(current != NULL){
                printf("%d -> ",current->key);
                current = current->next;
            }
        }
        printf("\\\n");
    }
}

int main(){

    int num_casos;
    scanf("%d", &num_casos);

    for(int i = 0; i < num_casos; i++){
        int qtd_endrc, qtd_key;
        scanf("%d %d",&qtd_endrc,&qtd_key);

        hash_table *ht = ciar_hash_table(qtd_endrc);

        for(int j = 0; j < qtd_key; j++){
            int key;
            scanf("%d",&key);
            put(ht, key, 0);
        }
        print_table(ht);
        if(i != num_casos - 1) printf("\n");
    }
    return 0;
}