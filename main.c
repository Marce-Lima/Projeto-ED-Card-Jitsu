#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "game.h"

void read_rules();

int main(){
	// tipo 0 = fogo
	// tipo 1 = agua
	// tipo 2 = gelo

	Player p1, p2;
	char resposta;

	//randomizar as cartas nos dois packs e gerar as duas hands
	init_fila(p1);
	init_fila(p2);

	init_hand(p1);
	init_hand(p2);

	//tela inicial
	printf("\n CARD-JITSU \n\n");

	printf("Ler as regras? (s/n)\n");
	scanf("%c\n", &resposta);

	if(){
		read_rules();
	}else{
		printf("Ah, vejo que você já tem o conhecimento necessário...\n");
		printf("Então mostre do que é capaz!");
	}

	printf("Insira o nome do(a) player 1: ");
	scanf("%[^\n]s", p1.name);

	printf("\nInsira o nome do(a) player 2: ");
	scanf("%[^\n]s", p2.name);

	

	return 0;
}

void read_rules(){
	printf("---REGRAS---\n\n");

	printf("Olá, pequeno gafanhoto!\n Bem-vindo ao Card-Jitsu, um e-sporte tradicional dos tempo remotos de Club Penguin.\n");
	printf("O jogo consiste em rodadas de batalhas de cartas. Cada jogador terá uma mão com cinco cartas e seu pack de cartas para repor a mão ao longo da partida.\n");
	printf("Cada carta possui um elemento (água, fogo, gelo) e um valor (de 1 até 7).\n");
	printf("Em cada rodada os jogadores devem escolher uma cartasem que seu adversário saiba qual foi.\n\n");

	printf("As cartas escolhidas entrarão em disputa ganhando pela regra de prioridade:\n");
	printf("1. Elementos diferentes - água vence fogo, fogo vence gelo e gelo vence água(como em pedra, papel e tesoura).\n");
	printf("2. Maior valor - caso os elementos das cartas escolhidas sejam iguais, ganhará a carta de maior valor.\n");
	printf("3. Caso ambos sejam iguais, é um empate técnico e ninguém obtem vitória.\n");
	printf("Ganha aquele que completar 3 vitórias de um mesmo elemento ou 1 vitória de cada elemento.\n\n");

	printf("Agora, vamos para a prática!\n\n");
};