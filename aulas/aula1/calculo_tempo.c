#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //ligou o cronometro
    clock_t tempo_inicial = clock();

    int soma = 10 + 20; //O(1)

    //desliga o cronometro
    clock_t tempo_final = clock();

    double duracao = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
    printf("O tempo de execucao foi %.5f segundos\n", duracao);

    tempo_inicial = clock();

    for(int i=0; i<10; i++){
        soma = soma + 1;

    }

    tempo_final = clock();

    double duracao = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
    printf("O tempo de execucao foi %.5f segundos\n", duracao);

    return 0;
}
