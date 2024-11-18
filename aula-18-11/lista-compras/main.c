//Faça um aplicação que simule uma lista de compras, com métodos para criar, inserir, mostrar e retirar itens da lista;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    int opcao=1, id=1, confirmacao=0;
    Item x;
    Lista* p = NULL; 

    while (opcao != 0) {
        printf("\n---------- LISTA DE COMPRAS ----------");
        printf("\n   1- CRIAR uma lista");//OK
        printf("\n   2- INSERIR item na lista");//ok
        printf("\n   3- EXIBIR itens da lista");//ok
        printf("\n   4- REMOVER item da lista");
        printf("\n   5- TAMANHO da lista");
        printf("\n   6- BUSCAR item da lista");
        printf("\n   7- EXCLUIR toda a lista");
        printf("\n   0- SAIR\n");
        printf("\nDigite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("\nVocê digitou a opção 0!");
                printf("\nSaindo do programa...\n");
            break;

            case 1:
                printf("\nVocê digitou a opção 1!");
                printf("\n##### CRIAR UMA LISTA #####\n");
                if (p != NULL) {
                    printf("Uma lista já existe. Deseja destruir a lista atual e criar uma nova?\n  1 - Sim\n  0 - Não\n");
                    printf("Digite sua escolha: ");
                    scanf("%d", &confirmacao);

                    if (confirmacao == 1) {
                        destruir_lista(p); 
                        free(p); 
                        p = criar_lista(); 
                        printf("Lista antiga destruída e nova lista criada com sucesso!\n");
                    } else {
                        printf("Operação cancelada. A lista atual foi mantida.\n");
                    }
                } else {
                    p = criar_lista(); 
                    printf("Lista criada com sucesso!\n");
                }
                break;

            case 2:
                printf("\nVocê digitou a opção 2!");
                printf("\n##### INSERIR ITENS NA LISTA #####\n");
                if (p == NULL) {
                    printf("A lista não foi criada. Crie uma lista antes de inserir elementos.\n");
                } else {
                    x.nome = malloc(50 * sizeof(char));
                    x.id = id++;
                    printf("Digite o Nome: ");
                    scanf(" %[^\n]", x.nome);
                    if (inserir_final(p, x)) {
                        printf("Item inserido na lista com sucesso!\n");
                    } else {
                        printf("Erro ao inserir item...\n");
                    }
                }
                break;

            case 3:
                printf("\nVocê digitou a opção 3!");
                printf("\n##### EXIBIR ITENS DA LISTA #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista está vazia...\n");
                } else {
                    exibir_lista(*p);
                }
                break;

            case 4:
                printf("\nVocê digitou a opção 4!");
                printf("\n##### REMOVER ITEM DA LISTA #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista está vazia. Não há itens para remover.\n");
                } else {
                    printf("     LISTA ATUAL:\n");
                    exibir_lista(*p);
                    printf("Digite o ID do item a ser removido: ");
                    scanf("%d", &id);
                    printf("\nDeseja realmente remover o item com ID %d?\n  1 - Sim\n  0 - Não\n", id);
                    printf("Digite sua escolha: ");
                    scanf("%d", &confirmacao);
                    if (confirmacao) {
                        if (remover_item(p, id)) {
                            printf("Item com ID %d removido com sucesso!\n", id);
                        } else {
                            printf("Item com ID %d não encontrado ou erro ao remover.\n", id);
                        }
                    } else {
                        printf("Operação cancelada pelo usuário.\n");
                    }
                }
                break;

            case 5:
                printf("\nVocê digitou a opção 5!");
                printf("\n##### TAMANHO DA LISTA #####\n");
                if (p == NULL) {
                    printf("A lista não foi criada. Tamanho: 0.\n");
                } else {
                    printf("Tamanho da lista: %d\n", tamanho_lista(*p));
                }
                break;

            case 6:
                printf("\nVocê digitou a opção 6!");
                printf("\n##### BUSCAR ITEM DA LISTA #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista está vazia. Não há itens para buscar.\n");
                } else {
                    printf("Digite o ID do item a buscar: ");
                    scanf("%d", &id);
                    if (buscar_item(*p, id, &x)) {
                        printf("Item encontrado: \n   ID = %d\n   Nome = %s\n", x.id, x.nome);
                    } else {
                        printf("Item com ID %d não encontrado.\n", id);
                    }
                }
                break;

            case 7:
                printf("\nVocê digitou a opção 7!");
                printf("\n##### EXCLUIR TODA A LISTA #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista já está vazia.\n");
                } else {
                    printf("\nDeseja realmente excluir essa lista?\n  1 - Sim\n  0 - Não\n");
                    printf("Digite sua escolha: ");
                    scanf("%d", &confirmacao);
                    if (confirmacao) {
                        destruir_lista(p);
                        free(p); 
                        p = NULL;
                        printf("Lista de compras excluída!\n");
                    } else {
                        printf("Operação cancelada pelo usuário.\n");
                    }
                }
                break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
