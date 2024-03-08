#include <stdio.h>

int primo(int *num) {
   for (int i = 2; i < *num; i++) {
      if (((*num) % i) == 0) {
         return 0;
      }
   }

   return 1;
}

int main() {
   
   int num;
   printf("Digite um numero inteiro: ");
   scanf("%i", &num);

   if (primo(&num))
      printf("Eh um numero primo\n");
   else
      printf("NAO eh primo\n");

   return 0;
}