public abstract class Conta {
    private int numeroAgencia;
    private int numeroConta;
    private String tipoConta;
    protected double saldo;
    private String nomeTitular;
    private static int qtdContas;

    public Conta(int agencia, int conta, String tipo, double saldo, String titular){
        this.numeroAgencia = agencia;
        this.numeroConta = conta;
        this.tipoConta = tipo;
        this.saldo = saldo;
        this.nomeTitular = titular;
        Conta.qtdContas +=1;
    }

    public abstract void depositar(double valor);

    public boolean sacar(double valor){
        if(valor > this.saldo){
            System.out.println("Não dá para sacar esta quantida: R$" + valor);
            System.out.println("Você possui: R$" + this.saldo);
            return false;
        }else{
            this.saldo -= valor;
            return true;
        }
    }

    public boolean transferir(Conta conta, double valor){
        if(valor > this.saldo){
            System.out.println("Não dá para transferir esta quantida: R$" + valor);
            System.out.println("Você possui: R$" + this.saldo);
            return false;
        }else{
            this.saldo -= valor;
            conta.depositar(valor);
            return true;
        }
    }

    public String Retorno(){
        return "Agência: " + this.numeroAgencia + "\nConta: " + this.numeroConta + "\nTipo: " + this.tipoConta +
                "\nSaldo: R$" + this.saldo + "\nTitular:" + this.nomeTitular;
    }


}
