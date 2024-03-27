#include <iostream>
#include "Retangulo.hpp"

using std::cout;
using std::endl;

void desenhaLargura(int quantHifens) {
  cout << '+';
  for (int i = 0; i < quantHifens; i++) cout << '-';
  cout << '+' << endl;
}
void desenhaAltura(int quantPipes, int quantHifens) {
  for (int i = 0; i < quantPipes; i++) {
    cout << '|';
    for (int j = 0; j < quantHifens; j++) cout << ' ';
    cout << '|' << endl;
  }
}

Retangulo::Retangulo(double alt, double larg) {
  setAlt(alt);
  setLarg(larg);
}

double Retangulo::perimetro() {
  double perimetro = this->altura * 2.0 + this->largura * 2.0;
  return perimetro;
}

double Retangulo::area() {
  return this->altura * this->largura;
}

void Retangulo::desenho() {
  int quantHifens = static_cast<int>(this->largura);
  int quantPipes = static_cast<int>(this->altura);
  
  // Topo
  desenhaLargura(quantHifens);
  // Lado Direito e Esquerdo
  desenhaAltura(quantPipes, quantHifens);
  // Base
  desenhaLargura(quantHifens);
}

double Retangulo::getAlt() { return this->altura; }
void Retangulo::setAlt(double alt) {
  this->altura = alt > 0.0 && alt < 20.0 ? alt : 1.0;
}

double Retangulo::getLarg() { return this->largura; }
void Retangulo::setLarg(double larg) {
  this->largura = larg > 0.0 && larg < 20.0 ? larg : 1.0;
}