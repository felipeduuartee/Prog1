
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "conjunto.h"
#include "lista.h"
#include "lef.h"
#include "define.h"
#include "mundo.h"


int aleat (int min, int max) {
	return rand() % (max - min + 1) + min;
}

// Cria um novo herói com base no ID fornecido.
struct heroi_t *criar_heroi(int id_heroi) {
    struct heroi_t *h;
    h = malloc(sizeof(struct heroi_t));
    if (!h)
        return NULL;

    h->id = id_heroi;
    h->exp = 0;
    h->paciencia = aleat(0,100);
    h->vel = aleat(50,5000);
    h->habilidade = cjto_criar(N_HABILIDADES);
	
    int tam = aleat(1,3);
	// Preenche o conjunto de habilidades aleatoriamente
    while (cjto_cardinalidade(h->habilidade) < tam) 
        cjto_adicionar(h->habilidade, aleat(0, N_HABILIDADES -1));
    return h;
}


// funcao responsavel por criar uma base aleatoria
struct base_t *criar_base(int id_base) {
    struct base_t *b;
    b = malloc(sizeof(struct base_t));
    b->local = malloc(sizeof(struct coord));
    if (!b || !b->local)
        return NULL;
    b->id = id_base;
    b->local->x = aleat(0, N_TAMANHO_MUNDO);
    b->local->y = aleat(0, N_TAMANHO_MUNDO);
    b->lot = aleat(3,10);
    b->presentes = cjto_criar(N_HEROIS);
    b->espera = lista_cria();
    return b;
}	


// funcao responsavel por criar uma missao
struct missao_t *criar_missao(int id_missao) {
    struct missao_t *m;

    m = malloc(sizeof(struct missao_t));
    m->local = malloc(sizeof(struct coord));

    if (!m || !m->local)
        return NULL;

    m->id = id_missao;
    m->local->x = aleat(0, N_TAMANHO_MUNDO);
    m->local->y = aleat(0, N_TAMANHO_MUNDO);
    m->habilidades = cjto_criar(N_HABILIDADES);

    int tam = aleat(6,10);

	// preencher habilidades aleatoriamente 
    while (cjto_cardinalidade(m->habilidades) < tam)
        cjto_adicionar(m->habilidades, aleat(0, N_HABILIDADES - 1));
    return m;
}

struct mundo_t *criar_mundo () {
	struct mundo_t *w;

	w = malloc (sizeof (struct mundo_t));
	w->tamanho = malloc (sizeof (struct coord));

	if (!w || !w->tamanho)
		return NULL;

	// defines estao no arquivo define.h
	w->total_herois = N_HEROIS;
	w->herois = NULL;
	w->total_bases = N_BASES;
	w->bases = NULL;
	w->total_missoes = N_MISSOES;
	w->missoes = NULL;
	w->total_habilidades = N_HABILIDADES;
	w->tamanho->x = N_TAMANHO_MUNDO;
	w->tamanho->y = N_TAMANHO_MUNDO;
	w->relogio = 0; // variavel responsavel por contar o tempo da simulacao
	w->tentativas = 0; // variavel responsavel por contar o numero de tentativas de missao
	return w;
}

// cria todos os herois (vetor de structs para acessar de forma organizada)
struct heroi_t **iniciar_herois (int n_heroi) {
	struct heroi_t **h;
	int i;
	h = malloc (n_heroi * sizeof (struct heroi_t));

	if (!h)
		return NULL;

	for (i = 0; i < N_HEROIS; i++) {
		h[i] = criar_heroi (i);
	}


	return h;
}

// cria todas as bases
struct base_t **iniciar_bases (int n_base) {
	struct base_t **b;
	int i;

	b = malloc (n_base * sizeof (struct base_t));

	if (!b)
		return NULL;

	
	for (i = 0; i < N_BASES; i++)
		b[i] = criar_base (i);
		
	return b;
}

// cria todas as missoes
struct missao_t **iniciar_missoes (int n_missao) {
	struct missao_t **m;
	int i;

	m = malloc (n_missao * sizeof (struct missao_t));

	if (!m)
		return NULL;
	
	for (i = 0; i < N_MISSOES; i++)
		m[i] = criar_missao (i);


	return m;
}


// funcao para iniciar o mundo com herois, bases e missoes
struct mundo_t *iniciar_mundo (struct mundo_t *w) {
	if (!w)
		return NULL;
	
	w->herois = iniciar_herois (w->total_herois);
	w->bases = iniciar_bases (w->total_bases);
	w->missoes = iniciar_missoes (w->total_missoes);
	return w;
}

