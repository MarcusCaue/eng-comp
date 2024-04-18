#include <stdio.h>
#include "ListaSeqOrd/ListaSeqOrd.h"

int main() {

   // Lista base
   LISTA l;
   criar(&l, 20);
   inserir(&l, 891); inserir(&l, 543); inserir(&l, 10); inserir(&l, 2331); inserir(&l, 9); inserir(&l, 2102); inserir(&l, 278);

   imprimir(&l);
   printf("Tamanho: %d\n\n", tamanho(&l));

   // Inserindo em posições válidas
   inserir_pos(&l, 0, 2);
   inserir_pos(&l, tamanho(&l), 3);
   inserir_pos(&l, 5, 4);
   inserir_pos(&l, 4, 7);

   imprimir(&l);
   printf("Tamanho: %d\n\n", tamanho(&l));

   // Inserindo em posições inválidas
   inserir_pos(&l, -90, 82);
   inserir_pos(&l, tamanho(&l) + 1, 13);

   imprimir(&l);
   printf("Tamanho: %d\n\n", tamanho(&l));

   apagar(&l);

   return 0;
}