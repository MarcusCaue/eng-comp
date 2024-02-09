// Crescimento Populacional => https://www.beecrowd.com.br/judge/pt/problems/view/1160

#include <stdio.h>

int main() {

   short int casosTeste;
   scanf("%hi", &casosTeste);

   for (short int i = 0; i < casosTeste; i++) {
      int popA, popB; double taxaA, taxaB;
      scanf("%i %i %lf %lf", &popA, &popB, &taxaA, &taxaB);

      taxaA /= 100; taxaB /= 100;

      short int anos = 0;
      while (popA <= popB) {
         popA += taxaA * popA;
         popB += taxaB * popB;
         anos++;
         if (anos > 100) {
            break;
         }
      }

      if (anos <= 100) {
         printf("%i anos.\n", anos);
      } else {
         printf("Mais de 1 seculo.\n");
      }
   }

   return 0;
}