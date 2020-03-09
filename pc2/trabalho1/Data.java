package trabalho1;

public class Data {
    protected int dia;
    protected int mes;
    protected long ano;

    public Data(int dia, int mes, long ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public void imprime() {
        System.out.println("Data: " + dia + "/" + mes + "/" + ano);
    }
}