#include <stdio.h>

float Adicionar_desc(float * pont_prod, float * pont_desconto){
  float valor_desc = *pont_prod * (*pont_desconto/100);
  float nov_valor = *pont_prod - valor_desc;
  
  printf("Valor do produto: %2.f\n", *pont_prod);
  printf("Valor do desconto: %2.f\n", valor_desc);
  printf("Valor do produto com desconto: %2.f\n", nov_valor);

  return 0;
}

int main() {
  float prod, desconto;

  printf("Entre com o valor do produto: ");
  scanf("%f", &prod);
  printf("Entre com o valor do desconto: ");
  scanf("%f", &desconto);

  Adicionar_desc(&prod, &desconto);

}