// Notas e Moedas => https://www.beecrowd.com.br/judge/pt/problems/view/1021

#include <stdio.h>

int main() {

   float valorTotal;
   scanf("%f", &valorTotal);

   int notas[] = {100, 50, 20, 10, 5, 2};
   
   printf("NOTAS:\n");

   // Verificando com o valor de cada nota
   for (int i = 0; i < 6; i++) 
   {
      int notaEscolhida = notas[i];
      int quantidade = valorTotal / notaEscolhida;
      valorTotal = valorTotal - (quantidade * notaEscolhida);
      printf("%i nota(s) de R$ %i.00\n", quantidade, notaEscolhida);
   }

   float moedas[] = {1.0f, 0.50f, 0.25f, 0.10f, 0.05f, 0.009f};

   printf("MOEDAS:\n");

   // Verificando com o valor de cada moeda
   for (int i = 0; i < 6; i++) 
   {
      float moedaEscolhida = moedas[i];
      int quantidade = valorTotal / moedaEscolhida;
      valorTotal = valorTotal - (quantidade * moedaEscolhida);
      printf("%i moeda(s) de R$ %.2f\n", quantidade, moedaEscolhida);
   }

   return 0;
}