/******************************************************************************
    Projeto: Avaliação 3 - Avaliador de Expressões
    Arquivo: main.c - programa principal
    Nome: Ana Beatriz Schuindt do Amaral e Matheus Henrique Moreira Louro
    Data: 15/02/25
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "expressao.h"
#include "templates_menu.h"

#define MAX_EXPRESSAO 100  

int main() {
    setlocale(LC_ALL, "Portuguese");
    char infixa[MAX_EXPRESSAO] = "", posfixa[MAX_EXPRESSAO] = ""; 
    int opcao;

    while (1) {
        menu_principal();
        scanf("%d", &opcao);
        getchar();

        system("clear"); 

        switch (opcao) {
            case 1:
                printf("Digite a expressão infixa: ");
                fgets(infixa, MAX_EXPRESSAO, stdin);
                infixa[strcspn(infixa, "\n")] = 0;  

                if (limparInfixa(infixa) == NULL)
                {
                    printf("Faltam parênteses de fechamento!\n");
                    break;
                }
                else {
                    infixaParaPosfixa(infixa, posfixa);
                    printf("Expressão pós-fixa: %s\n", posfixa);
                }
                break;

            case 2:
                if (strlen(posfixa) == 0) {
                    printf("Nenhuma expressão registrada! Defina uma expressão antes.\n");
                } else {
                    char *infixa_copia = limparInfixa(infixa);
                    printf("expressão infixa: %s\n", infixa_copia);
                    definirValoresVariaveis(posfixa);
                }
                break;

            case 3:
                if (strlen(posfixa) == 0) {
                    printf("Nenhuma expressão registrada! Defina uma expressão antes.\n");
                } else {
                    char *infixa_copia = limparInfixa(infixa);
                    printf("expressão infixa: %s\n", infixa_copia);
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
