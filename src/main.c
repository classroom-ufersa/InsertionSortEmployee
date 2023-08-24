#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.c"

int main(){
    int qtd_funcs = 0;
    Funcionario **funcs = (Funcionario**) malloc (10*sizeof(Funcionario*));

    int doc = 123123;
    funcs[qtd_funcs] = cria_funcionario("bruno", "progamador", doc);
    qtd_funcs++;
    funcs[qtd_funcs] = cria_funcionario("abruno", "progamador", doc);
    qtd_funcs++;
    funcs[qtd_funcs] = cria_funcionario("zbruno", "progamador", doc);
    qtd_funcs++;

    insertion_sort_funcionarios(funcs, qtd_funcs);

    for (int i = 0; i < qtd_funcs; i++)
    {
        printf("%s\n", funcs[i]->nome);
    }
    

    return 0;
}
