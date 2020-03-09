package trabalho1;

public class Lampada {
	protected String estado;
    private String tipo;
    private int potencia;
    private float preco;
	
	public Lampada() {
		this.estado = "Acesa";
	}

    public String getTipo() {
		return tipo;
	}
	public void setTipo(String tipo) {
		this.tipo = tipo;
	}
	public int getPotencia() {
		return potencia;
	}
	public void setPotencia(int potencia) {
		this.potencia = potencia;
	}
	public float getPreco() {
		return preco;
	}
	public void setPreco(float preco) {
		this.preco = preco;
	}
    public boolean estaLigada() {
        if (this.estado.equals("Acesa")) {
            return true;
        }
        return false;
    }
    
}