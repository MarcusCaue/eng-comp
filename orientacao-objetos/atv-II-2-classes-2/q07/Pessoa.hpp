#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class Pessoa {

private:
  string nome;
  string cpf;
  bool cpfValido;

public:
  Pessoa(string, string = "00000000000", bool = false);

  void apresentar();

  string getNome();
  void setNome(string);

  string getCpf();
  void setCpf(string);

  bool getCpfValido();
  void setCpfValido(bool);

};

#endif