//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        ContaCorrente cc = new ContaCorrente(1, 90, "Corrente", 1000, "Jorge");
        ContaPoupanca cp = new ContaPoupanca(2, 90, "Poupança", 980, "Vicente");

        System.out.println("\nTeste conta Corrente");
        System.out.println("\n----------------------------------------------\n");

        System.out.println(cc.Retorno());

        System.out.println("\n----------------------------------------------\n");
        System.out.println("Sacar:\n");

        cc.sacar(160);
        System.out.println(cc.Retorno());

        System.out.println("\n----------------------------------------------\n");
        System.out.println("Depositar: \n");

        cc.depositar(1800);
        System.out.println(cc.Retorno());

        System.out.println("\n----------------------------------------------\n");
        System.out.println("Tranferir:\n");

        cc.transferir(cp, 20);
        System.out.println(cc.Retorno());

        System.out.println("\n----------------------------------------------\n");

        System.out.println("Teste Conta Poupança");
        System.out.println("\n----------------------------------------------\n");

        System.out.println(cp.Retorno());

        System.out.println("\n----------------------------------------------\n");
        System.out.println("Sacar valor a mais:\n");

        cp.sacar(1100);

        System.out.println("\n----------------------------------------------\n");
        System.out.println("Sacar valor válido\n");

        cp.sacar(100);
        System.out.println(cp.Retorno());

        System.out.println("\n----------------------------------------------\n");
        System.out.println("Depositar:\n");

        cp.depositar(100);
        System.out.println(cp.Retorno());

        System.out.println("\n----------------------------------------------\n");
        System.out.println("Transferir valor a mais\n");

        cp.transferir(cc, 2000);

        System.out.println("\n----------------------------------------------\n");
        System.out.println("Transferir valor válido\n");

        cp.transferir(cc, 100);
        System.out.println(cp.Retorno());

        System.out.println("\n----------------------------------------------\n");


//        criação objeto conta vini
        ContaCorrente contaVini = new ContaCorrente(1, 10, "Corrente", 500, "Vinicius");

        System.out.println("\nInformações contaVini\n");

        System.out.println(contaVini.Retorno());

        System.out.println("\n----------------------------------------------\n");

//        crição objeto seguro
        SeguroDeVida seguro = new SeguroDeVida();

//        criação do objeto calc
        CalcularImposto calc = new CalcularImposto();

        calc.CalculaImposto(contaVini);
        calc.CalculaImposto(seguro);

        System.out.println("O valor de imposto do 1% do SALDO é:" + contaVini.getValorImposto());
        System.out.println("\nO valor de imposto do SEGURO de vida é:" + seguro.getValorImposto() + "\n");

        System.out.println("O valor TOTAL a se pagar no imposta é:" + calc.getTotalImposto());



    }
}