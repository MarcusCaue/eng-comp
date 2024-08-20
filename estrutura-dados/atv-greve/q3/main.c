#include <stdio.h>
#include "ListaSeqOrd/ListaSeqOrd.h"

void show(LISTA* l) {
   imprimir(l);
   printf("Tamanho: %d\n\n", tamanho(l));
}

int main() {

   // Lista base
   LISTA l;
   criar(&l, 11);
   inserir(&l, 891); inserir(&l, 543); inserir(&l, 10); inserir(&l, 2331); inserir(&l, 9); inserir(&l, 2102); inserir(&l, 278);

   show(&l);

   // Inserindo em posições válidas
   inserirPos(&l, 0, 2); // Início
   inserirPos(&l, tamanho(&l), 3); // Fim
   inserirPos(&l, 5, 4); // Meio

   // Inserindo em posições inválidas
   inserirPos(&l, -90, 82);
   inserirPos(&l, tamanho(&l) + 1, 13);

   show(&l);

   inserirPos(&l, 4, 7);
   inserirPos(&l, 0, 90); // Inserindo com a lista cheia

   show(&l);

   apagar(&l);
   return 0;
}