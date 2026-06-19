#include <stdio.h>
#include "lista_linear.h"

int main() {

    Lista *lista = lista_criar();

    printf("Inserindo elementos...\n");

    lista_inserir(lista, 10);
    lista_inserir(lista, 20);
    lista_inserir(lista, 30);
    lista_inserir(lista, 40);

    lista_exibir(lista);

    printf("\nBuscando 20...\n");

    if (lista_buscar(lista, 20))
        printf("20 encontrado!\n");
    else
        printf("20 nao encontrado!\n");

    printf("\nRemovendo 20...\n");

    if (lista_remover(lista, 20))
        printf("20 removido com sucesso!\n");
    else
        printf("20 nao encontrado!\n");

    lista_exibir(lista);

    printf("\nBuscando 20 novamente...\n");

    if (lista_buscar(lista, 20))
        printf("20 encontrado!\n");
    else
        printf("20 nao encontrado!\n");

    lista_destruir(lista);

    return 0;
}