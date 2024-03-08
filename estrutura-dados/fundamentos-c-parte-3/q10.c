#include <stdio.h>
#include <stdlib.h>

int somaArray(int array[], int len, int num) {
   int somatorio = 0;
   for (int i = 0; i < len; i++)
      somatorio += ((*(array + i)) * num);
   return somatorio;
}

int main() {
   
   int len;
   printf("Tamanho do array: ");
   scanf("%i", &len);

   int *arr = (int *) malloc(sizeof(int) * len);

   printf("Elementos do array: ");
   for (int i = 0; i < len; i++)
      scanf("%i", (arr + i));
   
   int num;
   printf("Fator multiplicante: ");
   scanf("%i", &num);

   int somatorio = somaArray(arr, len, num);
   printf("O somatorio dos elementos do seu array resultou em '%i'\n", somatorio);

   return 0;
}