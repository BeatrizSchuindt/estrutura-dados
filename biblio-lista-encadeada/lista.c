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

void exibir_lista(Lista p) {
    No *aux = p;
    while (aux != NULL) {
        printf("ID: %d, Nome: %s\n", aux->item.id, aux->item.nome);
        aux = aux->prox;
    }
}
