/*
 *  Simulador de Memória Virtual
 *
 *  Contém funções relativas ao simulador de memória virtual.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "smv.h"

TipoApontador resideEmMemoria(TipoLista * memoria, int pagina){

    TipoApontador aux;
    aux = memoria->Primeiro->Prox;

    while (aux != NULL){
        if (aux -> pagina == pagina) return aux;
        aux = aux -> Prox;
    }

    return NULL;

}

void FIFO(TipoLista * memoria, TipoCelula pagina){

    TipoApontador aux;
    aux = resideEmMemoria(memoria, pagina.pagina);


    if (aux == NULL){
        if (memoria->paginas_livres > 0)
            InsereUltimo(pagina.pagina, memoria);
        else{
            RemovePrimeiro(memoria); // Como estamos usando o método FIFO, então removemos o primeiro da memória.
            InsereUltimo(pagina.pagina, memoria); // E inserimos no final da fila
        }
        memoria->misses++;
    }
    else{
    }

}
