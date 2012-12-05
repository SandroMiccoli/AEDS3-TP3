/*
  Trabalho Prático 3 - Memória Virtual

  Implementar um simulador de memória virtual

  Criação: 04/12/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "tad_lista.h"


int main(int argc, char *argv[]){


    TipoLista lista;
    Cria(&lista);

    InserePrimeiro(5,&lista);
    InserePrimeiro(4,&lista);

    Imprime(lista);

    LiberaLista(&lista);

}
