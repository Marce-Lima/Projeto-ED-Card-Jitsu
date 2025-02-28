#include "game.h"
#include <stdlib.h>
#include <stdio.h>

int InsertCard(Hand* hand, pack_ pack){
    
    if(hand->num_cards == 5){
	    printf("Não foi possível inserir a carta (mão cheia)");
		return 0;
    }
    
	//pode adicionar no fim mesmo tanto faz
	Node* novo_no = (Node*)malloc(sizeof(Node));

	novo_no->item = re_Pack(pack);

	if(hand->num_cards == 0){
		hand->sentinel->next = novo_no;
		hand->sentinel->prev = novo_no;
		novo_no->next = hand->sentinel;
		novo_no->prev = hand->sentinel;
		hand->num_cards++;
	}else{
		Node* temp = hand->sentinel->prev;
		novo_no->prev = temp;
		novo_no->next = hand->sentinel;
		hand->sentinel->prev = novo_no;
		temp->next = novo_no;
		hand->num_cards++;
	}
	
	return 1;
	
}

void init_Hand(hand_ h){
    
    h = (hand_)malloc(sizeof(Hand));
    h->sentinel = (node_)malloc(sizeof(Node));
    h->iterador = NULL;
    h->sentinel->next = NULL;
    h->sentinel->prev = NULL;
    h->num_cards = 0;
    
}

int RemoveCard(player_ pl, card_ rem_card){
	//usar iterador
	// if(pl->hand->end == NULL)
	
}