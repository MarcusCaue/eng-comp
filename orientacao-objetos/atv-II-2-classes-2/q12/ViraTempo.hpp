#ifndef VIRA_TEMPO_HPP
#define VIRA_TEMPO_HPP

#include <iostream>

using std::cout;
using std::endl;

class ViraTempo {

private:
  int numAtual;
  int limite;
  char modo;

  void setLimite(int);
  void setModo(char);

public:
  ViraTempo(int = 0, char = 'I');

  void mostrarTempo();
  void avancarTempo();
  void virarTempo();

};

#endif