#include <iostream>
#include <string>
#include "Empregado.hpp"

using std::cout;
using std::endl;
using std::string;

Empregado::Empregado(string nome, string sobrenome, double salario) {
  this->nome = nome;
  this->sobrenome = sobrenome;

  this->salario = (salario <= 0.0) ? 0.0 : salario;
}

void Empregado::showAllAttr() {
  cout << "\n===== ATRIBUTOS DA CLASSE =====\n";
  cout << "Nome: \t\t" << this->nome << endl;
  cout << "Sobrenome: \t" << this->sobrenome << endl;
  printf("Salário: \t%.2lf\n", this->salario);
}

string Empregado::getNome() {
  return this->nome;
}
void Empregado::setNome(string nome) {
  this->nome = nome;
}

string Empregado::getSobrenome() {
  return this->sobrenome;
}
void Empregado::setSobrenome(string sobrenome) {
  this->sobrenome = sobrenome;
}

double Empregado::getSalario() {
  return this->salario;
}
void Empregado::setSalario(double salario) {
  this->salario = salario;
}
