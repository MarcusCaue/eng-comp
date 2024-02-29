// Painel de LED => https://judge.beecrowd.com/pt/problems/view/2292

#include <stdio.h>

char alter(char c) {
   return (c == 'X' ? 'O' : 'X');
}

int main() {

   int qCasosTeste;
   scanf("%i", &qCasosTeste);

   for (int i = 0; i < qCasosTeste; i++) {
      char painel[61];
      scanf("%s", painel);

      int alternacias;
      scanf("%i", &alternacias);

      for (int j = 0; j < alternacias; j++) {
         char estadoAnterior = painel[0];
         painel[0] = alter(painel[0]);

         for (int k = 1; painel[k] != '\0'; k++) {
            if (painel[k - 1] == 'X' && estadoAnterior == 'O') {
               estadoAnterior = painel[k];
               painel[k] = alter(painel[k]);
            }
         }
      }

      printf("%s\n", painel);
   }

   return 0;
}