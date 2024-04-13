#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack{
    struct _node* head;
}STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node{
    int element;
    struct _node* next;
}NODE;

//Cria uma stack com o a head NULL
STACK* Create_stack(){
    STACK* new_stack = (STACK*)malloc(sizeof(STACK));
    new_stack->head = NULL;
    return new_stack;
}

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element){
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->element = element;
    new_node->next = NULL;
    return new_node;
}

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack){
    return stack->head == NULL;
}

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack){
    if(stack->head == NULL){
        printf("Pilha vazia\n");
        return -1;
    }
    NODE* top = stack->head;
    stack->head = stack->head->next;
    int element = top->element;
    free(top);
    return element;
}

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element){
    NODE* new_node = create_node(element);
    new_node->next = stack->head;
    stack->head = new_node;
}

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
    void result(STACK* stack, char operation){
        int a = POP(stack);
        int b = POP(stack);

        switch(operation){
            case '+':
                PUSH(stack, a+b);
                break;
            case '-':
                PUSH(stack, b-a);
                break;
            case '*':
                PUSH(stack, a*b);
                break;
            case '/':
                PUSH(stack, b/a);
                break;
        }
        /*
        if(operation == '+') PUSH(stack, a+b);  
        else if(operation == '-') PUSH(stack, b-a);
        else if(operation == '*') PUSH(stack, a*b);
        else if(operation == '/') PUSH(stack, b/a);
        */
    }

    //Recebe uma pilha vazia e quantas strings serao lidas
    //Le as n strings que vao seguir e resolve as expressoes
    void Calculadora(STACK* calculadora, int size){
        char *string = (char*)malloc(10*sizeof(char));
        for(int i = 0; i < size; i++){
            scanf(" %s", string);
            if(string[0] == '+' || string[0] == '-' || string[0] == '*' || string[0] == '/') result(calculadora, string[0]);
            else PUSH(calculadora, atoi(string));
        } 
        free(string);
    }

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

    return 0;
}