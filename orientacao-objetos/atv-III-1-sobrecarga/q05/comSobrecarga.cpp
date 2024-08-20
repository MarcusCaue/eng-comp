#include <iostream>
#include "./IntegerSet/IntegerSet.hpp"

using namespace std;

void showSet(IntegerSet* s) {
  cout << "Elementos de " << s << ": " << *s;
  cout << "Quantidade: " << s->getTam() << endl << endl;
}

int main() {

  // Criando os conjuntos
  IntegerSet conjunto = IntegerSet();

  int elements[] = {1, 1, 1, 0, 0, 1, 1, 0, 1, 1};
  IntegerSet conjunto2 = IntegerSet(elements, 10);

  cout << "=========== CRIAÇÃO DOS CONJUNTOS ===========" << endl;
  showSet(&conjunto);
  showSet(&conjunto2);

  // Setando elementos
  cout << "=========== ADICIONANDO ELEMENTOS AOS CONJUNTOS ===========" << endl;
  conjunto << 101 << 82 << 9 << 1 << 6 << 51;
  conjunto2 << 43 << 0 << 21;

  showSet(&conjunto);
  showSet(&conjunto2);

  // Deletando elementos   
  cout << "=========== REMOVENDO ELEMENTOS DOS CONJUNTOS ===========" << endl;
  conjunto >> 82 >> 200 >> 51;
  conjunto2 >> 0 >> 6 >> 9;

  showSet(&conjunto);
  showSet(&conjunto2);

  // Unindo os elementos 
  cout << "=========== CONJUNTO UNIÃO ===========" << endl;
  IntegerSet uniao = conjunto | conjunto2;
  showSet(&uniao);

  // Obtendo os elementos em comum
  cout << "=========== CONJUNTO INTERSECÇÃO ===========" << endl;
  IntegerSet intersection = conjunto & conjunto2;
  showSet(&intersection);

  return 0;
}