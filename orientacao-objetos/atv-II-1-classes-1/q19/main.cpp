#include <iostream>
#include "ContaBanco.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
  // Inicialzização
  ContaBanco bradesco = { 1500.0 };
  ContaBanco itau = { 547.0 };

  // Recuperando o saldo
  cout << "Saldo da conta no Bradesco: R$" << bradesco.getSaldo() << endl;
  cout << "Saldo da conta no Itaú: R$" << itau.getSaldo() << endl;

  // Creditando o saldo
  cout << "\nValor a creditar no saldo da conta no Bradesco: ";
  double valor;
  cin >> valor;
  bradesco.creditar(valor);

  cout << "Novo valor do saldo da conta no Bradesco: R$" << bradesco.getSaldo() << endl;

  // Debitando o saldo
  cout << "\nValor a debitar do saldo da conta no Itaú: ";
  cin >> valor;
  itau.debitar(valor);
  
  cout << "Novo valor do saldo da conta no Itaú: R$" << itau.getSaldo() << endl << endl;

  // Tentando debitar um valor acima do saldo
  itau.debitar(itau.getSaldo() + 1000.0);
  
  return 0;
}