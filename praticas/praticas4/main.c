#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 100

void copia_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int v[TAM], v1[TAM], v2[TAM], v3[TAM];
    clock_t inicio, fim;

    srand(time(NULL));

    
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    
    copia_vetor(v, v1, TAM);
    copia_vetor(v, v2, TAM);
    copia_vetor(v, v3, TAM);

    //bubble Sort
    inicio = clock();
    bubble_sort(v1, TAM);
    fim = clock();
    printf("Tempo Bubble Sort: %lf segundos\n", 
           (double)(fim - inicio) / CLOCKS_PER_SEC);

    //selection Sort
    inicio = clock();
    selection_sort(v2, TAM);
    fim = clock();
    printf("Tempo Selection Sort: %lf segundos\n", 
           (double)(fim - inicio) / CLOCKS_PER_SEC);

    //quick Sort
    inicio = clock();
    quick_sort(v3, 0, TAM - 1);
    fim = clock();
    printf("Tempo Quick Sort: %lf segundos\n", 
           (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}