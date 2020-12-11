import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Arraylist_1_2 {
  public static void main(String[] args) {
    List<String> array = exercicio1();
    exercicio2(array);
  }

  public static List<String> exercicio1() {
    List<String> array = new ArrayList<>(Arrays.asList("vermelho", "verde", "azul", "marrom", "amarelo"));
    array.forEach((cor) -> System.out.println(cor));
    return array;
  }

  public static void exercicio2(List<String> array) {
    array.add(0, "roxo");
    array.remove(2);
    List<String> cpArray = new ArrayList(array);
    Collections.sort(array);
  }
}