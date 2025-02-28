Olá!
Este código foi feito como projeto prático para a disciplina de Estrutura de Dados, na UFSCar-So, para o Prof. Mário.
As estruturas implementadas neste código foram:
  1 - uma fila estática.
  2 - uma lista dinâmica duplamente encadeada circular com sentinela e iterador.
As funções foram separadas em três arquivos (.c) e utilizando uma mesma biblioteca (game.h) que foi criada para o projeto também.
A proposta foi recriar, de forma mais simples, um jogo de infância, o "Card-Jitsu", também conhecido como "Desafio Ninja", dentro do (finado T^T) server online "Club Penguin".
A fila foi aplicada como o "deque de cartas" (pack) de cada player. As cartas só podem ser retiradas pelo topo e, após jogadas, inseridas no fim da fila.
A lista foi aplicada como a "mão" (hand) de cada player. Cada player tem cinco cartas dispostas de seu prórpio deque para escolher qual jogar (a mesma que retornará à fila).

As regras do jogo estão dispostas dentro do próprio código. Aqui estão as mesmas:  
  ---REGRAS---
  Olá, pequeno gafanhoto!
  Bem-vindo ao Card-Jitsu, um e-sporte tradicional dos tempo remotos de Club Penguin.
  O jogo consiste em rodadas de batalhas de cartas. Cada jogador terá uma mão com cinco cartas e seu pack de cartas para repor a mão ao longo da partida. Cada carta possui um elemento (água, fogo, gelo) e um valor (de 1 até 7). Em cada rodada os jogadores devem escolher uma cartasem que seu adversário saiba qual foi.
  As cartas escolhidas entrarão em disputa ganhando pela regra de prioridade:
    1. Elementos diferentes - água vence fogo, fogo vence gelo e gelo vence água(como em pedra, papel e tesoura).
    2. Maior valor - caso os elementos das cartas escolhidas sejam iguais, ganhará a carta de maior valor.
    3. Caso ambos sejam iguais, é um empate técnico e ninguém obtem vitória na rodada.\nO formato das cartas quando mostradas é '(x) - [elemento | valor]', sendo x o número para escolhê-la.
  Ganha aquele que completar 3 vitórias de um mesmo elemento ou 1 vitória de cada elemento.

Caso tenha interesse em saber mais sobre o jogo, você pode acessar este link: https://club-penguin-land20.fandom.com/pt-br/wiki/Desafio-Ninja ou pesquisar diretamente por "Card-Jitsu" no navegador.
  
