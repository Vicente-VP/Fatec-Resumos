#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inserir_pct.h"

void alterar_sts(Pacote * *lista, int id, int status)
{
  Pacote *tempo = *lista;
  Pacote *ant; 

    if(tempo == NULL)
    {
      printf( "Não há pacote\n");
    }
    else{
      if(tempo->id == id)
      {
       tempo->status = status;
      }
        while(tempo->id != id)
          {
            ant = tempo;
            tempo = tempo->prox;
            if(tempo->id == id)
            {
              tempo->status = status;
            }
          }
    }
}