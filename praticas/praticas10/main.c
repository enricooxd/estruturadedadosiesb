#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash *h = hash_criar(7);

    printf("=== Inserindo: 10, 20, 15, 7, 3, 25, 17 ===\n");
    hash_inserir(h, 10);
    hash_inserir(h, 20);
    hash_inserir(h, 15);
    hash_inserir(h, 7);
    hash_inserir(h, 3);
    hash_inserir(h, 25);
    hash_inserir(h, 17);
    hash_exibir(h);

    printf("\n=== Busca ===\n");
    printf("Buscar 15: %s\n", hash_buscar(h, 15) ? "encontrado" : "nao encontrado");
    printf("Buscar 99: %s\n", hash_buscar(h, 99) ? "encontrado" : "nao encontrado");

    printf("\n=== Remocao ===\n");
    hash_remover(h, 20);
    hash_remover(h, 99);
    hash_exibir(h);

    printf("\n=== Inserindo duplicata ===\n");
    hash_inserir(h, 15);

    printf("\n=== Tabela vazia? %s ===\n", hash_esta_vazia(h) ? "sim" : "nao");

    hash_destruir(h);
    printf("\nTabela destruida com sucesso.\n");
    return 0;
}