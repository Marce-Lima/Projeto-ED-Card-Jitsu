#ifndef LISTA_H
#define LISTA_H

typedef struct card_{
    
    int type;
    int number;

}card;

typedef struct no_{

    card valor;
    struct no_* next;
    struct no_* prev;

}no;

typedef struct hand_{

    no* sentinela;
    no* iterador;
    int num_itens;

}hand;

void inicializar_hand(hand* h);
void Insert(hand* h, card card);
void Remove(hand* h, int n);
int vazia(hand* h);
int cheia(hand* h);
void Destruct(hand* h);

#endif