#ifndef LISTA_H
#define LISTA_H

#include  "game.h"

typedef struct{
	Card item;
	card_ next, prev;
} Node;

typedef struct{
	Node* start, end;
	Node* iterador;
} Hand;


#endif