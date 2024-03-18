#ifndef CUPOM_HPP

#define CUPOM_HPP

#include <string>
using std::string;

struct Item {
  string id;
  int quant;
  float preco;
  string descricao;
};

class Cupom {

private:
  Item itens[20];
  int itensCadastrados;

public:
  Cupom();

  void imprimirNota();
  float calculaCupom();

  void setItem(string, string, int, float);
  Item getItem(string);

};

#endif