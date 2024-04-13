#include <stdio.h>

int cont = 0;
int cont2 = 0;

int main(){
    int n;
    scanf("%d", &n);

    int x;
    scanf("%d", &x);
        if(x == n) cont++;
        
        while (x != -1)
        {
            scanf("%d", &x);
            if (x == n) cont++;      

            cont2++;
            if (cont2 == 20) break;
        }    

    printf("%d aparece %d vezes\n",n, cont);
    return 0;
}