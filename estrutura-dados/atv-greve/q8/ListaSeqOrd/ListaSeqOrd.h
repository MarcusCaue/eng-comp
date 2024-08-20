#ifndef LISTA_SEQ_ORD_H
#define LISTA_SEQ_ORD_H

typedef struct {
  unsigned int max;
  int *arr;
  int len;
} LISTA;

int contar(LISTA*, int);
int pop(LISTA*);
void inserirPos(LISTA*, int, int);
void copiar(LISTA*, LISTA*);
void estender(LISTA*, LISTA*);
void inverter(LISTA*, LISTA*);

// Funções que fazem uso do redimensionamento
void inserir_v2(LISTA*, int);
void inserirPos_v2(LISTA*, int, int);
void inserirOrd_v2(LISTA*, int);
void copiar_v2(LISTA*, LISTA*);
void estender_v2(LISTA*, LISTA*);
void inverter_v2(LISTA*, LISTA*);

void criar(LISTA*, int);
void apagar(LISTA*);

void inserir(LISTA*, int);
void inserirOrd(LISTA*, int);
int buscar(LISTA*, int); // Passa o elemento, retorna o índice
void remover(LISTA*, int);
int obter(LISTA*, int); // Passa o índice, retorna o elemento
int tamanho(LISTA*);
void imprimir(LISTA*);

#endif