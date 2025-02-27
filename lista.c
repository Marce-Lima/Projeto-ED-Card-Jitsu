#include "game.h"
#include <stdlib.h>
#include <stdio.h>

int InsertCard(Hand* hand, pack_ pack){
	//pode adicionar no fim mesmo tanto faz
	Node* novo_no = (Node*)malloc(sizeof(Node));

	novo_no->item = re_Pack(pack);

	if(hand->sentinel->next == NULL){
		hand->sentinel->next = novo_no;
		hand->sentinel->prev = novo_no;
		novo_no->next = hand->sentinel;
		novo_no->prev = hand->sentinel;
	}else if(hand->num_cards == 5){
		printf();
	}else{
		Node* temp = hand->sentinel->prev;
		novo_no->prev = temp;
		novo_no->next = hand->sentinel;
		hand->sentinel->prev = novo_no;
		temp->next = novo_no;
	}
	
}

int RemoveCard(player_ pl, card_ rem_card){
	//usar iterador
	// if(pl->hand->end == NULL)
	
}