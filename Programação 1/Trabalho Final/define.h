#ifndef DEFINE_H
#define DEFINE_H

// Definições de tempo
#define T_INICIO 0
#define T_FIM_DO_MUNDO 525600
#define TRES_DIAS 4320

// Definições de tamanho e número de elementos
#define N_TAMANHO_MUNDO 20000
#define N_HABILIDADES 10
#define N_HEROIS (N_HABILIDADES * 5)
#define N_BASES (N_HEROIS / 6)
#define N_MISSOES (T_FIM_DO_MUNDO / 100)

// Definições de tipos de eventos
#define CHEGA 1
#define ESPERA 2
#define DESISTE 3
#define AVISA 4
#define ENTRA 5
#define SAI 6
#define VIAJA 7
#define MISSAO 8
#define FIM 9

#endif // DEFINE_H
