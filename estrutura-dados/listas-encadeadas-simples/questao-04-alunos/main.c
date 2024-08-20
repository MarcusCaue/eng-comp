#include "./ListaEnc/ListaEnc.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
  Lista* turmaRomana = (Lista*) malloc(sizeof(Lista));
  inicializar(turmaRomana);
  imprimir(turmaRomana);

  int notas[2] = {9, 10};
  inserir_ord(turmaRomana, "Iulius Caesar", notas);

  notas[0] = 2; notas[1] = 2;
  inserir_ord(turmaRomana, "Fedrus Romae", notas);
  
  notas[0] = 4; notas[1] = 10;
  inserir_ord(turmaRomana, "Ovidiius Poeta", notas);
  
  notas[0] = 6; notas[1] = 8;
  inserir_ord(turmaRomana, "Horatius Orator", notas);
  
  notas[0] = 8; notas[1] = 1;
  inserir_ord(turmaRomana, "Seneca Phylosophus", notas);
  
  notas[0] = 10; notas[1] = 10;
  inserir_ord(turmaRomana, "Marcus Aurelius", notas);

  imprimir(turmaRomana);

  apagar(turmaRomana);
  free(turmaRomana);

  return 0;  
}

