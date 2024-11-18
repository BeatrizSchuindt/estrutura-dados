#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista criar_lista() {
    return NULL; //inicializa lista vazia
}

int inserir_inicio(Lista *p, Item x) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;

    novo->item = x;
    novo->prox = *p;
    *p = novo;
    return 1;
}

int inserir_final(Lista *p, Item x) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;

    novo->item = x;
    novo->prox = NULL;

    if (*p == NULL) {
        *p = novo;
    } else {
        No *aux = *p;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return 1;
}

int inserir_ordenado(Lista *p, Item x) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;

    novo->item = x;
    if (*p == NULL || (*p)->item.id > x.id) {
        novo->prox = *p;
        *p = novo;
    } else {
        No *ant = NULL, *atual = *p;
        while (atual != NULL && atual->item.id < x.id) {
            ant = atual;
            atual = atual->prox;
        }
        novo->prox = atual;
        ant->prox = novo;
    }
    return 1;
}

void exibir_lista(Lista p) {
    No *aux = p;
    while (aux != NULL) {
        printf("ID: %d, Nome: %s\n", aux->item.id, aux->item.nome);
        aux = aux->prox;
    }
}

int buscar(Lista p, int id, Item *resultado) {
    No *aux = p;
    while (aux != NULL) {
        if (aux->item.id == id) {
            *resultado = aux->item;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}