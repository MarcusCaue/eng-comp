// Menor e Posição => https://judge.beecrowd.com/pt/problems/view/1180

#include <stdio.h>

int main() {

   int tam;
   scanf("%i", &tam);

   int vetor[tam];
   for (int i = 0; i < tam; i++)
      scanf("%i", &vetor[i]);
   
   int menor = vetor[0];
   int pos;
   for (int i = 1; i < tam; i++) {
      if (vetor[i] < menor) {
         menor = vetor[i];
         pos = i;
      }
   }

   printf("Menor valor: %i\nPosicao: %i\n", menor, pos);

   return 0;
}