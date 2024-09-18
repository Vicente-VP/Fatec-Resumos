#include "inserir_pct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rastrea_pct(Pacote **lista, int id) {
  Pacote *p;

  for (p = *lista; p != NULL; p = p->prox) {
    if (p->id == id)
    {
      printf("Conteudo: %s\n", p->conteudo);
      if (p->status == 1){
        printf("%d - Pacote em processo \n", p->status);
      }else if (p->status == 2){
        printf("%d - Pacote em trânsito \n", p->status);
      }else if (p->status == 3){
        printf("%d - Pacote em espera \n", p->status);
      }else if (p->status == 4){
        printf("%d - Pacote entregue \n", p->status);
      }else if(p->status == 99){
        printf("%d - Pacote extraviado \n", p->status);
      }
      printf("---------------------------\n");
    }
    /*Incluido (Não esta no diagrama)*/
    if(p->id != id)
    {
      printf("Não há pacote com esse id\n");
    }
    /*--------------------------------*/
  }
}