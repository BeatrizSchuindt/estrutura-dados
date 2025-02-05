#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    int opcao = 1, id = 0, confirmacao = 0;
    Item x;
    Lista* p = NULL; 

    while (opcao != 0) {
        printf("\n---------- MENU DE LISTA ENCADEADA ----------");
        printf("\n   1- CRIAR uma lista");
        printf("\n   2- INSERIR elemento no INÍCIO da lista");
        printf("\n   3- INSERIR elemento no FINAL da lista");
        printf("\n   4- INSERIR elemento de forma ORDENADA");
        printf("\n   5- EXIBIR elementos da lista");
        printf("\n   6- REMOVER elemento no INÍCIO da lista");
        printf("\n   7- REMOVER elemento no MEIO da lista");
        printf("\n   8- REMOVER elemento no FINAL da lista");
        printf("\n   9- TAMANHO da lista");
        printf("\n   10- BUSCAR/PERTINÊNCIA de elemento na lista");
        printf("\n   11- DESTRUIR a lista");
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
                printf("\n##### INSERIR ELEMENTOS NO INÍCIO #####\n");
                if (p == NULL) {
                    printf("A lista não foi criada. Crie uma lista antes de inserir elementos.\n");
                } else {
                    x.nome = malloc(50 * sizeof(char));
                    printf("Digite o ID: ");
                    scanf("%d", &x.id);
                    printf("Digite o Nome: ");
                    scanf(" %[^\n]", x.nome);
                    if (inserir_inicio(p, x)) {
                        printf("Elemento inserido no início com sucesso!\n");
                    } else {
                        printf("Erro ao inserir elemento.\n");
                    }
                }
                break;

            case 3:
                printf("\nVocê digitou a opção 3!");
                printf("\n##### INSERIR ELEMENTOS NO FINAL #####\n");
                if (p == NULL) {
                    printf("A lista não foi criada. Crie uma lista antes de inserir elementos.\n");
                } else {
                    x.nome = malloc(50 * sizeof(char));
                    printf("Digite o ID: ");
                    scanf("%d", &x.id);
                    printf("Digite o Nome: ");
                    scanf(" %[^\n]", x.nome);
                    if (inserir_final(p, x)) {
                        printf("Elemento inserido no final com sucesso!\n");
                    } else {
                        printf("Erro ao inserir elemento.\n");
                    }
                }
                break;

            case 4:
                printf("\nVocê digitou a opção 4!");
                printf("\n##### INSERIR ELEMENTOS DE FORMA ORDENADA #####\n");
                if (p == NULL) {
                    printf("A lista não foi criada. Crie uma lista antes de inserir elementos.\n");
                } else {
                    x.nome = malloc(50 * sizeof(char));
                    printf("Digite o ID: ");
                    scanf("%d", &x.id);
                    printf("Digite o Nome: ");
                    scanf(" %[^\n]", x.nome);
                    if (inserir_ordenado(p, x)) {
                        printf("Elemento inserido de forma ordenada com sucesso!\n");
                    } else {
                        printf("Erro ao inserir elemento.\n");
                    }
                }
                break;

            case 5:
                printf("\nVocê digitou a opção 5!");
                printf("\n##### EXIBIR ELEMENTOS DA LISTA #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista está vazia.\n");
                } else {
                    exibir_lista(*p);
                }
                break;

            case 6:
                printf("\nVocê digitou a opção 6!");
                printf("\n##### REMOVER ELEMENTOS DO INÍCIO #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista está vazia. Não há elementos para remover.\n");
                } else {
                    printf("\nDeseja realmente remover o primeiro elemento?\n  1 - Sim\n  0 - Não\n");
                    printf("Digite sua escolha: ");
                    scanf("%d", &confirmacao);
                    if (confirmacao) {
                        if (remover_inicio(p)) {
                            printf("Elemento no início removido com sucesso!\n");
                        } else {
                            printf("Erro ao remover elemento.\n");
                        }
                    } else {
                        printf("Operação cancelada pelo usuário.\n");
                    }
                }
                break;

            case 7:
                printf("\nVocê digitou a opção 7!");
                printf("\n##### REMOVER ELEMENTOS DO MEIO #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista está vazia. Não há elementos para remover.\n");
                } else {
                    printf("Digite o ID do elemento a ser removido: ");
                    scanf("%d", &id);
                    printf("\nDeseja realmente remover o elemento com ID %d?\n  1 - Sim\n  0 - Não\n", id);
                    printf("Digite sua escolha: ");
                    scanf("%d", &confirmacao);
                    if (confirmacao) {
                        if (remover_meio(p, id)) {
                            printf("Elemento com ID %d removido com sucesso!\n", id);
                        } else {
                            printf("Elemento com ID %d não encontrado ou erro ao remover.\n", id);
                        }
                    } else {
                        printf("Operação cancelada pelo usuário.\n");
                    }
                }
                break;

            case 8:
                printf("\nVocê digitou a opção 8!");
                printf("\n##### REMOVER ELEMENTOS DO FINAL #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista está vazia. Não há elementos para remover.\n");
                } else {
                    printf("\nDeseja realmente remover o último elemento?\n  1 - Sim\n  0 - Não\n");
                    printf("Digite sua escolha: ");
                    scanf("%d", &confirmacao);
                    if (confirmacao) {
                        if (remover_final(p)) {
                            printf("Elemento no final removido com sucesso!\n");
                        } else {
                            printf("Erro ao remover elemento.\n");
                        }
                    } else {
                        printf("Operação cancelada pelo usuário.\n");
                    }
                }
                break;

            case 9:
                printf("\nVocê digitou a opção 9!");
                printf("\n##### TAMANHO DA LISTA #####\n");
                if (p == NULL) {
                    printf("A lista não foi criada. Tamanho: 0.\n");
                } else {
                    printf("Tamanho da lista: %d\n", tamanho_lista(*p));
                }
                break;

            case 10:
                printf("\nVocê digitou a opção 10!");
                printf("\n##### BUSCAR ELEMENTOS DA LISTA #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista está vazia. Não há elementos para buscar.\n");
                } else {
                    printf("Digite o ID do elemento a buscar: ");
                    scanf("%d", &id);
                    if (buscar(*p, id, &x)) {
                        printf("Elemento encontrado: \n   ID = %d\n   Nome = %s\n", x.id, x.nome);
                    } else {
                        printf("Elemento com ID %d não encontrado.\n", id);
                    }
                }
                break;

            case 11:
                printf("\nVocê digitou a opção 11!");
                printf("\n##### DESTRUIR LISTA #####\n");
                if (p == NULL || lista_vazia(*p)) {
                    printf("A lista já está vazia.\n");
                } else {
                    printf("\nDeseja realmente destruir a lista?\n  1 - Sim\n  0 - Não\n");
                    printf("Digite sua escolha: ");
                    scanf("%d", &confirmacao);
                    if (confirmacao) {
                        destruir_lista(p);
                        free(p); 
                        p = NULL;
                        printf("Lista destruída!\n");
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
