#include <stdio.h>
#include "ListaSeqOrd/ListaSeqOrd.h"

void show(LISTA* l) {
   imprimir(l);
   printf("Tamanho: %d\n\n", tamanho(l));
}

int main() {

   // Lista base com elementos
   LISTA l;
   criar(&l, 20);
   inserir(&l, 891); inserir(&l, 543); inserir(&l, 10); inserir(&l, 2331); inserir(&l, 9); inserir(&l, 2102); inserir(&l, 278);

   // Lista que vai ser usada para adicionar os elementos em 'l' na ordem inversa
   LISTA l2;
   criar(&l2, 20);
   inserir(&l2, 2); inserir(&l2, 21); inserir(&l2, 25); inserir(&l2, 22); inserir(&l2, 20); inserir(&l2, 22); inserir(&l2, 28); inserir(&l2, 29); inserir(&l2, 201);

   printf("================= ESTADO ATUAL DAS LISTAS =================\n");

   show(&l); // Lista 1
   show(&l2); // Lista 2

   printf("================= ADICIONANDO L2' EM L =================\n");
   inverter(&l, &l2);

   show(&l); // Lista 1
   show(&l2); // Lista 2

   // Resetando L
   apagar(&l);
   criar(&l, 20);

   printf("================= ADICIONANDO L2' EM L RESETADO =================\n");
   inverter(&l, &l2);

   show(&l); // Lista 1
   show(&l2); // Lista 2

   apagar(&l);
   apagar(&l2);
   return 0;
}