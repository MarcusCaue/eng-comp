#include <stdio.h>
#include "ListaSeqOrd/ListaSeqOrd.h"

void show(LISTA* l) {
   imprimir(l);
   printf("Tamanho: %d\n\n", tamanho(l));
}

int main() {

   // Lista base
   LISTA l;
   criar(&l, 20);
   inserir(&l, 891); inserir(&l, 543); inserir(&l, 10); inserir(&l, 2331); inserir(&l, 9); inserir(&l, 2102); inserir(&l, 278);

   // Segunda lista
   LISTA l2;
   criar(&l2, 20);

   // Fazendo a cópia
   copiar(&l2, &l);

   show(&l); // Lista 1
   show(&l2); // Lista 2
   
   // Fazendo modificações para mostrar que ambas não estão conectadas
   inserir(&l2, 11);
   inserir(&l2, 23);
   inserir(&l2, 91);

   inserirPos(&l, 0, 87);
   inserirPos(&l, 0, 214);
   inserirPos(&l, 0, 511);

   show(&l); // Lista 1
   show(&l2); // Lista 2

   apagar(&l);
   apagar(&l2);
   
   return 0;
}