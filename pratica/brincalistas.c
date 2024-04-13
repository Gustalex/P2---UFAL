#include <stdio.h>
#include <stdlib.h>

void brincar(int *lista, int size){
    int lista_invertida[size];
    int index = 0;

    for(int i = size-1; i >= 0; i--){
        lista_invertida[index] = lista[i];
        index++;
    }
    printf("Invert: ");
    for(int i = 0; i < size; i++){
        if(i == size-1) printf("%d\n", lista_invertida[i]);
        else
        printf("%d ", lista_invertida[i]);
    }

    int lista_ordenada[size];
    int index2 = 0;

    for(int i = 0; i < size; i += 2){
        lista_ordenada[index2] = lista[i];
        index2++;
    }
    for(int i = 1; i < size; i += 2){
        lista_ordenada[index2] = lista[i];
        index2++;
    }
    printf("ParImp: ");
    for(int i = 0; i < size; i++){
        if(i == size-1) printf("%d\n", lista_ordenada[i]);
        else
        printf("%d ", lista_ordenada[i]);
    }

    int soma_index[size];
    int index3 = 0;
    for(int i = 0; i < size; i++){
        soma_index[i] = lista_invertida[i] + lista_ordenada[i];
    }
    printf("Soma: ");
    for(int i = 0; i < size; i++){
        if(i == size-1) printf("%d\n", soma_index[i]);
        else
        printf("%d ", soma_index[i]);
    }
}
void lerlista(int **lista, int *size){
    int num;
    if(scanf("%d", &num) == EOF) return;
    else{
        *lista = (int *)realloc(*lista, (*size + 1) * sizeof(int));
        (*lista)[*size] = num;
        *size += 1;
        lerlista(lista, size);
    }
}
int main(){
    int size = 0;
    int *lista = (int *)malloc(size * sizeof(int));

    lerlista(&lista, &size);
    brincar(lista, size);
    
    free(lista);
    return 0;
}