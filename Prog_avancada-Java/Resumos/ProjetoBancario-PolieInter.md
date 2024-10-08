<h1 align="center">Resumo Sistema Bancário - Polimorfismo e Interface</h1>

<h3>Oque é Interface?</h3>
Interface é uma classe abstrata com as assinatura de todos os métodos <br/>

**[Dentro da interface não tem nada concreto]**

<h3>Oque é Polimorfismo?</h3>
Capacidade de um objeto assumir diferentes formas, ou seja, uma operação pode ser realizada por diferentes objetos de classes diferentes

**<h3>Agora falando sobre o projeto</h3>**

- **Main**: No classe main são instanciado objetos e demonstrado `todas` as funções realizadas pelo sistema. Testando uma a uma
 
- **Conta**: É uma Classe abstrata com atributos e métodos comuns a outras contas bancárias.
  - **Herança**: As Classes `ContaPoupança` e `ContaCorrente` herdam de `Conta`, logo são subclasses de `Conta`
  - **Polimorfismo**: O `método` abstrato depositar é implementado nas duas classes `ContaPoupança` e `ContaCorrente` de forma diferentes, permitindo que essas classes tenham comportamentos diferentes para depósitos
  - **Abstração**: Por ela ser uma Clsse abstrata ela não pode ser instanciada. Ela define um contrato para as asubclasses, definindo que elas implementem o `método`  depositar.

- **ContaCorrente**: É uma classe que herda de Conta e implementa de Tributável.
  - **Herança**: A classe herdas os métodos e s atributos da classe `Conta`, além disso ela possui comportamentos específicos, como cobrar uma taxa de 0,20 em saques
  - **Interface**: Implementa a classe Tributável(Interface), `obrigando` ela a implementar a classe getValorImposto()
  - **Polimorfismo**: COmo a classe `ContaCorrente` implementa Tributável, ela pode ser usada em qualquer lugar que o contexto exija um `Tributavel`, como no método `CalcularImposto` 

- **ContaPoupança**: É uma classe que herda de `Conta`, mas não implementa `Tributavel`.
  - **Herança**: Ela herda os métodos e atributos de `Conta` e implementa o método `depositar`, adaptando pra sua lógica específica.
  - **Polimorfismo**: O polimorfismo se aplica no método `depositar`, já que ele pode se comportar de maneira diferente em ca uma das classes.

- **CalcularImposto**: Ela é reponsável por calcular a soma dos impostos de objetos que implementam a `Interface` Tributável
  - **Interface**: O método `calcularImposto(Tributavel tributo)` demonstra a utilização de uma interface, já que ele pode receber qualquer objeto que implemente a `Interface` Tributável.
  - **Polimorfismo**: Através do polimorfismo o método `calcularImposto` pode aceitar e trabalhar com diferentes tipos de objetos, desde que eles estejam implementados a interface Tributável.

- **SeguroDeVida**: A classe `SeguroDeVida` implementa a Interface `Tributavel`.
  - **Interface**: A classe implementa obrigatóriamente  o método `getValorImposto` para calcular o valor do imposto fixo de 42 reais
  - **Polimorfismo**: Assim como na classe `ContaCorrente` esta classe pode ser tratada como um `Tributavel`, logo ela pode ser usada no método de `CalcularImposto`.

- **Tributavel**: Essa classe é uma `Interface` que define um método chamado `getValorImposto`
  - **Polimorfismo**: Ele ocorre, pois diferentes classes podem implementar a interface `Tributavel` e fornecer suas próprias  versões do método `getValorImposto`. Esse comportamento permite que o método `Calcular impostos` da classe `CalcularImposto` trabalhae com qualquer onjeto que implemente `Tributavel`, sem se preocuar com o seu tipo.

<h2 align='center'>Resumo dos Conceitos</h2>

1. <h3>Herança: ContaCorrente e ContaPoupnaça herdam da classe Conta, aproveitando seus atributos e métodos</h3>

2. <h3>Interface: A interface Tributavel define um contrato para calculo de impostos que é implementado pelas classes SeguroDeVida e ContaCorrente</h3>

3. <h3>Polimorfismo: Ele é observado pela classe CalcularImposto, que lida com diferentes objetos (como ContaCorrente e SeguroDeVida) que implementam a interface Tributavel</h3>

