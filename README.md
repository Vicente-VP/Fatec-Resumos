# Resumos - Estrutura de Dados

## Bimestre 1

### Tipos _primitivos_ x tipos _compostos_

**Tipos primitivos** são unitários, ou seja, não podem ser divididos em partes menores. Exemplos são `int`, `float`, `char` e `bool`.

**Tipos compostos** possuem atributos que compoem o inteiro. Apesar de ter um único endereço na memória, todas essas partes representam divisões no espaço ocupado. Cada linguagem tem seu método de representar tipos compostos: em C, Go e Rust há `struct`, em Java, C#, C++, Python, JS (quase todas as linguagens, na verdade) há `class`.

Criar uma arquitetura para os tipos compostos é _Estrutura de Dados_. Não basta jogar uma pilha de números na memória e esperar pelo melhor; existem conceitos fundamentais que guiam o desenvolvimento.

### Abstração de dados

Estruturas de dados geralmente são um reflexo do mundo real. Ao descrever uma tabela em BD, por exemplo, quebra-se um objeto em seus componentes essenciais. Estruturas de dados podem, às vezes, representar ideias mais abstratas, possibilitando sua utilização em mais contextos. Pra isso temos dois exemplos:

- Uma **pilha** representa uma lista de dados onde o último a entrar é o primeiro a sair. É possível pensar em uma pilha de pratos, onde é impossível tirar um prato do fundo da pilha; ou então um estacionamento, onde é preciso tirar o carro da frente para sair o de trás. A pilha pode ser referida como uma estrutura **LIFO** (_Last In First Out_) ou **FILO**.
- Uma **fila** pode refletir uma fila de pessoas na vida real, uma lista de espera para um evento, uma fila de execução de um programa, entre outras situações. Muitos se referem a ela como **FIFO** (_First In First Out_) ou **LILO**.

Existem inúmeras estruturas para lidar com diferentes situações.

### Ponteiros

Mover estruturas de dados pela memória pode ser um processo demorado e caro. Imagine, por exemplo, um array que contém dados de 1000000 clientes de uma serviço. Seria ineficiente criar uma cópia dos dados _toda vez_ que fosse passado para uma função. Por isso existem ponteiros.

Um ponteiro carrega o endereço de memória do valor verdadeiro. Em C, cria-se um ponteiro com o prefixo `&`, enquanto `*` é usado para denotar o tipo do ponteiro e desreferenciar o seu valor.

```c
// Função que aceita um ponteiro
void func(int *values[]) {
  for (int i = 0; i < len(values); i++)
    printf("%d ", *values[i]); // Acessando o valor do ponteiro
}

int main(void) {
  int values[] = {1, 2, 3, 4}
  func(&values); // Criando um ponteiro de uma variável
}
```

### Structs

C, assim como qualquer linguagem com tipos estáticos, precisa de um _template_ para criar estruturas de dados. Para isso existe o `struct`. Primeiro declara-se a estrutura e seus atributos, como se fossem variáveis de uma função. Depois, geralmente se declara um tipo com `typedef` ao redor da estrutura.

```c
struct person {
  char *name[50];
  int age;
  char gender;
  person *friends[];
}

typedef struct person Pessoa
```

Geralmente, ao trabalhar com estruturaas, usa-se ponteiros. É comum ter uma função que inicializa uma estrutura, um _pseudo-construtor_. E para inicializar uma estrutura, é **necessário alocar espaço na memória** com a função `malloc`, passando o tamanho desejado. Para acessar um atributo, podemos usar a setinha `->`.

```c
Person *person_init(char *name[50], int age, char gender) {
  Person *new = (Person *)malloc(sizeof(Person));
  new->age = age;
  new->gender = gender;
  strcpy(new->name, name);
  return new;
}
```

Vamos explicar a primeira linha da função:

- Primeiro declaramos a variável `new` com tipo `Person *`. Poderíamos ter dado qualquer nome à variável;
- Depois buscamos espaço na memória com `malloc`. Sabemos qual o tamanho certo com `sizeof(Person)`;
- Antes de atribuir o valor, convertemos para um ponteiro de Person com `(Person *)`. Essa sintaxe é usada para a converter de tipos em C.

### Peculiaridades do C

#### Atribuição de arrays e `strcpy`

É impossível atribuir um valor literal a um array depois que ele foi declarado.

```c
int values[] = {1, 2, 3, 4};
values = {5, 6, 7, 8}; // Gera erro de compilação
```

Um efeito colateral disso é que é impossível atribuir um valor a uma string depois de ser inicializada. No caso de uma estrutura, declaramos a string em malloc. Uma utilidade neste caso é a função `strcpy` (_string copy_):

```c
char* strcpy(char* destino, char* fonte) {
  // mágica (∩｀-´)⊃━☆ﾟ.*･｡ﾟ
}

int main(void) {
  char* fonte = "Somebody once told me the world is gonna roll me\nI ain't the sharpest tool in the shed\nShe was looking kind of dumb with her finger and her thumb\nIn the shape of an \"L\" on her forehead";
  char* copia;
  strcpy(copia, fonte);
}
```

- `->` vs `.`
- define, include

### Listas ligadas

### Mapas de memória
