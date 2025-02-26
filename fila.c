#include "fila.h"

void embaralhar(Card vet[], int vetSize){
	for (int i = 0; i < vetSize; i++){
		int r = rand() % vetSize;
		Card temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
} 