package exercicio6;

import java.util.Arrays;

public class Reflexao {
  public static void mostraAtributosDaClasse(Class classe) {
    Arrays.asList(classe.getDeclaredFields()).forEach((field) -> System.out.println(field));
  }

  public static void mostraMetodosDaClasse(Class classe) {
    Arrays.asList(classe.getMethods()).forEach((field) -> System.out.println(field));
  }
}
