#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar_hand(hand* h) {
	h->sentinela = (no*)malloc(sizeof(no));
	h->sentinela->next = h->sentinela;
	h->sentinela->prev = h->sentinela;
	h->num_itens = 0;
}

void Insert(hand* h, card valor) {
	no* new_node = (no*)malloc(sizeof(no));
	new_node->valor = valor;

	no* last = h->sentinela->prev;

	// Inserir apC3s o C:ltimo nC3
	last->next = new_node;
	new_node->prev = last;
	new_node->next = h->sentinela;
	h->sentinela->prev = new_node;

	h->num_itens++;
}

void Remove(hand* h, int n) {

	if(vazia(h)) return;
	
	h->iterador = h->sentinela->next;

	for(int i=1; i<n-1; i++) {
		h->iterador = h->iterador->next;
	}

	//card c = h->iterador->valor;
	no* aux = h->iterador;

    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;

	free(aux);
	h->num_itens--;

	return;

}

int vazia(hand* h) {
	return (h->sentinela->prev == h->sentinela && h->sentinela->next == h->sentinela);
}

void Destruct(hand* h){
    no* iterador = h->sentinela->next;
    no* aux;

	while(h->iterador != h->sentinela){
		aux = h->iterador->next;  // Salvar o próximo nó
        free(iterador);              // Liberar o nó atual
        iterador = aux;  
	}
	
	free(h->sentinela);
	free(h);
    return;
}

int cheia(hand* h){
    return (h->num_itens == 5);
}