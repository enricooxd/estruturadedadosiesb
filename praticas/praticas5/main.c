/*
Gerar um vetor com 100 números inteiros aleatórios, 
aplicar cada algoritmo de seleção e calcular o seu tempo de execução
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

void copia_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int v[TAM], v2[TAM];
    int alvo, pos, k, valor;
    clock_t inicio, fim;

    srand(time(NULL));

    
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    alvo = v[rand() % TAM];

    inicio = clock();
    pos = linear_search(v, TAM, alvo);
    fim = clock();

    printf("Linear Search:\n");
    printf("Valor: %d | Posicao: %d\n", alvo, pos);
    printf("Tempo: %lf segundos\n\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    k = 10;

    copia_vetor(v, v2, TAM);

    inicio = clock();
    valor = quick_select(v2, 0, TAM - 1, k);
    fim = clock();

    printf("Quick Select:\n");
    printf("%d menor elemento: %d\n", k, valor);
    printf("Tempo: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}