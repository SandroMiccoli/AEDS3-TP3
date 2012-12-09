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
    TipoApontador pagina_aux1, pagina_aux2, pagina_aux3;

    pagina_aux1 = memoria->Primeiro;
    pagina_aux2 = memoria->Primeiro->Prox;

    while (pagina_aux2 != NULL){
        if (pagina_aux1->num_acessos > pagina_aux2->num_acessos){
            pagina_aux3 = pagina_aux1;
            pagina_aux1 = pagina_aux2;
            pagina_aux2 = pagina_aux3;
        }

        pagina_aux1 = pagina_aux1->Prox;

        pagina_aux2 = pagina_aux2->Prox;
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
            RemovePrimeiro(memoria);              // Como estamos usando o método LFU, então removemos a página que é menos acessada (que nesse caso vai ser sempre a primeira)
            InsereUltimo(pagina.pagina, memoria); // E a inserimos no final da fila
        }
        memoria->misses++;
    }
    else{
        aux->num_acessos++;
        ordenaPorAcessos(memoria);
    }
}
