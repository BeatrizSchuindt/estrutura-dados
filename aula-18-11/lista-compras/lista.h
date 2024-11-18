//estrutura do item da lista
struct Compra {
    int id;
    char *nome;
};
typedef struct Compra Item;

//estrutura do nó da lista
typedef struct no {
    Item item;
    struct no *prox;
} No;

//apontador para o primeiro nó da lista
typedef No *Lista;

Lista* criar_lista(); // Criar lista
int inserir_final(Lista* p, Item x); //inserir no final
void exibir_lista(Lista p); //exibir elementos
int remover_item(Lista* p, int id); //remover do meio
int tamanho_lista(Lista p); //tamanho da lista
int buscar_item(Lista p, int id, Item *resultado); //buscar elemento
void destruir_lista(Lista* p); //destruir a lista

int lista_vazia(Lista p); //verifica se a lista está vazia
