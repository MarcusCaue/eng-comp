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

class Cliente : public PessoaFisica {

  friend ostream& operator<<(ostream& cout, const Cliente& p) {
    cout << "========= INFORMAÇÕES DO CLIENTE =========" << endl;
    cout << " - Nome: " << p.getNome() << endl;
    cout << " - CPF: " << p.getCpf() << endl;
    cout << " - Telefone: " << p.getTelefone() << endl;
    cout << " - Endereço: " << p.getEndereco() << endl;
    
    return cout;
  } 

private:
  string endereco;
  string tel;

public:
  Cliente() : PessoaFisica(), endereco(""), tel("") {}
  Cliente(string nome, string cpf, string end, string tel) :
    PessoaFisica(nome, cpf), endereco(end), tel(tel) {}

  string getEndereco() const { return this->endereco; }
  void setEndereco(string endereco) { this->endereco = endereco; }

  string getTelefone() const { return this->tel; }
  void setTelefone(string tel) { this->tel = tel; }

};

class Funcionario : public PessoaFisica {

  friend ostream& operator<<(ostream& cout, const Funcionario& f) {
    cout << "============ DADOS DO FUNCIONÁRIO ============" << endl;
    cout << "Nome: " << f.getNome() << endl;
    cout << "Matrícula: " << f.getMatricula() << endl;
    cout << "CPF: " << f.getCpf() << endl;
    printf("Salário base: R$%.2f\n", f.getSalarioBase());
    printf("Salário bruto: R$%.2f\n", f.calculaSalarioBruto());
    cout << "Carga horária mensal: " << f.getJornadaMensal() << endl;
    cout << "Quant. de horas trabalhadas no mês: " << f.getHorasTrabalhadas() << endl << endl;
    return cout;
  }

private:
  string matricula;
  double salarioBase;
  unsigned int jornadaMensal;
  unsigned int qHorasMes;

public:
  Funcionario(
    string nome = "", string cpf = "", string matricula = "",
    double salarioBase = 0.0, int jornadaMensal = 0, int qHorasMes = 0
  ) : 
    PessoaFisica(nome, cpf), matricula(matricula), salarioBase(salarioBase),
    jornadaMensal(jornadaMensal), qHorasMes(qHorasMes)
  {
    setHorasTrabalhadas(qHorasMes);
  }

  double calculaSalarioBruto() const { 
    if (this->jornadaMensal <= 0)
        return 0.0;

    double horas = (double) this->qHorasMes;
    double jornada = (double) this->jornadaMensal;

    return (this->salarioBase * (horas / jornada)); 
  }

  string getMatricula() const { return this->matricula; }
  void setMatricula(string matricula) { this->matricula = matricula; }

  double getSalarioBase() const { return this->salarioBase; }
  void setSalarioBase(double salarioBase) { this->salarioBase = salarioBase; }

  unsigned int getJornadaMensal() const { return this->jornadaMensal; }
  void setJornadaMensal(int jornadaMensal) { this->jornadaMensal = jornadaMensal; }

  unsigned int getHorasTrabalhadas() const { return this->qHorasMes; }
  void setHorasTrabalhadas(int horas) { 
    this->qHorasMes = (horas < 0 || horas > this->jornadaMensal) ? this->qHorasMes : horas;
  }

};

#endif