struct mundo_t *destroi_mundo(struct mundo_t *w) {
    if (!w)
        return NULL;
    int i;
    for (i = 0; i < w->total_herois; i++) { 
        cjto_destruir(w->herois[i]->habilidade);
        free(w->herois[i]);
    }

    for (i = 0; i < w->total_bases; i++) {
        cjto_destruir(w->bases[i]->presentes);
        lista_destroi(w->bases[i]->espera);
        free(w->bases[i]->local);
        free(w->bases[i]);
    }

    for (i = 0; i < w->total_missoes; i++) {
        cjto_destruir(w->missoes[i]->habilidades);
        free(w->missoes[i]->local);
        free(w->missoes[i]);
    }

    free(w->missoes);
    free(w->herois);
    free(w->bases);
    free(w->tamanho);
    free(w);
    return NULL;
}

void simula_mundo (struct mundo_t *w, struct lef_t *l, struct evento_t *ev) {
	bool fim_simulacao = false;
	while (!fim_simulacao) {
		// retirar o primeiro evento da lista
		ev = retira_lef (l);
		// atualiza o relogio conforme o tempo do evento
		w->relogio = ev->tempo; 
		switch (ev->tipo) {
			case CHEGA:
				trata_evento_chega (l, relogio_mundo(w), w->herois[ev->dado1], w->bases[ev->dado2]);
				break;
			case ESPERA:
				trata_evento_espera (l, relogio_mundo(w), w->herois[ev->dado1], w->bases[ev->dado2]);
				break;
			case DESISTE:
				trata_evento_desiste (l, relogio_mundo(w), w->herois[ev->dado1], w->bases[ev->dado2]);
				break;
			case AVISA:
				trata_evento_avisa (l, relogio_mundo (w), w->bases[ev->dado2]);
				break;
			case ENTRA:
				trata_evento_entra (l, relogio_mundo (w), w->herois[ev->dado1], w->bases[ev->dado2]);
				break;
			case SAI:
				trata_evento_sai (l, relogio_mundo (w), w->herois[ev->dado1], w->bases[ev->dado2]);
				break;
			case VIAJA:
				trata_evento_viaja (l, relogio_mundo (w), w->herois[ev->dado1], w->bases[ev->dado2], w);
				break;
			case MISSAO:
				trata_evento_missao (l, relogio_mundo (w), w->missoes[ev->dado1], w);
				break;
			case FIM:
				trata_evento_fim (relogio_mundo (w), w, l);
				fim_simulacao = true;
				break;
		}
		destroi_evento (ev);
	}

}

// pegar os herois, base aleatoria, tempo aleatorio, 
// funcao responsavel por criar missoes iniciais e viagem dos herois para bases
struct lef_t *cria_eventos_iniciais (struct mundo_t *w, struct lef_t *l) {
	
	int base, tempo, i;
	struct evento_t *ev;

	
	if (!l)
		return NULL;
	
	// cria eventos de chegada de herois
	for (i = 0; i < N_HEROIS; i++) {
		base = aleat (0, N_BASES - 1);
		tempo = aleat (0, TRES_DIAS);
		ev = cria_evento (tempo, CHEGA, w->herois[i]->id, w->bases[base]->id);
		insere_lef (l, ev);
	}
	
	for (i = 0; i < N_MISSOES; i++) {
		tempo = aleat (0, T_FIM_DO_MUNDO);
		ev = cria_evento (tempo, MISSAO, w->missoes[i]->id, 0);
		insere_lef (l, ev);
	}

	// cria o evento para o fim da simulação
	ev = cria_evento (T_FIM_DO_MUNDO, FIM, 0, 0);
	insere_lef (l, ev);
	return l;
}


// Calcula a distância entre a missão e todas as bases no mundo
void calcula_distancia_missao (struct mundo_t *w, struct missao_t *m, struct distancia_t *d) {
	int i;

	if (!w || !d)
		return;

	for (i = 0; i < w->total_bases; i++) {
		// pitagoras p/ calcular a distancia entre a loc da missao e a loc de todas as bases
		d[i].dist = sqrt(pow(m->local->x - w->bases[i]->local->x,2) + pow (m->local->y -w->bases[i]->local->y, 2)) ;
		d[i].id_base = i;
	}
}


// funcao que ordena as distancias entre as missoes e as bases em ordem crescente
void insertionSort(struct distancia_t *d, int n) {
    int i, j;
    struct distancia_t tmp;

    for (i = 1; i < n; i++) {
        tmp = d[i];
        j = i - 1;

        while (j >= 0 && d[j].dist > tmp.dist) {
            d[j + 1] = d[j];
            j--;
        }
        d[j + 1] = tmp;
    }
}


