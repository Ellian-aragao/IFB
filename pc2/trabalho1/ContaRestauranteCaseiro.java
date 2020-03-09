package trabalho1;

public class ContaRestauranteCaseiro {
    private int numero_usuario = 0;
    private int valor_conta;

    public ContaRestauranteCaseiro() {
        numero_usuario++;
        valor_conta = 0;
    }

    public void compra(float valor){
        this.valor_conta += valor;
    }

    public void mostraConta() {
        System.out.println("numero do usuário: " + this.numero_usuario + " valor da conta: " + this.valor_conta);
    }
}