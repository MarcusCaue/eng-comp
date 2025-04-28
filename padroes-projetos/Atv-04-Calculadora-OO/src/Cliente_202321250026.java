public class Cliente_202321250026 {

  public static void main(String args[]) {
    
    Calculadora_202321250026 calc = new Calculadora_202321250026();
    
    System.out.println("========== Chamadas à função somar() ==========");
    double[][] sumCaseTests = {
      {23.45, 10.98}, {10.87, -43.56}, {-7.44, 86}, {-5, -5}, 
      {0, 0}, {89, 0}, {0, 67}, {0, -76}
    };
    
    for (int i = 0; i < sumCaseTests.length; i++) {
      System.out.printf("Resultado da soma: %.2f\n", calc.somar(sumCaseTests[i][0], sumCaseTests[i][1]));
    }
    

    System.out.println("\n========== Chamadas à função subtrair() ==========");
    double[][] subCaseTests = {
      {5, 7}, {215, 5}, {7, -2}, {-8, 10}, {-90, 0},
      {-5, -5}, {0, 0}, {89, 0}, {0, 67}, {0, -76}
    };
    
    for (int i = 0; i < subCaseTests.length; i++) {
      System.out.printf("Resultado da subtração: %.2f\n", calc.subtrair(subCaseTests[i][0], subCaseTests[i][1]));
    }


    System.out.println("\n========== Chamadas à função multiplicar() ==========");
    double[][] multCaseTests = {
      {4, 2}, {5, -5}, {-10, 10}, {-4, -6},
      {0, 0}, {89, 0}, {0, 67}, {-90, 0}, {0, -76}
    };

    for (int i = 0; i < multCaseTests.length; i++) {
      System.out.printf("Resultado da multiplicação: %.2f\n", calc.multiplicar(multCaseTests[i][0], multCaseTests[i][1]));
    }

    System.out.println("\n========== Chamadas à função dividir() ==========");
    double[][] divCaseTests = {
      {10, 5}, {3.5, 4}, {-2, 4.1}, {-8, -2},
      {10.21, -2}, {0, 67}, {0, -76}, {0.42, -76},
      {0, 0}, {89, 0}, {-90, 0}
    };

    for (int i = 0; i < divCaseTests.length; i++) {
      System.out.printf("Resultado da divisão: %.2f\n", calc.dividir(divCaseTests[i][0], divCaseTests[i][1]));
    }
    
  }
}
