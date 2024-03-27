#ifndef LISTA_SEQ_STR_H
#define LISTA_SEQ_STR_H

typedef struct {
  unsigned int max;
  char **array;
  int len;
} LISTA;

void criar(LISTA*, int);
void apagar(LISTA*);

void inserir_ord(LISTA*, char str[]);
int buscar(LISTA*, char str[]); // Passa o elemento, retorna o índice 
void remover(LISTA*, char str[]);
char* obter(LISTA*, int); // Passa o índice, retorna o elemento
int tamanho(LISTA*);
void imprimir(LISTA*);

#endif