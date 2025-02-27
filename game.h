#ifndef GAME_H
#define GAME_H

#define MAX_NAME 20
#define MAX_CARDS 5
#define MAX_PACK 21

typedef struct{
    int type;
    int number;
  } Card;
   
typedef Card* card_;

// tipo 0 = fogo
// tipo 1 = agua
// tipo 2 = gelo

//lista (hand)
typedef struct{
	Card item;
	card_ next, prev;
} Node;

typedef struct{
	Node* sentinel;
	Node* iterador;
} Hand;

//fila estatica (pack)
typedef struct{
    Card card[21];
    int end, start;
}Pack;

typedef Pack* pack_;

//player
typedef struct{
    int wfire, wice, wwater; // tem q ter um tipo de vitoria diferente pra cada elemento
    char name[MAX_NAME];
    Pack pack[MAX_PACK];
    Hand* hand;
} Player;

typedef Player* player_;

void embaralhar(Card vet[], int vetSize);
void init_player(player_ pl, Card allcards[]);
int InsertCard(player_ pl);

#endif 