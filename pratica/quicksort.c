#include <stdio.h>

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int *v, int inicio, int fim) {
  if (inicio < fim) {
    int pivo = v[(inicio + fim) / 2];
    int i = inicio;
    int j = fim;
    while (i <= j) {
        while (v[i] < pivo) i++;  // Encontra o primeiro elemento maior que o pivô
        while (v[j] > pivo) j--; // Encontra o primeiro elemento menor que o pivô
      // Troca os dois elementos
      if (i <= j) {
        swap(&v[i], &v[j]);
        i++;
        j--;
      }
    }
    // Recursivamente ordena as duas metades
    quicksort(v, inicio, j);
    quicksort(v, i, fim);
  }
}

int main() {
    int arr[] = {5, 2, 8, 12, 1, 6, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
