#include <stdio.h>
#include<string.h>
#include<math.h>

int somar_arr(int arr[], int size){
    int soma = 0;
    for(int i = 0; i < size; i++) soma += arr[i];

    return soma;
}
int check_primo(int num){
    if(num < 2) return 0;
    int max_div = (int)sqrt(num);
    for(int i = 2; i <= max_div; i++){
        if(num % i == 0) return 0;
    }
    return 1;
}
int condicao_primo(int num){
    int cont_primo = 0;
    for(int i = 2; i <= num / 2; i++) {
        if(check_primo(i) && num % i == 0) cont_primo++;
        if(cont_primo == 3) return 1;
    }
    return 0;
}
void tentativas(int soma, int *soma_palpites, int *palpites){
    int num;
    while(*soma_palpites < soma && *palpites < 6){
        scanf("%d",&num);
        *soma_palpites += num;
        *palpites += 1;
    }
    if(*soma_palpites < soma && *palpites == 6) printf("Bonxai foi de base.\n");
    else if(*soma_palpites > soma) printf("Agora voce passou dos limites!\n");
    else printf("Parabueins! Voce ajudou Bonxai a escapar.\n");
}
int main(){

    char palavra[50];
    scanf("%s",palavra);
    int size = strlen(palavra);

    int palavra_ascii[size];
    for(int i = 0; i < size; i++){
        palavra_ascii[i] = (int)palavra[i];
    }

    int soma = somar_arr(palavra_ascii,size);

    if(soma % 17 == 0){
        printf("Agora estou Putin, Bonxai!");
        return 0;
    }

    else if(condicao_primo(soma)) soma *= 3; 

    int soma_palpites = 0, palpites = 0;
    tentativas(soma,&soma_palpites,&palpites);

    return 0;
}