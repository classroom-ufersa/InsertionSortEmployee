# Problemática  

Implementar um algoritmo que manipula um tipo estruturado **Funcionarios** e mantém os funcionários ordenados em ordem alfabética em um arquivo usando **insertion sort**.

## Desenvolvedores
- [Carlos Gabriel Ferreira](https://github.com/GabasDev)
- [Felipe Hidequel Santos da Silva](https://github.com/felipehidequel)
- [Michely Vitória Costa Felix](https://github.com/MichelyFelix)
# Strings com insertion sort
**Ordenação de strings com Inserion Sort**

O Insertion Sort, ou "Ordenação por Inserção", é um algoritmo de ordenação simples que funciona da seguinte maneira:

Imagine que você tem um baralho de cartas em mãos, e deseja organizá-las em ordem crescente. Você pega uma carta por vez e a insere na posição correta dentro das cartas já ordenadas que você tem na mão.

## Como funciona o Insertion Sort

**1-Divisão Inicial:** No início, você considera a primeira carta como uma lista ordenada de um único elemento.

**2-Inserção:** A partir da segunda carta em diante, você a compara com as cartas na lista ordenada. Você move as cartas maiores para a direita e insere a carta na posição adequada para que a lista ordenada cresça.

**3-Repetição:** Você repete o processo para cada carta restante na mão, sempre inserindo a carta na posição correta na lista ordenada.

**4-Resultado:** Depois de inserir todas as cartas, você obterá um baralho ordenado.

![Insertion Sort](https://th.bing.com/th/id/R.52464cf460b30d1022da21dc9d927de0?rik=kRMcpjXJT0y1bw&riu=http%3a%2f%2fwww.thagomizer.com%2fimg%2fInsertionSortInPlace.gif&ehk=vVtb0fIpEJJDvV4BNjGSBhyb3kw95pH2vSA%2bEpsiNxY%3d&risl=&pid=ImgRaw&r=0)

# Funções utilizadas
## Em C
- **Insertion Sort**
```
void insertion_sort_funcionarios(Funcionario **funcionario, int tamanho)
{
    int i, j;
    Funcionario *aux;
    // Laço principal:
    // Percorre o vetor a partir do 1o item até o penúltimo
    for (i = 0; i < tamanho - 1; i++)
    {
        // compara o item i com o proximo item da lista
        if (strcmp(funcionario[i]->nome, funcionario[i + 1]->nome) > 0)
        {
            // Se o item i for maior que o item i+1, armazena o item i+1 na variavel auxiliar aux
            aux = funcionario[i + 1];
            // Promove a troca de itens
            funcionario[i + 1] = funcionario[i];
            funcionario[i] = aux;
            // J recebe o indice do item anterior para iniciar o laço interno que faŕa
            // as comparações do item base(aux) com os item anteriores.
            j = i - 1;
            while (j >= 0)
            {
                if (strcmp(aux->nome, funcionario[j]->nome) < 0)
                {
                    // Se o item base for menor que o item anterior, será realizada a troca
                    funcionario[j + 1] = funcionario[j];
                    funcionario[j] = aux;
                }
                else
                {
                    // Se o item anterior não for maior que o item base, o laço se encerra
                    break;
                }
                // caso a troca seja realizada, aux será comparado com o item anterior
                j--;
            }
        }
    }
}
```
## Em Python
- **Insertion Sort**
```
@staticmethod
def insertion_sort(funcionarios):
    for i in range(1, len(funcionarios)):
        chave = funcionarios[i]
        j = i - 1
        while j >= 0 and chave.nome.upper() < funcionarios[j].nome.upper():
            funcionarios[j + 1] = funcionarios[j]
            j -= 1
        funcionarios[j + 1] = chave
```

# Análise de complexidade
## Big-O
O pior e médio caso do algoritmo de ordenação Insertion Sort é  T(n) = O(n²), indicando que o tempo de execução cresce quadraticamente conforme o tamanho da entrada aumenta. O melhor caso desse algoritmo é T(n) = O(n), quando a entrada está parcialmente ordenada, resultando em um crescimento linear no tempo de execução em relação ao tamanho da entrada.
```
   T(n) = c1 + (c2+c3+c4+c8)(n-1) + n(n-1)(c5+c6+c7)

    T(n) = c + b(n-1) + n(n-1)*a

    T(n) = c + bn - b + an² - an

    T(n) = bn + an² - an

    T(n) = n + n² - n

    T(n) = n²

    T(n) = O(n²)
 ```

# Vantagens e Desvantagens
## Vantagens 
- Simples de se implementar
- É um algoritmo estavel
## Desvantagens
- Quando se tem muitos dados não é muito eficiente 
