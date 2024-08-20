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
  Bruxo();
  Bruxo(string, string, string);

  void lancarFeitico() const;
  void display() const;

  string getNome() const;
  void setNome(string);

  string getCasa() const;
  void setCasa(string);

  string getFeitico() const;
  void setFeitico(string);

};

#endif