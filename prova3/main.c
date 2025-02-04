/******************************************************************************
    Projeto: Avaliação 3 - Avaliador de Expressões
    Arquivo: main.c - programa principal
    Nome: Ana Beatriz Schuindt do Amaral e Matheus Henrique Moreira Louro
    Data: 15/02/25
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expressao.h"

#define MAX_EXPRESSAO 100  

int main() {
    char infixa[MAX_EXPRESSAO] = "", posfixa[MAX_EXPRESSAO] = ""; 
    int opcao;

    while (1) {
        printf("\nMENU\n");
        printf("1 - Definir expressão infixa e converter para pós-fixa\n");
        printf("2 - Definir valores das variáveis\n");
        printf("3 - Avaliar expressão\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        system("clear"); 

        switch (opcao) {
            case 1:
                printf("Digite a expressão infixa: ");
                fgets(infixa, MAX_EXPRESSAO, stdin);
                infixa[strcspn(infixa, "\n")] = 0;  

                infixaParaPosfixa(infixa, posfixa);
                printf("Expressão pós-fixa: %s\n", posfixa);
                break;

            case 2:
                if (strlen(posfixa) == 0) {
                    printf("Nenhuma expressão registrada! Defina uma expressão antes.\n");
                } else {
                    definirValoresVariaveis(posfixa);
                }
                break;

            case 3:
                if (strlen(posfixa) == 0) {
                    printf("Nenhuma expressão registrada! Defina uma expressão antes.\n");
                } else {
                    printf("Resultado: %.2f\n", avaliarExpressao(posfixa));
                }
                break;

            case 4:
                printf("Encerrando...\n");
                exit(0);

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
