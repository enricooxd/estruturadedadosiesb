#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    int valor;
    struct no_t *anterior;
    struct no_t *proximo;
} No;

struct lista {
    No *primeiro;
    No *ultimo;
};

Lista* lista_criar() {
    Lista *l = (Lista*) malloc(sizeof(Lista));

    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }

    return l;
}

int lista_esta_vazia(Lista *l) {
    return (l->primeiro == NULL);
}

void lista_inserir(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;

    if (lista_esta_vazia(l)) {
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }

    l->ultimo = novo;
}

int lista_buscar(Lista *l, int valor) {
    No *aux = l->primeiro;

    while (aux != NULL) {
        if (aux->valor == valor)
            return 1;

        aux = aux->proximo;
    }

    return 0;
}

int lista_remover(Lista *l, int valor) {
    No *aux = l->primeiro;

    while (aux != NULL && aux->valor != valor) {
        aux = aux->proximo;
    }

    if (aux == NULL)
        return 0;

    if (aux->anterior != NULL)
        aux->anterior->proximo = aux->proximo;
    else
        l->primeiro = aux->proximo;

    if (aux->proximo != NULL)
        aux->proximo->anterior = aux->anterior;
    else
        l->ultimo = aux->anterior;

    free(aux);
    return 1;
}

void lista_exibir(Lista *l) {
    No *aux = l->primeiro;

    printf("Lista: ");

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }

    printf("\n");
}

void lista_destruir(Lista *l) {
    No *aux = l->primeiro;

    while (aux != NULL) {
        No *temp = aux;
        aux = aux->proximo;
        free(temp);
    }

    free(l);
}