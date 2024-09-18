/*-------------------------------------------------------*/
/*     FATEC-São Caetano do Sul Estrutura de Dados       */
/*             Avaliação N1 - Parte II                   */
/*       Objetivo: Controlar Envio de Produtos           */
/*                                                       */
/*           Autores: Vicente e Vinicius                 */
/*                                        Data:12/04/2024*/
/*-------------------------------------------------------*/
#include "inserir_pct.h"
#include "imprime_pct.h"
#include "alterar_sts.h"
#include "rastrear_pct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int id = 0;
  int opt;
  Pacote *novo = NULL;

  do {
    printf("\n1-Incluir pacote\n");
    printf("2-Imprimir pacotes\n");
    printf("3-mudar status do pacote\n");
    printf("4-Buscar pacote\n");
    printf("5-Sair\n");
    printf("Qual opção deseja?\n");
    printf("R:");
    scanf("%d", &opt);

    if(opt == 1){     
      printf("Digite a cidade de origem: \n");
      char cidorigi [50];
      printf("R: "); scanf("%s", cidorigi);
      
      printf("Digite a cidade de destino: \n");
      char ciddest [50];
      printf("R: "); scanf("%s", ciddest);
      
      printf("Digite o conteudo: \n");
      char conteudo [75];
      printf("R: "); scanf("%s", conteudo); 

      id += 2;
      
      inserir_pct(&novo, id, cidorigi, ciddest, conteudo);
    }
    if(opt == 2)
    {
      imprime(novo);
    }
    if(opt == 3)
    {
      printf("Digite o id: \n");
      int id;
      printf("R: "); scanf("%d", &id);
      printf("1-em processo\n");
      printf("2-em trânsito\n");
      printf("3-em espera\n");
      printf("4-entregue\n");
      printf("99-extraviado\n");
      printf("Digite o status: \n");
      int status;
      printf("R: "); scanf("%d", &status);
      alterar_sts(&novo, id, status);
    }
    if (opt == 4)
    {
      printf("Digite o id: \n");
      int id;
      printf("R: "); scanf( "%d", &id);
      rastrea_pct(&novo, id);
      
    }
  } while (opt != 5);
}