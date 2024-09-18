/*-------------------------------------------------------*/
/*     FATEC-São Caetano do Sul Estrutura de Dados       */
/*             Atividade Fila Hospital                   */
/*       Objetivo: Simular uma fila de Hospital          */
/*                                                       */
/*           Autores: Vinicius e Vicente                 */
/*                                        Data:13/05/2024*/
/*-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct {
  char nome[50];
  int idade;
  char consulta[150];
  int prioridade; 
} Paciente;

typedef struct Node {
    Paciente paciente;
    struct Node* proximo;
} Node;

typedef struct{
  Node* inic;
  Node* fim;
  int tamanho;
}Fila;

Fila *criarFila() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->tamanho = 0;
  fila->inic = NULL;
  fila->fim = NULL;
  return fila;
}

int filaVazia(Fila *fila) { return fila->tamanho == 0;}

int filaCheia(Fila *fila)
{
  return fila->tamanho == 100;
}

void adicionarPaciente(Fila *fila, Paciente paciente) {
  if (filaCheia(fila)){
    printf("A fila está cheia. Não é possível adicionar mais pacientes.\n");
  } else {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->paciente = paciente;
    novoNode->proximo = NULL;
    if (filaVazia(fila))
    {
      fila->inic = novoNode;
    }
    else{
      fila->fim->proximo = novoNode;
    }
    fila->fim = novoNode;
    fila->tamanho++;
}
}

void removerPaciente(Fila *fila) {
  if (filaVazia(fila)) {
    printf("A fila está vazia. Não há pacientes para remover.\n");
  } else {
    int tempo = 1 + rand() % (15 - 5);
    sleep(tempo);
    printf("________________________________________\n");
    printf("Paciente Atendido: %s\n", fila->inic->paciente.nome);
    printf("Prioridade: %d\n", fila->inic->paciente.prioridade);
    printf("Consulta: %s\n", fila->inic->paciente.consulta);
    printf("A consulta durou %d minutos\n", tempo);
    printf("_________________________________________\n");
    
    Node* temp = fila->inic;
    fila->inic = fila->inic->proximo;
    free(temp);
    fila->tamanho--;
  }
}

void atenderPaciente(Fila *filaNormal, Fila *filaPrioritaria, Fila *filaUrgente)
{
  Paciente paciente;
  
  int atend = paciente.prioridade;
  static int cont = 0;
  
  if(!filaVazia(filaUrgente))
  {
    printf("Paciente Urgente em atendimento!!!!!!!!!!! ;-;\n");
    removerPaciente(filaUrgente);
  }else if(!filaVazia(filaNormal) && cont < 2)
  {
    removerPaciente(filaNormal);
    cont++;
  }
  else if(!filaVazia(filaPrioritaria) || cont == 2)
  {
    removerPaciente(filaPrioritaria);
      cont = 0;
  }
}


void listarPacientes(Fila* filaNormal, Fila* filaPrio, Fila* filaUrgente) {
  char opt;
  printf("Qual Fila deseja ver?");
  printf("N - Normal\n P - Prioritária\n U - Urgente\n");
  scanf("%s", &opt);
  //listar fila Normal
  if(opt == 'N' || opt == 'n')
  {
    Node* primeiro = filaNormal->inic;
    if (filaVazia(filaNormal)) {
      printf("A fila está vazia.\n");
    }
    else{
    printf("Fila Normal:\n");
    for (int i = 0; i < filaNormal->tamanho; i++) {
      printf("Nome: %s\n", filaNormal->inic->paciente.nome);
      printf("Idade: %d\n", filaNormal->inic->paciente.idade);
      printf("Consulta: %s\n", filaNormal->inic->paciente.consulta);
      printf("Prioridade: %d\n", filaNormal->inic->paciente.prioridade);
      filaNormal->inic = filaNormal->inic->proximo;
      printf("--------------------\n");
      }
    }
    filaNormal->inic = primeiro;
  }
  //listar fila Prioritaria
  if(opt == 'P' || opt == 'p')
  {
    Node* primeiro = filaPrio->inic;
    if (filaVazia(filaPrio)) {
      printf("A fila está vazia.\n");
    }
    else{
    printf("Fila Prioritária:\n");
    for (int i = 0; i < filaPrio->tamanho; i++) {
      printf("Nome: %s\n", filaPrio->inic->paciente.nome);
      printf("Idade: %d\n", filaPrio->inic->paciente.idade);
      printf("Consulta: %s\n", filaPrio->inic->paciente.consulta);
      printf("Prioridade: %d\n", filaPrio->inic->paciente.prioridade);
      filaPrio->inic = filaPrio->inic->proximo;
      printf("--------------------\n");
      }
    }
    filaPrio->inic = primeiro;
  }
  //Listar fila Urgente
  if(opt == 'U' || opt == 'u')
  {
    Node* primeiro = filaUrgente->inic;
    if (filaVazia(filaUrgente)) {
      printf("A fila está vazia.\n");
    }
    else{
    printf("Fila Urgente:\n");
    for (int i = 0; i < filaUrgente->tamanho; i++) {
      printf("Nome: %s\n", filaUrgente->inic->paciente.nome);
      printf("Idade: %d\n", filaUrgente->inic->paciente.idade);
      printf("Consulta: %s\n", filaUrgente->inic->paciente.consulta);
      printf("Prioridade: %d\n", filaUrgente->inic->paciente.prioridade);
      filaUrgente->inic = filaUrgente->inic->proximo;
      printf("--------------------\n");
      }
    }
    filaUrgente->inic = primeiro;
  }
  
}

Paciente lerPaciente(){
  Paciente paciente;
  printf("Digite o nome do paciente: ");
  scanf(" %[^\n]s", paciente.nome);
  printf("Digite a idade do paciente: ");
  scanf("%d", &paciente.idade);
  printf("Digite a consulta do paciente: ");
  scanf(" %[^\n]s", paciente.consulta);
  printf("Digite a prioridade do paciente:\n1 - Normal \n2 - Prioritário \n3 - Urgente\n");
  scanf("%d", &paciente.prioridade);
  return paciente;
}
/*void atenderPaciente(Fila *fila)
{
    
}*/
int main(void) {
  int opcao;
  char nome[50];
  int idade, prioridade;
  char consulta[150];
  Fila *filaNormal = criarFila();
  Fila *filaPrio = criarFila();
  Fila *filaUrgente = criarFila();

  
  do {
    printf("1 - Adicionar paciente\n");
    printf("2 - Atender paciente\n");
    printf("3 - Listar pacientes\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:{
      Paciente novoPaciente = lerPaciente();
      
      if(novoPaciente.prioridade == 1)
      {
        adicionarPaciente(filaNormal, novoPaciente);
      } else if(novoPaciente.prioridade == 2){
        adicionarPaciente(filaPrio, novoPaciente);
      }else if(novoPaciente.prioridade == 3){
        adicionarPaciente(filaUrgente, novoPaciente);
      }
      break;
    }
    case 2:
      atenderPaciente(filaNormal, filaPrio, filaUrgente);
      break;
    case 3:
      listarPacientes(filaNormal, filaPrio, filaUrgente);
      break;
    case 4:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
  } while (opcao != 4);
  return 0;
}
