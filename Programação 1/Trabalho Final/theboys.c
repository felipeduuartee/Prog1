// programa principal do projeto "The Boys - 2023"
// Autor: Felipe Duarte Silva , GRR: 20231957

#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
#include "lista.h"
#include "lef.h"
#include "mundo.h"

int main () {
	struct mundo_t *w;
	struct lef_t *l;
	struct evento_t *ev;
	srand(0);
	ev = malloc (sizeof (struct evento_t));
	w = criar_mundo();
	w = iniciar_mundo (w);
	l = cria_lef ();
	l = cria_eventos_iniciais (w, l);
	simula_mundo (w, l, ev);
	destroi_mundo (w);
	destroi_evento (ev);
	destroi_lef (l);
	return (0) ;
}

