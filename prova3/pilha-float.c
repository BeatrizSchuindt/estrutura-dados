/******************************************************************************
    Projeto: Avaliação 3 - Avaliador de Expressões
    Arquivo: 
    Nome: Ana Beatriz Schuindt do Amaral e Matheus Henrique Moreira Louro
    Data: 15/02/25
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "pilha-float.h"

// função auxiliar para verificar se a pilha está vazia
int vaziapF(PilhaF p) {
    return (p->topo == -1);
}

// função auxiliar para verificar se a pilha está cheia
int cheiapF(PilhaF p) {
    return (p->topo == p->max - 1);
}

// criação da pilha com tamanho máximo m
PilhaF pilhaF(int m) {
    PilhaF p = malloc(sizeof(struct pilha_f));
    if (p == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }
    p->max = m;
    p->topo = -1;
    p->item = malloc(m * sizeof(Itemf));
    if (p->item == NULL) {
        printf("Erro ao alocar memória para os elementos da pilha.\n");
        free(p);
        exit(1);
    }
    return p;
}

// empilha elemento na pilha
void empilhaF(Itemf x, PilhaF p) {
    if (cheiapF(p)) { 
        printf("Erro: Pilha cheia!\n");
        abort();
    }
    p->item[++p->topo] = x;
}

// desempilha um elemento da pilha e retorna seu valor
Itemf desempilhaF(PilhaF p) {
    if (vaziapF(p)) {
        printf("Erro: Pilha vazia!\n");
        abort();
    }
    return p->item[p->topo--];
}

// retorna o elemento do topo da pilha sem removê-lo
Itemf topoF(PilhaF p) {
    if (vaziapF(p)) { 
        printf("Erro: Pilha vazia!\n");
        abort();
    }
    return p->item[p->topo];
}

// destói a pilha e libera a memória alocada
void destruir_pilhaF(PilhaF *Q) {
    if (*Q != NULL) {
        free((*Q)->item);
        free(*Q);
        *Q = NULL;
    }
}
