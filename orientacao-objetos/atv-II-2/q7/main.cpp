#include <iostream>
#include "Pessoa.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {

  // Inicialização
  Pessoa p = { "Jonas de Samos", "34561289787" };
  Pessoa pPadrao = { "Elemento" };

  // Apresentar
  p.apresentar();
  cout << endl;
  pPadrao.apresentar();

  // Alterando os atributos
  p.setNome("Sócrates de Atenas");
  p.setCpf("60743137094");
  p.setCpfValido(true);

  // Obtendo os atributos
  cout << "\nNome: " << p.getNome() << endl;
  cout << "CPF não formatado: " << p.getCpf() << " (" << p.getCpfValido() << ")\n";

  return 0;
}
