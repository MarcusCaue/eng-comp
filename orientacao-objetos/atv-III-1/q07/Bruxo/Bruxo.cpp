#include <iostream>
#include "Bruxo.hpp"

using std::cout;
using std::endl;

Bruxo::Bruxo() : nome(""), casa(""), feiticoPredileto("") { }

Bruxo::Bruxo(string nome, string casa, string feitico) {
  this->nome = nome;
  this->feiticoPredileto = feitico;
  setCasa(casa);
}

void Bruxo::display() const {
  cout << "\n===== ATRIBUTOS DO BRUXO =====\n";
  cout << "Nome: " << this->nome << endl;
  cout << "Casa: " << this->casa << endl;
  cout << "Feitiço preferido: " << this->feiticoPredileto << endl;
}

void Bruxo::lancarFeitico() const {
  cout << "Lançando feitiço '" << this->feiticoPredileto << "'!!!\n";
}

string Bruxo::getNome() const { return this->nome; }
void Bruxo::setNome(string nome) { this->nome = nome; }

string Bruxo::getCasa() const { return this->casa; }
void Bruxo::setCasa(string casa) {

  string casas[] = {"Lufa-lufa", "Corvinal", "Grifinória", "Sonserina"};

  bool casaValida = false;
  
  for (string c : casas) {
    if (casa == c) {
      casaValida = true;
      break;
    }
  }

  this->casa = (casaValida) ? casa : "";

}

string Bruxo::getFeitico() const { return this->feiticoPredileto; }
void Bruxo::setFeitico(string feitico) { this->feiticoPredileto = feitico; }