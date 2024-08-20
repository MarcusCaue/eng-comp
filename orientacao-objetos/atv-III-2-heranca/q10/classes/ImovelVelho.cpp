#include "./ImoveisHeaders.hpp"

double ImovelVelho::getDesconto() const { return this->desconto; }
void ImovelVelho::setDesconto(double adicional) { this->desconto = adicional; }

double ImovelVelho::getPreco() const {
  double precoFinal = this->preco - (this->preco * (desconto/100));
  return precoFinal;
}
