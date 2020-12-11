package exercicio7;

import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

@Target(ElementType.FIELD)
public @interface AnnotationEndereco {
  String logradouro();
  String numero() default "S/N";
  String bairro();
  String cidade();
  String estado();
}
