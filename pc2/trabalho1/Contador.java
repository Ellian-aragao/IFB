package trabalho1;

public class Contador {
    private int eventos;
    
    public void incrementa(int incrementador) {
        this.eventos += incrementador;
    }

    public void setZero() {
        this.eventos = 0;
    }

    public void getEventos() {
        System.out.println(eventos);
    }

    
}
        