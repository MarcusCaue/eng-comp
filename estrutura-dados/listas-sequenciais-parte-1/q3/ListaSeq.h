#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

typedef struct {
  unsigned int max;
  int *arr;
  int len;
} LISTA;

void criar(LISTA*, int);
void apagar(LISTA*);

void inserirUmaOcorrencia(LISTA *, int);
void inserir(LISTA*, int);
int buscar(LISTA*, int); // Passa o elemento, retorna o índice
void remover(LISTA*, int);
int obter(LISTA*, int); // Passa o índice, retorna o elemento
int tamanho(LISTA*);
void imprimir(LISTA*);

#endif