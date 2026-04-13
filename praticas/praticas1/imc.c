/*Ler o peso e a altura de uma pessoa, calcular o IMC e informar a situação dela
conforme a escala abaixo do peso (< 18.5), peso normal (18.5 até 24.9),
sobrepeso (25.0 até 29.9) ou obesidade (30.0+);  
*/

/*
Ler o peso e a altura de uma pessoa, calcular o IMC e informar a situação dela
conforme a escala abaixo do peso (< 18.5), peso normal (18.5 até 24.9),
sobrepeso (25.0 até 29.9) ou obesidade (30.0+);
*/

#include <stdio.h>

float calcular_imc(float altura, float peso) {
    if (altura <= 0.0f || peso <= 0.0f) {
        return 0.0f;
    }
    return peso / (altura * altura);
}

void testar_imc(float altura, float peso) {
    float imc = calcular_imc(altura, peso);
    
    printf("Altura = %.2f, Peso = %.1f, IMC = %.1f => ", altura, peso, imc);
    
    if (imc == 0.0f) {
        printf("0 (invalido)\n");
        return;
    }
    
    printf("1 (valido) - ");
    
    if (imc < 18.5) {
        printf("abaixo do peso\n");
    } else if (imc <= 24.9) {
        printf("peso normal\n");
    } else if (imc <= 29.9) {
        printf("sobrepeso\n");
    } else {
        printf("obesidade\n");
    }
}

int main() {
    testar_imc(0.0f, 50.0f);
    testar_imc(1.75f, 0.0f);
    testar_imc(1.75f, 70.0f);
    testar_imc(1.60f, 45.0f);
    testar_imc(1.70f, 80.0f);
    testar_imc(1.70f, 100.0f);
    testar_imc(1.80f, 60.0f);
    testar_imc(1.65f, 55.0f);
    testar_imc(1.75f, 90.0f);
    
    return 0;
}

    /*
    float peso;
    float altura;
    float imc;

    printf("Digite seu peso: ");
    scanf("%f", &peso);
    printf("Digite sua altura: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
    if(peso < 0 || altura < 0){
        printf("peso/altura invalido\n");
    }
    else {
        printf("Seu IMC eh: %.2f\n", imc);
        if(imc > 30){
        printf("Você esta obeso");
    }
        else if(imc < 18.5){
            printf("Voce esta abaixo do peso");
    } else if(imc >= 18.5 && imc < 25){
        printf("Voce esta com peso normal");
    } else if(imc >= 25 && imc < 30){
        printf("Você esta com sobrepeso");
    } else if(peso < 0 || altura < 0){
        printf("peso/altura invalido");
    }
*/

