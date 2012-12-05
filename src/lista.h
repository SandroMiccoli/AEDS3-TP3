#ifndef _TADLISTA_H_  /* Prevenção contra múltiplas inclusões */
#define _TADLISTA_H_

/*
 *  Tipo Abstrato de Dados de Lista
 *
 *  Contém funções de manipulação (criação, inserção, remoção e liberação de memória), e também de impressão e cópia.
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
