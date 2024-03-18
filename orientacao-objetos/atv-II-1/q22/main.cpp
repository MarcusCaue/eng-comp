#include <iostream>
#include <string>

#include "Cupom.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

  // Inicialização
  Cupom cp;

  // Cadastrando itens
  cp.setItem("1023", "Caneca Lufa-lufa", 1, 4.50f);  
  cp.setItem("1024", "Camisa Lufa-lufa", 4, 23.00f);
  cp.setItem("1254", "Chapéu de Bruxo", 3, 42.90f);
  cp.setItem("1097", "Varinha", 5, 10.40f);

  // Recuperando itens
  Item camiseta = cp.getItem("1024");
  Item varinha = cp.getItem("1097");
  
  cout << "1º Item recuperado: \n\tID: " << camiseta.id
       << "\n\tDescrição: " << camiseta.descricao
       << "\n\tQuantidade: " << camiseta.quant
       << "\n\tPreço: " << camiseta.preco
  ;

  cout << "\n\n2º Item recuperado: \n\tID: " << varinha.id
       << "\n\tDescrição: " << varinha.descricao
       << "\n\tQuantidade: " << varinha.quant
       << "\n\tPreço: " << varinha.preco
  ;

  // Valor total da nota
  printf("\n\nA sua nota tá valendo R$%.2f\n", cp.calculaCupom());

  cout << endl;

  // Impressão da nota
  cp.imprimirNota();

  return 0;
}