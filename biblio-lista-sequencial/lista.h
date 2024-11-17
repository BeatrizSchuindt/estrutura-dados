//1º passo - definição do TAD
//criação da struct Pessoa
struct Coisa{
    int id;
    char *nome;
};
//Criação do tipo de dados Item que se baseaia em Pessoa
typedef struct Coisa Item;

//Criação do tipo da lista
struct lista{
    int total; 
    int tamanho;
    Item *item;
};

typedef struct lista *Lista;

//funções de manipulação da lista
Lista criar(int tam);
Lista inserir(Item x,Lista p);
void exibir(Lista l);
int remover_inicio(Lista p);
//remoção meio
int remover_final(Lista p);//remoção fim
int buscar(Lista p, int id, Item *resultado);//busca/pertinência
void destruir(Lista p);//destruição

//bônus
int lista_vazia(Lista p);
