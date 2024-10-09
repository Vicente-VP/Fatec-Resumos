public class ContaCorrente extends Conta implements Tributavel{

    public ContaCorrente(int agencia, int conta, String tipo, double saldo, String titular) {
        super(agencia, conta, tipo, saldo, titular);
    }

    public boolean sacar(double valor){
            valor += 0.20;
            return super.sacar(valor);
    }

    public void depositar(double valor){
        if(valor < 0){
            System.out.println("Não insira valor negativo");
        }else this.saldo += valor;
    }

    @Override
    public double getValorImposto() {
        return this.saldo * 0.01;
    }
}
