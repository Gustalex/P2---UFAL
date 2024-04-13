#include <stdio.h>

int raiz_digital(int n){
    if(n<10) return n;
    else{
        int soma = 0;
        while(n > 0){
            soma += n % 10;
            n /= 10;
        }
        return raiz_digital(soma);
    }
}
int encotrar_num(int k, int x){
    int cont = 0, num = 1;

    while(cont < k){
        if(raiz_digital(num) == x) cont++;
        num++;
    }
    return num - 1;
}
int main(){

    int tarefas;
    scanf("%d", &tarefas);

    for(int i = 0; i < tarefas; i++){
        int k, x;
        scanf("%d %d", &k, &x);
        int res = encotrar_num(k,x);
        printf("%d\n",res);
    }
    return 0;
}