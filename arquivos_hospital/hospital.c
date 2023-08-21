#include "structsHospital.h"

int main() {

        int escolha;
        struct pacientes pacientes[100];
        int numPacientes = 0;


            escolha = 0;

    while (escolha != 3) {
        printf("\n O que você deseja fazer? \n");
        printf("Digite 1 para cadastrar\n");
        printf("Digite 2 para consultar informações\n");
        printf("Digite 3 para sair\n");
        printf("Digite para o que deseja fazer: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            pacientes[numPacientes] = cadastro();
            numPacientes++;
        }

        else if (escolha == 2) {
            consultar(pacientes, numPacientes);
        }

        else if (escolha == 3) {
            printf("\nObrigado por usar nosso sistema!\n");
        }

        else {
            printf("\nOpção inválida, tente novamente.\n");
        }

    }
    return 0;
}
