#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    int valor;
    struct no_t *esquerda;
    struct no_t *direita;
} no_t;

struct arvore_t {
    no_t *raiz;
};

/* --- funções auxiliares internas --- */

static no_t* no_criar(int valor) {
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (!novo) {
        fprintf(stderr, "Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor    = valor;
    novo->esquerda = NULL;
    novo->direita  = NULL;
    return novo;
}

static no_t* inserir_rec(no_t *no, int valor) {
    if (no == NULL) return no_criar(valor);
    if (valor < no->valor)
        no->esquerda = inserir_rec(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita  = inserir_rec(no->direita,  valor);
    return no;
}

static void pre_ordem_rec(no_t *no) {
    if (no == NULL) return;
    printf("%d ", no->valor);
    pre_ordem_rec(no->esquerda);
    pre_ordem_rec(no->direita);
}

static void em_ordem_rec(no_t *no) {
    if (no == NULL) return;
    em_ordem_rec(no->esquerda);
    printf("%d ", no->valor);
    em_ordem_rec(no->direita);
}

static void pos_ordem_rec(no_t *no) {
    if (no == NULL) return;
    pos_ordem_rec(no->esquerda);
    pos_ordem_rec(no->direita);
    printf("%d ", no->valor);
}

static void destruir_rec(no_t *no) {
    if (no == NULL) return;
    destruir_rec(no->esquerda);
    destruir_rec(no->direita);
    free(no);
}

/* --- funções do TDA --- */

arvore_t* arvore_criar() {
    arvore_t *a = (arvore_t*) malloc(sizeof(arvore_t));
    if (!a) {
        fprintf(stderr, "Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    a->raiz = NULL;
    return a;
}

void arvore_inserir(arvore_t *a, int valor) {
    a->raiz = inserir_rec(a->raiz, valor);
}

void arvore_exibir_pre_ordem(arvore_t *a) {
    printf("Pre-ordem:  ");
    if (arvore_esta_vazia(a)) { printf("arvore vazia.\n"); return; }
    pre_ordem_rec(a->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(arvore_t *a) {
    printf("Em-ordem:   ");
    if (arvore_esta_vazia(a)) { printf("arvore vazia.\n"); return; }
    em_ordem_rec(a->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(arvore_t *a) {
    printf("Pos-ordem:  ");
    if (arvore_esta_vazia(a)) { printf("arvore vazia.\n"); return; }
    pos_ordem_rec(a->raiz);
    printf("\n");
}

int arvore_esta_vazia(arvore_t *a) {
    return a->raiz == NULL;
}

void arvore_destruir(arvore_t *a) {
    destruir_rec(a->raiz);
    free(a);
}