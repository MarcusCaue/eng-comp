#include <stdio.h>
#include <stdlib.h>
#include "ListaSeqStr.h"

int main() {

  LISTA l;
  LISTA *pointerL = &l;
  criar(pointerL, 10);

  imprimir(pointerL);
  inserir_ord(pointerL, "Jonas de Samos");
  inserir_ord(pointerL, "Amanda de Abdera");
  inserir_ord(pointerL, "Kleito de Esparta");
  inserir_ord(pointerL, "João das Montanhas");
  inserir_ord(pointerL, "Ovidius Romae");
  inserir_ord(pointerL, "Julius Caesar");
  inserir_ord(pointerL, "Phaedrus Romae");
  imprimir(pointerL);
  printf("Tamanho: %d\n", tamanho(pointerL));

  printf("\nObtendo elemento na posição 3: %s\n", obter(pointerL, 3));
  // Caso inválido
  // printf("Obtendo elemento na posição 11: %s\n", obter(pointerL, 11));
  
  printf("\nPosição de elemento '%s': %d\n", "Amanda de Abdera", buscar(pointerL, "Amanda de Abdera"));
  printf("Posição de elemento '%s': %d\n", "Quintus Horatius", buscar(pointerL, "Quintus Horatius"));

  printf("\nRemovendo os elementos:\n\t - '%s'\n\t - '%s'\n\t - '%s'\n\n", "Jonas de Samos", "Ovidius Romae", "Phaedrus Romae");
  remover(pointerL, "Jonas de Samos");
  remover(pointerL, "Ovidius Romae");
  remover(pointerL, "Phaedrus Romae");
  
  imprimir(pointerL);

  apagar(pointerL);
  
  printf("\n");
  imprimir(pointerL);
  
  return 0;
}