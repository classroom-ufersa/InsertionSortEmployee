from Funcionario import Funcionario
from Arquivo import *
import time


funcs = []

def menu():
    print( """
        ===========MENU===============
         [1] - CADASTRAR FUNCIONARIO
         [2] - LISTAR
         [3] - SAIR
        ============================== 
        """)
    return input(" -- Digite uma ação: ")
    
def is_digit_exepction(var, flag):
    # Flag 1 verifica se a variavel é um digito
    # Flag != 1 verifica se a variavel não é um digito
    if flag == 1:
        if var.isdigit():
            print("Entrada Invalida!")
    else:
         if not var.isdigit():
            print("Entrada Invalida!")

escolha = None


if __name__ == '__main__':
    funcs = abrir_arquivo()
        
    escolha_int = None
    while escolha_int != 3:
        # inicializa as variaveis no formato correto
        name = '0'
        office = '0'
        document = 'doc'      
        escolha = menu()
        
        if escolha.isdigit():
            escolha_int = int(escolha)
        
        match escolha_int:
            case 1:
                while name.isdigit():
                    name = input("Digite o nome: ")
                    is_digit_exepction(name, 1)
                while office.isdigit():
                    office = input("Digite o cargo: ")
                    is_digit_exepction(office, 1)
                while not document.isdigit():
                    document = input("Digite o documento (somente números): ")
                    is_digit_exepction(document, 0)

                print("Cadastrando...")    
                novo_func = Funcionario(name.upper(), office.upper(), document)
                funcs.append(novo_func)
                print("Cadastro Realizado!")
            case 2:
                Funcionario.insertion_sort(funcs)
                print("Lista de funcionarios:")
                Funcionario.lista_funcionarios(funcs)
            case 3:
                print("Saindo...")
            case _ :
                print("Entrada Invalida!")
        
    start_time = time.time()            
    Funcionario.insertion_sort(funcs)
    print(f'Elapsed time: {time.time() - start_time}')
    salvar_arquivo(funcs)
