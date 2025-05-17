public class Calculadora_202221250012
{
    public Calculadora_202221250012(){}

    public Double calcular(Double a, Double b, char operacao)
    {
        switch (operacao) {
            case '+':
                return somar(a, b);
            case '-':
                return subtrair(a, b);
            case '*':
                return multiplicar(a, b);
            case '\\':
                return dividir(a, b);
            default:
                throw new IllegalArgumentException("Operação inválida: " + operacao);
        }
    }

    private Double somar(Double a, Double b) {return a+b;}
    private Double subtrair(Double a, Double b) {return a-b;}
    private Double multiplicar(Double a, Double b) {return a*b;}
    private Double dividir(Double a, Double b) {return a/b;}
    
};

