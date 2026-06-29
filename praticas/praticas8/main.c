#include <stdio.h>
#include "fila.h"

int main() {
    fila_t *f = fila_criar();

    printf("=== Enfileirando 10, 20, 30, 40, 50 ===\n");
    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);
    fila_enfileirar(f, 40);
    fila_enfileirar(f, 50);
    lista_exibir(f);

    printf("\n=== Consulta do inicio ===\n");
    printf("Inicio da fila: %d\n", fila_inicio(f));

    printf("\n=== Desenfileirando dois elementos ===\n");
    printf("Removido: %d\n", fila_desenfileirar(f));
    printf("Removido: %d\n", fila_desenfileirar(f));
    lista_exibir(f);

    printf("\n=== Enfileirando 60 e 70 ===\n");
    fila_enfileirar(f, 60);
    fila_enfileirar(f, 70);
    lista_exibir(f);

    printf("\n=== Esvaziando a fila ===\n");
    while (!fila_esta_vazia(f)) {
        printf("Removido: %d\n", fila_desenfileirar(f));
    }
    lista_exibir(f);

    fila_destruir(f);
    printf("\nFila destruida com sucesso.\n");
    return 0;
}