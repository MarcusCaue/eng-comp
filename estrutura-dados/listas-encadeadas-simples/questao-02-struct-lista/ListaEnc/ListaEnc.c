#include "./ListaEnc.h"

void inicializar(Lista *lst) {
  lst->ini = NULL;
  lst->fim = NULL;
}

void apagar(Lista *lst) {

  No *aux = lst->ini;
  No *ant = NULL;

  while (aux != NULL)
  {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }

  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir_ord(Lista *lst, int dado) {

  No* novoNo = (No*) malloc(sizeof(No));
  novoNo->dado = dado;
  novoNo->prox = NULL;

  No* aux = lst->ini, *ant = NULL;

  while (aux != NULL && dado > aux->dado)
  {
    ant = aux;
    aux = aux->prox;
  }

  if (lst->ini == NULL)  {
    lst->ini = lst->fim = novoNo;
  }
  else if (aux == lst->ini) {
    novoNo->prox = lst->ini;
    lst->ini = novoNo;
  }
  else if (aux == NULL) {
    lst->fim->prox = novoNo;
    lst->fim = novoNo;
  }
  else {
    ant->prox = novoNo;
    novoNo->prox = aux;
  }

}

void remover(Lista *lst, int dado) {

  No *aux = lst->ini;
  No *ant = NULL; 

  while (aux != NULL) {
    if (aux->dado == dado) {

      if (aux == lst->ini) {
        lst->ini = aux->prox; 
      }
      else if (aux == lst->fim) {
        lst->fim = ant;
        lst->fim->prox = NULL;
      }
      else {
        ant->prox = aux->prox;
      }

      free(aux);
      return;
    }

    ant = aux;
    aux = aux->prox; 
  }
}

No* buscar(Lista *lst, int dado) {

  No *aux = lst->ini;

  while (aux != NULL) {
    if (aux->dado == dado) {
      return aux;
    }
    aux = aux->prox;
  }

  return NULL;

}

int obter(No* node) {
  if (node == NULL) {
	  printf("Erro ao obter dado. Ponteiro invalido.");
	  exit(0);
  }
 
  return node->dado;
}

int tamanho(Lista *lst) {
  No *aux = lst->ini;
  int tam = 0;
 
  while (aux != NULL) {
	  tam++;
	  aux = aux->prox;
  }
 
  return tam;
}

void imprimir(Lista *lst) {
  No *aux = lst->ini;
  
  printf("[ ");
  
  while(aux != NULL){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  
  printf("]\n");
}
