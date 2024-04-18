#include <iostream>
#include "Varinha.hpp"

Varinha::Varinha(string mad, string nucleo, double comp) :
  tipoMadeira(mad),
  nucleo(nucleo),
  comprimento(comp)
{};

void Varinha::display() const {
  cout << "\n======= DADOS DA VARINHA =======\n";
  cout << "Tipo de madeira: " << getMad() << endl;
  cout << "Material do nucleo: " << getNucleo() << endl;
  printf("Comprimento: %.1lfcm\n\n", getComp());
}

string Varinha::getMad() const { return this->tipoMadeira; }
string Varinha::getNucleo() const { return this->nucleo; }
double Varinha::getComp() const { return this->comprimento; }
