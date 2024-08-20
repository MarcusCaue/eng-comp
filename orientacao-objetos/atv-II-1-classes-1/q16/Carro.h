#ifndef CARRO_H
#define CARRO_H

#include <string>
using std::string;

// Interface
class Carro {

private:
  string marca;
  int ano;

public:
  Carro(string nome, int ano);

  void displayMessage();

  string getMarca();
  void setMarca(string nome);

  int getAno();
  void setAno(int nome);

};

#endif