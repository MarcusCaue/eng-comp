#ifndef FUNCIONARIO
#define FUNCIONARIO

#include "./PessoasHeaders.hpp"

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