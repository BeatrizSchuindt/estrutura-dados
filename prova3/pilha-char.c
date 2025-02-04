/******************************************************************************
    Projeto: Avaliação 3 - Avaliador de Expressões
    Arquivo: 
    Nome: Ana Beatriz Schuindt do Amaral e Matheus Henrique Moreira Louro
    Data: 15/02/25
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "pilha-char.h"

// função auxiliar para verificar se a pilha está vazia
int vaziapC(PilhaC p) {
    return (p->topo == -1);
}

// função auxiliar para verificar se a pilha está cheia
int cheiapC(PilhaC p) {
    return (p->topo == p->max - 1);
}

// criação da pilha com tamanho máximo m
PilhaC pilhaC(int m) {
    PilhaC p = malloc(sizeof(struct pilha_c));
    if (p == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }
    p->max = m;
    p->topo = -1;
    p->item = malloc(m * sizeof(Itemp));
    if (p->item == NULL) {
        printf("Erro ao alocar memória para os elementos da pilha.\n");
        free(p);
        exit(1);
    }
    return p;
}

// empilha elemento na pilha
void empilhaC(Itemp x, PilhaC p) {
    if (cheiapC(p)) { 
        printf("Erro: Pilha cheia!\n");
        abort();
    }
    p->item[++p->topo] = x;
}

// desempilha elemento da pilha e retorna seu valor
Itemp desempilhaC(PilhaC p) {
    if (vaziapC(p)) {
        printf("Erro: Pilha vazia!\n");
        abort();
    }
    return p->item[p->topo--];
}

// retorna o elemento do topo da pilha sem remover
Itemp topoC(PilhaC p) {
    if (vaziapC(p)) { 
        printf("Erro: Pilha vazia!\n");
        abort();
    }
    return p->item[p->topo];
}

// destrói a pilha e libera a memória alocada
void destruir_pilhaC(PilhaC *Q) {
    if (*Q != NULL) {
        free((*Q)->item);
        free(*Q);
        *Q = NULL;
    }
}
