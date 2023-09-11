import os
from Funcionario import Funcionario

def abrir_arquivo():
    funcs = []
    try:
        with open ('funcionario.txt', 'r', encoding='utf8') as arquivo:
            for linha in arquivo:
                dados = linha.strip().split()
                if len(dados)==3:
                    funcionario = Funcionario(*dados)
                    funcs.append(funcionario)   
            arquivo.flush()        
                    
    except FileNotFoundError:
        print("Arquivo 'funcionario.txt' não existe!")
                            
    return funcs

def salvar_arquivo(funcionarios):
    with open ('funcionario.txt', 'w', encoding='utf8') as arquivo:
        arquivo.seek(0,0)
        for funcionario in funcionarios:
            arquivo.write(f'{funcionario.nome}\t{funcionario.cargo}\t{funcionario.documento}\n')
