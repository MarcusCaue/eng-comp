#ifndef BRUXO_HPP
#define BRUXO_HPP

#include "../Capa/CapaBruxo.hpp"
#include "../Varinha/Varinha.hpp"

#include <string>

using namespace std;

class Bruxo {

private:
  const string nome;
  string casa;
  string feitico;
  Varinha* varinha;
  CapaBruxo* capa;

public:
  // Aluno matriculado
  Bruxo(const string&, const string&, const string&, Varinha&, CapaBruxo&);
  // Novo aluno
  Bruxo(const string&);

  void lancarFeitico() const;
  void display() const;

  string getNome() const;
  string getCasa() const;
  string getFeitico() const;
  Varinha getVarinha() const;
  CapaBruxo getCapa() const;

  void setCasa(const string&);
  void setFeitico(const string&);
  void setCapa(CapaBruxo&);
  void setVarinha(Varinha&);
};

#endif