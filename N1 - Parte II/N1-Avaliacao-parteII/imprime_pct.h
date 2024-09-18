#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inserir_pct.h"

void imprime(Pacote *lista)
{
  Pacote *aux = lista;
  while (aux != NULL)
    {
      printf("Id: %d\n", aux->id);
      printf("Cidade de origem: %s\n", aux->cidorigi);
      printf("Cidade de destino: %s\n", aux->ciddest);
      /*Incluido (Não esta no diagrama)*/
      if (aux->status == 1){
        printf("%d - Pacote em processo \n", aux->status);
      }else if (aux->status == 2){
        printf("%d - Pacote em trânsito \n", aux->status);
      }else if (aux->status == 3){
        printf("%d - Pacote em espera \n", aux->status);
      }else if (aux->status == 4){
        printf("%d - Pacote entregue \n", aux->status);
      }else if(aux->status == 99){
        printf("%d - Pacote extraviado \n", aux->status);
      }
      /*-----------------------------------------------*/
      printf("Conteudo: %s\n", aux->conteudo);
      printf("------------------------------\n");
      aux = aux->prox;
    }
}