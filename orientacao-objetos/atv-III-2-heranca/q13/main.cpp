#include "./classes/PessoasHeaders.hpp"
#include "./classes/Funcionario.hpp"
#include <iostream>

using namespace std;

int main() {

  Funcionario johny;
  cout << johny;

  johny.setHorasTrabalhadas(12);
  cout << johny;
  johny.setHorasTrabalhadas(-9);
  cout << johny;

  Funcionario johnyMelhorado = Funcionario(
    "Johnathan Fonseca Costa", "987.908.000-89", "12332122331",
    3420.80, 120, 120
  );

  johny = johnyMelhorado;

  cout << endl << (Pessoa) johny << endl;
  cout << johny;

  johny.setHorasTrabalhadas(314);
  cout << johny;
  johny.setHorasTrabalhadas(-32);
  cout << johny;
  johny.setHorasTrabalhadas(100);
  cout << johny;

  return 0;
}