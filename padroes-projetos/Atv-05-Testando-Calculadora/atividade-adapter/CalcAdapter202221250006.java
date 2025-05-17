public class CalcAdapter202221250006 implements CalculadoraInterface {

  public double dividir(double a, double b) {    
    Calculadora_202221250006 calc = new Calculadora_202221250006();
    double result = calc.divisao(a, b);
    return result;
  }

  public double multiplicar(double a, double b) {
    Calculadora_202221250006 calc = new Calculadora_202221250006();
    double result = calc.multiplicacao(a, b);
    return result;
  }

  public double somar(double a, double b) {
    Calculadora_202221250006 calc = new Calculadora_202221250006();
    double result = calc.soma(a, b);
    return result;
  }

  public double subtrair(double a, double b) {
    Calculadora_202221250006 calc = new Calculadora_202221250006();
    double result = calc.subtracao(a, b);
    return result;
  }
  
}
