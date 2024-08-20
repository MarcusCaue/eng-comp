#include "./ImoveisHeaders.hpp"

#include <iostream>
#include <string>

using namespace std;

string Imovel::getEndereco() const { return this->endereco; }
void Imovel::setEndereco(string end) { this->endereco = end; }

double Imovel::getPreco() const { return this->preco; }
void Imovel::setPreco(double preco) { this->preco = preco; }
