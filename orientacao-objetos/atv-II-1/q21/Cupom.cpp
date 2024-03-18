#include <iostream>
#include "Cupom.hpp"

using std::cout;
using std::cin;
using std::endl;

Cupom::Cupom(string id, int quant, float preco, string desc) {
  this->id = id;
  this->descricao = desc;
  setQuant(quant);
  setPreco(preco);
}

float Cupom::calculaCupom() {
  return static_cast<float>(this->quant) * this->preco;
}

void Cupom::display() {
  cout << "\n===== ATRIBUTOS DO CUPOM =====\n";
  cout << "ID: " << this->id << endl;
  cout << "Descrição: " << this->descricao << endl;
  cout << "Quantidade: " << this->quant << endl;
  printf("Preço: %.2f\n", this->preco);
}

string Cupom::getId() { return this->id; }
void Cupom::setId(string id) { this->id = id; }

int Cupom::getQuant(){ return this->quant; }
void Cupom::setQuant(int quant){ 
  this->quant = (quant <= 0) ? 0 : quant;
}

float Cupom::getPreco(){ return this->preco; }
void Cupom::setPreco(float preco){
  this->preco = (preco <= 0.0f) ? 0.0f : preco;
}

string Cupom::getDescricao(){ return this->descricao; }
void Cupom::setDescricao(string desc){ this->descricao = desc; }
