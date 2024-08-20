#include "./ListaEnc/ListaEnc.h"

int main()
{
  // Criação e inicialização
  Lista* numbers = (Lista*) malloc(sizeof(Lista));
  inicializar(numbers);
  
  // Lista Vazia
  printf("Endereco de 'numbers': %p\n", numbers);
  imprimir(numbers);

  // Inserção de elementos
  inserir_ord(numbers, 2102);
  inserir_ord(numbers, 43);
  inserir_ord(numbers, 0);
  inserir_ord(numbers, 2103);
  inserir_ord(numbers, 22);

  printf("Elementos da lista: ");
  imprimir(numbers);
  printf("Tamanho da lista: %d\n\n", tamanho(numbers));

  // Remoção de elementos
  remover(numbers, -21);  // Elemento inexistente
  remover(numbers, 0);    // Removendo o primeiro
  remover(numbers, 2103); // Removendo o último
  remover(numbers, 22);   // Removendo no meio
  
  printf("Lista apos as remocoes: ");
  imprimir(numbers);

  // Buscando e Obtendo elementos
  printf("\nBuscando o elemento -21: ");

  No* findedNode = buscar(numbers, -21); // Inexistente
  if (findedNode)
    printf("\nEndereco do no encontrado: %p\n", &findedNode);
  else 
    printf("\nEsse elemento nao esta presente na lista.\n");
   
  printf("\nBuscando o elemento 43: ");
  findedNode = buscar(numbers, 43);
  if (findedNode) {
    printf("\nEndereco do no encontrado: %p\n", &findedNode);
    printf("Valor armazenado no no: %d\n\n", obter(findedNode));
  }
  else 
    printf("Esse elemento nao esta presente na lista.\n");
  
  // Esvaziamento da lista
  apagar(numbers);

  printf("Lista esvaziada: ");
  imprimir(numbers);

  free(numbers);

  return 0;
}
