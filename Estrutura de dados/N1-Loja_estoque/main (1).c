/*-------------------------------------------------------*/
/*     FATEC-São Caetano do Sul Estrutura de Dados       */
/*             Avaliação N1 - Parte I                    */
/*       Objetivo: Controlar Estoque de produtos         */
/*                                                       */
/*           Autores: Vicente e Vinicius                 */
/*                                        Data:02/04/2024*/
/*-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "cadastrar.h"
#include "buscar.h"
#include "baixa.h"

int main(void) {
  int resp;
  Produto *novo = NULL;
  do{
    printf("1-Incluir produto\n");
    printf("2-Imprimir produtos\n");
    printf("3-Baixa na quantidade do produto\n");
    printf("4-Buscar produto\n");
    printf("5-Sair\n");

    printf("\nR:"); scanf("%d", &resp);

    switch(resp){
      case 1: 
        printf("id do produto:\n");
        int id;
        printf("R:"); scanf("%d", &id);
        printf("nome do produto:\n");
        char name [45];
        printf("R:"); scanf("%s", name);
        printf("quantidade do produto:\n");
        int qtd;
        printf("R:"); scanf("%d", &qtd);
        printf("preço do produto:\n");
        float preco;
        printf("R:"); scanf("%f", &preco);
        insere(&novo,id, name, qtd, preco);
      break;
      case 2: 
        imprime(&novo);
      break;
      case 3: 
        printf("id do produto:\n");
        printf("R:"); scanf("%d", &id);
        printf("quantidade vendida:\n");
        printf("R:"); scanf("%d", &qtd);
        baixa(&novo, id, qtd);
      break;
      case 4: 
        printf("id do produto:\n");
        printf("R:"); scanf("%d", &id);
        busca(&novo, id);
      break;
    }
  }while (resp !=5);

  return 0;
}