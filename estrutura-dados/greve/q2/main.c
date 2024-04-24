#include <stdio.h>
#include "ListaSeqOrd/ListaSeqOrd.h"

int main() {

   // Lista base
   LISTA l;
   criar(&l, 20);
   inserir(&l, 891); inserir(&l, 543); inserir(&l, 10); inserir(&l, 2331); inserir(&l, 9); inserir(&l, 2102); inserir(&l, 278);

   imprimir(&l);
   printf("Tamanho: %d\n\n", tamanho(&l));

   // Removendo os últimos três elementos
   for (int i = 0; i < 3; i++)
      pop(&l);
   
   imprimir(&l);
   printf("Tamanho: %d\n\n", tamanho(&l));

   // Removendo o restante
   int len = tamanho(&l);
   for (int i = 0; i < len; i++)
      printf("Removendo o elemento '%d' da lista.\n", pop(&l));

   printf("\n");
   imprimir(&l);
   printf("Tamanho: %d\n\n", tamanho(&l));

   // Tentando remover com a lista vazia
   pop(&l);

   apagar(&l);
   return 0;
}