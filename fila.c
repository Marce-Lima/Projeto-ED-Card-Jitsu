#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

void embaralhar(Card vet[], int vetSize){
	for (int i = 0; i < vetSize; i++){
		int r = rand() % vetSize;
        
		Card temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
} 

void init_Pack(pack_ pack){
    pack->end = -1;
    pack->start = -1;
}

void en_Pack(pack_ pack, Card card){
    if(full_Pack(pack)){
        printf("Não foi possível incrementar o pack");
        return;
    }
    
    if(empyt_Pack(pack)){
        pack->end = 0;
        pack->start = 0;
    } else{
        pack->end = (pack->end + 1)%MAX_PACK;
    }
    
    pack->Card[pack->end] = card;
}

void re_Pack(pack_ pack){
    if(empyt_Pack(pack)){
        printf("Não foi possível retirar do o pack");
        return;
    }
    
    if(pack->start == pack->end) { // se for vazia, reinicializa os `ponteiros`
        pack->start = -1;
        pack->end = -1;
    } else{
        pack->start = (pack->start + 1) % MAX_PACK;
    }
}

int full_Pack(pack_ pack){
    return ((pack->end + 1) % MAX_PACK == pack->start);
}

int empty_Pack(pack_ pack){
    return (pack->start == -1);
}