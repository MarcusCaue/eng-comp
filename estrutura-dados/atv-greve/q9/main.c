#include <stdio.h>
#include <stdlib.h>
#include "ListaSeqOrd/ListaSeqOrd.h"

void show(LISTA* l) {
   imprimir(l); 
   printf("Tamanho: %d\n", tamanho(l));
   printf("Tamanho máximo: %d\n\n", l->max);
}

int main() {

   // Lista base
   LISTA l;
   criar(&l, 8);
   inserir(&l, 891); inserir(&l, 543); inserir(&l, 10); inserir(&l, 2331); inserir(&l, 9); inserir(&l, 2102); inserir(&l, 278);
   inserir_v2(&l, 21); inserir_v2(&l, 19); 
   inserirPos_v2(&l, 2, 231); inserirPos_v2(&l, 10, 55);
   inserirOrd_v2(&l, 81); inserirOrd_v2(&l, 25);

   printf("================= ESTADO ATUAL DA LISTA =================\n");
   show(&l);

   printf("================= ORDENANDO A LISTA COM SELECTION SORT =================\n");
   ordenar(&l);
   show(&l);

   // Adicionando mais e reordenando
   inserir_v2(&l, 7123); inserir_v2(&l, -321); inserir_v2(&l, -837); inserir_v2(&l, 0); inserir_v2(&l, -483); inserir_v2(&l, -9873); 
   inserirPos_v2(&l, 2, 21); inserirPos_v2(&l, 10, 21);

   printf("================= REORDENANDO A LISTA COM SELECTION SORT =================\n");
   ordenar(&l);
   show(&l);

   apagar(&l);
   return 0;
}
