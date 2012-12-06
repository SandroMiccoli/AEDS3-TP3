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

void ordenaPorAcessos(TipoLista * memoria){
    int min=99999;

    TipoApontador aux;
    aux = memoria->Primeiro -> Prox;

    while (aux != NULL){
        if (aux->num_acessos < min){
            Remove(memoria, aux);
            InserePrimeiro(aux->pagina, memoria);
            min = aux->num_acessos;

        }
        aux = aux -> Prox;
    }

}

void FIFO(TipoLista * memoria, TipoCelula pagina){

    TipoApontador aux;
    aux = resideEmMemoria(memoria, pagina.pagina);

    if (aux == NULL){
        if (memoria->paginas_livres > 0)
            InsereUltimo(pagina.pagina, memoria);
        else{
            RemovePrimeiro(memoria);              // Como estamos usando o método FIFO, então removemos o primeiro da memória.
            InsereUltimo(pagina.pagina, memoria); // E inserimos no final da fila
        }
        memoria->misses++;
    }
}

void LRU(TipoLista * memoria, TipoCelula pagina){

    TipoApontador aux;
    aux = resideEmMemoria(memoria, pagina.pagina);

    if (aux == NULL){
        if (memoria->paginas_livres > 0)
            InsereUltimo(pagina.pagina, memoria);
        else{
            RemovePrimeiro(memoria);              // Como estamos usando o método LRU, então removemos a página acessada a mais tempo (a primeira inserida)
            InsereUltimo(pagina.pagina, memoria); // E inserimos no final da fila
        }
        memoria->misses++;
    }
    // Caso a página tenha sido encontrada, ela é removida da lista e re-inserida no final
    else{
        Remove(memoria, aux);
        InsereUltimo(pagina.pagina, memoria);
    }
}

void LFU(TipoLista * memoria, TipoCelula pagina){

    TipoApontador aux;
    aux = resideEmMemoria(memoria, pagina.pagina);

    if (aux == NULL){
        if (memoria->paginas_livres > 0)
            InsereUltimo(pagina.pagina, memoria);
        else{
            RemovePrimeiro(memoria);              // Como estamos usando o método LRU, então removemos a página acessada a mais tempo (a primeira inserida)
            InsereUltimo(pagina.pagina, memoria); // E inserimos no final da fila
        }
        memoria->misses++;
    }
    else{
        aux->num_acessos++;
        ordenaPorAcessos(memoria);
    }
}
