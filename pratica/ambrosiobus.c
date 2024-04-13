#include <stdio.h>
#include <string.h>

typedef struct{
    int num_passagem;
    char data[11];
    char origem[51];
    char destino[51];
    char hora[6];
    int poltrona;
    int idade;
    char nome[51];
} Ficha;

void ler_ficha(Ficha *ficha, int *num_passageiros){
   
   do{
    scanf("%d", &ficha[*num_passageiros].num_passagem);
    if(ficha[*num_passageiros].num_passagem == -1){
        break;
    }
    scanf(" %[^\n]", ficha[*num_passageiros].data);
    scanf(" %[^\n]", ficha[*num_passageiros].origem);
    scanf(" %[^\n]", ficha[*num_passageiros].destino);
    scanf(" %[^\n]", ficha[*num_passageiros].hora);
    scanf("%d", &ficha[*num_passageiros].poltrona);
    scanf("%d", &ficha[*num_passageiros].idade);
    scanf(" %[^\n]", ficha[*num_passageiros].nome);
    (*num_passageiros)++;

   }while(*num_passageiros <= 44);
} 

double media_idades(Ficha *ficha, int num_passageiros){
    int soma_idades = 0;
    for(int i = 0; i < num_passageiros; i++){
            soma_idades += ficha[i].idade;
    }
    return (double)soma_idades / (double)num_passageiros;
}

void check(Ficha *ficha, int poltrona, int idade, int num_passageiros){
    int media = 0;
    media = media_idades(ficha, num_passageiros);

    for(int i = 0; i < num_passageiros; i++){
        if(ficha[i].poltrona % 2 == 0 && ficha[i].idade > media){
            printf("%s\n", ficha[i].nome);
        } 
    }
}
int main() {
    Ficha passageiro[44];
    int num_passageiros = 0;
    ler_ficha(passageiro, &num_passageiros);

    check(passageiro, 0, 0, num_passageiros);

    return 0;
}
