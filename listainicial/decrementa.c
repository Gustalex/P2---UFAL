#include <stdio.h>

int check_primeiro(int n) {
    if (n < 10) return (n % 2 == 0) ? 1 : 0; 
    else return check_primeiro(n/10);     
}
int main() {
   
    int n;
    scanf("%d", &n);
    
    n -= check_primeiro(n) ? 4 : 3;
    printf("%d\n", n);
    
    return 0;
}
