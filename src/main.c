#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.c"

int main() {
    int opcao;
    Funcionario **funcs = (Funcionario **)malloc(10 * sizeof(Funcionario *));
    int numFuncionarios = 0;

    char nome[50];
    char cargo[50];
    int documento;

    do {
        printf("-- BEM VINDO --\n");
        printf("-- DIGITE A OPCAO DESEJADA --\n");
        printf("1-- CADASTRAR FUNCIONARIO --\n");
        printf("2-- LISTAR FUNCIONARIO\n");
        printf("3-- SAIR\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                abrir_arquivo(&funcs, &numFuncionarios); 
                printf("Digite o nome do funcionario: ");
                scanf("%s", nome);
                printf("Digite o cargo do funcionario: ");
                scanf("%s", cargo);
                printf("Digite o numero do documento do funcionario: ");
                scanf("%d", &documento);
                cria_funcionario(nome, cargo, &documento); 
                break;
            case 2:
                listar_funcionarios(funcs, numFuncionarios);
                break;
            default:
                printf("Opcao inválida\n");
                break;
        }
    } while (opcao != 3);

    // Libera a memoria alocada para os funcionarios
    for (int i = 0; i < numFuncionarios; i++) {
        free(funcs[i]);
    }
    free(funcs);
    return 0;
}