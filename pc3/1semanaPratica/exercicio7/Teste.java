package exercicio7;

import java.util.Arrays;

public class Teste {
  public static void main(String[] args) {
    try {
      Arrays.asList
      // System.out.println
      (new Auxiliar().getClass().getDeclaredField("pessoa").isAnnotationPresent(AnnotationEndereco.class))// getField("pessoa").getDeclaredAnnotations())
          .forEach((item) -> System.out.println(item));
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
