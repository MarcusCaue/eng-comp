#ifndef IMOVEIS_HEADERS
#define IMOVEIS_HEADERS

#include <iostream>
#include <string>

using namespace std;

class Imovel {

protected:
  string endereco;
  double preco;

public:
  Imovel() {}
  Imovel(string end, double preco) : endereco(end), preco(preco) {}

  string getEndereco() const;
  void setEndereco(string end);

  double getPreco() const;
  void setPreco(double preco);

};

// As adições e descontos são em forma de porcentagem
class ImovelNovo : public Imovel {

private:
  double adicionalPreco;

public:
  ImovelNovo() {}
  ImovelNovo(string end, double preco, double adicionalPreco) : 
    Imovel(end, preco), adicionalPreco(adicionalPreco) {}

  double getAdicionalPreco() const;
  void setAdicionalPreco(double adicional);

  double getPreco() const;

};

class ImovelVelho : public Imovel {

private:
  double desconto;

public:
  ImovelVelho() {}
  ImovelVelho(string end, double preco, double desconto) : 
    Imovel(end, preco), desconto(desconto) {}

  double getDesconto() const;
  void setDesconto(double desconto);

  double getPreco() const;

};

#endif