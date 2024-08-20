#include "ChapeuSeletor.hpp"
#include <iostream>

using namespace std;

int main() {

  ChapeuSeletor chapeu;
  chapeu.recepcionar();
  
  string casaSorteada = chapeu.sortearCasa();
  cout << "A casa sorteada foi: " << casaSorteada;

  chapeu.avaliarCasa(casaSorteada);
  
  return 0;
}