#ifndef _TADLISTA_H_  /* Prevenção contra múltiplas inclusões */
#define _TADLISTA_H_

/*
 *  Trabalho Prático 0 - AEDS III
 *
 *  Aluno:      Sandro Miccoli
 *  Matrícula:  2009052409
 *
 *  Data de entrega: 29/08/11
 *
 */

#include <stdlib.h>
#include <stdio.h>


typedef int TipoChave;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  short int Algarismo;
  TipoApontador Anterior;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
  int len;
} TipoLista;


void Cria(TipoLista *Lista);

int Vazia(TipoLista Lista);

void InserePrimeiro(short int x, TipoLista *Lista);

void InsereUltimo(short int x, TipoLista *Lista);

void RemovePrimeiro(TipoLista *Lista);

void RemoveUltimo(TipoLista *Lista);

void LiberaLista(TipoLista *Lista);

void Imprime(TipoLista Lista);

void ImprimeReverso(TipoLista Lista);

void copiaLista(TipoLista *A, TipoLista* B);

#endif /* _TADLISTA_H_ */
