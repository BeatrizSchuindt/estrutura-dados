/******************************************************************************
    Projeto: Avaliação 3 - Avaliador de Expressões
    Arquivo: 
    Nome: Ana Beatriz Schuindt do Amaral e Matheus Henrique Moreira Louro
    Data: 15/02/25
*******************************************************************************/
// ESTRUTURA DA PILHA
typedef float Itemf;
typedef struct pilha_f {
    int max;
    int topo;
    Itemf *item;
} *PilhaF; 

// PROTÓTIPOS DAS FUNÇÕES DA PILHA QUE SERÃO UTILIZADAS
PilhaF pilhaF(int m);
void empilhaF(Itemf x, PilhaF p);
Itemf desempilhaF(PilhaF p);
Itemf topoF(PilhaF p);
void destruir_pilhaF(PilhaF *Q);
