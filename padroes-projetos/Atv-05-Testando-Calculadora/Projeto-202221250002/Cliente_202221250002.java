package org.acme;
    
public class Cliente_202221250002 {
    public static void main(String[] args) {
        Integer[] array = {1,2,3,4,5};
        // A calculadora qualquer quantiade de números em qualquer formato, em caso de recebimento de arrays
        // deve ser um array de um wrapper dos tipos primitivos e que implementa a interface
        // Number(Ex: Integer, Double)
        System.out.println(Calculadora_202221250002.sum(array));
        System.out.println(Calculadora_202221250002.multiply(1.0, 2, 3, 4, 5));
        System.out.println(Calculadora_202221250002.divide(1.0, 2, 3, 4, 5));
        System.out.println(Calculadora_202221250002.subtract(1.0, 2, 3, 4, 5));
    }
}