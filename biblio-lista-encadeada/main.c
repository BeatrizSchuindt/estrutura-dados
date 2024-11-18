#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    int opcao = 1;


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
        printf("\n   9- BUSCAR/PERTINÊNCIA de elemento na lista");
        printf("\n  10- DESTRUIR a lista");
        printf("\n   0- SAIR\n");
        printf("\nAo clicar outra opção, você sai do programa.\n");

        printf("\nDigite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nVocê digitou a opção 1!");
                printf("\n##### CRIAR UMA LISTA #####");
                break;

            case 2:
                printf("\nVocê digitou a opção 2!");
                printf("\n##### INSERIR ELEMENTOS NO INÍCIO #####");
                break;

            case 3:
                printf("\nVocê digitou a opção 3!");
                printf("\n##### INSERIR ELEMENTOS NO FINAL #####");
                break;

            case 4:
                printf("\nVocê digitou a opção 4!");
                printf("\n##### INSERIR ELEMENTOS DE FORMA ORDENADA #####");
                break;

            case 5:
                printf("\nVocê digitou a opção 5!");
                printf("\n##### EXIBIR ELEMENTOS DA LISTA #####");
                break;

            case 6:
                printf("\nVocê digitou a opção 6!");
                printf("\n##### REMOVER ELEMENTOS DO INÍCIO #####");
                break;

            case 7:
                printf("\nVocê digitou a opção 7!");
                printf("\n##### REMOVER ELEMENTOS DO MEIO #####");
                break;

            case 8:
                printf("\nVocê digitou a opção 8!");
                printf("\n##### REMOVER ELEMENTOS DO FINAL #####");
                break;

            case 9:
                printf("\nVocê digitou a opção 9!");
                printf("\n##### BUSCAR ELEMENTOS DA LISTA #####");
                break;

            case 10:
                printf("\nVocê digitou a opção 10!");
                printf("\n##### DESTRUIR LISTA #####");
                break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
