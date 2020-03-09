package trabalho1;

public class Professor {
    protected String nome;
    protected String departamento;
    protected Data dataDeAdmissao;
    protected int numeroDeRegistro;

    public Professor(String nome, String departamento, int dia, int mes, long ano, int numeroDeRegistro) {
      this.nome = nome;
      this.departamento = departamento;
      this.dataDeAdmissao = new Data(dia, mes, ano);
      this.numeroDeRegistro = numeroDeRegistro;
    }
}