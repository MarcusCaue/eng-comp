#include <stdio.h>
#include <stdlib.h>
#include "ListaSeqOrd.h"

// Retorna a quantidade de ocorrências de um determinado inteiro.
int contar(LISTA* l, int valor) {
  // Quando não há elementos na lista
  if (l->len == 0)
    return 0;

  int occ = 0;

  for (int i = 0; i < l->len; i++) {
    int element = l->arr[i];
    if (element == valor)
      occ++;
  }

  return occ;
}
// Remove e retorna o último elemento da lista
int pop(LISTA* l) {
  if (l->len <= 0) {
    printf("ERRO!!! A LISTA NÃO TEM ELEMENTOS!\n");
    exit(1);
  }

  int lastElement = l->arr[--l->len];
  return lastElement;
}
// Insere um elemento em uma determinada posição da lista
void inserirPos(LISTA* l, int pos, int valor) {
  int len = l->len;

  // Lista cheia, não dá para adicionar
  if (len >= l->max) {
    printf("Lista cheia, não dá para adicionar.\n");
    return;
  }
  // Posição inválida
  else if (pos < 0 || pos > len) {
    printf("Posição inválida. Tente novamente\n");
    return;
  }

  int* array = l->arr;

  // Inserindo na última posição
  if (pos == len) {
    array[l->len++] = valor;
    return;
  }
  
  // Abrindo o espaço para adicionar 'valor' em 'pos'
  for (int i = len; i > pos; i--) 
    array[i] = array[i - 1];

  array[pos] = valor;
  l->len++;
}
// Copia todos os elementos de l2 em l1 (sobrescrevendo o que já tinha em l1)
void copiar(LISTA* l1, LISTA* l2) {
  int max1 = l1->max;
  int len2 = l2->len;

  // Adicionar somente o que cabe em l1
  int len = len2 <= max1 ? len2 : max1;

  for (int i = 0; i < len; i++)
    l1->arr[i] = l2->arr[i];

  l1->len = len;
}
// Anexa uma cópia dos elementos de l2 ao fim de l1
void estender(LISTA* l1, LISTA* l2) {
  // l2 vazia ou l1 sem espaço disponível
  if (l2->len == 0 || l1->len >= l1->max)
    return;
  
  int quantosCabem = l1->max - l1->len;

  int iteracoes = (l2->len <= quantosCabem ? l2->len : quantosCabem);

  // Índice para o fim de l1
  int j = l1->len;

  for (int i = 0; i < iteracoes; i++)
    l1->arr[j + i] = l2->arr[i];
  
  l1->len += iteracoes;
}


void criar(LISTA *lst, int tam_max) {
  lst->max = tam_max;
  lst->len = 0;
  lst->arr = (int *) malloc(sizeof(int) * tam_max);

  if (lst->arr == NULL) {
    printf("NÃO HÁ MAIS MEMÓRIA DISPONÍVEL!!!\n");
    exit(1);
  }
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
