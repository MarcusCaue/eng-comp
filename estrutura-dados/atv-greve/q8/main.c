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

   printf("================= ESTADO ATUAL DA LISTA =================\n");
   show(&l);

   // Inserindo elementos
   inserir_v2(&l, 21); inserir_v2(&l, 19); 
   inserirPos_v2(&l, 2, 231); inserirPos_v2(&l, 10, 55);
   inserirOrd_v2(&l, 81); inserirOrd_v2(&l, 25);

   printf("================= APÓS INSERIR ELEMENTOS =================\n");
   show(&l);

   // Copiando elementos
   LISTA newList;
   criar(&newList, 2);

   copiar_v2(&newList, &l);

   printf("================= APÓS COPIAR L EM NEWLIST =================\n");
   show(&l);
   printf("\n");
   show(&newList);

   // Estendendo as listas
   estender_v2(&l, &newList);

   printf("================= ESTENDENDO L COM NEWLIST =================\n");
   show(&l);

   // Inserindo na primeira o inverso da segunda
   inverter_v2(&l, &newList);

   printf("================= INSERINDO NEWLIST' EM L =================\n");
   show(&l);
   printf("\n");
   show(&newList);

   apagar(&l);
   apagar(&newList);

   return 0;
}