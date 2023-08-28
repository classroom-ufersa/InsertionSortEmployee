def insertion_sort(lista):
    tamanho = len(lista)
    for i in range(0, tamanho):
        chave = lista[i]
        j = i - 1
        while j >= 0 and lista[j] > chave:
            lista[j+1] = lista[j]
            j -= 1
        lista[j+1] = chave


if __name__ == '__main__':        
    lista = ['felipe', 'abner', 'kneys']

    insertion_sort(lista=lista)

    print(lista)