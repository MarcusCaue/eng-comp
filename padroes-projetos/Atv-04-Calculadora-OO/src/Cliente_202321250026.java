public class Cliente_202321250026 {
  public static void main(String args[]) {
    
    Calculadora_202321250026 calc = new Calculadora_202321250026();
  
    double n1 = 0;
    double n2 = 90;

    // System.out.println(90 / 0);
    System.out.println(n1 / n2);

    System.out.println("========== Chamadas à função somar() ==========");
    System.out.printf("Resultado da soma: %.2f\n", calc.somar(23.45, 10.98));
    System.out.printf("Resultado da soma: %.2f\n", calc.somar(10.87, -43.56));
    System.out.printf("Resultado da soma: %.2f\n", calc.somar(-7.44, 86));
    System.out.printf("Resultado da soma: %.2f\n", calc.somar(-5, -5));
    System.out.printf("Resultado da soma: %.2f\n", calc.somar(0, 0));
    System.out.printf("Resultado da soma: %.2f\n", calc.somar(89, 0));
    System.out.printf("Resultado da soma: %.2f\n", calc.somar(0, 67));
    System.out.printf("Resultado da soma: %.2f\n\n", calc.somar(0, -76));

    System.out.println("========== Chamadas à função subtrair() ==========");
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(5, 7));
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(215, 5));
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(7, -2));
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(-8, 10));
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(-5, -5));
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(0, 0));
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(89, 0));
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(0, 67));
    System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(-90, 0));
    System.out.printf("Resultado da subtração: %.2f\n\n", calc.subtrair(0, -76));

    System.out.println("========== Chamadas à função multiplicar() ==========");
    System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(4, 2));
    System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(5, -5));
    System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(-10, 10));
    System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(-4, -6));
    System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(0, 0));
    System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(89, 0));
    System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(0, 67));
    System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(-90, 0));
    System.out.printf("Resultado da multiplicação: %.2f\n\n", calc.multiplicar(0, -76));

    System.out.println("========== Chamadas à função dividir() ==========");
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(10, 5));
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(3, 4));
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(-2, 4));
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(-8, -2));
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(10, -2));
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(0, 67));
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(0, -76));
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(0, 0)); // Divisão por zero => Indefinição
    System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(89, 0)); // Divisão por zero => Indeterminação
    System.out.printf("Resultado da divisão: %.2f\n\n", calc.dividir(-90, 0)); // Divisão por zero => Indeterminação

  }
}
