#ifndef CUPOM_HPP

#define CUPOM_HPP

#include <string>
using std::string;

class Cupom {

private:
  string id;
  int quant;
  float preco;
  string descricao;

public:
  Cupom(string, int, float, string);

  float calculaCupom();
  void display();
  
  string getId();
  void setId(string);

  int getQuant();
  void setQuant(int);

  float getPreco();
  void setPreco(float);

  string getDescricao();
  void setDescricao(string);
};

#endif