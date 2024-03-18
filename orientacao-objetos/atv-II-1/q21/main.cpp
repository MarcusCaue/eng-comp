#include <iostream>
#include "Cupom.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

  // Inicialização
  Cupom cp = { "898933021", 5, 7.90f, "Um texto qualquer para colocar como descrição." };
  
  cp.display(); 

  // Alterando os atributos com funções set()
  cp.setDescricao("Outro texto para ser adicionado como descrição.");
  cp.setId("99002287162");
  cp.setQuant(5);
  cp.setPreco(10.20f);
  
  // Mostrando os atributos com funções get()
  cout << "\n===== ATRIBUTOS COM GET =====\n";
  cout << "ID: " << cp.getId() << endl;
  cout << "Descrição: " << cp.getDescricao() << endl;
  cout << "Quantidade: " << cp.getQuant() << endl;
  printf("Preço: %.2f\n", cp.getPreco());

  // Valor total da nota
  float tot = cp.calculaCupom();

  cout << "\n===== VALOR TOTAL DO CUPOM =====\n";
  printf("Valor total do cupom: %.2f\n", tot);

  return 0;
}

