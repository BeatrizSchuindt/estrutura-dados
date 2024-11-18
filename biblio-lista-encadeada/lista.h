//estrutura do item da lista
struct Coisa {
    int id;
    char *nome;
};
typedef struct Coisa Item;

//estrutura do nó da lista
typedef struct no {
    Item item;
    struct no *prox;
} No;

//apontador para o primeiro nó da lista
typedef No *Lista;

Lista criar_lista();//criar
int inserir_inicio(Lista *p, Item x);//inserir no início
//inserir no final
//inserir de forma ordenada
//exibir elementos
//remover do início
//remover do final
//remover do meio
//buscar elemento
//destruir a lista
