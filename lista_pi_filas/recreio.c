#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nota;
    int posicao;
} Aluno;

typedef struct {
    Aluno* alunos;
    int tamanho;
} Fila;

Fila criar_fila(int tamanho) {
    Fila fila;
    fila.alunos = (Aluno*)malloc(tamanho * sizeof(Aluno));
    fila.tamanho = tamanho;
    return fila;
}

void free_fila(Fila fila) {
    free(fila.alunos);
}

void enqueue(Fila* fila, int nota, int posicao) {
    Aluno aluno;
    aluno.nota = nota;
    aluno.posicao = posicao;
    fila->alunos[posicao - 1] = aluno;
}

void reordenarFila(Fila* fila) {
    for (int i = 1; i < fila->tamanho; i++) {
        Aluno atual = fila->alunos[i];
        int j = i - 1;
        while (j >= 0 && fila->alunos[j].nota < atual.nota) {
            fila->alunos[j + 1] = fila->alunos[j];
            j = j - 1;
        }
        fila->alunos[j + 1] = atual;
    }
}

int main() {
    int casos;
    scanf("%d", &casos);

    for (int i = 0; i < casos; i++) {
        int tamanho;
        scanf("%d", &tamanho);

        Fila fila = criar_fila(tamanho);

        for (int j = 0; j < tamanho; j++) {
            int nota;
            scanf("%d", &nota);
            enqueue(&fila, nota, j + 1);
        }
        reordenarFila(&fila);
        int cont = 0;
        for (int k = 0; k < fila.tamanho; k++) {
            if (fila.alunos[k].posicao == k + 1) cont++; 
        }
        printf("%d\n", cont);
        free_fila(fila);
    }
    return 0;
} 