public class Calculadora_202221250006 {

    public double soma(Number ... valores) {
        double result = 0.0;
        for (Number valor : valores){
            result += valor.doubleValue();
        }
        return result;
    }
    public double subtracao(Number ... valores) {
        if (valores.length == 0) {
            throw new IllegalArgumentException("Nenhum número fornecido para subtração.");
        }
        double result = valores[0].doubleValue();
        for(int i = 1; i < valores.length; i++){
            result -= valores[i].doubleValue();
        }
        return result;
    }
    public double multiplicacao(Number ... valores) {
        double result = 1.0;
        for (Number valor : valores){
            result *= valor.doubleValue();
        }
        return result;
    }
    public double divisao(Number ... valores) {
        if (valores.length == 0) {
            throw new IllegalArgumentException("Nenhum número fornecido para divisão.");
        }
        double result = valores[0].doubleValue();
        for(int i = 1; i < valores.length; i++){
            double valor = valores[i].doubleValue();
            if (valor == 0) {
                throw new ArithmeticException("Divisão por zero.");
            }
            result /= valor;
        }
        return result;
    }

}
