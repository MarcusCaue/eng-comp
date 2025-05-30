import interfaces.CalculadoraInterface;
import adapters.*;

public class Cliente_202321250026 {

  public static void run(CalculadoraInterface calc, String calcName) {
    double somaResult, subResult, multResult, divResult;
    double n1, n2;

    n1 = 10;
    n2 = 10;
    
    somaResult = calc.somar(n1, n2);
    subResult  = calc.subtrair(n1, n2);
    multResult = calc.multiplicar(n1, n2);
    divResult  = calc.dividir(n1, n2);
    
    System.out.printf("soma %.2f utilizando a Calculadora de %s\n", somaResult, calcName);
    System.out.printf("subtração %.2f utilizando a Calculadora de %s\n", subResult, calcName);
    System.out.printf("multiplicação %.2f utilizando a Calculadora de %s\n", multResult, calcName);
    System.out.printf("divisão %.2f utilizando a Calculadora de %s\n", divResult, calcName);
    System.out.println();
  }

  public static void main(String args[]) {

    // Usando a calculadora de 202221250006
    run(new CalcAdapter202221250006(), "202221250006");

    // Usando a calculadora de 202221250012
    run(new CalcAdapter202221250012(), "202221250012");

  }
}

