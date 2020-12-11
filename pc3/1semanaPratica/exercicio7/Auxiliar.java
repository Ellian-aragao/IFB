package exercicio7;

import exercicio6.Pessoa;

public class Auxiliar {
  
  @AnnotationEndereco(bairro = "M Norte", cidade = "Brasília", logradouro = "Ceilândia", estado = "Distrito Federal")
  public Pessoa pessoa = new Pessoa("robertinho", 18, "999.999.999-99", "1.234.567");

}
