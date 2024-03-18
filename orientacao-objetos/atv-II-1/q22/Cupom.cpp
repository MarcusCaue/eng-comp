#include <iostream>
#include "Cupom.hpp"

using std::cout;

Cupom::Cupom() {
  this->itensCadastrados = 0;
}

Item Cupom::getItem(string id) {
  Item itemProcurado = {"-1", 0, 0.0f, "Item ainda não encontrado"};

  for (int i = 0; i < this->itensCadastrados; i++) {
    Item item = this->itens[i];

    if (item.id == id) {
      itemProcurado = item;
      break;
    }
  }

  return itemProcurado;
}

void Cupom::setItem(string id, string desc, int quant, float preco) {
  Item novoItem = { id, quant, preco, desc };
  this->itens[this->itensCadastrados++] = novoItem;
}

float Cupom::calculaCupom() {
  float tot = 0.0f;

  for (int i = 0; i < this->itensCadastrados; i++) {
    Item item = this->itens[i];
    tot += (static_cast<float>(item.quant) * item.preco);
  }

  return tot;
}

void Cupom::imprimirNota() {
  cout << "===== DADOS DO CUPOM =====\n";
  cout << "-> ITENS CADASTRADOS: \n";

  for (int i = 0; i < this->itensCadastrados; i++) {
    Item item = this->itens[i];

    const char *id = item.id.c_str();
    const char *desc = item.descricao.c_str();
    int quant = item.quant;
    float preco = item.preco;
    float totalItem = (static_cast<float>(quant) * preco);
    
    printf("%iº item:\n\tID: %s\n\tDESCRIÇÃO: %s\n\tQUANTIDADE: %i\n\tPREÇO: %.2f\n\tVALOR TOTAL: %.2f\n\n", (i+1), id, desc, quant, preco, totalItem);
  }

  printf("Valor total da nota: %.2f\n", calculaCupom());
}