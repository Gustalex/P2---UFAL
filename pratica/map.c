#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fatorial(int num){
    if(num==0) return 1;
    else return num*fatorial(num-1);
}
int raiz(int num){
    return sqrt(num);
}
int map(int (*func)(int),int *arr,int tam){
    int *arr2 = (int *)malloc(tam*sizeof(int));
    if(arr2 == NULL) exit(1);
    for(int i = 0;i < tam;i++){
        arr2[i] = func(arr[i]);
    }
    for(int i = 0;i < tam;i++) printf("%d ",arr2[i]);
    free(arr2);
    return 0;
}

int main(){

    int qtd;
    scanf("%d",&qtd);

    int *arr = (int *)malloc(qtd*sizeof(int));
    if(arr == NULL) exit(1);
    
    for(int i = 0;i < qtd; i++) scanf("%d",&arr[i]);

    map(fatorial,arr,qtd);
    printf("\n");
    map(raiz,arr,qtd);

    free(arr);

    return 0;
}