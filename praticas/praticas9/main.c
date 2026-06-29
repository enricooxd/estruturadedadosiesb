#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    arvore_t *a = arvore_criar();

    printf("=== Inserindo: 50, 30, 70, 20, 40, 60, 80 ===\n");
    arvore_inserir(a, 50);
    arvore_inserir(a, 30);
    arvore_inserir(a, 70);
    arvore_inserir(a, 20);
    arvore_inserir(a, 40);
    arvore_inserir(a, 60);
    arvore_inserir(a, 80);

    printf("\n=== Percursos ===\n");
    arvore_exibir_pre_ordem(a);
    arvore_exibir_em_ordem(a);
    arvore_exibir_pos_ordem(a);

    printf("\n=== Inserindo mais elementos: 10, 45, 75 ===\n");
    arvore_inserir(a, 10);
    arvore_inserir(a, 45);
    arvore_inserir(a, 75);

    printf("\n=== Percursos atualizados ===\n");
    arvore_exibir_pre_ordem(a);
    arvore_exibir_em_ordem(a);
    arvore_exibir_pos_ordem(a);

    arvore_destruir(a);
    printf("\nArvore destruida com sucesso.\n");
    return 0;
}