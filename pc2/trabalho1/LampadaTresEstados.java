package trabalho1;

public class LampadaTresEstados extends Lampada{
    public void setDesligada() {
        this.estado = "Desligada";
    }

    public void setAcesa() {
        this.estado = "Acesa";
    }

    public void setMeiaLuz() {
        this.estado = "Meia-Luz";
    }
}