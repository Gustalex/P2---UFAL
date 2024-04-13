#include <stdio.h>
#include <string.h>

void checagem(){
        char id[20];
        scanf(" %[^\n]", id);
        char data[11];
        scanf(" %[^\n]", data);
        char passagem[20];
        scanf(" %[^\n]", passagem);
        char data_passagem[11];
        scanf(" %[^\n]", data_passagem);
        char cadeira[5];
        scanf(" %[^\n]", cadeira);

        if(strcmp(id,"Nao possui")== 0){
            printf("a saida e nessa direção\n");
            return;
        }
        else if(strcmp(passagem,"Nao possui") == 0){
            printf("a recepição e nessa direção\n");
            return;
        }
        else if(strcmp(data,data_passagem) != 0){
            printf("190\n");
            return;
        }
        else{
            printf("o seu assento e %s tenha um bom dia\n",cadeira);
        }
    }

int main(){

    int qtd_passageiros;
    scanf("%d",&qtd_passageiros);

    for(int i = 0; i < qtd_passageiros; i++){
        checagem();
    }
    return 0;
}