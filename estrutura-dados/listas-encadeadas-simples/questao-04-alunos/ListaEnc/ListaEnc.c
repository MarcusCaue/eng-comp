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

void inserir_ord(Lista *lst, const char nome[], int notas[2]) {

  No* novoNo = (No*) malloc(sizeof(No));
  novoNo->nome = nome;
  novoNo->notas[0] = notas[0];
  novoNo->notas[1] = notas[1];
  novoNo->media = (notas[0] + notas[1]) / 2.0;
  novoNo->prox = NULL;

  No* aux = lst->ini, *ant = NULL;

  while (aux != NULL && novoNo->media < aux->media)
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

void imprimir(Lista *lst) {
  No *aux = lst->ini;
  
  if (aux == NULL) {
    printf("Lista vazia.\n");
    return;
  }
  
  printf("================ DADOS DA LISTA DE ALUNOS ================\n");

  int i = 1;
  while(aux != NULL){
    printf("%d aluno: \n", i++);
    printf("    - Nome: %s\n", aux->nome);
    printf("    - Media: %.1lf\n", aux->media);
    printf("    - Notas: [%d, %d]\n\n", aux->notas[0], aux->notas[1]);
    aux = aux->prox;
  }
  
}
