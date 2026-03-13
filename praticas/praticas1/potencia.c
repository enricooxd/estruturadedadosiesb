#include <stdio.h>  

int main(){

/*
Ler uma base e um expoente inteiro positivo e calcular a 
potência da base elevada ao expoente sem usar funções prontas.
*/
int base;
int expoente;
int resultado;

    printf("Digite a base (numero inteiro): ");
    scanf("%d", &base);
    printf("Digite o expoente (numero inteiro): ");
    scanf("%d", &expoente);

    resultado = 1;
    for(int i = 0; i < expoente; i++){
        resultado *= base;
    }

    printf("O resultado de %d elevado a %d eh: %d\n", base, expoente, resultado);

    return 0;
}