#ifndef LISTA_H
#define LISTA_H

typedef struct no_
{
    int valor;
    struct no_ next;
    struct no_ prev;
}no;


typedef struct hand_ {

    no* sentinela;
    no* iterador;
    int num_itens;

}hand;

void inicializar_hand();

#endif