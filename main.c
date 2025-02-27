#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

void read_rules();
void show_hand(Hand *hand);
card_ select_card(/*int answer,*/ player_ pl);

int main(){

	Player p1, p2;
	Hand* hand_temp;
	char answer;
	int answer_num = 0, round = 0;
	card_ choice_p1, choice_p2;
	Card allcards[] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7},
                    {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7},
                    {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}}; // define todas as cartas disponiveis

	//criar player
	init_player(&p1, allcards);
	init_player(&p2, allcards);

	//add cartas a mão
	for (int i = 0; i < MAX_CARDS; i++)
	{
		InsertCard(&p1);
		InsertCard(&p2);
	}
	
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
	while(1){

		//anunciar round
		round++;
		printf("---->>>< ROUND %d ><<<----\n", round);

		// tipo 0 = fogo
		// tipo 1 = agua
		// tipo 2 = gelo

		//anunciar vez do p1
		printf("== Vez de %s ==\n\n", p1.name);
		printf("(Não permita que seu adversário veja suas cartas! Pressione 'Enter' para ver suas cartas.)\n");
		hand_temp = p1.hand;
		show_hand(hand_temp);
		//escolha
		scanf("%d\n", &answer_num);
		choice_p1 = select_card(/*answer,*/ &p1);

		//anunciar vez do p2
		printf("== Vez de %s ==\n\n", p2.name);
		printf("(Não permita que seu adversário veja suas cartas! Pressione 'Enter' para ver suas cartas.)\n");
		hand_temp = p2.hand;
		show_hand(hand_temp);
		//escolha
		scanf("%d\n", &answer_num);
		choice_p2 = select_card(/*answer,*/ &p2);


		if(choice_p1->type == choice_p2->type){//empate de tipo

			if(choice_p1->number == choice_p2 ->number){//empate duplo
				printf("---Cartas iguais---");
				printf("=----= Empate! =----=\n");

			}else{
			if(choice_p1->type == 0){//empate fogo

				printf("\n+++ ambos escolheram fogo +++\n");
				printf("\n--- valor da carta de %s: %d < valor da carta de %s: %d ---\n", p1.name, choice_p1->number, p2.name, choice_p2->number);

				if(choice_p1->number > choice_p2->number){
					printf("=----= %s ganhou a rodada! =----=\n", p1.name);
					p1.wfire++;

				}else if(choice_p1->number < choice_p2->number){
					printf("=----= %s ganhou a rodada! =----=\n", p2.name);
					p2.wfire++;
				}
				
			}else if(choice_p1->type == 1){//empate agua

				printf("\n+++ ambos escolheram agua +++\n");
				printf("\n--- valor da carta de %s: %d > valor da carta de %s: %d ---\n", p1.name, choice_p1->number, p2.name, choice_p2->number);

				if(choice_p1->number > choice_p2->number){
					printf("=----= %s ganhou a rodada! =----=\n", p1.name);
					p1.wwater++;

				}else if(choice_p1->number < choice_p2->number){
					printf("=----= %s ganhou a rodada! =----=\n", p2.name);
					p2.wwater++;
				}

			}else{//ampate gelo

				printf("\n+++ ambos escolheram gelo +++\n");
				printf("\n--- valor da carta de %s: %d > valor da carta de %s: %d ---\n", p1.name, choice_p1->number, p2.name, choice_p2->number);

				if(choice_p1->number > choice_p2->number){
					printf("=----= %s ganhou a rodada! =----=\n", p1.name);
					p1.wice++;
				}else if(choice_p1->number < choice_p2->number){
					printf("=----= %s ganhou a rodada! =----=\n", p2.name);
					p2.wice++;
				}
			}
			}

		}else{
			//comparar elementos
			switch (choice_p1->type)
			{
				case 0://p1 - fogo

					if(choice_p2->type == 1){//p2 - agua

						printf("\n+++ %s escolheu fogo e %s escolheu agua +++\n", p1.name, p2.name);
						printf("=----= %s ganhou a rodada! =----=\n", p2.name);
						p2.wwater++;

					}else{//p2 - gelo

						printf("\n+++ %s escolheu fogo e %s escolheu gelo +++\n", p1.name, p2.name);
						printf("=----= %s ganhou a rodada! =----=\n", p1.name);
						p1.wfire++;
					}
				break;

				case 1://p1 - agua
					if(choice_p2->type == 2){//p2 - gelo
						printf("\n+++ %s escolheu agua e %s escolheu gelo +++\n", p1.name, p2.name);
						printf("=----= %s ganhou a rodada! =----=\n", p2.name);
						p2.wice++;
					}else{//p2 - fogo
						printf("\n+++ %s escolheu agua e %s escolheu fogo +++\n", p1.name, p2.name);
						printf("=----= %s ganhou a rodada! =----=\n", p1.name);
						p1.wwater++;
					}
				break;

				case 2://p1 - gelo

					if(choice_p2->type == 1){//p2 - agua

						printf("\n+++ %s escolheu gelo e %s escolheu agua +++\n", p1.name, p2.name);
						printf("=----= %s ganhou a rodada! =----=\n", p1.name);
						p1.wice++;

					}else{//p2 - fogo

						printf("\n+++ %s escolheu gelo e %s escolheu fogo +++\n", p1.name, p2.name);
						printf("=----= %s ganhou a rodada! =----=\n", p2.name);
						p2.wfire++;
					}

				break;
			}

		}

		//remover a carta da hand e adicionar outra
		//RemoveCard(&p1, choice_p1);
		//RemoveCard(&p2, choice_p2);
		InsertCard(&p1);
		InsertCard(&p2);

		//condicoes de vitoria
		if(p1.wfire == 3 || p1.wice == 3 || p1.wwater == 3 || (p1.wfire > 0 && p1.wice > 0 && p1.wwater > 0)){
			printf("\nA batalha acabou, abaixem suas cartas!\n");
			printf("A vitória pertence a %s!\n", p1.name);
			break;
		}
		if(p2.wfire == 3 || p2.wice == 3 || p2.wwater == 3 || (p2.wfire > 0 && p2.wice > 0 && p2.wwater > 0)){
			printf("\nA batalha acabou, abaixem suas cartas!\n");
			printf("A vitória é de %s!\n", p2.name);
			break;
		}
	
	}

	return 0;
}

