#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
typedef struct funcionario Funcionario;

/*Cria tipo estruturado Funcionario e preenche os seus campos
** @param nome: nome do funcionario
** @param cargo: cargo ocupado pelo funcionario
** @param documento: documento que identifica o funcionario
*/
Funcionario *cria_funcionario(char *nome, char *cargo, int documento);

/* Ordena por ordem alfabetica o campo "nome" de um array do tipo Funcionario
** @param Funcionario: array de funcionarios
** @param tamanho: tamanho do array
*/
void insertion_sort_funcionarios(Funcionario **funcionario, int tamanho);

/*Função abre o arquivo, ler ele e armazena em um vetor
**@param Funcionario: arry de funcionarios
**@param tamanho: tamanho do arry
*/
FILE *abrir_arquivo(Funcionario **funcionario, int *tamanho);

/*Grava os dados de um array de Funcionario em um arquivo de texto
** @param funcionario: array de Funcionario
** @param tamanho: numero de funcionarios
*/
void grava_arquivo(Funcionario** funcionario,int tamanho);

/*Imprime na tela os dados de um array de Funcionario em um arquivo de texto
** @param funcionario: array de Funcionario
** @param tamanho: numero de funcionarios
*/
void imprime(Funcionario** funcionario, int tamanho);

#endif // FUNCIONARIO_H