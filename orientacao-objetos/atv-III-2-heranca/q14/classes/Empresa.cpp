#include "./Empresa.hpp"

ostream& operator<<(ostream& cout, const Empresa& e) {
      cout << "================= DADOS DA EMPRESA =================" << endl;
      cout << "- Nome fantasia: " << e.getNome() << endl;
      cout << "- Razão Social: " << e.getRazaoSocial() << endl;
      cout << "- CNPJ: " << e.getCnpj() << endl;

      cout << "- Funcionários: " << endl;
      if (e.qFuncs <= 0) {
         cout << "    - (Essa empresa não tem funcionários)";
      }
      else {
         for (int i = 0; i < e.qFuncs; i++) {
            Funcionario& f = e.funcionarios[i];
            printf("    - %s (%s) - R$%.2f\n", f.getNome().c_str(), f.getMatricula().c_str(), f.calculaSalarioBruto());
         }
      }

      cout << endl << "- Clientes: " << endl;
      if (e.qClients <= 0) {
         cout << "    - (Essa empresa não tem clientes)";
      }
      else {
         for (int i = 0; i < e.qClients; i++) {
            Cliente& c = e.clientes[i];
            printf("    - %s - %s\n", c.getNome().c_str(), c.getCpf().c_str());
         }
      }
      cout << endl;

      return cout;
}

void Empresa::insertClient(const Cliente& c) {
   if (this->qClients >= this->qMaxClient)
      return;
  
  this->clientes[this->qClients++] = c;
}

void Empresa::insertFunc(const Funcionario& f) {
   if (this->qFuncs >= this->qMaxFunc)
      return;
  
  this->funcionarios[this->qFuncs++] = f;
}

void Empresa::popClient() {
   if (this->qClients <= 0)
      return;

  this->qClients--;
}

void Empresa::popFunc() {
   if (this->qFuncs <= 0)
      return;

  this->qFuncs--;
}

int Empresa::findClient(string cpf) {
   for (int i = 0 ; i < this->qClients ; i++) {
      Cliente& c = this->clientes[i];
      if (c.getCpf() == cpf)
         return i;
   }

   return -1;
}

int Empresa::findFunc(string cpf) {
   for (int i = 0 ; i < this->qFuncs ; i++) {
      Funcionario& f = this->funcionarios[i];
      if (f.getCpf() == cpf)
         return i;
   }

   return -1;
}

void Empresa::removeClient(string cpf) {
   int index = findClient(cpf);

   if (index <= -1)
      return;

   for (int i = index; i < this->qClients - 1; i++)
      this->clientes[i] = this->clientes[i+1];
   
   this->qClients--;
}

void Empresa::removeFunc(string cpf) {
   int index = findFunc(cpf);

   if (index <= -1)
      return;

   for (int i = index; i < this->qFuncs - 1; i++)
      this->funcionarios[i] = this->funcionarios[i+1];
   
   this->qFuncs--;
}

void Empresa::showClients() const {
   cout << "=============== DADOS DOS CLIENTES DA EMPRESA ===============" << endl;

   if (this->qClients <= 0) {
      cout << "A empresa não tem clientes ainda." << endl << endl;
      return;
   }
   
   for (int i = 0; i < this->qClients; i++) {
      Cliente& c = this->clientes[i];
      cout << "- " << i+1 << "º Cliente: " << endl;
      cout << "    - Nome: " << c.getNome() << endl;
      cout << "    - CPF: " << c.getCpf() << endl;
      cout << "    - Telefone: " << c.getTelefone() << endl;
      cout << "    - Endereço: " << c.getEndereco() << endl << endl;
   }
}

void Empresa::showFuncs() const {
   cout << "=============== DADOS DOS FUNCIONÁRIOS DA EMPRESA ===============" << endl;

   if (this->qFuncs <= 0) {
      cout << "A empresa não tem funcionários ainda." << endl << endl;
      return;
   }
   
   for (int i = 0; i < this->qFuncs; i++) {
      Funcionario& f = this->funcionarios[i];
      cout << "- " << i+1 << "º Funcionário: " << endl;
      cout << "    - Nome: " << f.getNome() << endl;
      cout << "    - Matrícula: " << f.getMatricula() << endl;
      cout << "    - CPF: " << f.getCpf() << endl;
      printf( "    - Salário base: R$%.2f\n", f.getSalarioBase());
      printf( "    - Salário bruto: R$%.2f\n", f.calculaSalarioBruto());
      cout << "    - Carga horária mensal: " << f.getJornadaMensal() << endl;
      cout << "    - Quant. de horas trabalhadas no mês: " << f.getHorasTrabalhadas() << endl << endl;
   }
}

double Empresa::calcularFolhaDePagamento() const {
   double total = 0.0;

   for (int i = 0; i < this->qFuncs; i++)
      total += this->funcionarios[i].calculaSalarioBruto();

   return total;
}
