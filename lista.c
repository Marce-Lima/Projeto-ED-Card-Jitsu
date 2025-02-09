#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

void init_player(player_ pl, allcards){
	pl->hand->end = NULL;
	pl->hand->start = (Node*)malloc(sizeof(Node)); // cria baralho do jogador
	
	for(int i=0; i < MAX_PACK; i++){
		pl->pack[i] = allcards[i];
	}
	
	embaralhar(pl->pack, MAX_PACK);
	
	for(int i=0; i < MAX_CARDS; i++){
		InsertCard(pl);
	}
}

int InsertCard(player_ pl){
	// if(pl->hand->end == NULL)
	
}

void embaralhar(Card vet[], int vetSize){
	for (int i = 0; i < vetSize; i++){
		int r = rand() % vetSize;
		Card temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
} 