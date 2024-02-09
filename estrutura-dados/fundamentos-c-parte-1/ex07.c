// Hora da Corrida => https://www.beecrowd.com.br/judge/pt/problems/view/2968

#include <stdio.h>
#include <math.h>

int main() {

   int voltas, placas;
   scanf("%i %i", &voltas, &placas);

   int totPlacas = placas * voltas;

   short int i;
   double perc;
   int percPlacas;
   for (i = 1; i < 9; i++) {
      perc = i * 0.10f;
      percPlacas = ceil(totPlacas * perc);
      printf("%i ", percPlacas);
   }

   perc = i * 0.10f;
   percPlacas = ceil(totPlacas * perc);
   printf("%i\n", percPlacas);
   
   return 0;
}