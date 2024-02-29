// Acima da Diagonal Principal => https://judge.beecrowd.com/pt/problems/view/1183

#include <stdio.h>

int main() {

   double matriz[4][4];
   char op;

   scanf("%c", op);
   
   for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
         scanf("%lf", &matriz[i][j]);

   double soma = 0;   
   for (int linha = 0; linha < 3; linha++)
      for (int coluna = linha + 1; coluna < 4; coluna++)
         soma += matriz[linha][coluna];

   if (op == 'S')
      printf("%.1f\n", soma);
   else 
      printf("%.1f\n", (soma / 66.0));

   return 0;
}