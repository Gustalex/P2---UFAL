#include <stdio.h>

void contar_digi(int num, int *cont){
    if(num == 0) return;
    *cont += 1;
    contar_digi(num/10,cont);
}

int main(){

    int numero;
    scanf("%d",&numero);

    int cont = 0;
    contar_digi(numero,&cont);

    printf("%d",cont);

    return 0;
}