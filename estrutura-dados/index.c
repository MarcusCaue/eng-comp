// Painel de LED => https://judge.beecrowd.com/pt/problems/view/2292

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

// Converte de Decimal para Binário
char* toBin(int decimal) {
   char *binary = (char *) malloc(sizeof(char) * 61);

   int digits[61] = {0};

   int i = 0;
   do {
      int digit = decimal % 2;
      decimal = decimal / 2;
      digits[i++] = digit;
   } while (decimal >= 2);

   digits[i] = 1;

   int tamReal = i;
   // Invertendo o binário
   for (i; i > -1; i--) {
      binary[tamReal - i] = digits[i] + '0';
   }

   binary[i] = '\0';

   return binary;
}

// Converte de Binário para Decimal
int toDecimal(char num[]) {
   int decimal = 0;
   int len = strlen(num) - 1;

   for (int i = 0; num[i] != '\0'; i++) {
      int digit = num[i] - '0';
      decimal = decimal + (digit == 1 ? digit * pow(2, (len - i)) : 0);
   }

   return decimal;
}

// Converte a representação binária para a representação com 'X' e 'O'
char* toNormalLed(char num[]) {
   int len = strlen(num);

   char *led = (char *) malloc(sizeof(char) * len);

   int i;
   for (i = 0; num[i] != '\0'; i++)
      led[i] = (num[i] == '0' ? 'X' : 'O');

   led[i] = '\0';

   return led;
}

int main() {
   char painel[61] = {'\0'};
   scanf("%s", painel);

   int alternacias;
   scanf("%i", &alternacias);

   char *painelBin = toInvertedBin(painel);
   int decimal = toDecimal(painelBin);

   int novoLedDecimal = decimal + alternacias;

   char *novoLedBin = toBin(novoLedDecimal);
   char *novoLed = toNormalLed(novoLedBin);

   printf("%s\n", novoLed);

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