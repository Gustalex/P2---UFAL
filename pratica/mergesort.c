#include <stdio.h>

// Função para mesclar dois subarrays
void merge(int arr[], int left[], int right[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;

    // Mescla os elementos dos subarrays em ordem decrescente
    while (i < leftSize && j < rightSize) {
        if (left[i] >= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copia os elementos restantes do subarray esquerdo, se houver
    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    // Copia os elementos restantes do subarray direito, se houver
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

// Função recursiva para dividir e mesclar o array
void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Divide o array em dois subarrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Chama a função recursivamente para os subarrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Mescla os subarrays ordenados
    merge(arr, left, right, mid, size - mid);
}

int main() {
    int arr[] = {5, 9, 1, 3, 2, 8, 4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, size);

    printf("\nArray ordenado de forma decrescente: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
