/*
 *  Tipo Abstrato de Dados de Lista
 *
 *  Contém funções de manipulação (criação, inserção, remoção e liberação de memória), e também de impressão e cópia.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "tad_lista.h"


void Cria(TipoLista *Lista){
    Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Primeiro -> Prox = NULL;
    Lista -> Primeiro -> Anterior = NULL;
    Lista -> Ultimo = Lista -> Primeiro;
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void InserePrimeiro(short int x, TipoLista *Lista){

    Lista -> Primeiro -> Anterior = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Primeiro -> Anterior -> Anterior = NULL;
    Lista -> Primeiro -> Anterior -> Prox = Lista -> Primeiro;
    Lista -> Primeiro = Lista -> Primeiro -> Anterior;

    Lista -> Primeiro -> Prox -> Algarismo = x;

    Lista -> len++;
}

void InsereUltimo(short int x, TipoLista *Lista){
    TipoApontador Aux;
    Aux = Lista -> Ultimo;
    Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;

    Lista -> Ultimo -> Algarismo = x;
    Lista -> Ultimo -> Prox = NULL;
    Lista -> Ultimo -> Anterior = Aux;
    Lista -> len++;
}



void RemovePrimeiro(TipoLista *Lista){

    // Se for o único elemento da lista
    if (Lista -> Primeiro -> Prox == Lista -> Ultimo){
        LiberaLista(Lista);
        Cria(Lista);
        return;
    }
    else{
        TipoApontador Aux;

        Aux = Lista -> Primeiro -> Prox;
        Lista -> Primeiro -> Prox = Aux -> Prox;
        Lista -> Primeiro -> Prox -> Anterior = Aux -> Anterior;
        Lista -> len--;

        free(Aux);
    }
}

void RemoveUltimo(TipoLista *Lista){

    if (Lista -> Primeiro == Lista -> Ultimo){
        Cria(Lista);
        free(Lista -> Primeiro);
        return;
    }

    TipoApontador Aux;

    Aux = Lista -> Ultimo;
    Lista -> Ultimo = Aux -> Anterior;
    Lista -> Ultimo -> Prox = NULL;
    Lista -> len--;

    free(Aux);
}

void LiberaLista(TipoLista *Lista){

    TipoApontador Aux, Aux2;
    Aux = Lista->Primeiro -> Prox;

    while (Aux != NULL){
        Aux2 = Aux;
        Aux = Aux -> Prox;
        free(Aux2);
    }

    free(Lista->Primeiro);

}


void Imprime(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Primeiro -> Prox;

    while (Aux != NULL){
        printf("%d", Aux -> Algarismo);
        Aux = Aux -> Prox;
    }
    //printf(" Tamanho: %d\n", Lista.len);
    printf("\n");

    //free(Aux);
}

void ImprimeReverso(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Ultimo -> Anterior;

    printf("%d", Lista.Ultimo -> Algarismo); // Imprimi a última célsula da lista.

    do{
        printf("%d", Aux -> Algarismo);
        Aux = Aux -> Anterior;
    }while (Aux -> Anterior != NULL); // Pega o anterior do anterior para não imprimir a célula cabeça.
    printf("\n");

}

void copiaLista(TipoLista *A, TipoLista* B){
    TipoApontador Aux;

    Aux = A -> Primeiro -> Prox;


    while(Aux != NULL){
        InsereUltimo(Aux -> Algarismo, B);
        Aux = Aux -> Prox;
    }

}

