#ifndef BRUXO_HPP

#include <string>
using std::string;

#define BRUXO_HPP

class Bruxo {

private:
  string nome;
  string casa;
  string feiticoPredileto;

public:
  Bruxo(string, string, string);

  void lancarFeitico();
  void display();

  string getNome();
  void setNome(string);

  string getCasa();
  void setCasa(string);

  string getFeitico();
  void setFeitico(string);

};

#endif