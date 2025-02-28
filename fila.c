#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

void embaralhar(pack_ pack, int vetSize){
	for (int i = 0; i < vetSize; i++){
		int r = rand() % vetSize;
        
		Card temp = pack->card[i];
		pack->card[i] = pack->card[r];
		pack->card[r] = temp;
	}
} 

void init_Pack(pack_ pack, Card allcards[]){
    
    //coloca as cartas pelo fim da fila
	for(int i=0; i < MAX_PACK; i++){
		en_Pack(pack, allcards[i]);
	}
	
	pack->end = -1;
	pack->start = -1;
    
}

void en_Pack(pack_ pack, Card card){
    
    if(full_Pack(pack)){
        printf("Não foi possível incrementar o pack\n");
        return;
    }
    
    if(empty_Pack(pack)){
        pack->end = 0;
        pack->start = 0;
    } else{
        pack->end = (pack->end + 1)%MAX_PACK;
    }
    
    pack->card[pack->end] = card;

    pack->quantidade++;
}

Card re_Pack(pack_ pack){
    
    Card aux = {0,0};
    
    if(empty_Pack(pack)){
        printf("Não foi possível retirar do o pack\n");
        return aux;
    }
    
    if(pack->start == pack->end) { // se for vazia, reinicializa os `ponteiros`
        aux = pack->card[pack->start];
        pack->start = 0;
        pack->end = -1;
    } else{
        aux = pack->card[pack->start];
        pack->start = (pack->start + 1) % MAX_PACK;
    }
    
    pack->quantidade--;
    
    return aux;
}

int full_Pack(pack_ pack){
    if(pack->quantidade > 21){
        pack->quantidade = 21;
    }
    return (pack->quantidade == 21);
}

int empty_Pack(pack_ pack){
    if(pack->quantidade < 1){
        pack->quantidade = 0;
        pack->end = 0;
	    pack->start = 0;
    }
    return (pack->quantidade == 0);
}