/*
Percorrer uma matriz 10x10 de duas maneiras diferentes: com dois laços aninhados; com apenas um laço. 
Calcular o tempo de execução para cada abordagem. Indicar a complexidade assintótica das duas soluções.
*/

#include <stdio.h>
#include <time.h>

#define TAM 10

#include <stdio.h>
#include <time.h>

#define TAM 10

int main() {
    int matriz[TAM][TAM];
    clock_t inicio, fim;
    double tempo1, tempo2;

    // Preenchimento da matriz
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            matriz[i][j] = i + j;
        }
    }

    /*
    Percorrendo com dois laços aninhados
    Complexidade Assintótica:
    Tempo: O(n^2) -> dois laços aninhados de tamanho n
    Espaço: O(1)
    */
    inicio = clock();

    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            int valor = matriz[i][j];
        }
    }

    fim = clock();
    tempo1 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    /*
    Percorrendo com apenas um laço
    Complexidade Assintótica:
    Tempo: O(n^2) -> percorre n*n elementos em um único laço
    Espaço: O(1)
    */
    inicio = clock();

    for(int k = 0; k < TAM * TAM; k++) {
        int i = k / TAM;
        int j = k % TAM;
        int valor = matriz[i][j];
    }

    fim = clock();
    tempo2 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo com dois lacos: %f segundos\n", tempo1);
    printf("Tempo com um laco: %f segundos\n", tempo2);

    return 0;
    
}
