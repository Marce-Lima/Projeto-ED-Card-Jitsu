#ifndef LISTA_H
#define LISTA_H

#define MAX_NAME 20
#define MAX_CARDS 5
#define MAX_PACK 21

typedef struct{
  int type;
  int number;
} Card;
 
typedef Card* card_;

typedef struct{
	Card item;
	card_ next, prev;
} Node;

typedef struct{
	Node* start, end;
	Node* iterador;
} Hand;

typedef struct{
  int wfire, wice, wwater; // tem q ter um tipo de vitoria diferente pra cada elemento
  char name[MAX_NAME];
  Card pack[MAX_PACK];
  Hand* hand;
} Player;

typedef Player* player_;

#endif