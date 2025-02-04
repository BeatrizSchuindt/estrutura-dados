// LISTA BASEADA EM VETOR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    int op=0, opcao=0, tamanho=0, confirmacao=0;
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
                //to do - criar verificação se há alguma lista já criada em açãos
                //tentar fazer o tamanho da função ser dinâmicamente alocado
                printf("\nVocê digitou a opção 1!\n");
                printf("\n##### CRIAR UMA LISTA #####");
                printf("\nDigite o tamanho da lista desejada: ");
                scanf("%d", &tamanho);
                p = criar(tamanho);
                
                printf("\nLista CRIADA!\n");
            break;
            
            case 2:
                printf("\nVocê digitou a opção 2!\n");
                printf("\n##### INSERIR ELEMENTOS NA LISTA #####");
                
                if(p) {
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
                } else {
                    printf("\nNenhuma lista foi encontrada... Tente novamente.\n");
                }
                break;
            
            case 3:
                printf("\nVocê digitou a opção 3!\n");
                printf("\n##### EXIBIR ELEMENTOS #####");
                if(p) {
                    if (!lista_vazia(p)) { 
                        printf("\nExibindo elementos da lista: ");
                        exibir(p);
                    } else {
                        printf("\nSem elementos...\n");
                    }
                } else {
                    printf("\nNenhuma lista foi encontrada... Tente novamente.\n");
                }
                
                printf("\n");
            break;
            
            case 4:
                printf("\nVocê digitou a opção 4!\n");
                printf("\n##### REMOÇÃO DO INÍCIO #####");
                if (p) { 
                    if (!lista_vazia(p)) { 
                        printf("\n  Digite 1 para SIM\n  Digite 0 para NÃO");
                        printf("\nVocê tem certeza que deseja remover o primeiro elemento? ");
                        scanf("%d", &confirmacao);
                        if (confirmacao) {
                            if (remover_inicio(p)) {
                                printf("\nPrimeiro elemento removido com sucesso.\n");
                            } else {
                                printf("\nFalha ao remover o primeiro elemento.\n");
                            }
                        } else {
                            printf("\nOperação cancelada pelo usuário.\n");
                        }
                    } else {
                        printf("\nA lista está vazia. Não há elementos para remover.\n");
                    }
                } else {
                    printf("\nNenhuma lista foi encontrada. Crie uma lista primeiro.\n");
                }
            break;
            
            case 5:
                printf("\nVocê digitou a opção 5!\n");
                printf("\n##### REMOÇÃO NO MEIO #####");
                if (p) { 
                    if (!lista_vazia(p)) {
                        int id;
                        printf("\nDigite o ID do elemento que deseja remover: ");
                        scanf("%d", &id);
            
                        printf("\n  Digite 1 para SIM\n  Digite 0 para NÃO");
                        printf("\nVocê tem certeza que deseja remover o elemento com ID %d? ", id);
                        scanf("%d", &confirmacao);
            
                        if (confirmacao) {
                            if (remover_meio(p, id)) {
                                printf("\nElemento com ID %d removido com sucesso.\n", id);
                            } else {
                                printf("\nElemento com ID %d não encontrado.\n", id);
                            }
                        } else {
                            printf("\nOperação cancelada pelo usuário.\n");
                        }
                    } else {
                        printf("\nA lista está vazia. Não há elementos para remover.\n");
                    }
                } else {
                    printf("\nNenhuma lista foi encontrada. Crie uma lista primeiro.\n");
                }
            break;
            
            case 6:
                printf("\nVocê digitou a opção 6!\n");
                printf("\n##### REMOÇÃO DO FINAL #####");
                if (p) {
                    if (!lista_vazia(p)) { 
                        printf("\n  Digite 1 para SIM\n  Digite 0 para NÃO");
                        printf("\nVocê tem certeza que deseja remover o último elemento? ");
                        scanf("%d", &confirmacao);
                        if (confirmacao) {
                            if (remover_final(p)) {
                                printf("\nÚltimo elemento removido com sucesso.\n");
                            } else {
                                printf("\nFalha ao remover o último elemento.\n");
                            }
                        } else {
                            printf("\nOperação cancelada pelo usuário.\n");
                        }
                    } else {
                        printf("\nA lista está vazia. Não há elementos para remover.\n");
                    }
                } else {
                    printf("\nNenhuma lista foi encontrada. Crie uma lista primeiro.\n");
                }
            break;
            
            case 7:
                printf("\nVocê digitou a opção 7!\n");
                printf("\n##### BUSCAR ELEMENTOS #####");
                if (p) { 
                    if (!lista_vazia(p)) { 
                        int id;
                        printf("\nDigite o ID do elemento que deseja buscar: ");
                        scanf("%d", &id);
                        Item resultado;
                        if (buscar(p, id, &resultado)) {
                            printf("\nElemento encontrado:\n");
                            printf("ID: %d\n", resultado.id);
                            printf("Nome: %s\n", resultado.nome);
                        } else {
                            printf("\nElemento com ID %d não encontrado.\n", id);
                        }
                    } else {
                        printf("\nLista está vazia. Nenhum elemento para buscar.\n");
                    }
                } else {
                    printf("\nNenhuma lista foi encontrada. Crie uma lista primeiro.\n");
                }
            break;
            
            case 8:
                printf("\nVocê digitou a opção 8!\n");
                printf("\n##### DESTRUIR A LISTA #####");
                
                if(p) {
                    printf("\n  Digite 1 para SIM\n  Digite 0 para NÃO");
                    printf("\nVocê tem certeza que deseja excluir a lista? ");
                    scanf("%d", &confirmacao);

                    if(confirmacao) {
                        destruir(p);
                        p = NULL;
                        printf("\nLista destruída!\n");
                    } else {
                        break;
                    }

                } else {
                    printf("\nNenhuma lista foi encontrada... Tente novamente.\n");
                }
            break;
            
            case 9:
                //SAIR
            break;
        }
    }
    
    return 0;
}
