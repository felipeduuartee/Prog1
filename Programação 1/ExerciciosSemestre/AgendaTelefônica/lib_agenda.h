#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct de cada registro telefonico
typedef struct registro {
	char nome[50];
	char telefone[15];
	struct registro *prox;
}registro_t;

//struct agenda
//marca letra
//ponteiro para a lista de registros iniciando com a letra
struct agenda_t{
	char letra;
	registro_t *prox;
};

//Cria Registro telefonio com nome e telefone
int cria_registro (registro_t **novo, char *nome, char *fone);

int inicializa (struct agenda_t *agenda);

int menu ();

int insere_agenda (struct agenda_t *agenda, registro_t **novo);

void consulta(struct agenda_t *agenda);

/*int inser e_inicio(nodo_t **aux, int elemento)

int insere_fim(nodo_t **aux,int elemento)
*/

