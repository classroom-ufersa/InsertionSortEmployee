#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct funcionario Funcionario;

Funcionario* cria_funcionario(char *nome, char *cargo, char *cpf);

#endif // FUNCIONARIO_H