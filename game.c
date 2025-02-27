#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

void init_player(player_ pl, Card allcards[]){
    
    //criar sentinela
	pl->hand->sentinel = (Node*)malloc(sizeof(Node)); // cria baralho do jogador e a sentinela
    pl->hand->sentinel->next = NULL;
    pl->hand->sentinel->prev = NULL;

    //inicializar vitorias
    pl->wfire = 0;
    pl->wwater = 0;
    pl->wice = 0;
	
    //inicializar ponteiros da fila
	init_Pack(pl->pack);
	
    //coloca as cartas pelo fim da fila
	for(int i=0; i < MAX_PACK; i++){
		en_Pack(pl->pack, allcards[i]);
	}
	
    //rand as cartas da fila
	embaralhar(pl->pack, MAX_PACK);
	
    //coloca as cartas do pack na hand
	for(int i=0; i < MAX_CARDS; i++){
		//InsertCard(pl);
	}
}