#include <stdio.h>

int loop(int n, int *cont, int *total){
    if(n == 0) return 0;
    else{
        int digito = n % 10;
        int mult = (digito % 2 == 0) ? 2 : 3;

        *total += digito * mult * (*cont);
        (*cont)++;
        loop(n / 10, cont, total);
    }
}
int main(){
    
    int numero;
    int cont, total;

    scanf("%d", &numero);

    while(numero != 0){
        cont = 1;
        total = 0;
        loop(numero, &cont, &total);
        printf("%d\n", total);
        scanf("%d", &numero);
    }
    return 0; 
}


