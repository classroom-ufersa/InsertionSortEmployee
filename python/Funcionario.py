class Funcionario:
    """classe representa funcionario"""
    def __init__(self, nome, cargo, documento):
        self._nome = nome
        self._cargo = cargo
        self._documento = documento    
    @property
    def nome(self):
        return self._nome    
    @property
    def cargo(self):
        return self._cargo    
    @property
    def documento(self):
        return self._documento    
    @nome.setter
    def nome(self, nome):
        self._nome = nome        
    @cargo.setter
    def cargo(self, cargo):
        self._cargo = cargo        
    @documento.setter
    def documento(self, documento):
        self._documento = documento
        
    def imprime_dados(self):
        print(f'Funcionario {self.nome} - Cargo {self.cargo} - Documento {self.documento}')
        
    @staticmethod
    def insertion_sort(funcionarios):
        for i in range(1, len(funcionarios)):
            chave = funcionarios[i]
            j = i - 1
            while j >= 0 and chave.nome < funcionarios[j].nome:
                funcionarios[j + 1] = funcionarios[j]
                j -= 1
            funcionarios[j + 1] = chave
        
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