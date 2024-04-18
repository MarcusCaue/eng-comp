#include <stdio.h>
#include <stdlib.h>
#include "ListaSeqOrd.h"

int contar(LISTA* lst, int valor) {
  int occ = 0;

  for (int i = 0; i < lst->len; i++) {
    int element = *(lst->arr + i);
    if (element == valor)
      occ++;
  }

  return occ;
}

int pop(LISTA* lst) {
  if (lst->len <= 0) {
    printf("ERRO!!! A LISTA NÃO TEM ELEMENTOS!\n");
    exit(1);
  }

  int lastElement = lst->arr[lst->len - 1];
  lst->len--;

  return lastElement;
}


void criar(LISTA *lst, int tam_max) {
  lst->max = tam_max;
  lst->len = 0;
  lst->arr = (int *) malloc(sizeof(int) * tam_max); 
}
void apagar(LISTA *lst) {
  lst->len = 0;
  lst->max = 0;
  free(lst->arr);
}

void inserir(LISTA* lst, int el) {
  if (lst->len >= lst->max)
    return;
  
  lst->arr[lst->len++] = el;
}
void inserir_ord(LISTA *lst, int el) {
  int *len = &lst->len;
  int max = lst->max;
  int *array = lst->arr;
  
  if (*len >= max) {
    printf("Lista '%p' está cheia!\n", &lst);
    return;
  } 

  int p = 0;
  while (p < *len && array[p] < el)
    p++;

  for (int i = *len ; i > p ; i--)
    array[i] = array[i-1];

  array[p] = el;
  *len += 1;
}
void remover(LISTA *lst, int el) {
  int index = buscar(lst, el);

  if (index != -1) {
    int *len = &lst->len;
    int *array = lst->arr;
    
    for (int i = index; i < (*len) - 1; i++)
      array[i] = array[i+1];
    
    *len -= 1;
  }
}

int buscar(LISTA *lst, int el) {
  int len = lst->len;
  int *array = lst->arr;
  
  for (int i = 0 ; i < len ; i++)
    if (array[i] == el)
      return i;

  return -1;
}
int obter(LISTA *lst, int index) {
  int *len = &lst->len;
  int *array = lst->arr;

  if (index >= 0 && index < *len)
    return *(array + index);

  printf("Posição inexistente!\nPROGRAMA FECHADO\n");
  exit(1);

}

void imprimir(LISTA *lst) {
  int len = lst->len;
  int *array = lst->arr;
  
  printf("Lista %p => [ ", lst);
  for (int i = 0 ; i < len; i++)
    printf("%d ", array[i]);
  printf("]\n");
}
int tamanho(LISTA *lst) { return lst->len; }
