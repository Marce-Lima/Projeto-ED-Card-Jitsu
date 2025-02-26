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
		printf("Ah, vejo que você já tem o conhecimento necessário...");
		printf("\nEntão mostre do que é capaz!");
	}

	printf("Insira o nome do(a) player 1: ");
	scanf("%[^\n]s", p1.name);

	printf("\nInsira o nome do(a) player 2: ");
	scanf("%[^\n]s", p2.name);

	

	return 0;
}

void read_rules(){
	printf("Olá, pequeno gafanhoto!\n
		Bem-vindo ao Card-Jitsu, um e-sporte tradicional dos tempo remotos de Club Penguin.\n");
};