#include <stdio.h>

/*
Ler o valor de um saque e calcular a quantidade de notas necessárias nas 
cédulas de 200, 100, 50, 20, 10, 5 e 2,
utilizando a menor quantidade possível de notas. 
O valor máximo permitido para saque é 1000.
*/


int main(){
    int saque;
    printf("Digite o valor que voce deseja sacar(valor maximo permitido eh de 1000): ");
    scanf("%d", &saque);
    if(saque > 1000 || saque <= 0){
        printf("Valor de saque invalido.\n");
        printf("Valor de saque deve ser entre 1 e 1000.\n");
        return 1;
    } else {
        int notas200 = saque / 200;
        saque = saque % 200;
        int notas100 = saque / 100;
        saque = saque % 100;
        int notas50 = saque / 50;
        saque = saque % 50;
        int notas20 = saque / 20;
        saque = saque % 20;
        int notas10 = saque / 10;
        saque = saque % 10;
        int notas5 = saque / 5;
        saque = saque % 5;
        int notas2 = saque / 2;
        
        printf("Notas de 200: %d\n", notas200);
        printf("Notas de 100: %d\n", notas100);
        printf("Notas de 50: %d\n", notas50);
        printf("Notas de 20: %d\n", notas20);
        printf("Notas de 10: %d\n", notas10);
        printf("Notas de 5: %d\n", notas5);
        printf("Notas de 2: %d\n", notas2);

        printf("Voce sacou um total de %d reais.\n", notas200 * 200 + notas100 * 100 + notas50 * 50 + notas20 * 20 + notas10 * 10 + notas5 * 5 + notas2 * 2);
    }   

    return 0;
}