#include <iostream>
#include <string>
#include "Data.hpp"

using std::string;
using std::to_string;

Data::Data(int dia, int mes, int ano) {
  this->dia = dia;
  this->ano = ano;
  setMes(mes);
}

string adicionaZeroEsquerda(int val) {
  return "0" + to_string(val);
}

void Data::mostrarData() {
  string dia = (this->dia < 10) ? adicionaZeroEsquerda(this->dia) : to_string(this->dia);
  string mes = (this->mes < 10) ? adicionaZeroEsquerda(this->mes) : to_string(this->mes);

  std::cout << dia << "/" << mes << "/" << ano << std::endl;
}

int Data::getDia() { return this->dia; }
void Data::setDia(int dia) { this->dia = dia; }

int Data::getMes() { return this->mes; }
void Data::setMes(int mes) { this->mes = (mes >= 1 && mes <= 12) ? mes : 1; }

int Data::getAno() { return this->ano; }
void Data::setAno(int ano) { this->ano = ano; }
