/*
Ler um vetor com 100 números e procurar um valor informado pelo usuário utilizando a busca sequencial.
Indicar a complexidade assintótica do algorítimo analisando o melhor caso e o pior caso.
*/

/*
Ler um vetor com 100 números e procurar um valor informado pelo usuário utilizando a busca sequencial.
Indicar a complexidade assintótica do algorítimo analisando o melhor caso e o pior caso.
*/

/*
Ler um vetor com 100 números e procurar um valor informado pelo usuário utilizando a busca sequencial.
Indicar a complexidade assintótica do algorítimo analisando o melhor caso e o pior caso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int vetor[100];
    int valor, posicao = -1;

    srand(time(NULL));
    for(int i = 0; i < 100; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor:\n");
    for(int i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nDigite o valor a ser buscado: ");
    scanf("%d", &valor);

    /*
    Busca Sequencial
    Complexidade:
    Melhor caso: O(1)
    Pior caso: O(n)
    */
    for(int i = 0; i < 100; i++) {
        if(vetor[i] == valor) {
            posicao = i;
            break;
        }
    }

    if(posicao != -1) {
        printf("\nValor encontrado na posicao: %d\n", posicao);
    } else {
        printf("\nValor nao encontrado no vetor.\n");
    }

    return 0;
}