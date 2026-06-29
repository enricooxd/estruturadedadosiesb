#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct hash_t {
    no_t **tabela;
    int tamanho;
};

static int hash_funcao(TabelaHash *h, int valor) {
    return abs(valor) % h->tamanho;
}

TabelaHash* hash_criar(int tamanho) {
    TabelaHash *h = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (!h) {
        fprintf(stderr, "Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    h->tamanho = tamanho;
    h->tabela  = (no_t**) calloc(tamanho, sizeof(no_t*));
    if (!h->tabela) {
        fprintf(stderr, "Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    return h;
}

void hash_inserir(TabelaHash *h, int valor) {
    if (hash_buscar(h, valor)) {
        printf("Valor %d ja existe na tabela.\n", valor);
        return;
    }
    int idx    = hash_funcao(h, valor);
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (!novo) {
        fprintf(stderr, "Erro: memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor   = valor;
    novo->proximo = h->tabela[idx];
    h->tabela[idx] = novo;
}

int hash_buscar(TabelaHash *h, int valor) {
    int idx     = hash_funcao(h, valor);
    no_t *atual = h->tabela[idx];
    while (atual != NULL) {
        if (atual->valor == valor) return 1;
        atual = atual->proximo;
    }
    return 0;
}

void hash_remover(TabelaHash *h, int valor) {
    int idx      = hash_funcao(h, valor);
    no_t *atual  = h->tabela[idx];
    no_t *ant    = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (ant == NULL)
                h->tabela[idx] = atual->proximo;
            else
                ant->proximo   = atual->proximo;
            free(atual);
            printf("Valor %d removido.\n", valor);
            return;
        }
        ant   = atual;
        atual = atual->proximo;
    }
    printf("Valor %d nao encontrado.\n", valor);
}

void hash_exibir(TabelaHash *h) {
    printf("=== Tabela Hash ===\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("[%2d]: ", i);
        no_t *atual = h->tabela[i];
        if (atual == NULL) {
            printf("vazio");
        } else {
            while (atual != NULL) {
                printf("%d", atual->valor);
                if (atual->proximo != NULL) printf(" -> ");
                atual = atual->proximo;
            }
        }
        printf("\n");
    }
}

int hash_esta_vazia(TabelaHash *h) {
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) return 0;
    }
    return 1;
}

void hash_destruir(TabelaHash *h) {
    for (int i = 0; i < h->tamanho; i++) {
        no_t *atual = h->tabela[i];
        while (atual != NULL) {
            no_t *tmp = atual;
            atual     = atual->proximo;
            free(tmp);
        }
    }
    free(h->tabela);
    free(h);
}