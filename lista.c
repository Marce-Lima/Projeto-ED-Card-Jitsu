#include "game.h"
#include <stdlib.h>
#include <stdio.h>

void insert_Hand(hand_ h, Card valor){

	if(h->num_cards == 5){
	    printf("Não foi possível inserir a carta (mão cheia)");
		return;
    }

    node_ new_node = (node_)malloc(sizeof(Node));
	
	new_node->item = valor;
	
	node_ last = h->sentinel->prev;

	// Inserir apos o ultimo no
	last->next = new_node;
	new_node->prev = last;
	new_node->next = h->sentinel;
	h->sentinel->prev = new_node;

	h->num_cards++;
}

void init_Hand(hand_ h){

	//alocar a sentinela
	h->sentinel = (node_)malloc(sizeof(Node));
	h->sentinel->next = h->sentinel;
	h->sentinel->prev = h->sentinel;
	h->num_cards = 0;

}

void remove_Hand(hand_ h, int n){

	if(empty_Hand(h)) return;
	
	h->iterador = h->sentinel->next;

	for(int i=1; i<n-1; i++) {
		h->iterador = h->iterador->next;
	}

	//card c = h->iterador->valor;
	node_ aux = h->iterador;

    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;

	free(aux);
	h->num_cards--;

	return;

}

void destruct_Hand(hand_ h){
    node_ iterador = h->sentinel->next;
    node_ aux;

	while(h->iterador != h->sentinel){
		aux = h->iterador->next;  // Salvar o próximo nó
        free(iterador);             // Liberar o nó atual
        iterador = aux;  
	}
	
	free(h->sentinel);
	free(h);
    return;
}

int full_Hand(hand_ h){
    return (h->num_cards == 5);
}

int empty_Hand(hand_ h){
	return (h->sentinel->prev == h->sentinel && h->sentinel->next == h->sentinel);
}