void trata_evento_missao(struct lef_t *l, int tempo, struct missao_t *m, struct mundo_t *w) {
    if (!l || !m || !w)
        return;

	// bmp = base mais proxima
    int i, j, bmp;
    struct evento_t *ev;
    struct cjto_t *hab;
    struct distancia_t *dist;
    dist = malloc(w->total_bases * sizeof(struct distancia_t));

	// calcula a distancia entre a missao m e todas as bases do mundo
    calcula_distancia_missao(w, m, dist);    
    bmp = -1;
    printf("%6d: MISSAO %d HAB REQ:", tempo, m->id);
    cjto_imprimir(m->habilidades);

    insertionSort(dist, N_BASES);

	// laço para percorrer todas as bases
    for (i = 0; i < w->total_bases; i++) {
        hab = cjto_criar(N_HABILIDADES);
        printf("%6d: MISSAO %d HAB BASE %d:", tempo, m->id, w->bases[dist[i].id_base]->id);

		// laço para percorrer todos os herois e verificarem se eles pertencem à base atual
        for (j = 0; j < w->total_herois; j++) {
            if (cjto_pertence(w->bases[dist[i].id_base]->presentes, w->herois[j]->id))
                cjto_uniao(hab, w->herois[j]->habilidade, hab);
        }

        cjto_imprimir(hab);

		// verificar se o conjunto hab tem as habilidades necessarias para a missao
        if (cjto_contem(hab, m->habilidades)) {
            bmp = dist[i].id_base;

            for (i = 0; i < w->total_herois; i++) {

                if (w->herois[i]->id_base == bmp)
                    w->herois[i]->exp++;

            }

            printf("%6d: MISSAO %d CUMPRIDA BASE %d HEROIS:", tempo, m->id, bmp);
            cjto_imprimir(w->bases[bmp]->presentes);
            cjto_destruir(hab);			
            free(dist);
            return;
        }

        cjto_destruir(hab);
    }

	// caso nenhuma base cumpra a missao, ela é adiada em um dia
    if (bmp == -1) {
        ev = cria_evento(tempo + 24 * 60, MISSAO, m->id, 0);
        insere_lef(l, ev);
        printf("%6d: MISSAO %d IMPOSSIVEL\n", tempo, m->id);
        w->tentativas++;
    }

    free(dist);
}

// funcao que trata a viagem de um heroi para uma base
void trata_evento_viaja (struct lef_t *l, int tempo, struct heroi_t *h, struct base_t *b, struct mundo_t *w) {
	
	struct evento_t *ev;
	// distancia entre posicao atual e base destino
	int dist = sqrt(pow(w->bases[h->id_base]->local->x - b->local->x, 2) + pow(w->bases[h->id_base]->local->y - b->local->y, 2));
	int duracao = dist / h->vel;

	if (!l || !h || !b)
		return;

	// evento chegada
	ev = cria_evento (tempo + duracao, CHEGA, h->id, b->id);
	insere_lef (l, ev);
	printf ("%6d: VIAJA  HEROI %2d BASE %d BASE %d DIST %d VEL %d CHEGA %d\n", tempo, h->id, w->bases[h->id_base]->id, b->id, dist,  h->vel, duracao + tempo);
}

// funcao que trata o aviso do porteiro da base
void trata_evento_avisa(struct lef_t *l, int tempo, struct base_t *b) {

	int id_heroi;
    struct evento_t *ev;

    if (!l || !b)
        return;

    printf("%6d: AVISA PORTEIRO BASE %d (%2d/%2d) FILA", tempo, b->id, cjto_cardinalidade(b->presentes), b->lot);
    lista_imprime("", b->espera);

	// enquanto a base nao estiver cheia e a lista de espera nao estiver vazia
    while ((cjto_cardinalidade(b->presentes) < b->lot) && (!lista_vazia(b->espera))) {
        lista_retira(b->espera, &id_heroi, 0);
        cjto_adicionar(b->presentes, id_heroi);
        ev = cria_evento(tempo, ENTRA, id_heroi, b->id);
        insere_lef(l, ev);
        printf("%6d: AVISA PORTEIRO BASE %d ADMITE %2d\n", tempo, b->id, id_heroi);
    }
}

void trata_evento_entra(struct lef_t *l, int tempo, struct heroi_t *h, struct base_t *b) {
    
	// tpb = tempo de permanencia na base
	int tpb; 
    struct evento_t *ev;

	if (!h || !b)
        return;

    cjto_adicionar(b->presentes, h->id);
    tpb = 15 + h->paciencia * aleat(1, 20);
    ev = cria_evento(tempo + tpb, SAI, h->id, b->id);
    insere_lef(l, ev);
    printf("%6d: ENTRA HEROI %2d BASE %d (%2d/%2d) SAI %d\n", tempo, h->id, b->id, cjto_cardinalidade(b->presentes), b->lot, tpb + tempo);
}

