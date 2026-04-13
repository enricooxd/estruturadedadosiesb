#include <stdio.h>
#include "conta.h"

int main() {
    Conta* minhaConta = conta_criar(123);

    if (minhaConta == NULL) {
        printf("Erro ao criar conta.\n");
        return 1;
    }

    conta_depositar(minhaConta, 500.0);
    printf("Saldo apos deposito: %.2f\n", conta_ver_saldo(minhaConta));

    if (conta_sacar(minhaConta, 200.0)) {
        printf("Saque realizado com sucesso!\n");
    } else {
        printf("Falha no saque.\n");
    }

    printf("Saldo atual: %.2f\n", conta_ver_saldo(minhaConta));

    if (!conta_sacar(minhaConta, 400.0)) {
        printf("Saldo insuficiente para saque.\n");
    }

    conta_destruir(minhaConta);

    return 0;
}