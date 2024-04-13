#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[51];
    int senha;
    char situacao;
} Academia;

void cadastro(Academia *aluno, int *num_alunos) {
    do {
        scanf(" %[^\n]", aluno[*num_alunos].nome);
        if (strcmp(aluno[*num_alunos].nome, "SAIR") == 0) {
            break;
        }
        scanf("%d", &aluno[*num_alunos].senha);
        scanf(" %c", &aluno[*num_alunos].situacao);
        (*num_alunos)++;
    } while (*num_alunos < 100);
}

void check_senha(Academia *aluno, int num_alunos) {
    int senha;
    do {
        scanf("%d", &senha);
        if (senha == -1) {
            break;
        }
        int encontrado = 0;
        for (int i = 0; i < num_alunos; i++) {
            if (aluno[i].senha == senha) {
                encontrado = 1;
                if (aluno[i].situacao == 'P') {
                    printf("%s, seja bem-vindo(a)!\n", aluno[i].nome);
                } else {
                    printf("Não está esquecendo de algo, %s? Procure a recepção!\n", aluno[i].nome);
                }
                break;
            }
        }
        if (encontrado == 0) {
            printf("Seja bem-vindo(a)! Procure a recepção!\n");
        }
    } while (1);
}

int main() {
    Academia aluno[100];
    int num_alunos = 0;
    cadastro(aluno, &num_alunos);
    check_senha(aluno, num_alunos);
    return 0;
}
//skibiridup
//skrbiridibup