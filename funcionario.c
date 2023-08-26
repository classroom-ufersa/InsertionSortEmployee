
void grava_arquivo(Funcionario* funcionario,int tamanho){
FILE* arquivo = fopen("funcionarios.txt", "wt");
if(arquivo == NULL){
    printf("Erro ao abrir arquivo!");
    exit(1);
}
imprime(funcionario,tamanho,arquivo);
fclose(arquivo);
}


void imprime(Funcionario** funcionario, int tamanho, FILE* arquivo){
    insertion_sort_funcionarios(funcionario,tamanho);
        fprintf(arquivo,"Nome:\tCargo:\tDocumento:\t\n");
    for(int contador = 0; contador < tamanho; contador++){
        fprintf(arquivo,"%s\t %s\t %d\t", funcionario[contador]->nome, funcionario[contador]->cargo, funcionario[contador]->documento);
    }
}

