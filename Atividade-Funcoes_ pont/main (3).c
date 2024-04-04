/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         VIcente Venancio Pascoal                       */
/*             Objetivo: Desenvolver um programa modular e realizar       */
/*             operações simples para o array abaixo, utilizando          */
/*             ponteiros em C.                                            */
/*             Paradigama: - programação modular com ponteiro             */
/*                                                                        */
/*                                                        Data:14/03/2024 */
/*------------------------------------------------------------------------*/ 

#include <stdio.h>

// motrar as notas em ordem crescente
int ordemNotas(int *array, int len){
  int i, j, aux;
  
  for(i=0;i<5;i++){

    for(j=1+i;j<5; ++j){

      if(array[i] > array[j]){
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
      }
    }
  }



  printf("As notas em ordem crescente são: ");
  
  for(i=0; i<len; i++){
    printf("%d; ", array[i]);
  }

  return 0;
}

// Mostrar a maior nota
int maiorElemento (int *array, int len){
  int i, maior = -1;
  for(i = 0; i<len; i++){
    if(maior < array[i]){
      maior = array[i];
    }
  }

  printf("\nA maior nota é: %d", maior);

  return 0;
}

// somar todas as notas
int SomaNota(int *array, int len){
  int soma = 0, i;

  for(i = 0; i<len; i++){
    soma += array[i];
  }

  printf("\nA soma das notas é: %d", soma);

  return 0;
}

// Multiplicar a nota pelo valor desejado do usuário
int multiplicarNota(int *array, int len, int multi){
  int i;

  for(i=0;i<len;i++){
    array[i] = array[i] * multi;
  }
  
  printf("\nAs notas multiplicadas: ");

  for(i=0;i<len;i++){
    printf("%d ", array[i]);
  }

  return 0;
}

int main(void) {
  int notas[5], i, len = 5, multi;
  

  printf("Digite 5 notas: \n");

  for (i = 0; i < len; i++){
    scanf("%d", &notas[i]);
  }

  printf("Entre com um valor para multiplicar as notas: ");
  scanf("%d", &multi);

  ordemNotas(notas, len);
  maiorElemento(notas, len);
  SomaNota(notas, len);
  multiplicarNota(notas, len, multi);

}