// Linha na Matriz => https://judge.beecrowd.com/pt/problems/view/1181

#include <stdio.h>

int main() {

   double matriz[12][12] = {0};

   int linha = 0;
   char operacao = '\0';

   scanf("%i %c", &linha, &operacao);

   for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++)
         scanf("%lf", &matriz[i][j]);
   
   double soma = 0;
   for (int i = 0; i < 12; i++)
      soma += matriz[linha][i];
   
   if (operacao == 'M') {
      double media = soma / 12.0;
      printf("%.1lf\n", media);
   } else {
      printf("%.1lf\n", soma);
   }

   return 0;
}