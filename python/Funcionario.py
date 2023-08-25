class Funcionario:
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