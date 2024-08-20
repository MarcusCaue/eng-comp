#include <stdio.h>
#include <stdlib.h>
#include "ListaSeqOrd/ListaSeqOrd.h"

void show(LISTA* l) {
   imprimir(l); 
   printf("Tamanho: %d\n", tamanho(l));
   printf("Tamanho máximo: %d\n\n", l->max);
}

void redimensionar(LISTA*, int);

int main() {

   // Lista base
   LISTA l;
   criar(&l, 20);
   inserir(&l, 891); inserir(&l, 543); inserir(&l, 10); inserir(&l, 2331); inserir(&l, 9); inserir(&l, 2102); inserir(&l, 278);

   printf("================= ESTADO ATUAL DA LISTA =================\n");
   show(&l);

   // Redimensionando para mais
   printf("================= REDIMENSIONANDO PARA MAIS =================\n");
   redimensionar(&l, 30);
   show(&l);

   // Redimensionando para menos
   printf("================= REDIMENSIONANDO PARA MENOS =================\n");
   redimensionar(&l, 10);
   show(&l);

   // Redimensionando para uma quantidade menor do que a quantidade de elementos na lista 
   printf("================= REDIMENSIONANDO DE NOVO =================\n");
   redimensionar(&l, 5);
   show(&l);

   apagar(&l);
   return 0;
}