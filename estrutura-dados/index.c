// Tipos de Triângulos => https://www.beecrowd.com.br/judge/pt/problems/view/1045

#include <stdio.h>

int main() {

   // A => MAIOR LADO
   double a, b, c;
   scanf("%lf %lf %lf", &a, &b, &c);

   if (b > a && b > c) {
      double refer = a;
      // B é o maior
      a = b;
      b = refer;
   } else if (c > a && c > b) {
      double refer = a;
      // C é o maior
      a = c;
      c = refer;
   }

   if (a >= (b + c))
      printf("NAO FORMA TRIANGULO\n");
   else {

      double quadA = a * a, quadB = b*b, quadC = c * c;

      if (quadA == (quadB + quadC))
         printf("TRIANGULO RETANGULO\n");
      else if (quadA > (quadB + quadC))
         printf("TRIANGULO OBTUSANGULO\n");
      else if (quadA < (quadB + quadC))
         printf("TRIANGULO ACUTANGULO\n");
      
      if (quadA == quadB && quadB == quadC)
         printf("TRIANGULO EQUILATERO\n");
      else if (quadB == quadC || quadB == quadA || quadA == quadC)
         printf("TRIANGULO ISOSCELES\n");

   }

   return 0;
}