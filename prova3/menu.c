#include "menu.h"
#include "expressao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_EXPRESSAO 100 

void menu_principal()
{

    char infixa[MAX_EXPRESSAO] = "", posfixa[MAX_EXPRESSAO] = ""; 
    int opcao;

    while (1) {
        printf("\n");
        printf("============================================\n");
        printf("              MENU PRINCIPAL          \n");
        printf("============================================\n");
        printf("  0 - Visualizar operações permitidas\n");
        printf("  1 - Converter expressão infixa → pós-fixa\n");
        printf("  2 - Definir valores das variáveis\n");
        printf("  3 - Avaliar expressão\n");
        printf("  4 - Sair\n");
        printf("============================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);    
        getchar();

        system("clear"); 

        switch (opcao) {
            case 0:
                printf("\n");
                printf("============================================\n");
                printf("              OPERAÇÕES SUPORTADAS          \n");
                printf("============================================\n");
                printf("  +  →  Adição (Ex: 3 + 2)\n");
                printf("  -  →  Subtração (Ex: 5 - 1)\n");
                printf("  *  →  Multiplicação (Ex: 4 * 3)\n");
                printf("  /  →  Divisão (Ex: 8 / 2)\n");
                printf("  ^  →  Potência (Ex: 2 ^ 3 para 2³ = 8)\n");
                printf("--------------------------------------------\n");
                printf("OBSERVAÇÃO: Para extrair a raiz quadrada de um número,\n");
                printf("use a potência 0.5. Exemplo: 9 ^ 0.5 resulta em 3.\n");
                printf("============================================\n");
                break;
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

                    float resultado = avaliarExpressao(posfixa);
                    if (isnan(resultado))
                        printf("Erro ao avaliar a expressão. Verifique os valores inseridos e tente novamente.\n");
                    else
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
    
}
