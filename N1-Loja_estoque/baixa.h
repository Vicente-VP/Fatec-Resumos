#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrar.h"

int baixa(Produto * *lista, int id, int qtd)
{
  Produto *tempo = *lista;
  Produto *ant; 

    if(tempo == NULL)
    {
    printf( "Catálogo vazio\n");
    }
    else{

      if(tempo->id == id)
      {
        tempo->qtd = tempo->qtd - qtd;
        if(tempo->qtd <= 0)
        {
          *lista = tempo->prox;
          free(tempo);
        }
        return 0;
      }
        while(tempo->id != id)
          {
            ant = tempo;
            tempo = tempo->prox;
            if(tempo->id == id)
            {
              tempo->qtd = tempo->qtd - qtd;
              if(tempo->qtd <= 0)
              {
                ant->prox = tempo->prox;
                free(tempo);
              } 
              return 0;
            }
          }
    }
    return 0;
}