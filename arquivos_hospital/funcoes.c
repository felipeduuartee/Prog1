#include "structsHospital.h"


// essa função irá imprimir os dados do paciente após comparar com os nomes ja cadastrados no sistema
void consultar(struct pacientes p[], int num) {
    char nome[50];
    int encontrado = 0;

    printf("Digite o nome do paciente que deseja consultar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < num; i++) {
        if (strcmp(p[i].nome, nome) == 0) { // compara o nome do paciente no indice i e o nome que foi pedido as informações
            printf("\n--- Informações do Paciente ---\n");
            printf("Nome: %s\n", p[i].nome);
            printf("Idade: %d anos\n", p[i].idade);
            printf("Peso: %.2f kg\n", p[i].peso);
            for(int j = 0; j < 10; j++) {
                if(strlen(p[i].remedios[j].nome) != 0) { // analisa se o paciente ta tomando algum remedio, 'mais de 0'
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
        printf("\033[31mPaciente não encontrado.\033[0m\n\n");
    }
}


// funcao que cadastra o paciente, nome, idade, peso e medicamentos
struct pacientes cadastro() {
    int n, i = 0;
    struct pacientes cadastro;

    memset(&cadastro, 0, sizeof(cadastro));  // Inicializando com zeros

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", cadastro.nome);
    printf("Digite a idade de %s *APENAS NUMEROS* : ", cadastro.nome);
    scanf("%d", &cadastro.idade);
    printf("Digite o peso de %s *APENAS NUMEROS E PONTOS*: ",cadastro.nome);
    scanf("%f", &cadastro.peso);

    printf("Quantos medicamentos %s está tomando? ", cadastro.nome);
    scanf("%d", &n);

    while (i < n) {
        printf("Digite nome do %d° medicamento: ", i + 1);
        scanf(" %[^\n]", cadastro.remedios[i].nome);

        printf("Digite o dia de inicio do %s *APENAS NUMEROS*: ", cadastro.remedios[i].nome);
        scanf("%d", &cadastro.remedios[i].inicio.dia);
        printf("Digite o mês de inicio do %s *APENAS NUMEROS*: ", cadastro.remedios[i].nome);
        scanf("%d", &cadastro.remedios[i].inicio.mes);
        printf("Digite o ano de inicio do %s *APENAS NUMEROS*: ", cadastro.remedios[i].nome);
        scanf("%d", &cadastro.remedios[i].inicio.ano);

        i++;
    }

    return cadastro;
}



