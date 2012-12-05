/*
  Manipulação de arquivos.

  Funções de leitura, escrita e manipulação.

  Criação: 15/09/12
  Autor: Sandro Miccoli

*/

#ifndef ARQUIVOS_H_
#define ARQUIVOS_H_

// Leitura

FILE * abreArquivoLeitura(char * arquivo);

// Escrita

FILE * abreArquivoEscrita(char * arquivo);

void escreverLinha(char * linha, FILE * arquivo);

// Manipulação

int fimDoArquivo(FILE * arquivo);

int fechaArquivo(FILE * arquivo);

#endif /* ARQUIVOS_H_ */
