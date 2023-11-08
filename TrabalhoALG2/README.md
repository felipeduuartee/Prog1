# Trabalho de Algoritmos e Estruturas de Dados II

Este trabalho foi realizado como parte do curso de Algoritmos e Estruturas de Dados II da Universidade Federal do Paraná (UFPR).

## Título do Trabalho
Estudo Sistemático de Algoritmos de Busca e Ordenação em Diferentes Contextos

## Autor
- **Nome:** Felipe Duarte Silva
- **GRR:** 20231957

## Introdução
Este relatório apresenta um estudo sistemático de algoritmos de busca e ordenação em diferentes contextos. Foram analisados algoritmos de busca sequencial e busca binária, bem como algoritmos de ordenação, incluindo Insertion Sort, Selection Sort, Merge Sort e Quick Sort.

O objetivo deste estudo é avaliar a eficiência, o número de comparações e o tempo de execução desses algoritmos para diferentes tamanhos de entradas.

## Algoritmos de Busca
### Busca Sequencial
A busca sequencial é um algoritmo que analisa cada elemento da lista de dados sequencialmente. Ele continua até encontrar o elemento desejado ou verificar todos os elementos, indicando a ausência do elemento na lista.

### Busca Binária
A busca binária é uma técnica que requer que a lista de dados esteja previamente ordenada. O algoritmo divide o conjunto de dados pela metade repetidamente, eliminando metades onde o elemento desejado não pode estar, até localizar o elemento ou esvaziar o conjunto.

## Algoritmos de Ordenação
### Insertion Sort
O algoritmo Insertion Sort percorre a lista de dados e coloca cada elemento na posição correta em relação aos elementos já avaliados, garantindo a ordenação até o elemento atual.

### Selection Sort
O algoritmo Selection Sort identifica o menor (ou maior) elemento da lista e o troca com o primeiro elemento não ordenado. Esse processo é repetido até que todos os elementos estejam ordenados.

### Merge Sort
O Merge Sort divide a lista de dados em duas metades, ordena cada metade individualmente e, em seguida, mescla as duas metades ordenadas para produzir a lista final ordenada.

### Quick Sort
O Quick Sort seleciona um elemento chamado "pivô" e particiona a lista de modo que todos os elementos menores que o pivô venham antes dele, e todos os elementos maiores venham depois. Esse processo é aplicado às sublistas resultantes.

## Resultados dos Testes
Os algoritmos foram avaliados usando vetores ordenados de forma não crescente em uma máquina com as seguintes especificações:

- Processador: 11th Gen Intel® Core™ i7-1165G7 com velocidade base de 2.80GHz
- Memória RAM: 15 GiB
- Sistema Operacional: Ubuntu 20.04.6

Os resultados dos testes incluem o número de comparações e o tempo de execução para diferentes tamanhos de vetores. Os resultados são apresentados graficamente, com ênfase nas análises dos algoritmos de ordenação.

## Conclusão
Os resultados destacam a variabilidade de eficiência entre os algoritmos em diferentes contextos. Comprovou-se que o Quick Sort, influenciado pela escolha do pivô, e o Merge Sort são mais eficientes que o Insertion Sort e o Selection Sort, independentemente da dimensão do vetor. Quanto às técnicas de busca, a Busca Binária, que requer dados ordenados, supera a Busca Sequencial em eficiência para vetores de todos os tamanhos.

Para informações mais detalhadas, consulte o relatório completo.
