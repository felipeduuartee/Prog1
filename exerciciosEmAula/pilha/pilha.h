#define TAMANHO_PILHA 100  // Define o tamanho máximo da pilha

typedef struct {
    char itens[TAMANHO_PILHA];
    int topo;
} Pilha;

int tamanhoPilha(Pilha* p);
void inicializarPilha(Pilha* p);
int pilhaVazia(Pilha* p);
int pilhaCheia(Pilha* p);
int empilha(Pilha* p, char valor);
int desempilha(Pilha* p, char* valorRetirado);
