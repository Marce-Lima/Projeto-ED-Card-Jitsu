#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

void init_player(player_ pl, Card allcards[]){
    
	//pl->hand->end = NULL;
	//pl->hand->start = (Node*)malloc(sizeof(Node)); // cria baralho do jogador
	
	init_Pack(pl->pack);
	
	for(int i=0; i < MAX_PACK; i++){
		en_Pack(pl->pack, allcards[i]);
	}
	
	embaralhar(pl->pack, MAX_PACK);
	
	for(int i=0; i < MAX_CARDS; i++){
		InsertCard(pl);
	}
}