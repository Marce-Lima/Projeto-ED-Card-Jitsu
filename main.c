#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

void read_rules();
void show_hand(Hand *hand);

int main(){

	Player player1, player2;
	player_ p1 = &player1;
	player_ p2 = &player2;
	
	p1->id = 1;
	p1->id = 2;
	
	char answer;
	int round_ = 0;

	Card allcards[] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7},
                    {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7},
                    {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}}; // define todas as cartas disponiveis

	//criar player
	init_player(p1, allcards);
	init_player(p2, allcards);

	//add cartas a mão
	for (int i = 0; i < MAX_CARDS; i++)
	{
		InsertCard(p1->hand, p1->pack);
		InsertCard(p2->hand, p2->pack);
	}
	
	//tela inicial
	printf("\n CARD-JITSU \n\n");

	//ler regras
	printf("Ler as regras? (s/n)\n");
	scanf("%c", &answer);
	if(answer == 's'){
		read_rules();
	}else{
		printf("Ah, vejo que você já tem o conhecimento necessário...\n");
		printf("Então mostre do que é capaz!\n\n");
	}

	//jogo em si
	while(1){

		//anunciar round
		round_++;
		printf("\n---->>>< ROUND %d ><<<----\n", round_);

		// tipo 0 = fogo
		// tipo 1 = agua
		// tipo 2 = gelo
		
        turn(p1);
        turn(p2);
        
        check(p1, p2);

		//condicoes de vitoria
		if(win(p1)){
			break;
		}
		if(win(p2)){
			break;
		}
	
	}

	return 0;
}

void turn(player_ p){
    
    int answer_num;
    
    printf("== Vez de p%d ==\n\n", p->id);
	printf("(Não permita que seu adversário veja suas cartas! Pressione 'Enter' para ver suas cartas.)\n");
	show_hand(p->hand);

		//escolha
	scanf("%d", &answer_num);
	p->choice = select_card(answer_num, p->hand, p->pack);
    
    return;
}

void read_rules(){

	printf("---REGRAS---\n\nOlá, pequeno gafanhoto!\n Bem-vindo ao Card-Jitsu, um e-sporte tradicional dos tempo remotos de Club Penguin.\n");
	printf("O jogo consiste em rodadas de batalhas de cartas. Cada jogador terá uma mão com cinco cartas\ne seu pack de cartas para repor a mão ao longo da partida.\n");
	printf("Cada carta possui um elemento (água, fogo, gelo) e um valor (de 1 até 7).\nEm cada rodada os jogadores devem escolher uma cartasem que seu adversário saiba qual foi.\n\n");
	printf("As cartas escolhidas entrarão em disputa ganhando pela regra de prioridade:\n\t1. Elementos diferentes - água vence fogo, fogo vence gelo e gelo vence água(como em pedra, papel e tesoura).\n");
	printf("\t2. Maior valor - caso os elementos das cartas escolhidas sejam iguais, ganhará a carta de maior valor.\n");
	printf("\t3. Caso ambos sejam iguais, é um empate técnico e ninguém obtem vitória na rodada.\nO formato das cartas quando mostradas é '(x) - [elemento | valor]', sendo x o número para escolhê-la.\n");
	printf("Ganha aquele que completar 3 vitórias de um mesmo elemento ou 1 vitória de cada elemento.\n\nAgora, vamos para a prática!\n\n");
}