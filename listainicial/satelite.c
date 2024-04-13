#include <stdio.h>
#include <stdlib.h>

void procurar_posicao(int quantidade,char **matriz, int *linha,int *coluna,int *quadrante){
    for(int i=0;i<quantidade;i++){
        for(int j=0;j<quantidade;j++){
            if(matriz[i][j]=='*'){
                *linha=i;
                *coluna=j;
                return;
            }
        }
    }
}

int main() {
    int quantidade, linha=0, coluna=0,quadrante=0;
    char **matriz;
    scanf("%d", &quantidade);

    matriz=malloc(quantidade*sizeof(char*));
    for (int n=0;n<quantidade;n++){
        matriz[n]=malloc(quantidade*sizeof(char));
    }
    
    for(int i=0;i<(quantidade);i++){
        for(int j=0;j<(quantidade);j++){
            scanf(" %c", &matriz[i][j]);
        }
    }
    
    procurar_posicao(quantidade,matriz,&linha,&coluna,&quadrante);
    while(quantidade>=2){
        if(linha<quantidade/2){
            if(coluna>=quantidade/2) quadrante=1;
            else quadrante=2;
        }
        else{
            if(coluna<quantidade/2) quadrante=3;
            else quadrante=4;
        }
        
        printf("%d",quadrante);
        
        quantidade/=2;
        
        if(quadrante==1) coluna-=quantidade;
        
        else if(quadrante==3) linha-=quantidade/2;
        
        else if(quadrante==4){
            linha-=quantidade;
            coluna-=quantidade;
        }
        
    }
    printf("0");

    for(int k=0;k<quantidade*2;k++){
        free(matriz[k]);
    }
    free(matriz);
        
    return 0;
}