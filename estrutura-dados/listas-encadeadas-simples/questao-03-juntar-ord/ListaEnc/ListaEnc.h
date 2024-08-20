#ifndef LISTA_ENC_HPP
#define LISTA_ENC_HPP

#include <stdio.h>
#include <stdlib.h>

struct sNo {
  int dado;
  struct sNo *prox;
};

typedef struct sNo No;

typedef struct {
  No *ini, *fim;
} Lista;

Lista juntar_ord(Lista *l1, Lista *l2);

void inicializar(Lista *lst);
void apagar(Lista *lst);

void inserir_ord(Lista *lst, int dado);
void remover(Lista *lst, int dado);
No *buscar(Lista *lst, int dado);

int obter(No *node);
int tamanho(Lista *lst);
void imprimir(Lista *lst);

#endif