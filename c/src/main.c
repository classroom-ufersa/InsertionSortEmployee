#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.c"

#define N_FUNCIONARIOS 10

int main() {
    int opcao;
    Funcionario **funcs = (Funcionario **)malloc(N_FUNCIONARIOS * sizeof(Funcionario *));
    int numFuncionarios = 0;
   int main() {
    int opcao;
    Funcionario **funcs = (Funcionario **)malloc(N_FUNCIONARIOS * sizeof(Funcionario *));
    int numFuncionarios = 0;
    
  FILE *arquivo_anexar = fopen("funcionarios.txt", "a+");// abre um arquivo em modo de inclusão
    if (arquivo_anexar == NULL) {
        perror("Erro ao abrir o arquivo!");
        exit(1);
    }
   
    //contagem de funcionarios detro do arquivo 
    while (fscanf(arquivo_anexar, "%*s %*s %*d\n") != EOF) {
        numFuncionarios++;
    }
    
    fseek(arquivo_anexar, 0, SEEK_SET);//move o ponteiro de leitura/escrita para o inicio do arquivo já que a+ aponta para o final do arquivo
    //le os dados dos funcionarios que estão no arquivo e armazena na estrutura Funcionario
    for (int i = 0; i < numFuncionarios; i++) {
        funcs[i] = (Funcionario *)malloc(sizeof(Funcionario));
        if (funcs[i] == NULL) {
            perror("Erro ao alocar memoria");
            exit(1);
        }
        fscanf(arquivo_anexar, "%s %s %d\n", funcs[i]->nome, funcs[i]->cargo, &funcs[i]->documento);
    }
    
    fclose(arquivo_anexar);
    
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
            if (numFuncionarios < N_FUNCIONARIOS){
                printf("Digite o nome do funcionario: ");
                scanf("%s", nome);
                printf("Digite o cargo do funcionario: ");
                scanf("%s", cargo);
                printf("Digite o numero do documento do funcionario: ");
                scanf("%d", &documento);                
                funcs[numFuncionarios] = cria_funcionario(nome, cargo, documento);
                numFuncionarios++; 
                break;
            }
            else{
                printf("Limite de funcionarios atingido");
                break;
            }
            case 2:
                if(numFuncionarios != 0){
                    imprime(funcs, numFuncionarios);
                }
                else{
                    printf("Nenhum Funcionario Cadastrado!\n");
                }

                break;
            default:
                break;
        }
    } while (opcao != 3);

   FILE *arquivoEscrita = fopen("funcionarios.txt", "w");
    if (arquivoEscrita == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Libera a memoria alocada para os funcionarios
    for (int i = 0; i < numFuncionarios; i++) {
        free(funcs[i]);
    }
    free(funcs);
    return 0;
}
