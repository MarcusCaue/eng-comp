#include <iostream>
#include "Bruxo.hpp"

// Novo aluno na escola
Bruxo::Bruxo(const string& nome) : nome(nome) {
  this->casa = "undefined";
  this->feitico = "undefined";
  this->varinha = nullptr;
  this->capa = nullptr;
}

// Aluno com atributos definidos
Bruxo::Bruxo(
  const string& nome, 
  const string& casa, 
  const string& feitico, 
  Varinha& varinha, 
  CapaBruxo& capa
) : nome(nome) {
  this->feitico = feitico;
  setCasa(casa);
  this->varinha = &varinha;
  setCapa(capa);
}

void Bruxo::display() const {
  cout << "\n===== ATRIBUTOS DO BRUXO =====\n";
  cout << "Nome: " << this->nome << endl;
  cout << "Casa: " << this->casa << endl;
  cout << "Feitiço preferido: " << this->feitico << endl;

  // Dados da Varinha
  if (this->varinha == nullptr)
    cout << "Este bruxo ainda não tem varinha." << endl;
  else
    this->varinha->display();

  // Dados da Capa
  if (this->capa == nullptr)
    cout << "Este bruxo ainda não tem capa." << endl;
  else
    this->capa->display();
}

// Não tem como um bruxo lançar feitiço se ele ainda não tem um
void Bruxo::lancarFeitico() const {
  if (this->feitico != "undefined")
    cout << "Lançando feitiço '" << this->feitico << "'!!!" << endl;
  else
    cout << "Este jovem bruxo ainda não sabe nenhum feitiço." << endl;
}

string Bruxo::getNome()     const { return this->nome; }
string Bruxo::getFeitico()  const { return this->feitico; }
string Bruxo::getCasa()     const { return this->casa; }
Varinha Bruxo::getVarinha() const { return *(this->varinha); }
CapaBruxo Bruxo::getCapa()  const { return *(this->capa); }

// Um bruxo não pode ser de uma casa e usar uma capa de outra casa.
void Bruxo::setCapa(CapaBruxo& capa) {
  string casaCapa = capa.getCasa();
  this->capa = (this->casa != casaCapa ? nullptr : &capa);
}

void Bruxo::setCasa(const string& casa) {
  string casas[] = {"Lufa-Lufa", "Corvinal", "Grifinória", "Sonserina"};

  for (string c : casas) {
    if (casa == c) {
      this->casa = casa;
      return;
    }
  }

  this->casa = "undefined";
}

void Bruxo::setVarinha(Varinha& varinha) { this->varinha = &varinha; }
void Bruxo::setFeitico(const string& feitico) { this->feitico = feitico; }