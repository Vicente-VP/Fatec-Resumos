//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Funcionario g1 = new Gerente();
        g1.setNome("Vicente");
        g1.setCpf("235568413");
        g1.setSalario(5000.0);

        System.out.println(g1.getNome());
        System.out.println(g1.getCpf());
        System.out.println(g1.getSalario());

        g1.setSenha(2222);
        boolean autenticou =  g1.autentica(2222);
        System.out.println(autenticou);

        System.out.println(g1.getBonificacao());

    }
}