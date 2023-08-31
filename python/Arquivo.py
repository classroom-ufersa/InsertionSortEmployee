import os
from Funcionario import Funcionario

size = os.path.getsize('funcionario.txt')
isempty = size == 0

def abrir_arquivo():
    funcs = []
    if not isempty:
        with open ('funcionario.txt', 'r', encoding='utf8') as arquivo:
            for linha in arquivo:
                nome, cargo, documento = linha.strip().split()
                funcionario = Funcionario(nome, cargo, documento)
                funcs.append(funcionario)
                
    return funcs

def salvar_arquivo(funcionarios):
    with open ('funcionario.txt', 'w', encoding='utf8') as arquivo:
        arquivo.seek(0,0)
        for funcionario in funcionarios:
            arquivo.write(f'{funcionario.nome}\t{funcionario.cargo}\t{funcionario.documento}\n')
