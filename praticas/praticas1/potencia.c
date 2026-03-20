/*
Ler uma base e um expoente inteiro positivo e calcular a 
potência da base elevada ao expoente sem usar funções prontas.
*/


#include <stdio.h>  

int main(){

int calcular_potencia(int base, int expoente){

    if (expoente < 0){
        return 0;
    }

    int resultado = 1;

    for(int i = 0; i < expoente; i++){
        resultado = resultado * base;
    }

    return resultado;
}

    int r = 0;

    r = calcular_potencia(2, 3);
    printf("2^3 = %d => %i\n", r, r == 8);

    r = calcular_potencia(5, 2);
    printf("5^2 = %d => %i\n", r, r == 25);

    r = calcular_potencia(10, 0);
    printf("10^0 = %d => %i\n", r, r == 1);

    r = calcular_potencia(3, 4);
    printf("3^4 = %d => %i\n", r, r == 81);

    r = calcular_potencia(7, 1);
    printf("7^1 = %d => %i\n", r, r == 7);

    r = calcular_potencia(2, -2);
    printf("2^-2 (expoente negativo) => %i\n", r == 0);

    return 0;
}
/*
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
*/