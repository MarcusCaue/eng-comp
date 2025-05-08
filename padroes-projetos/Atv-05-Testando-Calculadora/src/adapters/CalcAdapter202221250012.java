package adapters;

import interfaces.CalculadoraInterface;
import calculadoras.Calculadora_202221250012;

public class CalcAdapter202221250012 implements CalculadoraInterface {

  public double dividir(double a, double b) { 
    Calculadora_202221250012 calc = new Calculadora_202221250012();
    double result = calc.calcular(a, b, '\\');
    return result;
  }

  public double multiplicar(double a, double b) {
    Calculadora_202221250012 calc = new Calculadora_202221250012();
    double result = calc.calcular(a, b, '*');
    return result;
  }

  public double somar(double a, double b) {
    Calculadora_202221250012 calc = new Calculadora_202221250012();
    double result = calc.calcular(a, b, '+');
    return result;
  }

  public double subtrair(double a, double b) {
    Calculadora_202221250012 calc = new Calculadora_202221250012();
    double result = calc.calcular(a, b, '-');
    return result;
  }
  
}