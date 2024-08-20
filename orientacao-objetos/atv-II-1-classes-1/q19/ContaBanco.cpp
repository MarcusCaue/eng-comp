#include <iostream>
#include "ContaBanco.hpp"

ContaBanco::ContaBanco(double saldoInicial) {
  this->saldo = (saldoInicial >= 0.0) ? saldoInicial : 0.0;
}

void ContaBanco::creditar(double valor) {
  this->saldo += valor;
}

void ContaBanco::debitar(double valor) {
  if (valor > this->saldo) {
    std::cout << "ERRO!!!! NÃO SE PODE DEBITAR UM VALOR ACIMA DO VALOR DO SALDO\n";
  } else {
    this->saldo -= valor;
  }
}

double ContaBanco::getSaldo() {
  return this->saldo;
}