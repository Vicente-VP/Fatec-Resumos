#ifndef INSERIR_PCT_H
#define INSERIR_PCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pacote {
  int id;
  char cidorigi [50];
  char ciddest [50];
  int status;
  char conteudo [75];
  struct pacote *prox;
};

typedef struct pacote Pacote;


Pacote *cria_pct (void){
  return NULL;
}


Pacote * inserir_pct(Pacote * * lista, int id, char cidorigi [], char ciddest [], char conteudo []){
  Pacote * novo = (Pacote *) malloc(sizeof(Pacote));
  novo -> id = id;
  strcpy(novo->cidorigi, cidorigi);
  strcpy(novo->ciddest, ciddest);
  novo->status = 1;
  strcpy(novo->conteudo, conteudo);
  novo->prox = *lista;
  *lista = novo;
  return 0;
}

#endif