/*
  Trabalho Prático 3 - Memória Virtual

  Implementar um simulador de memória virtual

  Criação: 04/12/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "arquivos.h"

int main(int argc, char *argv[]){


    if (argc == 3){ // Nome do arquivo (argv[0]) mais os dois parâmetros

        char entrada[40] = "entrada/";
        char saida[40] = "saida/";
        int k; // instâncias a serem simuladas
        int tam_mem_fis, tam_pagina, n_acessos; // tamanho (em bytes) da memória física, de cada página e o número n de acessos

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * inp = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);

        fscanf(inp, "%d ", &k); // Lê as k instâncias de problemas

        for (int l=0; l<k; l++){

            fscanf(inp, "%d %d %d\n", &tam_mem_fis, &tam_pagina, &n_acessos);

            printf("DADOS: %d %d %d\n",tam_mem_fis, tam_pagina, n_acessos);

            TipoLista lista;
            Cria(&lista);

            for (int a=0; a<n_acessos; a++){


                InserePrimeiro(5,&lista);
                InserePrimeiro(4,&lista);

            }

            Imprime(lista);

            LiberaLista(&lista);


        }

    }

}
