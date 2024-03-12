#include <stdio.h>
#include <stdlib.h>

int somaArray(int arr[], int indexOfLastElement) {
   if (indexOfLastElement <= 0)
      return arr[0];
   else 
      return arr[indexOfLastElement] + somaArray(arr, indexOfLastElement - 1);
}

int main() {
   int len;
   printf("Tamanho do Array: ");
   scanf("%i", &len);

   int *arr = (int *) malloc(sizeof(int) * len);

   printf("Elementos do Array: ");
   for (int i = 0; i < len; i++)
      scanf("%i", &arr[i]);

   int somatorio = somaArray(arr, len - 1);

   printf("A soma de todos os elementos do array resulta em: %i", somatorio);

   return 0;
}