public abstract class Funcionario {
    private String nome;
    private String cpf;
    private double salario;

    private int senha;
    public void setSenha(int senha){
        this.senha = senha;
    }
    public boolean autentica(int senha){
        if(this.senha == senha){
            return true;
        }else{
            return false;
        }
    }

    public double getBonificacao(){
        return this.salario*0.1;
    }


    public String getNome() {
        return nome;
    }

    public String getCpf() {
        return cpf;
    }

    public double getSalario() {
        return salario;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }
}
