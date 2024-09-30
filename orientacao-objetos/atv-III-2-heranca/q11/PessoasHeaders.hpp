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

class PessoaJuridica : public Pessoa {

private:
  string cnpj;
  string razaoSocial;

public:
  PessoaJuridica() : Pessoa(""), cnpj(""), razaoSocial("") {}
  PessoaJuridica(string nomeFantasia, string cnpj, string razaoSocial) : 
    Pessoa(nomeFantasia), cnpj(cnpj), razaoSocial(razaoSocial) {}

  string getCnpj() const { return this->cnpj; }
  void setCnpj(string cnpj) { this->cnpj = cnpj; }

  string getRazaoSocial() const { return this->razaoSocial; }
  void setRazaoSocial(string razaoSocial) { this->razaoSocial = razaoSocial; }

};

#endif