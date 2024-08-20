#include <iostream>
using std::cout;
using std::endl;

#include "Carro.h"

Carro::Carro(string nome, int ano) {
  setMarca(nome);
  setAno(ano);
}

void Carro::setMarca(string nome) {
  if (nome == "")
    this->marca = "\"Sem Marca\"";
  else if (nome.length() > 10)
    this->marca = nome.substr(0, 10);
  else
    this->marca = nome;
}

string Carro::getMarca() { return this->marca; }

void Carro::displayMessage() {
  cout << "\n==== INFORMAÇÕES DO CARRO ==== " << endl
       << "MARCA: " << getMarca() << endl
       << "ANO: " << getAno() << endl
  ;
}

int Carro::getAno() { return this->ano; }
void Carro::setAno(int ano) {
  this->ano = ano;
}