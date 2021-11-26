#include <windows.h>
#include <stdio.h>
#include <time.h>


void swap(u_int *a, u_int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(u_int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(u_int arr[], int n) {
    // Construye el Montículo máximo
    // createMaxHeapify
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i); // 9

    // Ordena
    // heapsort
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    u_int MAX;
    int PRINT = 1;

    printf("Ingresa el número de elementos: ");
    scanf("%ud", &MAX);
    printf("¿Desea imprimir los arreglos? (0: no, 1: sí): ");
    scanf("%d", &PRINT);

    if (MAX <= 0) {
        printf("Error: Ingresa un número válido\n");
        return 1;
    }

    srand(time(0));
    u_int *arr = (u_int *) malloc(MAX * sizeof(*arr));

    for (u_int i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX; // Aleatorio
        /*arr[i] = MAX - i; // De mayor a menor*/
        /*arr[i] = i; // Ordenado*/
    }
    int n = MAX;

    if (PRINT) {
        printf("Arreglo desordenado: (%d elementos)\n", n);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    double time_taken;

    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    heapSort(arr, n); // HeapSort
    
    QueryPerformanceCounter(&end);
    time_taken = end.QuadPart - start.QuadPart;
    
    time_taken = (double ) time_taken / (double) frequency.QuadPart; 

    
    if (PRINT) {
        printf("Arreglo ordenado: (%d elementos)\n", n);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    printf("Tiempo tomado: %.9f segundos\n", time_taken);
    printf("             : %.9f milisegundos\n", time_taken*1000);

    free(arr);
}
