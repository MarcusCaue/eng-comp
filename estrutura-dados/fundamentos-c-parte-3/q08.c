#include <stdio.h>

int max(int *n1, int *n2) {
   return (*n1 > *n2) ? *n1 : *n2;
}

int main() {
   int n1, n2;
   printf("Digite dois numeros inteiros: ");
   scanf("%i %i", &n1, &n2);

   int maior = max(&n1, &n2);

   printf("O maior dentre os numeros lidos eh: %i\n", maior);

   return 0;
}