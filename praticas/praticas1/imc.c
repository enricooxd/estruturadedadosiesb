#include <stdio.h>

int main(){

    /*Ler o peso e a altura de uma pessoa, calcular o IMC e informar a situação dela
    conforme a escala abaixo do peso (< 18.5), peso normal (18.5 até 24.9),
    sobrepeso (25.0 até 29.9) ou obesidade (30.0+);  
    */
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
    }
    
    return 0;
}