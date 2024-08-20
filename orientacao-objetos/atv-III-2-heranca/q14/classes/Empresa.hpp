#ifndef EMPRESA
#define EMPRESA

#include "./PessoasHeaders.hpp"

class Empresa : public PessoaJuridica {

   friend ostream& operator<<(ostream& cout, const Empresa& e);

private:
   Funcionario* funcionarios;
   Cliente* clientes;
   int qMaxFunc;
   int qFuncs;
   int qMaxClient;
   int qClients;

public:
   Empresa(
      string nomeFantasia = "", string cnpj = "", string razaoSocial = "",
      int qMaxFunc = 5, int qMaxClient = 20
   ) :
      PessoaJuridica(nomeFantasia, cnpj, razaoSocial), 
      qMaxFunc(qMaxFunc), qMaxClient(qMaxClient),
      qFuncs(0), qClients(0)
   {
      this->funcionarios = new Funcionario[this->qMaxFunc];
      this->clientes = new Cliente[this->qMaxClient];
   }

   ~Empresa() {
      delete [] this->funcionarios, this->clientes;
   }

   void insertClient(const Cliente& c);
   void insertFunc(const Funcionario& f);

   void removeClient(string cpf);
   void removeFunc(string cpf);
   void popClient();
   void popFunc();

   int findClient(string cpf);
   int findFunc(string cpf);

   void showClients() const;
   void showFuncs() const;

   double calcularFolhaDePagamento() const;
   
};

#endif