public class Calculadora_202321250026 {

  public double somar(double n1, double n2) {
    return n1 + n2;
  }  

  public double subtrair(double n1, double n2) {
    return n1 - n2;
  }  

  public double multiplicar(double n1, double n2) {
    return n1 * n2;
  }  

  public double dividir(double n1, double n2) {
    try {
      double result = n1 / n2;
      return result;
    } catch (ArithmeticException e) {
      System.out.println("Erro no método dividir da classe 'Calculadora_202321250026.java'");
      System.out.printf("Argumentos passados: n1 = %d e n2 = %d\n", n1, n2);
      System.out.printf("Operação na qual a falha ocorreu: n1/n2 -> %d/%d\n", n1, n2);
      System.out.println("Não é possível fazer divisão por zero.");
      System.out.println("Valor retornado: -1.0");
      return -1.0;
    }
  }  
  
}