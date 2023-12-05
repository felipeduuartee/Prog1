# Simulação de Missões e Heróis

Este é um projeto de simulação de missões e heróis em C. Ele simula um mundo onde heróis devem cumprir missões em várias bases e possui um sistema de eventos para controlar o progresso do jogo.

## Pré-requisitos

Antes de executar o código, certifique-se de ter um ambiente de desenvolvimento C configurado no seu sistema. Você também pode compilar o código com um compilador C padrão, como o GCC.

## Estrutura do Projeto

O projeto é composto por vários arquivos e estruturas de dados principais:

  * main.c: O ponto de entrada do programa que controla a simulação.
  * structs.h: Define as estruturas de dados usadas no projeto, como heroi_t, missao_t, base_t, etc.
  * funcoes.c: Contém funções auxiliares que manipulam as estruturas de dados e realizam cálculos.
  * eventos.c: Lida com a criação e manipulação de eventos na simulação.
  * lista.c: Implementa uma lista encadeada usada em várias partes do código.
  * cjto.c: Implementa um conjunto (conjunto) de operações em conjuntos de dados.
  * mundo.c: Controla o mundo da simulação, incluindo heróis, missões e bases.
  * lef.c: Implementa uma fila de eventos futuros (LEF) para controlar o tempo na simulação.

