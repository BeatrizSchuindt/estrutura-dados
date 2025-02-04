/******************************************************************************
    Projeto: Avaliação 3 - Avaliador de Expressões
    Arquivo: 
    Nome: Ana Beatriz Schuindt do Amaral e Matheus Henrique Moreira Louro
    Data: 15/02/25
*******************************************************************************/
// ESTRUTURA DA PILHA
typedef char Itemp;
typedef struct pilha_c {
    int max;
    int topo;
    Itemp *item;
} *PilhaC; // O ponteiro passa o endereço da pilha, por isso o asterisco

// PROTÓTIPOS DAS FUNÇÕES AUXILIARES
int vaziapC(PilhaC p);
int cheiapC(PilhaC p);

// PROTÓTIPOS DAS FUNÇÕES DA PILHA QUE SERÃO UTILIZADAS
PilhaC pilhaC(int m);
void empilhaC(Itemp x, PilhaC p);
Itemp desempilhaC(PilhaC p);
Itemp topoC(PilhaC p);
void destruir_pilhaC(PilhaC *Q);
