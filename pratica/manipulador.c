#include <stdio.h>
int soma_digi(int n){
    if(n < 10) return n;
    return n%10 + soma_digi(n/10);
}
int primo(int n, int divisor) {
   
    if (n < 2) return 0;  
    if (divisor == 1) return 1;  
    if (n % divisor == 0) return 0;
        
    return primo(n, divisor - 1);
}
int loop(int combinacoes,int num1, int *numfinal){
    if(combinacoes == 0) return *numfinal;
    int num;
    scanf("%d", &num);
        if(primo(num,num-1) == 1 && primo(num1,num1-1) == 1){
            *numfinal = num1 + num;
        }
        else{
            *numfinal = soma_digi(num1) * soma_digi(num);
        }
        num1 = *numfinal;
    return loop(combinacoes-1,num1,numfinal);
}
int main(){

    int combinacoes, num1;
    scanf("%d %d", &combinacoes, &num1);

    int numfinal = 0;
    printf("%d\n", loop(combinacoes,num1,&numfinal));

    return 0;
}