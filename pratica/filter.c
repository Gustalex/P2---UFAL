#include <stdio.h>
#include <stdlib.h>

int checkpar(int num){
    int check = (num % 2 == 0) ? 1 : 0;
    return check;
}
int* filter(int (*func)(int), int *arr, int tam){

    int *arr2 = (int*)malloc(tam * sizeof(int));
    if (arr2 == NULL) exit(1);

    int cont = 0;
    for (int i = 0; i < tam; i++) {
        if (func(arr[i]) == 1) {
            arr2[cont] = arr[i];
            cont++;
        }
    }
    for (int i = 0; i < cont; i++) printf("%d ", arr2[i]);
    return arr2;
}
int main() {
    int qtd;
    scanf("%d", &qtd);

    int *arr = (int *)malloc(qtd*sizeof(int));
    if (arr == NULL) exit(1);

    for (int i = 0; i < qtd; i++) scanf("%d", &arr[i]);

    int* arr_filtr = filter(checkpar, arr, qtd);

    free(arr);
    free(arr_filtr);
    return 0;
}
