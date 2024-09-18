#include "cadastrar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int busca(Produto * *lista, int id) {
  Produto *p;
  for (p = *lista; p != NULL; p = p->prox) {
    if (p->id == id) {
      printf("%s\n", p->nome);
      printf("\n-----------------------\n");
    }
  }
  return 0;
}