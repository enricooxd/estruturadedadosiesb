#include "ordenacao.h"

// Bubble Sort
void bubble_sort(int v[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int v[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

// Função auxiliar do Quick Sort
int particao(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    int j, temp;

    for (j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}

// Quick Sort
void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particao(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}