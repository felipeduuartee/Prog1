#include "listas.h"

int main() {
    ListaDuplamenteEncadeada lista;
    INICIALIZAR(&lista);
    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir valor na lista\n");
        printf("2. Buscar valor na lista\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                INSERIR(&lista, valor);
                break;
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                if (buscarValor(&lista, valor)) {
                    printf("Valor encontrado!\n");
                } else {
                    printf("Valor não encontrado na lista.\n");
                }
                break;
            case 3:
                IMPRIMIR(&lista);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
