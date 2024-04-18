#include "Pessoa.hpp"

Pessoa::Pessoa(){}
Pessoa::Pessoa(string nome, int idade, float altura) :
   nome(nome), idade(idade), altura(altura)
{ }

string Pessoa::getNome() const { return this->nome; }
int Pessoa::getIdade() const { return this->idade; }
float Pessoa::getAltura() const { return this->altura; }

void Pessoa::setIdade(int idade) { this->idade = idade; }
void Pessoa::setAltura(float altura) { this->altura = altura; }