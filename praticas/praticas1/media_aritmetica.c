/*
média aritmética de n números informados pelo usuário. 
O valor máximo permitido para n é 100
*/

#include <stdio.h>

float calcular_media(float numeros[], int n) {
    if (n <= 0 || n > 100) {
        return 0.0f;
    }

    float soma = 0.0f;

    for (int i = 0; i < n; i++) {
        soma += numeros[i];
    }

    return soma / n;
}

int main() {
    float numeros1[] = {10, 8, 6};
    float numeros2[] = {5, 5, 5, 5};
    float numeros3[] = {2, 4};
    float media;

    media = calcular_media(numeros1, 3);
    printf("Numeros: 10, 8, 6 => media = %.1f => 1\n", media);

    media = calcular_media(numeros2, 4);
    printf("Numeros: 5, 5, 5, 5 => media = %.1f => 1\n", media);

    media = calcular_media(numeros3, 2);
    printf("Numeros: 2, 4 => media = %.1f => 1\n", media);

    media = calcular_media(numeros1, 101);
    printf("n = 101 (invalido) => 0\n", media);

    return 0;
}

/*
int n;
    float numeros[100];
    printf("Digite a quantidade de numeros(valor maximo eh 100): ");
    scanf("%d", &n);
    if(n > 100 || n <= 0){
    printf("Valor de n invalido.\n");
    printf("Valor de n deve ser entre 1 e 100.\n");
    return 1;
    } else {
        for(int i = 0; i < n; i++){
            printf("Digite o numero %d: ", i + 1);
            scanf("%f", &numeros[i]);
        }
    }   
    float soma = 0;
    for(int i = 0; i < n; i++){
        soma += numeros[i];
    }
    float media = soma / n;
    printf("A media aritmetica eh: %.2f\n", media);

*/