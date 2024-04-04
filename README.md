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

### Structs

### Peculiaridades do C

- strcpy
- `->` vs `.`
- array assignment
- define, include

### Listas ligadas

### Mapas de memória
