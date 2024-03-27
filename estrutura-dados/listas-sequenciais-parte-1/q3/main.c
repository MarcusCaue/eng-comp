#include <stdio.h>
#include "ListaSeq.h"

int main()
{
  LISTA l;
  LISTA *pointerL = &l;

  criar(pointerL, 10);

  inserirUmaOcorrencia(pointerL, 23);
  inserirUmaOcorrencia(pointerL, 12);
  inserirUmaOcorrencia(pointerL, 23); // Adicionando um elemento já existente
  inserirUmaOcorrencia(pointerL, 23);
  inserirUmaOcorrencia(pointerL, 9);
  inserir(pointerL, 23);
  inserir(pointerL, 23);
  inserir(pointerL, 76);

  imprimir(pointerL);

  remover(pointerL, 23); // Removendo todas as ocorrências de 23

  imprimir(pointerL);
  
  return 0;
}