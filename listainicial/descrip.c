#include <stdio.h>
#include <string.h>

int main(){
    
    char mensagem[100];
    int cont=0;
    scanf("%s",mensagem);
    
    int tmn = strlen(mensagem);

    for(int i = 0;i < tmn;i++){
        if(mensagem[i]=='*'){
            printf("(%d",i+1);
            cont++;
        }
        else printf("%d",i+1);
    }

    if(cont>0){
        for(int k = 0;k < cont;k++) printf(")");
    }
    return 0;
}