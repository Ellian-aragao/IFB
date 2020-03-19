package trabalho2;

public class Funcionario {
    Integer matricula;
    String nome;
    String dataDeNascimento;
    String cargo;

    public Funcionario(Integer matricula, String nome, String dataDeNascimento, String cargo) {
        this.matricula = matricula;
        this.nome = nome;
        this.dataDeNascimento = dataDeNascimento;
        this.cargo = cargo;
    }

    @Override
    public String toString() {
        return ("------Funcionario------\n cargo: " + cargo + "\n data de nascimento: " + dataDeNascimento + "\n matricula: " + matricula + "\n nome: " + nome);
    }
}