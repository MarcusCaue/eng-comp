#include "Pessoa.hpp"
#include <string>

bool validaDigito(string cpf, int quantDigitos, char digitoAverificar) {
  int soma = 0;

  for (int i = quantDigitos; i > 1; i--)
    soma += (cpf[quantDigitos - i] - '0') * i;

  soma *= 10;
  int restoDivisao = (soma % 11 == 10) ? 0 : soma % 11; 

  if (restoDivisao != (digitoAverificar - '0'))
    return false;
  
  return true;
}
bool allDigitsAreEquals(string cpf) {
  char digitoBase = cpf[0];

  for (int i = 1; i < 11; i++) {
    if (cpf[i] != digitoBase) {
       return false;
    }
  }
    
  return true;
}

Pessoa::Pessoa(string nome, string cpf) {
  this->nome = nome;
  setCpf(cpf);
}

void Pessoa::apresentar() {
  string cpfFormatado = formatarCpf();
  string situacao = this->cpfValido ? "Válido" : "Inválido";
  
  cout << this->nome << " - " << cpfFormatado << " (" << situacao << ")" << endl;
}
string Pessoa::formatarCpf() {
  string cpfFormatado = this->cpf;

  cpfFormatado = cpfFormatado.substr(0, 3) + '.' 
               + cpfFormatado.substr(3, 3) + '.'
               + cpfFormatado.substr(6, 3) + '-'
               + cpfFormatado.substr(9, 2)
  ;

  return cpfFormatado;
}

string Pessoa::getNome() { return this->nome; }
void Pessoa::setNome(string nome) { this->nome = nome; }

string Pessoa::getCpf() { return cpf; }
void Pessoa::setCpf(string cpf) {
  this->cpf = cpf;

  // Verificando se todos os digitos são iguais
  if (allDigitsAreEquals(this->cpf)) {
    this->cpfValido = false;
    return;
  }
  
  // Validação dos dois dígitos verificadores
  for (int i = 10; i < 12; i++) {
    if (! validaDigito(this->cpf, i, this->cpf[i - 1])) {
      this->cpfValido = false;
      return;
    } 
  }

  this->cpfValido = true;
}