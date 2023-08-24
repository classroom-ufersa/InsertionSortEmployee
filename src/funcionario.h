#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct funcionario Funcionario;

/*Cria tipo estruturado Funcionario e preenche os seus campos*/
Funcionario *cria_funcionario(char *nome, char *cargo, int documento);

/* Ordena por ordem alfabetica o campo "nome" de um array do tipo Funcionario
** @param Funcionario: array de funcionarios
** @param tamanho: tamanho do array
*/
void insertion_sort_funcionarios(Funcionario **funcionario, int tamanho);

#endif // FUNCIONARIO_H