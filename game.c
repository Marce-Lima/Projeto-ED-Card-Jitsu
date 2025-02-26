#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

void init_player(player_ pl, Card allcards[]){
    

	pl->hand->sentinel = (Node*)malloc(sizeof(Node)); // cria baralho do jogador e a sentinela
    pl->hand->sentinel->next = NULL;
    pl->hand->sentinel->prev = NULL;
	
	init_Pack(pl->pack);
	
	for(int i=0; i < MAX_PACK; i++){
		en_Pack(pl->pack, allcards[i]);
	}
	
	embaralhar(pl->pack, MAX_PACK);
	
	for(int i=0; i < MAX_CARDS; i++){
		InsertCard(pl);
	}
}