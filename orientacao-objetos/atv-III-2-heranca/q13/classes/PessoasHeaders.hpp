#ifndef PESSOAS_HEADERS
#define PESSOAS_HEADERS

#include <iostream>
#include <string>

using namespace std;

class Pessoa {

  friend ostream& operator<<(ostream& cout, const Pessoa& p) {
    cout << "O nome dessa pessoa é: " << p.getNome() << endl;
    return cout;
  }

protected:
  string nome;

public:
  Pessoa() : nome("") {}
  Pessoa(string nome) : nome(nome) {}

  string getNome() const { return this->nome; }
  void setNome(string nome) { this->nome = nome; }

};

class PessoaFisica : public Pessoa {

private:
  string cpf;

public:
  PessoaFisica() : Pessoa(""), cpf("") {}
  PessoaFisica(string nome, string cpf) : Pessoa(nome), cpf(cpf) {}

  string getCpf() const { return this->cpf; }
  void setCpf(string cpf) { this->cpf = cpf; }

};

#endif