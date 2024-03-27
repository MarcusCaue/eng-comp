#include "ListaSeq.h"

int main() {

  LISTA l;
  LISTA *pointerList = &l;
  criar(pointerList, 10);

  inserir(pointerList, 98);
  inserir(pointerList, 7);
  inserir(pointerList, 21);
  inserir(pointerList, 51);

  imprimir(pointerList);
  
  inserir_ini(pointerList, 0);
  inserir_ini(pointerList, 1);
  inserir_ini(pointerList, 2);
  inserir_ini(pointerList, 3);

  imprimir(pointerList);

  return 0;
}