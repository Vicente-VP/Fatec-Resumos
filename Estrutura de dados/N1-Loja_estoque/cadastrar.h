#ifndef CADASTRAR_H
#define CADASTRAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
  int id;
  char nome[50];
  int qtd;
  float preco;
  struct produto *prox;
};

typedef struct produto Produto;

Produto *cria(void){
  return NULL;
}

Produto * insere (Produto * *lista, int id, char nome [], int qtd, float preco){
  
  Produto * novo = (Produto *) malloc(sizeof(Produto));
  
  novo->id = id;
  strcpy(novo->nome, nome);
  novo->qtd = qtd;
  novo->preco = preco;
  novo->prox = *lista;

  *lista = novo;
  return 0;
}

Produto * imprime(Produto * *lista)
{
  Produto *p;
  for(p = *lista; p != NULL; p = p->prox)
    {
      printf("id: %d\n", p->id);
      printf("nome: %s\n", p->nome);
      printf("quantidade: %d\n", p->qtd);
      printf("preço: %2.2f\n", p->preco);
      printf("-----------------------\n");
    }
  return 0;
}

#endif /* CADASTRAR_H */