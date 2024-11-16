#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista criar(int tam){
    Lista n = malloc(tam*sizeof(struct lista));
    n->tamanho=tam;
    n->total=0;
    n->item=malloc(tam*sizeof (Item));
    return (n);
}


Lista inserir(Item x,Lista p)
{
    if(p->total<p->tamanho){
        p->item[p->total]=x;
        p->total++;
    }
    else
        printf("\nLista cheia!");
    return p;
}

void exibir(Lista p)
{
    int i=0;
    while(i<p->total)
    {
       printf("\nID: %d  ",p->item[i].id);
       printf("Nome: %s",p->item[i].nome);
       i++;
    }
}

int buscar(Lista p, int id, Item *resultado) {
    if (p == NULL || p->total == 0) {
        return 0;
    }
    
    for (int i = 0; i < p->total; i++) {
        if (p->item[i].id == id) { 
            *resultado = p->item[i]; 
            return 1; 
        }
    }
    return 0; 
}

void destruir(Lista p){
    free(p->item);
    free(p);
}

int lista_vazia(Lista p) {
    return (p->total == 0);
}

