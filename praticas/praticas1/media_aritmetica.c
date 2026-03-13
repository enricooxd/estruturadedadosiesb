#include <stdio.h>

/*
média aritmética de n números informados pelo usuário. 
O valor máximo permitido para n é 100
*/

int main (){

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

return 0;
}