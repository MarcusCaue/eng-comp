#include <iostream>
#include "IntegerSet.hpp"

using namespace std;

void showSet(IntegerSet* s) {
  cout << "Elementos de " << s << ": " << endl;
  s->print();
  cout << "Quantidade: " << s->getTam() << endl << endl;
}

int main() {

  // Creating Sets
  IntegerSet conjunto = IntegerSet();

  int elements[] = {1, 1, 1, 0, 0, 1, 1, 0, 1, 1};
  IntegerSet conjunto2 = IntegerSet(elements, 10);

  cout << "=========== CRIAÇÃO DOS CONJUNTOS ===========" << endl;
  showSet(&conjunto);
  showSet(&conjunto2);

  // Setando elementos
  cout << "=========== ADICIONANDO ELEMENTOS AOS CONJUNTOS ===========" << endl;
  conjunto.insertElement(101);
  conjunto.insertElement(82);
  conjunto.insertElement(9);
  conjunto.insertElement(1);
  conjunto.insertElement(6);
  conjunto.insertElement(51);

  conjunto2.insertElement(43);
  conjunto2.insertElement(0);
  conjunto2.insertElement(21);

  showSet(&conjunto);
  showSet(&conjunto2);

  // Deletando elementos   
  cout << "=========== REMOVENDO ELEMENTOS AOS CONJUNTOS ===========" << endl;
  conjunto.deleteElement(82);
  conjunto.deleteElement(200);
  conjunto.deleteElement(51);

  conjunto2.deleteElement(0);
  conjunto2.deleteElement(6);
  conjunto2.deleteElement(9);

  showSet(&conjunto);
  showSet(&conjunto2);

  // Unindo os elementos 
  IntegerSet uniao = unionOfSets(conjunto, conjunto2);
  cout << "=========== CONJUNTO UNIÃO ===========" << endl;
  showSet(&uniao);

  // Obtendo os elementos em comum
  IntegerSet intersection = intersectionOfSets(conjunto, conjunto2);
  cout << "=========== CONJUNTO INTERSECÇÃO ===========" << endl;
  showSet(&intersection);

  return 0;
}