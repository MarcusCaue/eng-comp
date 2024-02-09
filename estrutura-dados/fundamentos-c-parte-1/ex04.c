// Tempo de Jogo => https://www.beecrowd.com.br/judge/pt/problems/view/1046

#include <stdio.h>

int main() {

   int inicio, fim;
   scanf("%i %i", &inicio, &fim);

   int duracao;
   // Inicio > Fim => Virou o dia
   if (inicio > fim) {
      duracao = (24 - inicio) + fim;
   } 
   // Inicio < Fim => Terminou no mesmo dia
   else if (inicio < fim) {
      duracao = fim - inicio;
   }
   // Inicio == Fim => Durou o dia inteiro
   else {
      duracao = 24;
   }

   printf("O JOGO DUROU %i HORA(S)\n", duracao);

   return 0;
}