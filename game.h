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
typedef struct no{
	Card item;
	struct no *next, *prev;
} Node;

typedef Node* node_;

typedef struct{
	Node* sentinel;
	Node* iterador;
    int num_cards;
} Hand;

typedef Hand* hand_;

//fila estatica (pack)
typedef struct{
    Card card[21];
    int end, start;
}Pack;

typedef Pack* pack_;

//player
typedef struct{
    int wins[3]; // tem q ter um tipo de vitoria diferente pra cada elemento
    //char name[MAX_NAME];
    int id;
    Pack pack[MAX_PACK];
    Hand* hand;
    Card choice;
} Player;

typedef Player* player_;

// funcoes de game
void init_player(player_ pl, Card cards[]);
int InsertCard(hand_ hand, pack_ pack);
void show_hand(hand_ hand);
Card select_card(int answer, hand_ hand, pack_ pack);
int win(player_ pl);
void results(player_ p);
void check(player_ p1, player_ p2);

// funcoes pack
int full_Pack(pack_ pack);
int empty_Pack(pack_ pack);
void init_Pack(pack_ pack);
void en_Pack(pack_ pack, Card card);
Card re_Pack(pack_ pack);
void embaralhar(pack_ pack, int vetSize);

// funcoes main
void turn(player_ p);

#endif 