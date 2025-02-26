#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"

#define MAX_NAME 20
#define MAX_CARDS 5
#define MAX_PACK 21

typedef struct{
    int type;
    int number;
  } Card;
   
typedef Card* card_;

Card allcards[] = {(0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7),
                    (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7),
                    (2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (2, 6), (2, 7)}; // define todas as cartas disponiveis

typedef struct{
    int wfire, wice, wwater; // tem q ter um tipo de vitoria diferente pra cada elemento
    char name[MAX_NAME];
    Pack pack[MAX_PACK];
    Hand* hand;
} Player;
  
typedef Player* player_;

void init_player(player_ pl, Card allcards);

#endif 