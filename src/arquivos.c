/*
  Manipulação de arquivos.

  Funções de leitura, escrita e manipulação.

  Criação: 15/09/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

// Funções de leitura

FILE * abreArquivoLeitura(char * arquivo) {
    FILE * ptr_arquivo = NULL;
    if ((ptr_arquivo = fopen(arquivo, "r")) == NULL){
        printf("Erro ao abrir arquivo para leitura.\n");
        exit(1);
    }
    else {
        //printf("Arquivo aberto com sucesso!\n");
        return ptr_arquivo;
    }
}


// Funções de escrita

FILE * abreArquivoEscrita(char * arquivo) {
    FILE * ptr_arquivo = NULL;
    if ((ptr_arquivo = fopen(arquivo, "w")) == NULL){
        printf("Erro ao abrir arquivo para escrita.\n");
        exit(1);
    }
    else {
        //printf("Arquivo aberto com sucesso!\n");
        return ptr_arquivo;
    }
}

void escreverLinha(char * linha, FILE * arquivo){
    fprintf(arquivo, "%s", linha);

}


// Manipulação

// Retorna se é o fim do arquivo ou não
int fimDoArquivo(FILE * arquivo){
    return feof(arquivo);
}

// Retorna se conseguiu ou não fechar o arquivo
int fechaArquivo(FILE * arquivo){
    return fclose(arquivo);
}
