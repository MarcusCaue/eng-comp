#include "./ListaEnc/ListaEnc.h"

int main()
{
  Lista l1, l2, merged;
  inicializar(&l1);
  inicializar(&l2);

  // Juntando listas vazias
  printf("Lista mesclada: ");
  merged = juntar_ord(&l1, &l2);
  imprimir(&merged);

  inserir_ord(&l1, 43);
  inserir_ord(&l1, 41);
  inserir_ord(&l1, 40);
  inserir_ord(&l1, 48);
  inserir_ord(&l1, 51);
  inserir_ord(&l1, -43);

  inserir_ord(&l2, 0);
  inserir_ord(&l2, 10);
  inserir_ord(&l2, -5);
  inserir_ord(&l2, -3);
  inserir_ord(&l2, 2);
  inserir_ord(&l2, 3);

  printf("\nLista 1: ");
  imprimir(&l1);
  
  printf("Lista 2: ");
  imprimir(&l2);

  printf("Lista mesclada: ");
  merged = juntar_ord(&l1, &l2);
  imprimir(&merged);

  printf("\n====================== MANIPULANDO AS LISTAS APOS A MESCLA ======================\n");
  inserir_ord(&l1, 89);
  inserir_ord(&l1, 2088);

  inserir_ord(&l2, -12);
  inserir_ord(&l2, -1221);

  inserir_ord(&merged, 33);
  inserir_ord(&merged, 144);

  printf("\nLista 1: ");
  imprimir(&l1);
  
  printf("Lista 2: ");
  imprimir(&l2);

  printf("Lista mesclada: ");
  imprimir(&merged);

  apagar(&l1);
  apagar(&l2);
  apagar(&merged);

  printf("\n====================== LISTAS ESVAZIADAS ======================\n");
  printf("\nLista 1: ");
  imprimir(&l1);
  
  printf("Lista 2: ");
  imprimir(&l2);

  printf("Lista mesclada: ");
  imprimir(&merged);

  return 0;
}
