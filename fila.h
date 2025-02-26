#ifndef GAME_H
#define GAME_H

#include "game.h" 

// tipo 0 = fogo
// tipo 1 = agua
// tipo 2 = gelo
typedef struct{
    Card [21];
}Pack;

void embaralhar(Card vet[], int vetSize);

#endif