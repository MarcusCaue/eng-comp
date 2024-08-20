#ifndef LISTA_ENC_HPP
#define LISTA_ENC_HPP

#include <stdio.h>
#include <stdlib.h>

struct sNo {
  const char* nome;
  int notas[2];
  double media;
  struct sNo *prox;
};

typedef struct sNo No;

typedef struct {
  No *ini, *fim;
} Lista;

void inicializar(Lista *lst);
void apagar(Lista *lst);

void inserir_ord(Lista *lst, const char nome[], int notas[2]);
void imprimir(Lista *lst);

#endif