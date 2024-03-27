#include <iostream>
#include "Pessoa.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {

  // Inicialização
  Pessoa p = { "Jonas de Samos", "83606476078" };
  Pessoa pPadrao = { "Elemento", "78958254568" };

  // Apresentar
  p.apresentar();
  cout << endl;
  pPadrao.apresentar();

  // Alterando os atributos
  p.setNome("Sócrates de Atenas");
  p.setCpf("60743137094");

  // Obtendo os atributos
  cout << "\nNome: " << p.getNome() << endl;
  cout << "CPF: " << p.formatarCpf() << endl;
  
  return 0;
}
