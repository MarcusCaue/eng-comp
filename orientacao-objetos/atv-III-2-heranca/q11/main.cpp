#include "./PessoasHeaders.hpp"
#include <iostream>

using namespace std;

int main() {

  Pessoa fabricio = Pessoa("Fabricio");
  
  PessoaFisica ricardo = PessoaFisica("Ricardo de Sousa", "546.333.000-58");
  
  PessoaJuridica infoDataSolucoes = PessoaJuridica("InfoDataSolucoes", "47.857.673/0001-00", fabricio.getNome());

  cout << fabricio;
  cout << ricardo;
  cout << infoDataSolucoes;

  return 0;
}