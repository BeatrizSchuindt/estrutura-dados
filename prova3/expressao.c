/******************************************************************************
    Projeto: Avaliação 3 - Avaliador de Expressões
    Arquivo: 
    Nome: Ana Beatriz Schuindt do Amaral e Matheus Henrique Moreira Louro
    Data: 15/02/25
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilha-char.h"
#include "pilha-float.h"
#include "expressao.h"

typedef struct {
    char nome;
    float valor;
} Variavel;

Variavel variaveis[26];
int numVariaveis = 0;

// função para definir a prioridade dos operadores
int prioridade(char operador) {
    switch (operador) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;  
    }
}

// função para buscar o valor de uma variável
float obterValorVariavel(char nome) {
    for (int i = 0; i < numVariaveis; i++) {
        if (variaveis[i].nome == nome) {
            return variaveis[i].valor;
        }
    }
    printf("Erro: Variável %c não encontrada!\n", nome);
    exit(1);
}

int verificar_parenteses(const char *expr) {
    PilhaC p = pilhaC(strlen(expr));

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            empilhaC('(', p);
        } else if (expr[i] == ')') {
            if (vaziapC(p)) {
                destruir_pilhaC(&p);  // Correção: passar referência
                return 0;  // Parêntese fechado sem abertura correspondente
            }
            desempilhaC(p);
        }
    }

    int balanceado = vaziapC(p);
    destruir_pilhaC(&p);  // Correção: passar referência
    return balanceado;
}

char *limparInfixa(char infixa[]) {
    int tamanho = strlen(infixa);
    char *infixa_copia = malloc(tamanho + 1);  // Correção na alocação

    if (infixa_copia == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '(' || c == ')' || 
            c == '+' || c == '-' || c == '*' || c == '/') {
            infixa_copia[j++] = c;
        }
    }
    infixa_copia[j] = '\0';

    if (!verificar_parenteses(infixa_copia)) {
        
        free(infixa_copia);  // Libera a memória antes de retornar NULL
        return NULL;
    }

    return infixa_copia;
}


// função para converter expressão infixa para pós-fixa
void infixaParaPosfixa(char *infixa, char *posfixa) {
    PilhaC pilha = pilhaC(strlen(infixa));
    int i, j = 0;

    for (i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];

        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
            posfixa[j++] = c;
        } else if (c == '(') {
            empilhaC(c, pilha);
        } else if (c == ')') {
            while (!vaziapC(pilha) && topoC(pilha) != '(') {
                posfixa[j++] = desempilhaC(pilha);
            }
            desempilhaC(pilha);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!vaziapC(pilha) && prioridade(topoC(pilha)) >= prioridade(c) && topoC(pilha) != '(') {
                posfixa[j++] = desempilhaC(pilha);
            }
            empilhaC(c, pilha);
        }
        else {
            continue;
        }
    }

    while (!vaziapC(pilha)) {
        char op = desempilhaC(pilha);
        if (op != '(') {
            posfixa[j++] = op;
        }
    }

    posfixa[j] = '\0';
    destruir_pilhaC(&pilha);
}

// função para definir valores das variáveis
void definirValoresVariaveis(const char *posfixa) {
    numVariaveis = 0;
    
    for (int i = 0; posfixa[i] != '\0'; i++) {
        char c = posfixa[i];
        
        if (isalpha(c)) {
            int existe = 0;
            for (int j = 0; j < numVariaveis; j++) {
                if (variaveis[j].nome == c) {
                    existe = 1;
                    break;
                }
            }
            if (!existe) {
                variaveis[numVariaveis].nome = c;
                numVariaveis++;
            }
        }
    }

    printf("\nDefina os valores das variáveis:\n");
    for (int i = 0; i < numVariaveis; i++) {
        printf("%c = ", variaveis[i].nome);
        scanf("%f", &variaveis[i].valor);
    }

    printf("\nValores armazenados:\n");
    for (int i = 0; i < numVariaveis; i++) {
        printf("%c = %.2f\n", variaveis[i].nome, variaveis[i].valor);
    }
}

// função para avaliar a expressão pós-fixa
float avaliarExpressao(const char *posfixa) {
    PilhaF pilha = pilhaF(strlen(posfixa));

    for (int i = 0; posfixa[i] != '\0'; i++) {
        char c = posfixa[i];

        if (isalpha(c)) {
            float valor = obterValorVariavel(c);
            empilhaF(valor, pilha);
        } else {
            float op2 = desempilhaF(pilha);
            float op1 = desempilhaF(pilha);
            float resultado = 0;

            switch (c) {
                case '+': resultado = op1 + op2; break;
                case '-': resultado = op1 - op2; break;
                case '*': resultado = op1 * op2; break;
                case '/':
                    if (op2 == 0) {
                        printf("Erro: Divisão por zero!\n");
                        exit(1);
                    }
                    resultado = op1 / op2;
                    break;
            }
            empilhaF(resultado, pilha);
        }
    }

    float resultadoFinal = desempilhaF(pilha);
    destruir_pilhaF(&pilha);
    return resultadoFinal;
}
