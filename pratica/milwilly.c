#include <stdio.h>

int main() {
   
    int arr[1000];
    int n, cont;

    while (1) {
        for (int i = 0; i < 1000; i++) {
            scanf("%d", &arr[i]);
        }

        if (arr[0] == -1) {
            break;
        }

        scanf("%d", &n);

        cont = 0;
        for (int i = 0; i < 1000; i++) {
            if (arr[i] == n) {
                cont++;
            }
        }

        printf("%d appeared %d times\n", n, cont);
    }

    return 0;
}
