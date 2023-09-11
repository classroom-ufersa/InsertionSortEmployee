class Funcionario:
    """classe representa funcionario"""
    def __init__(self, nome, cargo, documento):
        self._nome = nome
        self._cargo = cargo
        self._documento = documento
    """Getters"""        
    @property
    def nome(self):
        return self._nome    
    @property
    def cargo(self):
        return self._cargo    
    @property
    def documento(self):
        return self._documento
    """Setters"""     
    @nome.setter
    def nome(self, nome):
        self._nome = nome        
    @cargo.setter
    def cargo(self, cargo):
        self._cargo = cargo        
    @documento.setter
    def documento(self, documento):
        self._documento = documento
    """Imprime os dados de um funcionario"""     
    def imprime_dados(self):
        print(f'{self.nome} - {self.cargo} - {self.documento}')
    """Método de ordenação insertion sort aplicado para ordenar uma lista de Funcionarios por nome"""    
    @staticmethod
    def insertion_sort(funcionarios):
        for i in range(1, len(funcionarios)):
            chave = funcionarios[i]
            j = i - 1
            while j >= 0 and chave.nome < funcionarios[j].nome:
                funcionarios[j + 1] = funcionarios[j]
                j -= 1
            funcionarios[j + 1] = chave
    """Lista todos os funcionarios"""
    @staticmethod
    def lista_funcionarios(funcionarios):
        print('NOME   CARGO   DOCUMENTO')
        for funcionario in funcionarios:
            funcionario.imprime_dados()
        
if __name__ == '__main__':
    funcionarios = [
    Funcionario("Maria", "Gerente", "123"),
    Funcionario("João", "Analista", "456"),
    Funcionario("Carlos", "Assistente", "789")
]

    print("Funcionários não ordenados:")
    for func in funcionarios:
        func.imprime_dados()

    Funcionario.insertion_sort(funcionarios)

    print("\nFuncionários ordenados por nome:")
    for func in funcionarios:
        func.imprime_dados()