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

void removeMenosAcessada(TipoLista * memoria){
    int min = 99999;

    TipoApontador menos_acessada;
    TipoApontador aux;

    aux = memoria->Primeiro;

    while (aux != NULL){
        if (aux->num_acessos < min){
            menos_acessada = aux;
            min = menos_acessada->num_acessos;
        }
        else if(aux->num_acessos == min){
                if (aux->pagina < menos_acessada->pagina){
                    menos_acessada = aux;
                }/*
                else if (aux->pagina > menos_acessada->pagina){
                    menos_acessada = aux;
                }*/
        }
        aux = aux -> Prox;
    }

    Remove(memoria, menos_acessada);
}

void ordenaPorAcessos(TipoLista * memoria){
    int min=99999;

    TipoApontador pagina_aux;
    pagina_aux = memoria->Ultimo;

    while (pagina_aux != NULL){
        if (pagina_aux->num_acessos < min){
            Remove(memoria, pagina_aux);
            InserePrimeiro(pagina_aux->pagina, memoria);
            min = pagina_aux->num_acessos;

        }
        else if (pagina_aux->num_acessos == min){
            //printf("PAG ATUAL: %d, PAG ANTERIOR: %d\n",pagina_aux->pagina, pagina_aux->Anterior->pagina);
            if (pagina_aux->pagina < pagina_aux->Anterior->pagina){
                printf("PAGINAAUX ANTES: %d", pagina_aux->pagina);
                Remove(memoria, pagina_aux);
                printf("\tPAGINAAUX DEPOIS: %d\n\n", pagina_aux->pagina);
                InserePrimeiro(pagina_aux->pagina, memoria);
            }
            else if (pagina_aux->pagina > pagina_aux->Anterior->pagina){
                Remove(memoria, pagina_aux->Anterior);
                InserePrimeiro(pagina_aux->Anterior->pagina, memoria);
            }
        }
        pagina_aux = pagina_aux -> Anterior;
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
            removeMenosAcessada(memoria);         // Como estamos usando o método LFU, então removemos a página que é menos acessada
            InsereUltimo(pagina.pagina, memoria); // E inserimos no final da fila
        }
        memoria->misses++;
    }
    else{
        aux->num_acessos++;
        //ordenaPorAcessos(memoria);
    }
}
