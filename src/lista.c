/*
 *  Tipo Abstrato de Dados de Lista
 *
 *  Contém funções de manipulação (criação, inserção, remoção e liberação de memória), e também de impressão e cópia.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


void Cria(TipoLista *Lista){
    Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Primeiro -> Prox = NULL;
    Lista -> Primeiro -> Anterior = NULL;
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> paginas_livres=0;
    Lista -> len=0;
    Lista -> misses=0;
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void InserePrimeiro(short int x, TipoLista *Lista){

    Lista -> Primeiro -> Anterior = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Primeiro -> Anterior -> Anterior = NULL;
    Lista -> Primeiro -> Anterior -> Prox = Lista -> Primeiro;
    Lista -> Primeiro = Lista -> Primeiro -> Anterior;

    Lista -> Primeiro -> Prox -> pagina = x;


    Lista -> len++;
    Lista -> paginas_livres--;
}

void InsereUltimo(short int x, TipoLista *Lista){
    TipoApontador Aux;
    Aux = Lista -> Ultimo;
    Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;

    Lista -> Ultimo -> pagina = x;
    Lista -> Ultimo -> Prox = NULL;
    Lista -> Ultimo -> Anterior = Aux;
    Lista -> len++;
    Lista -> paginas_livres--;
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
        Lista -> paginas_livres++;

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
    Lista -> paginas_livres++;

    free(Aux);
}

void Remove(TipoLista *Lista, TipoApontador pagina){

    if ((pagina->Prox == NULL) && (pagina->Anterior == NULL)){
        Lista->Primeiro = NULL;
        Lista->Ultimo = NULL;
    }
    // Se a página for a última
    else if (pagina->Prox == NULL){
        Lista->Ultimo = pagina->Anterior;
        Lista->Ultimo->Prox = NULL;
    }
    // Se a página for a primeira
    else if (pagina->Anterior == NULL) {
        Lista->Primeiro = pagina->Prox;
        Lista->Primeiro->Anterior = NULL;
    }
    else {
        pagina->Anterior->Prox = pagina->Prox;
        pagina->Prox->Anterior = pagina->Anterior;
    }

    Lista->len--;
    Lista->paginas_livres++;

    free(pagina);

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
        printf("%d", Aux -> pagina);
        Aux = Aux -> Prox;
    }
    //printf(" Tamanho: %d\n", Lista.len);
    printf("\n");

    //free(Aux);
}

void ImprimeReverso(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Ultimo -> Anterior;

    printf("%d", Lista.Ultimo -> pagina); // Imprimi a última célsula da lista.

    do{
        printf("%d", Aux -> pagina);
        Aux = Aux -> Anterior;
    }while (Aux -> Anterior != NULL); // Pega o anterior do anterior para não imprimir a célula cabeça.
    printf("\n");

}

void copiaLista(TipoLista *A, TipoLista* B){
    TipoApontador Aux;

    Aux = A -> Primeiro -> Prox;


    while(Aux != NULL){
        InsereUltimo(Aux -> pagina, B);
        Aux = Aux -> Prox;
    }

}

