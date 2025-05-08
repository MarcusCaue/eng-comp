package adapters;

import interfaces.CalculadoraInterface;
import calculadoras.Calculadora_202221250002;
// Os métodos da Calculadora_202221250002 são estáticos, por isso não preciso fazer instânciação

public class CalcAdapter202221250002 implements CalculadoraInterface {

  public double dividir(double a, double b) {    
    double result = Calculadora_202221250002.divide(a, b);
    return result;
  }

  public double multiplicar(double a, double b) {
    double result = Calculadora_202221250002.multiply(a, b);
    return result;
  }

  public double somar(double a, double b) {
    double result = Calculadora_202221250002.sum(a, b);
    return result;
  }

  public double subtrair(double a, double b) {
    double result = Calculadora_202221250002.subtract(a, b);
    return result;
  }
  
}