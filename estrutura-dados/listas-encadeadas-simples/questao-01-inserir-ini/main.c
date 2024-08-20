#include <stdio.h>
#include <stdlib.h>

struct No {
  int dado;
  struct No *prox;
};

void inserir_ini(int dado);

void inserir(int dado);
void remover(int dado);
struct No* buscar(int dado);
void apagar();
void imprimir();

struct No *ini = NULL, *fim = NULL;

int main() 
{
  struct No* listaNums = ini;

  inserir(32); inserir(54); inserir(21);
  printf("Dados inseridos no final: ");
  imprimir();

  printf("Inserindo dados no inicio: \n");

  inserir_ini(99);
  imprimir();
  
  inserir_ini(2102);
  imprimir();
  
  inserir_ini(12);
  imprimir();

  return 0;
}

void inserir_ini(int dado) {

  struct No* novoNo = (struct No*) malloc(sizeof(struct No));
  novoNo->dado = dado;

  novoNo->prox = ini;
  ini = novoNo;

}

void inserir(int dado)
{
  struct No *aux = (struct No*) malloc(sizeof(struct No));
  aux->dado = dado;
  aux->prox = NULL;

  if (ini == NULL)
  {
    ini = aux;
    fim = aux;
  }
  else
  {
    fim->prox = aux;
    fim = aux;
  }
}

struct No *buscar(int dado) {
  struct No *aux = ini;
  
  while (aux != NULL) {
    if (aux->dado == dado) {
      return aux;
    }

    aux = aux->prox;
  }

  return NULL;
}

void remover(int dado) {
  struct No *aux = ini;
  struct No *ant = NULL; 

  while (aux != NULL) {
    if (aux->dado == dado) {

      if (aux == ini) {
        ini = aux->prox; 
      }
      else if (aux == fim) {
        fim = ant;
        fim->prox = NULL;
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

void apagar(){
  struct No *aux = ini;
  struct No *ant = NULL;

  while (aux != NULL) { 
    ant = aux;
    aux = aux->prox;
    free(ant);
  }

  ini = fim = NULL;
}

void imprimir(){
  struct No *aux = ini;
  
  printf("[ ");
  
  while(aux != NULL){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  
  printf("]\n");
}