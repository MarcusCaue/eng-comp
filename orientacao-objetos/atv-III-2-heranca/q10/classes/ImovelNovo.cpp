#include "./ImoveisHeaders.hpp"

double ImovelNovo::getAdicionalPreco() const { return this->adicionalPreco; }
void ImovelNovo::setAdicionalPreco(double adicional) { this->adicionalPreco = adicional; }

double ImovelNovo::getPreco() const {
  double precoFinal = this->preco + (this->preco * (adicionalPreco / 100));
  return precoFinal;
}