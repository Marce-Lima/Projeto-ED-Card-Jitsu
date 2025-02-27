#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

void init_player(player_ pl, Card allcards[]){
    
    //criar sentinela
	pl->hand->sentinel = (Node*)malloc(sizeof(Node)); // cria baralho do jogador e a sentinela
    pl->hand->sentinel->next = NULL;
    pl->hand->sentinel->prev = NULL;
    pl->hand->num_cards = 0;

    //inicializar vitorias
    pl->wins[0] = 0;
    pl->wins[1] = 0;
    pl->wins[2] = 0;
	
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
		InsertCard(pl->hand, pl->pack);
	}
}

void show_hand(Hand *hand){

	int i = 1;
	hand->iterador = hand->sentinel->next;

	printf("cartas:\n");

	while(hand->iterador != hand->sentinel){

		Card carta_atual = hand->iterador->item;

		printf("( %d ) - [ ", i);

		if(carta_atual.type == 0)
			printf("fogo |");
		else if(carta_atual.type == 1)
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

Card select_card(int answer, Hand* hand, pack_ pack){

	hand->iterador = hand->sentinel;

    for(int i=0; i<answer; i++){
        hand->iterador = hand->iterador->next;
    }

    node_ aux = hand->iterador;

    hand->iterador->item = re_Pack(pack);
    en_Pack(pack, aux->item);
    //

	return aux->item;
}

int win(player_ pl){

	if(pl->wins[0] == 3 || pl->wins[1] == 3 || pl->wins[1] == 3 || (pl->wins[0] > 0 && pl->wins[1] > 0 && pl->wins[2] > 0)){
		printf("\nA batalha acabou, abaixem suas cartas!\n");
		printf("A vitória pertence ao player %d!\n", pl->id);
		return 1;
	}

	return 0;

}

void check(player_ p1, player_ p2){
    
    Card c1 = p1->choice, c2 = p2->choice;
    
    if(c1.type = c2.type){
        if(c1.number == c2.number) printf("Empate");
        else{
            if(c1.number < c2.number){
                results(p2);
            }
            else{
                results(p1);
            }
        }
    } else{
        if(c2.type == (c1.type + 1)%3){
            results(p2);
        }else{
            results(p1);
        }
    }
}

void results(player_ p){
    printf("player %d ganhou", p->id);
    p->wins[p->choice.type] ++;
}