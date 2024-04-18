#include <stdio.h>
#include "ListaSeqOrd/ListaSeqOrd.h"

int main() {

   // Lista base
   LISTA l;
   criar(&l, 20);
   inserir(&l, 10); inserir(&l, 10); inserir(&l, 10); inserir(&l, 10); inserir(&l, 9); inserir(&l, 2102); inserir(&l, 278);

   // Pegando a quantidade de ocorrências de 10 na lista
   int quant10 = contar(&l, 10);
   // Pegando a quantidade de ocorrências de um elemento ausente na lista
   int quantAusente = contar(&l, 2788);

   imprimir(&l);

   printf("Quantidade de ocorrências de 10: %d\n", quant10);
   printf("Quantidade de ocorrências de 2788: %d\n", quantAusente);
   
   apagar(&l);

   return 0;
}