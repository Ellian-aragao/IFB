import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class hashMap_3 {
  public static void main(String[] args) {
    Map<Integer, String> hashmap = new HashMap<>();
    Random random = new Random();
    for (int i = 0; i < 20; i++) {
      String str = "a - " + i;
      hashmap.put(random.nextInt(), str);
    }
    hashmap.forEach((key, value) -> System.out.println(String.format("%d -> %s", key, value)));
  }
}