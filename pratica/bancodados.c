#include <stdio.h>
#include <string.h>

typedef struct {
    int idade;
    char nome[500];
    char sexo;
    char est_civil;
    int qtd_amigos;
    int qtd_fotos;
} pessoa;

void ler_pessoa(pessoa *p){

    scanf("%d", &p->idade);

    scanf(" %[^\n]", p->nome);

    scanf(" %c", &p->sexo);

    scanf(" %c", &p->est_civil);

    scanf("%d", &p->qtd_amigos);

    scanf("%d", &p->qtd_fotos);
}

void imprimir_pessoa(pessoa p){

    printf("Idade: %d\n", p.idade);
    printf("Nome: %s\n", p.nome);
    printf("Sexo: %c\n", p.sexo);
    printf("Estado Civil: %c\n", p.est_civil);
    printf("Numero de amigos: %d\n", p.qtd_amigos);
    printf("Numero de fotos: %d\n\n", p.qtd_fotos);
}

int main() {
    int num_pessoas;
    
    scanf("%d", &num_pessoas); 

    pessoa pessoas[num_pessoas];

    for (int i = 0; i < num_pessoas; i++) {
        ler_pessoa(&pessoas[i]);
    }

    for (int i = 0; i < num_pessoas; i++) {
        imprimir_pessoa(pessoas[i]);
    }

    return 0;
}
