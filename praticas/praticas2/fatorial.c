/*
Ler um número inteiro positivo e calcular o seu fatorial de duas formas: utilizando repetição;
e utilizando recursividade. Indicar a complexidade assintótica de cada solução.
*/

#include <stdio.h>

/*
    Fatorial por repeticao 
    Complexidade:
    - Tempo: O(n)  -> percorre de 1 até n
    - Espaço: O(1) -> usa apenas variáveis simples
*/
long long fatorial_repeticao(int n) {
    long long fat = 1;

    for(int i = 1; i <= n; i++) {
        fat *= i;
    }

    return fat;
}

/*
    Fatorial por recursividade
    Complexidade:
    - Tempo: O(n)  -> chama a função n vezes
    - Espaço: O(n) -> pilha de chamadas recursivas
*/
long long fatorial_recursividade(int n) {
    if(n == 0 || n == 1)
        return 1;

    return n * fatorial_recursividade(n - 1);
}

int main() {
    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("Erro: numero deve ser positivo!\n");
        return 1;
    }

    printf("\nFatorial (repeticao) = %lld", fatorial_repeticao(n));
    printf("\nFatorial (recursividade) = %lld\n", fatorial_recursividade(n));

    return 0;
}