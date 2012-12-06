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

            num_paginas = tam_mem_fis / tam_pagina;

            printf("DADOS: %d %d %d NUM_PAGS: %d\n",tam_mem_fis, tam_pagina, n_acessos, num_paginas);

            TipoLista memoria_primaria;
            Cria(&memoria_primaria);
            memoria_primaria.paginas_livres = num_paginas;


            for (int a=0; a<n_acessos; a++){

                fscanf(inp, "%d", &posicao_acessada);

                pagina_atual.pagina = posicao_acessada / tam_pagina;

                FIFO(&memoria_primaria, pagina_atual);

//                printf("%d ",posicao_acessada);
//                printf("%d ",pagina_atual.pagina);
//                printf("MISS: %d\n",memoria_primaria.misses);



            }

            printf("FIFO: %d\n",memoria_primaria.misses);

            Imprime(memoria_primaria);

            LiberaLista(&memoria_primaria);


        }

        fechaArquivo(inp);
        fechaArquivo(out);

    }

}
