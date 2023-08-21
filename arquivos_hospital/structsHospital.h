#include <stdio.h>
#include <string.h>

struct data {
    int dia;
    int mes;
    int ano;
};

struct medicamento {
    char nome[50];
    struct data inicio;
};

struct pacientes {
    char nome[50];
    int idade;
    float peso;
    struct medicamento remedios[10];
};

void consultar(struct pacientes p[], int num) ;
struct pacientes cadastro() ;
