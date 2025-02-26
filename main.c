#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

void read_rules();
void show_hand(Player *p1);

int main(){

	Player p1, p2;
	char answer;
	int round = 0;

	//randomizar as cartas nos dois packs e gerar as duas hands
	init_fila(p1);
	init_fila(p2);
	init_hand(p1);
	init_hand(p2);

	//tela inicial
	printf("\n CARD-JITSU \n\n");

	//ler regras
	printf("Ler as regras? (s/n)\n");
	scanf("%c\n", &answer);
	if(answer == 's'){
		read_rules();
	}else{
		printf("Ah, vejo que você já tem o conhecimento necessário...\n");
		printf("Então mostre do que é capaz!\n\n");
	}

	//nomes dos players
	printf("Insira um nome para player 1: ");
	scanf("%[^\n]s", p1.name);

	printf("\nInsira um nome para player 2: ");
	scanf("%[^\n]s", p2.name);

	//jogo em si
	while(1)
	{
		//anunciar round
		round++;
		printf("---->>>< ROUND %d ><<<----\n", round);

		// tipo 0 = fogo
		// tipo 1 = agua
		// tipo 2 = gelo

		//anunciar vez do p1
		printf("== Vez de %s ==\n\n", p1.name);
		printf("(Não permita que seu adversário veja suas cartas! Pressione 'Enter' para ver suas cartas.)\n");
		show_hand(&p1);



		//condicoes de vitoria
		if(p1.wfire == 3 || p1.wice == 3 || p1.wwater == 3 || (p1.wfire > 0 && p1.wice > 0 && p1.wwater > 0)){
			printf("\nA batalha acabou, abaixem suas cartas!\n");
			printf("A vitória pertence a %s!\n", p1.name);
			break;
		}
		if(p2.wfire == 3 || p2.wice == 3 || p2.wwater == 3 || (p2.wfire > 0 && p2.wice > 0 && p2.wwater > 0)){
			printf("\nA batalha acabou, abaixem suas cartas!\n");
			printf("A vitória pertence a %s!\n", p2.name);
			break;
		}
	
	}

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
}

void show_hand(Player *p1){

	while(p1->hand->iterador != p1->hand->){

	}

}