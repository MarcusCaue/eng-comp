package calculadoras;

import java.util.Arrays;
import java.util.function.DoubleBinaryOperator;

public class Calculadora_202221250002 {

    private static Double binaryOperation(DoubleBinaryOperator reducer, Double neutral,Number ...args){
        return Arrays.stream(args).mapToDouble(Number::doubleValue).reduce(neutral, reducer);
    }

    /**
     Calcula a soma de n números consecultivos
     @param args recebe vários números sequencialmente ou em lista (no caso de listas, o tipo deve ser uma classe wrapper)
     **/
    public static Double sum(Number ...args){
        return binaryOperation(Double::sum,0.0,args);
    }
    /**
     Calcula a multiplicação de n números consecultivos
     @param args recebe vários números sequencialmente ou em lista (no caso de listas, o tipo deve ser uma classe wrapper)
     **/
    public static Double multiply(Number ...args){
        return binaryOperation((val,el)->val*el,1.0,args);
    }

    /**
     Calcula a divisão de n números consecultivos
     @param args recebe vários números sequencialmente ou em lista (no caso de listas, o tipo deve ser uma classe wrapper)
     @throws ArithmeticException quando o index 1 em diante é 0
     **/
    public static Double divide(Number ...args){
        double[] values = Arrays.stream(args)
                .mapToDouble(Number::doubleValue)
                .toArray();
        for (int i  = 1;i<values.length;i++){
            if(values[i]==0.0){
                throw new ArithmeticException("Divisão por zero encontrada, tá maluco é?");
            }
        }
        return binaryOperation((val,el)->val/el,1.0,args);
    }
    /**
     Calcula a subtração de n números consecultivos
     @param args recebe vários números sequencialmente ou em lista (no caso de listas, o tipo deve ser uma classe wrapper)
     **/
    public static Double subtract(Number ...args){
        return binaryOperation((val,el)->val-el,0.0,args);
    }

}
