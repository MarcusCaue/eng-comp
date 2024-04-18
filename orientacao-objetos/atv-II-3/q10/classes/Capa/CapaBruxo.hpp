#ifndef CAPABRUXO_HPP
#define CAPABRUXO_HPP

#include <string>

using namespace std;

class CapaBruxo
{
private:
  // Considere que uma capa já criada não pode ter suas características modificadas.
  double tamanho;
  string casa;
  string cor;

  void setCasa(string);
  void setTam(double);

public:
  CapaBruxo(string, double);

  void display() const;

  string getCor() const;
  string getCasa() const;
  double getTam() const;
};

#endif