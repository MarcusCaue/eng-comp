// C mais ou menos? => https://www.beecrowd.com.br/judge/pt/problems/view/2486

#include <stdio.h>

int len(char string[]) {
   int len = 0;

   for (len; string[len] != '\0'; len++) { }

   return len;
}

int isEquals(char string1[], char string2[])
{
   if (len(string1) != len(string2)) {
      return 0;
   }

   int isEquals = 1;

   for (int i = 0; string1[i] != '\0'; i++)
   {
      char c1 = string1[i], c2 = string2[i];

      if (c1 != c2) {
         isEquals = 0;
         break;
      }
   }

   return isEquals;
}

int quantVitC(char alimento[]) 
{
   if (isEquals(alimento, "suco de laranja")) {
      return 120;
   } else if (isEquals(alimento, "morango fresco") || isEquals(alimento, "mamao")) {
      return 85;
   } else if (isEquals(alimento, "goiaba vermelha")) {
      return 70;
   } else if (isEquals(alimento, "manga")) {
      return 56;
   } else if (isEquals(alimento, "laranja")) {
      return 50;
   } else if (isEquals(alimento, "brocolis")) {
      return 34;
   } else {
      return -1;
   }
}

int main() {

   int alimentosConsumidos;
   scanf("%i", &alimentosConsumidos);

   while (alimentosConsumidos != 0) {

      int quant, vitaminaC = 0; 
      char alimento[16] = {'\0'};

      for (int i = 0; i < alimentosConsumidos; i++)
      {
         scanf("%i", &quant);

         // Remove o character '\n' lá do Buffer
         getchar();
         // Leitura da string contendo o nome do alimento
         scanf("%16[^\n]", alimento);

         vitaminaC += quantVitC(alimento) * quant;
      }

      if (vitaminaC > 130) {
         printf("Menos %i mg\n", (vitaminaC - 130));
      } else if (vitaminaC < 110) {
         printf("Mais %i mg\n", (110 - vitaminaC));
      } else {
         printf("%i mg\n", vitaminaC);
      }

      getchar();
      scanf("%i", &alimentosConsumidos);
   }

   return 0;
}