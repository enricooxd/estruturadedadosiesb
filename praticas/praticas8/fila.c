#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct fila_t {
    no_t *inicio;
    no_t *fim;
};

fila_t* fila_criar() {
    fila_t *f = (fila_t*) malloc(sizeof(fila_t));
    if (!f) {
        fprintf(stderr, "Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    f->inicio = NULL;
    f->fim    = NULL;
    return f;
}

void fila_enfileirar(fila_t *f, int valor) {
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (!novo) {
        fprintf(stderr, "Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor   = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
}

int fila_desenfileirar(fila_t *f) {
    if (fila_esta_vazia(f)) {
        fprintf(stderr, "Erro: fila vazia.\n");
        exit(EXIT_FAILURE);
    }
    no_t *removido = f->inicio;
    int valor      = removido->valor;
    f->inicio      = removido->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(removido);
    return valor;
}

int fila_inicio(fila_t *f) {
    if (fila_esta_vazia(f)) {
        fprintf(stderr, "Erro: fila vazia.\n");
        exit(EXIT_FAILURE);
    }
    return f->inicio->valor;
}

void lista_exibir(fila_t *f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila (inicio -> fim): ");
    no_t *atual = f->inicio;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) printf(" -> ");
        atual = atual->proximo;
    }
    printf("\n");
}

int fila_esta_vazia(fila_t *f) {
    return f->inicio == NULL;
}

void fila_destruir(fila_t *f) {
    while (!fila_esta_vazia(f)) {
        fila_desenfileirar(f);
    }
    free(f);
}