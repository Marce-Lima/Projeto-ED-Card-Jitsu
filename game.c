#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

void init_player(player_ pl, int id){

    //cria a hand e a sentinela
    pl->hand = (hand_)malloc(sizeof(Hand));
    init_Hand(pl->hand);
    
    pl->choice.type = -1;
    pl->choice.number = -1;

    //inicializar vitorias
    pl->wins[0] = 0;
    pl->wins[1] = 0;
    pl->wins[2] = 0;
    
    pl->id = id;
	
    //rand as cartas da fila
	embaralhar(&pl->pack, MAX_PACK);
	
    //coloca as cartas do pack na hand
	for(int i=0; i < MAX_CARDS; i++){
        Card temp = re_Pack(&pl->pack);
		insert_Hand(pl->hand, temp);
	}
    
}

void show_hand(hand_ hand){

	int i = 1;
	hand->iterador = hand->sentinel->next;

	printf("\n\tSuas cartas:\n\n");

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

Card select_card(int answer, hand_ hand, pack_ pack){

	hand->iterador = hand->sentinel;

    for(int i=0; i<answer; i++){
        hand->iterador = hand->iterador->next;
    }

    Card aux = hand->iterador->item;

    hand->iterador->item = re_Pack(pack);
    en_Pack(pack, aux);
    //

	return aux;
}

int win(player_ pl){

	if(pl->wins[0] == 3 || pl->wins[1] == 3 || pl->wins[1] == 3 || (pl->wins[0] > 0 && pl->wins[1] > 0 && pl->wins[2] > 0)){
		printf("\n\nA batalha acabou, abaixem suas cartas!\n\n");
		printf("<<<A vitória pertence ao player %d!>>>\n", pl->id);
		return 1;
	}

	return 0;

}

void check(player_ p1, player_ p2){
    
    Card c1 = p1->choice, c2 = p2->choice;
    
    if(c1.type == c2.type){
        
        printf("Os tipos empataram!\n");
        
        if(c1.number == c2.number) printf("Os números também!\n\nEmpate!\n");
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
    printf("\nPlayer %d ganhou!\n", p->id);
    p->wins[p->choice.type] ++;
}