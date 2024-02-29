// Painel de LED => https://judge.beecrowd.com/pt/problems/view/2292

#include <stdio.h>

int main() {

   int qCasosTeste;
   scanf("%i", &qCasosTeste);

   for (int i = 0; i < qCasosTeste; i++) {
      char painel[61];
      int alternacias;
      scanf("%s ", painel);
      scanf("%i", &alternacias);

      for (int j = 0; j < alternacias; j++) {
         painel[0] = (painel[0] == 'X' ? 'O' : 'X');

         


      }
   }






   return 0;
}