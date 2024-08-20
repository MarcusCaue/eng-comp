#include "./PessoasHeaders.hpp"
#include <iostream>

using namespace std;

int main() {

  Pessoa fabricio = Pessoa("Fabricio");

  PessoaFisica ricardo = PessoaFisica("Ricardo de Sousa", "546.333.000-58");

  PessoaJuridica infoDataSolucoes = PessoaJuridica("InfoDataSolucoes", "47.857.673/0001-00", fabricio.getNome());

  Cliente rodrigo = Cliente("Rodrigo Fonseca", "478.695.85-77", "Rua Vasco é melhor que Flamengo, nº 2000", "99685-4712");
  
  cout << fabricio;
  cout << ricardo;
  cout << infoDataSolucoes;
  cout << static_cast<Pessoa>(rodrigo) << endl; // Exibindo o Cliente como Pessoa

  // Exibindo o Cliente com o operador '<<' sobrecarregado por ele
  cout << rodrigo;
  
  return 0;
}