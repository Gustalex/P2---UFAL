#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    int item;
    struct elemento *next;
}elemento;

typedef struct hash_table{
    int total_elementos;
    int size;
    elemento **table;
    int *crrnt_list_size;
}hash_table;

int hash_func(int item, int size){
    return item % size;
}

hash_table *cirar_hash_table(int size){
    hash_table *new_table = (hash_table*)malloc(sizeof(hash_table));
    new_table->size = size;
    new_table->total_elementos = 0;
    new_table->table = (elemento**)malloc(size*sizeof(elemento*));
    new_table->crrnt_list_size = (int*)malloc(size*sizeof(int));
    for(int i = 0; i < size ;i++){
        new_table->table[i] = NULL;
        new_table->crrnt_list_size[i] = 0;
    }
    return new_table;
}

int existe(hash_table *table, int item, int *cont){
    int i = hash_func(item, table->size);
    elemento *aux = table->table[i];
    while(aux != NULL){
        if(aux->item == item){
            (*cont) += 1;
            return 1;
        }
        (*cont) += 1;
        aux = aux->next;
    }
    return 0;
}

int remove_item(hash_table *table, int item, int *cont){
    int i = hash_func(item, table->size);
    elemento *current = table->table[i];
    elemento *prev = NULL;

    int flag = 0;

    if(current != NULL && current->item == item){
        (*cont) += 1;
        flag = 1;
    }
    while(current != NULL && current->item != item){
        (*cont) += 1;
        prev = current;
        current = current->next;
    }
    if(current != NULL && current->item == item && flag == 0) (*cont) += 1;
    if(current){
        if(prev){
            prev->next = current->next;
            current->next = NULL;
        }
        else{
            table->table[i] = current->next;
        }
        table->total_elementos--;
        table->crrnt_list_size[i]--;
        return 1;
    }
    return 0;
}

int put(hash_table *table, int item, int *cont){
    int i = hash_func(item, table->size);
    if(existe(table, item, cont) == 1) return 0;

    elemento *new_element = (elemento*)malloc(sizeof(elemento));
    new_element->item = item;
    new_element->next = table->table[i];
    table->table[i] = new_element;
    table->total_elementos++;
    table->crrnt_list_size[i]++;
    return 1;
}

hash_table *rehash(hash_table *table, int m){
    hash_table *new_ht = cirar_hash_table(2*m - 1);
    for(int i = 0; i < m; i++){
        elemento *aux = table->table[i];
        while(aux != NULL){
            int cont;
            put(new_ht, aux->item, &cont);
            aux = aux->next;
        }
    }
    return new_ht;
}

int max_list(hash_table *table){
    int max = 0;
    for(int i = 0; i < table->size; i++){
        if(table->crrnt_list_size[i] > max) max = table->crrnt_list_size[i];
    }
    return max;
}

int main(){

    int m = 7;
    hash_table *ht = cirar_hash_table(m);
    char comando[5];
    int item;
    int cont;

    for(int i = 0; scanf("%s",comando)!= EOF; i++){
        cont = 0;
        switch(comando[0]){
            case 'A':
                scanf("%d", &item);
                int res1 = put(ht, item, &cont);
                double a = (double)ht->total_elementos/ht->size;
                if(a >= 0.75) ht = rehash(ht, ht->size);
                printf("%d %d %d\n", i, res1, cont);
                break;
            case 'D':
                scanf("%d", &item);
                int res2 = remove_item(ht, item, &cont);
                printf("%d %d %d\n", i, res2, cont);
                break;
            case 'H':
                scanf("%d", &item);
                int res3 = existe(ht, item, &cont);
                printf("%d %d %d\n", i, res3, cont);
                break;
            case 'P':
                printf("%d %d %d %d\n", i, ht->size, ht->total_elementos, max_list(ht));
                break;
            }
    }
}
