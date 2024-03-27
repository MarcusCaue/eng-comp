#include "Pessoa.hpp"

Pessoa::Pessoa(string nome, string cpf, bool cpfValido) {
  this->nome = nome;
  this->cpf = cpf;
  this->cpfValido = cpfValido;
}

void Pessoa::apresentar() {
  string cpfFormatado = getCpf();
  cpfFormatado = cpfFormatado.substr(0, 3) + '.' 
               + cpfFormatado.substr(3, 3) + '.'
               + cpfFormatado.substr(6, 3) + '-'
               + cpfFormatado.substr(9, 2)
  ;
  string situacao = getCpfValido() ? "Válido" : "Inválido";

  cout << getNome() << " - " << cpfFormatado << " (" << situacao << ")" << endl;
}

string Pessoa::getNome() { return this->nome; }
void Pessoa::setNome(string nome) { this->nome = nome; }

string Pessoa::getCpf() { return cpf; }
void Pessoa::setCpf(string cpf) { this->cpf = cpf; }

bool Pessoa::getCpfValido() { return cpfValido; }
void Pessoa::setCpfValido(bool cpfValido) { this->cpfValido = cpfValido; }