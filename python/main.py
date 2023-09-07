from Funcionario import Funcionario
from Arquivo import *
import time


funcs = []

name = None
office = None
document = None

menu = """
    -- BEM VINDO --
    -- DIGITE A OPÇÃO DESEJADA --
    -- 1 - CADASTRAR FUNCIONARIO --
    -- 2 - LISTAR --
    -- 3 - SAIR --
    """
    
escolha = None


if __name__ == '__main__':
    funcs = abrir_arquivo()
        
    escolha_int = None
    while escolha_int != 3:
        print(menu)      
        escolha = input(" -- Digite uma ação: ")
        
        if escolha.isdigit():
            escolha_int = int(escolha)
        
        match escolha_int:
            case 1:
                name = input("Digite o nome: ")
                office = input("Digite o cargo: ")
                document = input("Digite o documento: ")
                novo_func = Funcionario(name.upper(), office.upper(), document)
                funcs.append(novo_func)
                print("Cadastro Realizado!")
            case 2:
                print('Ordernando...')
                start_time = time.time() 
                Funcionario.insertion_sort(funcs)
                end_time = time.time()
                print(f'Elapsed time: {end_time-start_time}')
                print("\nFuncionarios\n")
                for func in funcs:
                    func.imprime_dados()
        
    start_time = time.time()            
    Funcionario.insertion_sort(funcs)
    print(f'Elapsed time: {time.time() - start_time}')
    salvar_arquivo(funcs)
