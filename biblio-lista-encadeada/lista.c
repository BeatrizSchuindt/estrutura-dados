#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista* criar_lista() {
    Lista* li = (Lista*)malloc(sizeof(Lista)); 
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

int inserir_inicio(Lista* p, Item x) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        return 0; 
    }

    novo->item = x;
    novo->prox = *p;
    *p = novo;
    return 1;
}

int inserir_final(Lista* p, Item x) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        return 0; 
    }

    novo->item = x;
    novo->prox = NULL;

    if (*p == NULL) { 
        *p = novo;
    } else {
        No* aux = *p;
        while (aux->prox != NULL) { 
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return 1;
}

int inserir_ordenado(Lista* p, Item x) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        return 0; 
    }

    novo->item = x;
    if (*p == NULL || (*p)->item.id > x.id) { 
        novo->prox = *p;
        *p = novo;
    } else {
        No* ant = NULL;
        No* atual = *p;

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
    No* aux = p;
    while (aux != NULL) {
        printf("ID: %d, Nome: %s\n", aux->item.id, aux->item.nome);
        aux = aux->prox;
    }
}

int remover_inicio(Lista* p) {
    if (*p == NULL) {
        return 0; 
    }

    No* remover = *p;
    *p = remover->prox;
    free(remover->item.nome); 
    free(remover); 
    return 1;
}

int remover_final(Lista* p) {
    if (*p == NULL) {
        return 0; 
    }

    No* ant = NULL;
    No* atual = *p;

    while (atual->prox != NULL) { 
        ant = atual;
        atual = atual->prox;
    }

    if (ant == NULL) {
        *p = NULL;
    } else {
        ant->prox = NULL;
    }

    free(atual->item.nome); 
    free(atual); 
    return 1;
}

int remover_meio(Lista* p, int id) {
    if (*p == NULL) {
        return 0; 
    }

    No* ant = NULL;
    No* atual = *p;

    while (atual != NULL && atual->item.id != id) { 
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return 0; 
    }

    if (ant == NULL) { 
        *p = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual->item.nome); 
    free(atual);
    return 1;
}

int tamanho_lista(Lista p) {
    if (p == NULL) {
        return 0; 
    }

    int cont = 0;
    No* aux = p;

    while (aux != NULL) { 
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int buscar(Lista p, int id, Item* resultado) {
    No* aux = p;

    while (aux != NULL) {
        if (aux->item.id == id) { 
            *resultado = aux->item;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void destruir_lista(Lista* p) {
    No* aux;

    while (*p != NULL) {
        aux = *p;
        *p = (*p)->prox;
        free(aux->item.nome); 
        free(aux); 
    }
}

int lista_vazia(Lista p) {
    return (p == NULL); 
}