#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSeqStr.h"

void criar(LISTA *lst, int tam_max) {
  lst->max = tam_max;
  lst->len = 0;

  int tamanhoStrings = sizeof(char) * 21;  
  lst->array = (char **) malloc(tamanhoStrings * tam_max);
}
void apagar(LISTA *lst) {
  lst->len = 0;
  lst->max = 0;
  free(lst->array);
}

void inserir_ord(LISTA *lst, char el[]) {
  int *len = &lst->len;
  int max = lst->max;
  char **elementos = lst->array;

  if (*len >= max) {
    printf("Lista '%p' está cheia!\n", &lst);
    return;
  } 

  int p = 0;
  while (p < *len && strcmp(elementos[p], el) < 0)
    p++;

  for (int i = *len; i > p ; i--)
    elementos[i] = elementos[i-1];

  elementos[p] = el;
  *len += 1;
}
void remover(LISTA *lst, char el[]) {
  int index = buscar(lst, el);

  if (index != -1) {
    int *len = &lst->len;
    char **elementos = lst->array;

    for (int i = index; i < (*len) - 1; i++)
      elementos[i] = elementos[i+1];

    *len -= 1;
  }
}

int buscar(LISTA *lst, char el[]) {
  int len = lst->len;
  char **elementos = lst->array;

  for (int i = 0; i < len; i++)
    if (strcmp(elementos[i], el) == 0)
      return i;

  return -1;
}
char* obter(LISTA *lst, int index) {
  int *len = &lst->len;
  char **elementos = lst->array;

  if (index >= 0 && index < (*len))
    return elementos[index];

  printf("Posição inexistente!\nPROGRAMA FECHADO\n");
  exit(1);
}

void imprimir(LISTA *lst) {
  int len = lst->len;
  char **elementos = lst->array;

  printf("Lista %p => [ ", lst);
  for (int i = 0 ; i < len; i++)
    printf("'%s' ", elementos[i]);
  printf("]\n");
}

int tamanho(LISTA *lst) {
  return lst->len;
}