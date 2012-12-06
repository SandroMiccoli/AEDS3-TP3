#ifndef _SMV_H_  /* Prevenção contra múltiplas inclusões */
#define _SMV_H_

/*
 *  Simulador de Memória Virtual
 *
 *  Contém funções relativas ao simulador de memória virtual.
 *
 *
 *  Aqui iremos usar a biblioteca de listas duplamente encadeadas (lista.h) para manipular
 *  nossa memória e as páginas.
 *
 *  Cada lista representará nossa memória, e as suas células representarão as páginas.
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

// Função que vasculha a memória primária e verifica se a página se encontra nela
TipoApontador resideEmMemoria(TipoLista * memoria, int pagina);

void fifo(TipoLista * memoria, TipoCelula pagina);


#endif /* _SMV_H_ */
