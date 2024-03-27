#include <stdio.h>
#include <stdlib.h>
#include "ListaSeq.h"

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

void inserir(LISTA *lst, int el) {
  int *len = &lst->len;
  int max = lst->max;
  int *array = lst->arr;
  
  if ((*len) < max) {
    array[(*len)] = el;
    *len += 1;
  } else {
    printf("Lista cheia!!\n");
  }
}
void inserir_ini(LISTA *lst, int el) {
  int *len = &lst->len;
  int max = lst->max;
  int *array = lst->arr;

  if ((*len) < max) {
    for (int i = *len; i > 0; i--)
      array[i] = array[i - 1];

    array[0] = el;
    *len += 1;
  } else {
    printf("LISTA CHEIA!!!\n");
  }
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

int tamanho(LISTA *lst) {
  return lst->len;
}