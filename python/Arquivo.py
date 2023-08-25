from Funcionario import Funcionario

def abrir_arquivo():
    funcs = []
    with open ('funcionario.txt', 'r', encoding='utf8') as arquivo:
        for linha in arquivo:
            nome, cargo, documento = linha.strip().split()
            funcionario = Funcionario(nome, cargo, documento)
            funcs.append(funcionario)
    
    return funcs

def salvar_arquivo(funcionarios):
    with open ('funcionario.txt', 'a') as arquivo:
        for funcionario in funcionarios:
            arquivo.write(f'{funcionario.nome}\t{funcionario.cargo}\t{funcionario.documento}\n')

if __name__ == '__main__':
    funcionarios = abrir_arquivo()
    novo_func = Funcionario('felipe', 'sinistro', '21323')
    funcionarios.append(novo_func)
    salvar_arquivo(funcionarios)