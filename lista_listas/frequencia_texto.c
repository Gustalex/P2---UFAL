#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char carac;
    int freq;
    struct node *prox;
}node;

node* criar_lista(char *texto){
    node *head = NULL;
    int freq[256];
    memset(freq, 0, sizeof(freq));
    
    for(int i = 0; texto[i] != '\0'; i++){
        freq[(int)texto[i]]++;
    }

    for(int i = 0; i < 256; i++){
        if(freq[i] > 0){
            node *newNode = (node*)malloc(sizeof(node));
            newNode->carac = (char)i;
            newNode->freq = freq[i];
            newNode->prox = head;
            head = newNode;
        }
    }
    return head;
}
void printar_lista(node *head){
    node *current = head;
    while(current != NULL){
        printf("%c %d\n", current->carac, current->freq);
        current = current->prox;
    }
}

int main(){

    char *texto = (char*)malloc(100*sizeof(char));

    scanf(" %[^\n]", texto);

    node* head = criar_lista(texto);

    printar_lista(head);    

    free(texto);
    return 0;
}
