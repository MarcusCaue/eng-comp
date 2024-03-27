#ifndef LISTA_SEQ_ORD_H
#define LISTA_SEQ_ORD_H

typedef struct {
  unsigned int max;
  int *arr;
  int len;
} LISTA;

void criar(LISTA*, int);
void apagar(LISTA*);

void inserir_ord(LISTA*, int);
int buscar(LISTA*, int); // Passa o elemento, retorna o índice
void remover(LISTA*, int); // X
int obter(LISTA*, int); // Passa o índice, retorna o elemento
int tamanho(LISTA*);
void imprimir(LISTA*);

#endif