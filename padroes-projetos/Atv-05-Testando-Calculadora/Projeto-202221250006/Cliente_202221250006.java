public class Cliente_202221250006 {

    public static void main(String[] args) {

        Calculadora_202221250006 calculadora = new Calculadora_202221250006();

        System.out.println("Soma: " + calculadora.soma(1.0, 5.6, 3.4));
        System.out.println("Subtração: " + calculadora.subtracao(10, 10, 2.0));
        System.out.println("Multiplicação: " + calculadora.multiplicacao(5, 55));
        System.out.println("Divisão: " + calculadora.divisao(50, 2.9));

        try {
            System.out.println("Divisão por zero: " + calculadora.divisao(10, 0));
        } catch ( ArithmeticException e) {
            System.out.println(e.getMessage());
        }
    }
}
