#include "ArrayList.hpp"
#include <iostream>

using namespace std;

int main() {

  ArrayList list = ArrayList(10);

  list.add(2);
  list.add(7);
  list.add(9);
  list.add(8);

  cout << "Lista original: ";
  list.print();
  cout << endl;

  cout << "Elemento no indice 0: " << list.busca(0) << endl;
  // cout << "\nElemento no indice 40: " << list.busca(40);
  list.add(8);
  list.add(10);
  list.add(11);
  list.add(8);
  list.add(8);
  list.add(24);
  list.add(8);
  list.add(41);

  cout << "\nLista com vários 8: ";
  list.print();
  cout << endl;

  cout << "Removendo o elemento na posicao 2" << endl;
  list.remove(2);
  cout << "Lista: ";
  list.print();
  cout << endl;

  cout << "Removendo todas as ocorrências de 8 na lista." << endl;
  list.removeEl(8);

  cout << "Lista final: ";
  list.print();
  cout << endl; 

  return 0;
}