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
    struct medicamento remedios[3];
};

void consultar(struct pacientes p[], int num) {
    char nome[50];
    int encontrado = 0;

    printf("Digite o nome do paciente que deseja consultar: ");
    scanf("%s", nome);

    for (int i = 0; i < num; i++) {
        if (strcmp(p[i].nome, nome) == 0) {
            printf("\n--- Informações do Paciente ---\n");
            printf("Nome: %s\n", p[i].nome);
            printf("Idade: %d anos\n", p[i].idade);
            printf("Peso: %.2f kg\n", p[i].peso);
            for(int j = 0; j < 3; j++) {
                if(strlen(p[i].remedios[j].nome) != 0) {
                    printf("Medicamento %d: %s\n", j+1, p[i].remedios[j].nome);
                    printf("Data de Início: %d/%d/%d\n",
                        p[i].remedios[j].inicio.dia,
                        p[i].remedios[j].inicio.mes,
                        p[i].remedios[j].inicio.ano);
                }
            }
            printf("\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Paciente não encontrado.\n");
    }
}

struct pacientes cadastro() {
    int n, i = 0;
    struct pacientes cadastro;

    printf("Digite o nome do paciente: ");
    scanf("%s", cadastro.nome);
    printf("Digite a idade do paciente: ");
    scanf("%d", &cadastro.idade);
    printf("Digite o peso do paciente: ");
    scanf("%f", &cadastro.peso);

    printf("Quantos medicamentos %s está tomando? ", cadastro.nome);
    scanf("%d", &n);

    while (i < n) {
        printf("Digite nome do %d° medicamento: ", i + 1);
        scanf("%s", cadastro.remedios[i].nome);

        printf("Digite o dia de início do medicamento: ");
        scanf("%d", &cadastro.remedios[i].inicio.dia);
        printf("Digite o mês de início do medicamento: ");
        scanf("%d", &cadastro.remedios[i].inicio.mes);
        printf("Digite o ano de início do medicamento: ");
        scanf("%d", &cadastro.remedios[i].inicio.ano);

        i++;
    }

    return cadastro;
}

int main() {
    int escolha;
    struct pacientes pacientes[100];
    int numPacientes = 0;

    escolha = 0;

    while (escolha != 3) {
        printf("Voce quer cadastrar ou consultar informações de um paciente?\n");
        printf("Digite 1 para cadastrar\n");
        printf("Digite 2 para consultar informações\n");
        printf("Digite 3 para sair\n");
        printf("Digite para o que deseja fazer: \t");
        scanf("%d", &escolha);

        if (escolha == 1) {
            pacientes[numPacientes] = cadastro();
            numPacientes++;
        }

        if (escolha == 2) {
            consultar(pacientes, numPacientes);
        }
    }

    return 0;
}
