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

   // Lista que vai ser usada para estender 'l'
   LISTA l2;
   criar(&l2, 20);
   inserir(&l2, 2); inserir(&l2, 21); inserir(&l2, 25); inserir(&l2, 22); inserir(&l2, 20); inserir(&l2, 22); inserir(&l2, 28); inserir(&l2, 29); inserir(&l2, 201);

   show(&l); // Lista 1
   show(&l2); // Lista 2

   printf("================= ESTENDENDO L =================\n");
   estender(&l, &l2);

   show(&l); // Lista 1

   // Estendendo de novo
   printf("================= ESTENDENDO L MAIS UMA VEZ =================\n");
   estender(&l, &l2);

   show(&l); // Lista 1

   // Tentando estender mais uma vez
   printf("================= TENTANDO ESTENDER L OUTRA VEZ =================\n");
   estender(&l, &l2);

   show(&l); // Lista 1

   apagar(&l);
   apagar(&l2);

   return 0;
}