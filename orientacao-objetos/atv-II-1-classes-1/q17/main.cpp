#include <iostream>
#include "Empregado.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

  // Inicialização com Construtor
  Empregado ovidio = { "Ovidius", "Romae", 1200.80};
  ovidio.showAllAttr();

  // Inicializando com salário < 0
  Empregado fedro = { "Gaius Julius", "Phaedrus", -2121 };
  fedro.showAllAttr();

  // Pegando os atributos por funções get()
  Empregado horacio = { "Quintus Horatius", "Romae", 1578.45};
  cout << "\n===== ATRIBUTOS DE HORÁCIO =====\n";
  cout << "Nome: \t\t" << horacio.getNome() << endl;
  cout << "Sobrenome: \t" << horacio.getSobrenome() << endl;
  printf("Salário: \t%.2lf\n", horacio.getSalario());  

  // Alterando os atributos por funções set()
  Empregado cicero = { "Marco Tulio", "Cicero", 1000.00 };
  cicero.setNome("Marcus Tulius");
  cicero.setSobrenome("Cicerus");
  cicero.setSalario(2000.00);
  cicero.showAllAttr();

  // Manipulando o salário
  cout << "\n===== MANIPULANDO O SALÁRIO ===== \n";
  Empregado julioCesar = { "Gaius Julius", "Caesar", 1000.00 };
  Empregado brutus = { "Marcus Junius", "Brutus", 1500.00 };

  printf("Salário de %s: %.2f\n", julioCesar.getSobrenome().c_str(), julioCesar.getSalario());
  printf("Salário de %s: %.2f\n", brutus.getSobrenome().c_str(), brutus.getSalario());
  
  julioCesar.setSalario(julioCesar.getSalario() * 1.10);
  brutus.setSalario(brutus.getSalario() * 1.10);

  printf("\nSalário de %s com 10%% de aumento: %.2f\n", julioCesar.getSobrenome().c_str(), julioCesar.getSalario());
  printf("Salário de %s com 10%% de aumento: %.2f\n", brutus.getSobrenome().c_str(), brutus.getSalario());
  
  return 0;
}