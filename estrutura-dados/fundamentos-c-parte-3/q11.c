#include <stdio.h>

void reset(int *pointer) {
   *pointer = 0;
}

int main() {
   int num;
   printf("Digite um numero inteiro: ");
   scanf("%i", &num);

   int *pNum = &num;
   reset(pNum);

   printf("Variavel 'num' resetada. Seu valor atual agora eh: %i\n", num);

   return 0;
}