void read_rules(){

	printf("---REGRAS---\n\nOlá, pequeno gafanhoto!\n Bem-vindo ao Card-Jitsu, um e-sporte tradicional dos tempo remotos de Club Penguin.\n");
	printf("O jogo consiste em rodadas de batalhas de cartas. Cada jogador terá uma mão com cinco cartas e seu pack de cartas para repor a mão ao longo da partida.\n");
	printf("Cada carta possui um elemento (água, fogo, gelo) e um valor (de 1 até 7).\nEm cada rodada os jogadores devem escolher uma cartasem que seu adversário saiba qual foi.\n\n");
	printf("As cartas escolhidas entrarão em disputa ganhando pela regra de prioridade:\n");
	printf("\t1. Elementos diferentes - água vence fogo, fogo vence gelo e gelo vence água(como em pedra, papel e tesoura).\n");
	printf("\t2. Maior valor - caso os elementos das cartas escolhidas sejam iguais, ganhará a carta de maior valor.\n");
	printf("\t3. Caso ambos sejam iguais, é um empate técnico e ninguém obtem vitória na rodada.\nO formato das cartas quando mostradas é '(x) - [elemento | valor]', sendo x o número para escolhê-la.\n");
	printf("Ganha aquele que completar 3 vitórias de um mesmo elemento ou 1 vitória de cada elemento.\n\nAgora, vamos para a prática!\n\n");
}

void show_hand(Hand *hand){

	int i = 1;
	hand->iterador = hand->sentinel->next;

	printf("cartas:\n");

	while(hand->iterador != hand->sentinel){

		Card carta_atual = hand->iterador->item;

		printf("( %d ) - [ ", i);

		if(carta_atual.number == 0)
			printf("fogo |");
		else if(carta_atual.number == 1)
			printf("água |");
		else
			printf("gelo |");

		printf(" %d ]\t", carta_atual.number);

		Node* no_temp = hand->iterador;
		hand->iterador = no_temp->next;
		i++;
	}

	printf("\n\n Escolha sua carta (1 - 5): ");

}

card_ select_card(/*int answer*/ player_ pl){

	Node* selected_card = pl->hand->sentinel->next;

	return &selected_card->item;
}