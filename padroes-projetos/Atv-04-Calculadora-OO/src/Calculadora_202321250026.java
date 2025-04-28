public class Calculadora_202321250026 {

  public double somar(double n1, double n2) {
    return n1 + n2;
  }  

  public double subtrair(double n1, double n2) {
    return n1 - n2;
  }  

  public double multiplicar(double n1, double n2) {
    double result = n1 * n2;
    if (result == 0.0) {
      return Math.abs(result);
    }

    return result;
  }  

  public double dividir(double n1, double n2) {
    try {
      double result = n1 / n2;
      if (Double.isNaN(result) || Double.isInfinite(result)) {
        throw new ArithmeticException();
      }

      if (result == 0.0) {
        return Math.abs(result);
      }

      return result;
    } 
    catch (ArithmeticException e) {
      System.out.println("\nErro no método dividir da classe 'Calculadora_202321250026.java'");
      System.out.printf("Argumentos passados: n1 = %f e n2 = %f\n", n1, n2);
      System.out.printf("Operação na qual a falha ocorreu: n1/n2 -> %f/%f\n", n1, n2);
      System.out.println("Não é possível fazer divisão por zero.");
      System.out.println("Valor retornado: -1.0\n");
      return -1.0;
    }
  }  
  
}