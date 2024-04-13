#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int key;
    int valor;
}elemento;

typedef struct hash_table{
    int size;
    elemento *table;
}hash_table;

hash_table* create_hash_table(int size){
    hash_table *new_table = (hash_table*)malloc(sizeof(hash_table));
    new_table->size = size;
    new_table->table = (elemento*)malloc(sizeof(elemento)*size);
    for(int i = 0; i < size; i++){
        new_table->table[i].key = -2;
        new_table->table[i].valor = -2;
    }
    return new_table;
}

void put(hash_table *ht, int key, int valor, int size){
    int index = key % size;
    while(ht->table[index].key != -2){
        index = (index + 1)%size;
    }
}
