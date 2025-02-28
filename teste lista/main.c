#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAX_HAND 5

int main()
{
    hand* H = (hand*)malloc(sizeof(hand));
    card a;

    card Cards[] = {{0,1},{0,2},{1,1},{1,2},{2,1}};

    inicializar_hand(H);

    for (int i = 0; i < MAX_HAND; i++)
    {
        Insert(H, Cards[i]);
    }
    
    H->iterador = H->sentinela->next;

    for (int i = 0; i < MAX_HAND; i++)
    {
        a = H->iterador->valor;
        printf("\n[ %d | %d ]\n", a.type, a.number);
        H->iterador = H->iterador->next;
    }
    
    Destruct(H);

    return 0;
}
