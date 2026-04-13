

/*
Ler o valor de um saque e calcular a quantidade de notas necessárias nas 
cédulas de 200, 100, 50, 20, 10, 5 e 2,
utilizando a menor quantidade possível de notas. 
O valor máximo permitido para saque é 1000.
*/
/*
Ler o valor de um saque e calcular a quantidade de notas necessárias nas 
cédulas de 200, 100, 50, 20, 10, 5 e 2,
utilizando a menor quantidade possível de notas. 
O valor máximo permitido para saque é 1000.
O saque só pode ser feito com valores que sejam possíveis de serem pagos com as notas disponíveis.
*/

#include <stdio.h>

struct Notas {
    int n200;
    int n100;
    int n50;
    int n20;
    int n10;
    int n5;
    int n2;
    int valido;
};

struct Notas calcular_notas(int valor) {
    struct Notas resultado;
    
    resultado.n200 = 0;
    resultado.n100 = 0;
    resultado.n50 = 0;
    resultado.n20 = 0;
    resultado.n10 = 0;
    resultado.n5 = 0;
    resultado.n2 = 0;
    resultado.valido = 1;
    
    if (valor <= 0 || valor > 1000) {
        resultado.valido = 0;
        return resultado;
    }
    
    int resto = valor;
    
    resultado.n200 = resto / 200;
    resto %= 200;
    
    resultado.n100 = resto / 100;
    resto %= 100;
    
    resultado.n50 = resto / 50;
    resto %= 50;
    
    resultado.n20 = resto / 20;
    resto %= 20;
    
    resultado.n10 = resto / 10;
    resto %= 10;
    
    resultado.n5 = resto / 5;
    resto %= 5;
    
    resultado.n2 = resto / 2;
    resto %= 2;
    
    if (resto != 0) {
        resultado.valido = 0;
        resultado.n200 = 0;
        resultado.n100 = 0;
        resultado.n50 = 0;
        resultado.n20 = 0;
        resultado.n10 = 0;
        resultado.n5 = 0;
        resultado.n2 = 0;
    }
    
    return resultado;
}

void testar_saque(int valor) {
    struct Notas resultado = calcular_notas(valor);
    
    printf("Saque de R$ %d: ", valor);
    
    if (resultado.valido) {
        printf("Valido (1) - Notas: ");
        if (resultado.n200 > 0) printf("%dx200 ", resultado.n200);
        if (resultado.n100 > 0) printf("%dx100 ", resultado.n100);
        if (resultado.n50 > 0) printf("%dx50 ", resultado.n50);
        if (resultado.n20 > 0) printf("%dx20 ", resultado.n20);
        if (resultado.n10 > 0) printf("%dx10 ", resultado.n10);
        if (resultado.n5 > 0) printf("%dx5 ", resultado.n5);
        if (resultado.n2 > 0) printf("%dx2 ", resultado.n2);
        printf("\n");
    } else {
        printf("Invalido (0)\n");
    }
}

int main() {
    testar_saque(376);
    testar_saque(400);
    testar_saque(75);
    testar_saque(1200);
    testar_saque(1);
    testar_saque(3);
    testar_saque(7);
    testar_saque(100);
    
    return 0;
}

/*
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
*/
