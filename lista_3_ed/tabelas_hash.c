#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    int key;
    int valor;
    struct elemento *next;
}elemento;

typedef struct hash_table{
    int size;
    int total;
    elemento **table;
}hash_table;

int hash_func(int key, int size){
    return key%size;
}

hash_table *criar_ht(int size){
    hash_table *new_table = (hash_table*)malloc(sizeof(hash_table));
    new_table->size = size;
    new_table->total = 0;
    new_table->table  = (elemento**)malloc(size * sizeof(elemento*));
    for(int i = 0; i < size; i++){
        new_table->table[i] = NULL;
    }
    return new_table;
}

void put(hash_table *ht, int key, int valor){
    int hash = hash_func(key, ht->size);
    elemento *new_element = (elemento*)malloc(sizeof(elemento));
    new_element->key = key;
    new_element->valor = valor;
    new_element->next = NULL;

    elemento *current = ht->table[hash];
    elemento *prev = NULL;

    while (current != NULL && current->key < key){
        prev = current;
        current = current->next;
    }
    if (prev == NULL){
        new_element->next = ht->table[hash];
        ht->table[hash] = new_element;
    }
    else{
        new_element->next = current;
        prev->next = new_element;
    }
    ht->total++;
}

void remove_key(hash_table *ht, int key){
    int hash = hash_func(key, ht->size);
    elemento *current = ht->table[hash];
    elemento *prev = NULL;
    while(current != NULL){
        if(current->key == key){
            if(prev == NULL) ht->table[hash] = current->next;
            else prev->next = current->next;
            free(current);
            ht->total--;
            return;
        }
        prev = current;
        current = current->next;
    }
}


void procurar(hash_table *ht, int key){
    int cont = 0;
    int encontrado = 0;

    int hash = hash_func(key, ht->size);
   
    elemento *current = ht->table[hash];

    while(current != NULL){
        cont++;
        if(current->key == key){
            encontrado = 1;
            break;
        }
        current = current->next;
    }
    printf("BUSCA POR %d\n", key);
    printf("numero de elementos da tabela hash: %d\n", ht->total); 
    if(encontrado) printf("elemento %d encontrado!\n", key); 
    else   printf("elemento nao encontrado!\n");
    printf("numero de elementos acessados na tabela hash: %d\n", cont);
}

void print_table(hash_table *ht){
    printf("imprimindo tabela hash:\n");
    for(int i = 0; i < ht->size; i++){
        printf("[%d]:", i);
        elemento *current = ht->table[i];
        if(current != NULL){
            while(current != NULL){
                printf("%d=>", current->key);
                current = current->next;
            }
        } else {
            printf("Lista vazia!");
        }
        printf("\n");
    }
}

int main(){
    int m;
    scanf("%d", &m);
    
    hash_table *ht = criar_ht(m);

    char comando;
    int key, valor;

    while(1){
        scanf(" %c", &comando);
        switch(comando){
            case 'a':
                scanf("%d %d", &key, &valor);
                put(ht, key, valor);
                break;
            case 'r':
                scanf("%d", &key);
                remove_key(ht, key);
                break;
            case 'p':
                scanf("%d", &key);
                procurar(ht, key);
                break;
            case 'i':
                print_table(ht);
                break;
            case 'f':
                return 0;
            default:
                break;
        }       
    }

    return 0;
}