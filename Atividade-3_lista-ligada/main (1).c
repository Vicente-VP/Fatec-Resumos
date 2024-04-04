#include <stdio.h>
#include <stdlib.h>

struct lista {
  int info;
  struct lista * prox;
};
typedef struct lista Lista;

Lista* lst_cria (void)
{   
   return NULL;
}

Lista * list_insere (Lista * l, int i){
  Lista * novo = (Lista *) malloc(sizeof(Lista));
  novo -> info = i;
  novo -> prox = l;
  return novo;
}

Lista * list_imprime(Lista * l){
  Lista * p;
  for(p = l; p!= NULL; p = p->prox){
    printf("info = %d\n", p->info);
  }
  return 0;
}

int list_vazia(Lista * l){
  if(l == NULL) 
    printf("A lista esta Vazia\n");
  else 
    printf("A lista não esta vazia\n");
  return 0;
}

int list_buscar(Lista * l, int v){
  Lista * p;
  for(p = l; p!= NULL; p = p->prox){
    if(p-> info == v){
      printf("O elemento %d foi encontrado\n", v);
      return 0;
    }else{
      printf("O elemento %d não foi encontrado\n", v);
      return 0;
    }
  }  
  return 0;
}

void list_libera (Lista* l)
{
   int t;
   Lista* p = l;  
      while (p != NULL) {
         Lista* t = p->prox;  
         free(p);                 
         p = t;                    
      }
}

int list_deleta(Lista **l, int v){
  Lista * temp = *l;
  Lista * ant;

  if(temp ==NULL){
    printf("Lista esta vazia");
  }else {
    if (temp->info == v){
      *l = temp-> prox;
      printf("Apagando o numero %d\n", v);
      free(temp);
      return 0;
    }
    while (temp->info !=v){
      ant = temp;
      temp = temp->prox;
      if(temp->info == v){
        ant ->prox = temp -> prox;
        printf("Apagando o numero %d\n", v);
        free(temp);
        return 0;
      }
    }
  }

  return 0;
}


int main(void) {
  Lista * l;
  int r;
  int resposta;
  
  do{
    printf("\nEscolha uma opção:\n");
    printf("0: inserir um elemento\n");
    printf("1: imprimir a lista\n");
    printf("2: deletar um elemento\n");
    printf("3: liberar a lista\n");
    printf("4: verificar se a lista esta vazia\n");
    printf("5: buscar um elemento\n");
    printf("6: Sair\n\n");

    scanf("%d", &r);
    int v;
    switch (r){
      case 0:
        printf("digite um numero: ");
        scanf("%d", &v);
        l = list_insere(l,v);
      break;
      case 1:
        list_imprime(l);
      break;
      case 2:
        printf("digite um numero para deletar: ");
        scanf("%d", &v);
        list_deleta(&l, v);
      break;
      case 3:
        list_libera(l);
      break;
      case 4:
        list_vazia(l);
      break;
      case 5:
        printf("digite um numero para buscar: ");
        scanf("%d", &v);
        list_buscar(l, v);
      break;
      case 6:
        printf("Saindo do sistema");
      break;
    } 
  }
  while (r != 6);
  
}