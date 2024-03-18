#include <iostream>
#include "./Carro.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

  cout << "Qual a marca do seu carro? ";
  string marca; cin >> marca;

  cout << "Qual o ano do seu carro? ";
  int ano; cin >> ano;

  Carro meuCarrao = {marca, ano};

  meuCarrao.displayMessage();
  
  return 0;
}