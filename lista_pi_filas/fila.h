#include <stdio.h>
#include <stdlib.h>

#define TMN_MAX 10

//fila comum
typedef struct fila{
    int tmn_atual;
    int head;
    int tail;
    int itens[TMN_MAX];
}fila;

fila *criar_fila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->tmn_atual = 0;
    f->head = 0;
    f->tail = 0;
    return f;
}

void enfileirar(fila *f, int item){
    if(f->tmn_atual == TMN_MAX){
        printf("Fila cheia\n");
        return;
    }
    f->itens[f->tail] = item;
    f->tail = (f->tail + 1) % TMN_MAX;
    f->tmn_atual++;
}

void desenfileirar(fila *f){
    if(f->tmn_atual == 0){
        printf("Fila vazia\n");
        return;
    }
    f->head = (f->head + 1) % TMN_MAX;
    f->tmn_atual--;
}

int vazia(fila *f){
    return f->tmn_atual == 0;
}



