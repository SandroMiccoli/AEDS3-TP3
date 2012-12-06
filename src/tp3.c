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
#include "smv.h"

int main(int argc, char *argv[]){


    if (argc == 3){ // Nome do arquivo (argv[0]) mais os dois parâmetros

        char entrada[40] = "entrada/";
        char saida[40] = "saida/";
        int k; // instâncias a serem simuladas
        int tam_mem_fis, tam_pagina, n_acessos; // tamanho (em bytes) da memória física, de cada página e o número n de acessos
        int num_paginas; // Quantas páginas a memória primária terá
        int posicao_acessada;

        TipoCelula pagina_atual;

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * inp = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);

        fscanf(inp, "%d ", &k); // Lê as k instâncias de problemas

        for (int l=0; l<k; l++){

            fscanf(inp, "%d %d %d\n", &tam_mem_fis, &tam_pagina, &n_acessos);

            num_paginas = tam_mem_fis / tam_pagina; // Num de páginas é a razão do tam da memória com o tamanho de cada página

            TipoLista memoria_fifo, memoria_lru, memoria_lfu;
            Cria(&memoria_fifo);
            Cria(&memoria_lru);
            Cria(&memoria_lfu);
            memoria_fifo.paginas_livres = num_paginas;
            memoria_lru.paginas_livres = num_paginas;
            memoria_lfu.paginas_livres = num_paginas;


            for (int a=0; a<n_acessos; a++){

                fscanf(inp, "%d", &posicao_acessada);

                pagina_atual.pagina = posicao_acessada / tam_pagina;

                FIFO(&memoria_fifo, pagina_atual);
                LRU(&memoria_lru, pagina_atual);
                LFU(&memoria_lfu, pagina_atual);
            }

            fprintf(out,"%d ",memoria_fifo.misses);
            fprintf(out,"%d ",memoria_lru.misses);
            fprintf(out,"%d\n",memoria_lfu.misses);

            LiberaLista(&memoria_fifo);
            LiberaLista(&memoria_lru);
            LiberaLista(&memoria_lfu);


        }

        fechaArquivo(inp);
        fechaArquivo(out);

    }

}
