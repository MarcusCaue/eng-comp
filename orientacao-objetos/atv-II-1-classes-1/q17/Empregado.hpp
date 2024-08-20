#ifndef EMPREGADO_HPP
#define EMPREGADO_HPP

#include <string>
using std::string;

class Empregado {
  private:
    string nome;
    string sobrenome;
    double salario;

  public:
    Empregado(string nome, string sobrenome, double salario);

    void showAllAttr();

    string getNome();
    void setNome(string nome);

    string getSobrenome();
    void setSobrenome(string sobrenome);

    double getSalario();
    void setSalario(double salario);
    
};

#endif