// deleta o id do heroi, do conjunto dos presentes
void trata_evento_sai(struct lef_t *l, int tempo, struct heroi_t *h, struct base_t *b) {
    
	struct evento_t *ev;
    int dest_aleat;

	if (!h || !b)
        return;

    
    cjto_remover(b->presentes, h->id);
    dest_aleat = aleat(0, N_BASES - 1);
    ev = cria_evento(tempo, VIAJA, h->id, dest_aleat);
    insere_lef(l, ev);
    ev = cria_evento(tempo, AVISA, 0, 0);
    insere_lef(l, ev);
    printf("%6d: SAI HEROI %2d BASE %d (%2d/%2d)\n", tempo, h->id, b->id, cjto_cardinalidade(b->presentes), b->lot);
}


// chega na base
void trata_evento_espera (struct lef_t *l, int tempo, struct heroi_t *h, struct base_t *b) {
	struct evento_t *ev;
	
	if (!h || !b)
		return;
	
	lista_insere (b->espera, h->id, -1); // sempre final da fila
	ev = cria_evento (tempo, AVISA, 0, b->id);
	insere_lef (l, ev);
	printf ("%6d: ESPERA HEROI %2d BASE %d (%2d)\n", tempo, h->id, b->id, lista_tamanho (b->espera) - 1);
}

// paciencia menor *FORMULA&**
void trata_evento_desiste (struct lef_t *l, int tempo, struct heroi_t *h, struct base_t *b) {
	struct evento_t *ev;
	int baseRand;

	if (!h || !b)
		return;
	
	baseRand = aleat (0, N_BASES - 1);
	ev = cria_evento (tempo, VIAJA, h->id, baseRand);
	insere_lef (l, ev);
	printf ("%6d: DESISTE HEROI %2d BASE %d\n", tempo, h->id, b->id);
}


//um evento chama outro evento, paciencia, lista cheia
// VERIFIACR A VARIAVEL ESPERARRR
void trata_evento_chega (struct lef_t *l, int tempo, struct heroi_t *h, struct base_t *b) {
	
	bool espera;
	struct evento_t *ev;

	if (!h || !b)
		return;
	
	h->id_base = b->id;
		// se a base nao estiver cheia e a lista de espera estiver vazia, o heroi entra na base
	if (b->presentes->num < b->lot && lista_vazia (b->espera))
		espera = true;
	
	else
		// se a base estiver cheia e a lista de espera estiver cheia, o heroi desiste
		// se a paciencia é maior que dez vezes o tamanho da lista de espera
		espera = (h->paciencia) > (10 * b->espera->size);
	
	if (espera) {
		ev = cria_evento (tempo, ESPERA, h->id,b->id);
		printf ("%6d: CHEGA HEROI %2d BASE %d (%2d/%2d) ESPERA\n", tempo, h->id, b->id, b->presentes->num ,b->lot);
	}
	else {
		ev = cria_evento (tempo, DESISTE, h->id, b->id);
		printf ("%6d: CHEGA HEROI %2d BASE %d (%2d/%2d) DESISTE\n", tempo, h->id, b->id, b->presentes->num ,b->lot);
		
	}
	insere_lef (l, ev);
}


// funcao que imprime as informações dos herois
void trata_evento_fim (int tempo, struct mundo_t *w, struct lef_t *l) {
	printf ("%6d: FIM\n", tempo);

	int i, m_completas;
    float media, cont, tentativas;
	struct evento_t *ev;
	cont = 0;


	for (i = 0; i < N_HEROIS; i++) {
		printf ("HEROI %2d PAC %3d VEL %4d EXP %4d HABS", w->herois[i]->id, w->herois[i]->paciencia, w->herois[i]->vel, w->herois[i]->exp);
		cjto_imprimir (w->herois[i]->habilidade);
	}

	// remover e destuir todos os eventos na lef
	while (l->primeiro) {
		ev = retira_lef (l);
		// missoes nao cumprimas
		if (ev->tipo == MISSAO)
			cont++;
		destroi_evento (ev);
	}

	m_completas = w->total_missoes - cont;
	media = (float)m_completas / w->total_missoes * 100;
	tentativas = (float) w->tentativas / w->total_missoes;
	printf ("%d/%d MISSOES CUMPRIDAS (%.2f%%), MEDIA %.2f TENTATIVAS/MISSAO\n", m_completas, w->total_missoes, media, tentativas);
}


int relogio_mundo (struct mundo_t *w) {
	if (!w)
		return -1;
	return w->relogio;
}

