// Painel de LED => https://judge.beecrowd.com/pt/problems/view/2292

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* toInvertedBin(char num[]) {
   int len = strlen(num) - 1;

   char *numInvert = (char *) malloc(sizeof(char) * (len + 1));

   for (int i = 0; num[i] != '\0'; i++) {
      num[i] = (num[i] == 'X' ? '0' : '1');
   }

   for (int i = 0; num[i] != '\0'; i++) {
      numInvert[i] = num[len - i];
   }

   numInvert[len+1] = '\0';

   return numInvert;
}

int main() {
   char painel[61];
   scanf("%s", painel);

   char *painelBin = toInvertedBin(painel);

   int binary = atoi(painelBin);

   // Converter para binário agora
   int novoLed = binary + alternacias;

   printf("%d", novoLed);
   // int qCasosTeste;
   // scanf("%i", &qCasosTeste);

   // long long unsigned alternacias;
   // scanf("%llu", &alternacias);

   // for (int i = 0;i < qCasosTeste; i++) {
   //    char painel[61];
   //    scanf("%s", painel);




   // }



   return 0;
}