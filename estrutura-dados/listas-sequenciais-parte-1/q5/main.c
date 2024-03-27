#include <stdio.h>
#include <stdlib.h>
#include "ListaSeqOrd.h"

int main() {

  LISTA l;
  LISTA l2;
  criar(&l, 30);
  criar(&l2, 15);

  imprimir(&l);
  imprimir(&l2);

  printf("\nAdicionando elementos\n\n");
  
  inserir_ord(&l, 10);
  inserir_ord(&l2, -98);
  inserir_ord(&l, 2102);
  inserir_ord(&l2, 413);
  inserir_ord(&l, 21);
  inserir_ord(&l2, 52);
  inserir_ord(&l, -7);

  imprimir(&l);
  imprimir(&l2);
  
  printf("\nTamanho da lista %p: %d", &l, tamanho(&l));
  printf("\nTamanho da lista %p: %d\n", &l2, tamanho(&l2));

  printf("\nElemento em %p na posição '%d' => '%d'\n", &l, 1, obter(&l, 1));
  printf("Elemento '%d' em %p na posição '%d'\n", -98, &l2, buscar(&l2, -98));

  printf("\nRemovendo os elementos '%d' e '%d'(inexistente) de %p\n", 21, 897, &l);
  remover(&l, 21);
  remover(&l, 897);

  printf("Removendo os elementos '%d' e '%d'(inexistente) de %p\n\n", -98, 517, &l2);
  remover(&l2, -98);
  remover(&l2, 517);
  
  imprimir(&l);  
  imprimir(&l2);

  apagar(&l);
  apagar(&l2);
  
  printf("\nListas %p e %p apagadas.\n\n", &l, &l2);
  
  imprimir(&l);
  imprimir(&l2);

  return 0;
}