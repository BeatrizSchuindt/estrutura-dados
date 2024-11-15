// LISTA BASEADA EM VETOR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    int op=0, opcao=0, tamanho=0;
    char nomeaux[30];
    Item x;
    Lista p = NULL;
    
    while (opcao != 9) {
        printf("\n---------- MENU DE LISTA SEQUENCIAL ----------");
        printf("\n   1- CRIAR uma lista"); //ok
        printf("\n   2- INSERIR elementos na lista"); //ok
        printf("\n   3- EXIBIR elementos da lista"); //ok
        printf("\n   4- Remoção no INÍCIO da lista");
        printf("\n   5- Remoção no MEIO da lista");
        printf("\n   6- Remoção no FINAL da lista");
        printf("\n   7- BUSCAR elemento na lista");
        printf("\n   8- DESTRUIR a lista"); 
        printf("\n   9- SAIR\n");
        
        printf("\nDigite uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("\nVocê digitou a opção 1!\n");
                printf("\n##### CRIAR UMA LISTA #####\n");
                printf("Digite o tamanho da lista desejada: ");
                scanf("%d", &tamanho);
                p = criar(tamanho);
                
                printf("\nLista CRIADA!\n");
            break;
            
            case 2:
                printf("\nVocê digitou a opção 2!\n");
                printf("\n##### INSERIR ELEMENTOS NA LISTA #####");
                
                for(int i=1;;i++) {
                    x.id=i;
                    x.nome=malloc(30*sizeof(char));
                    
                    printf("\nDigite um nome ");
                    scanf("%s",nomeaux);
                    strcpy(x.nome,nomeaux);
       
                    p = inserir(x,p);
                    
                    printf("\nDigite 1 para CONTINUAR.\nDigite 2 para PARAR");
                    printf("\nDeseja continuar? ");
                    scanf("%d",&op);
                    
                    if(op!=1)
                        break;
                    }
                break;
            
            case 3:
                printf("\nVocê digitou a opção 3!\n");
                printf("\n##### EXIBIR ELEMENTOS #####\n");
                if(p) {
                    exibir(p);
                } else {
                    printf("Nenhuma lista foi encontrada... Tente novamente.\n");
                }
                
                printf("\n");
            break;
            
            case 4:
                printf("\nVocê digitou a opção 4!\n");
                printf("\n##### REMOÇÃO DO INÍCIO #####\n");
            break;
            
            case 5:
                printf("\nVocê digitou a opção 5!\n");
                printf("\n##### REMOÇÃO NO MEIO #####\n");
            break;
            
            case 6:
                printf("\nVocê digitou a opção 6!\n");
                printf("\n##### REMOÇÃO DO FINAL #####\n");
            break;
            
            case 7:
                printf("\nVocê digitou a opção 7!\n");
                printf("\n##### BUSCAR ELEMENTOS #####\n");
            break;
            
            case 8:
                printf("\nVocê digitou a opção 8!\n");
                printf("\n##### DESTRUIR A LISTA #####\n");
            break;
            
            case 9:
                //SAIR
            break;
        }
    }
    
    return 0;
}
