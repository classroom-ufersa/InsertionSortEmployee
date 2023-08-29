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
        
    while escolha != 3:
        print(menu)      
        escolha = int(input(" -- Digite uma ação: "))
        
        match escolha:
            case 1:
                name = input("Digite o nome: ")
                office = input("Digite o cargo: ")
                document = input("Digite o documento: ")
                novo_func = Funcionario(name, office, document)
                funcs.append(novo_func)
            case 2:
                for func in funcs:
                    func.imprime_dados()
        
    start_time = time.time()            
    Funcionario.insertion_sort(funcs)
    print(f'Elapsed time: {time.time() - start_time}')
    salvar_arquivo(funcs)
