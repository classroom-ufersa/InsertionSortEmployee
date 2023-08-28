#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

struct funcionario
{
    char nome[101];
    char cargo[21];
    int documento;
};

Funcionario *cria_funcionario(char *nome, char *cargo, int documento)
{
    Funcionario *f = (Funcionario *)malloc(sizeof(Funcionario));
    if (f == NULL)
    {
        exit(1);
    }

    strcpy(f->nome, nome);
    strcpy(f->cargo, cargo);
    f->documento = documento;

    return f;
}

void insertion_sort_funcionarios(Funcionario **funcionario, int tamanho)
{
    int i, j;
    Funcionario *aux;
    // Laço principal:
    // Percorre o vetor a partir do 1o item até o penúltimo
    for (i = 0; i < tamanho - 1; i++)
    {
        // compara o item i com o proximo item da lista
        if (strcmp(funcionario[i]->nome, funcionario[i + 1]->nome) > 0)
        {
            // Se o item i for maior que o item i+1, armazena o item i+1 na variavel auxiliar aux
            aux = funcionario[i + 1];
            // Promove a troca de itens
            funcionario[i + 1] = funcionario[i];
            funcionario[i] = aux;
            // J recebe o indice do item anterior para iniciar o laço interno que faŕa
            // as comparações do item base(aux) com os item anteriores.
            j = i - 1;
            while (j >= 0)
            {
                if (strcmp(aux->nome, funcionario[j]->nome) < 0)
                {
                    // Se o item base for menor que o item anterior, será realizada a troca
                    funcionario[j + 1] = funcionario[j];
                    funcionario[j] = aux;
                }
                else
                {
                    // Se o item anterior não for maior que o item base, o laço se encerra
                    break;
                }
                // caso a troca seja realizada, aux será comparado com o item anterior
                j--;
            }
        }
    }
}

FILE *abrir_arquivo(Funcionario **funcionario, int *tamanho)
{
    char nome[101], cargo[21];
    int documento;
    FILE *arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    int i;
    for (i = 0; !feof(arquivo); i++)
    {
        // Ler os arquivo funcionario
        fscanf(arquivo, "%s %s %d\n",nome,cargo,&documento);
        funcionario[i]=cria_funcionario(nome,cargo,documento);
    }

    *tamanho = i;
    return (arquivo);
}

void grava_arquivo(Funcionario** funcionario,int tamanho){
FILE* arquivo = fopen("funcionarios.txt", "wt");
if(arquivo == NULL){
    printf("Erro ao abrir arquivo!");
    exit(1);
}
imprime(funcionario,tamanho,arquivo);
fclose(arquivo);
}


void imprime(Funcionario** funcionario, int tamanho, FILE* arquivo){
    insertion_sort_funcionarios(funcionario,tamanho);
    for(int contador = 0; contador < tamanho; contador++){
    printf(arquivo,"%s\t %s\t %d\t", funcionario[contador]->nome, funcionario[contador]->cargo, funcionario[contador]->documento);
    }
}

