#include <iostream>
#include "./ClassesHeaders.hpp"

using std::cout, std::endl;

Animal::Animal() : nome(""), raca("") {}
Animal::Animal(string nome) : nome(nome), raca("") {}

string Animal::caminha() const {
   string saida = "O animal chamado " + this->nome + ", da raça " + this->raca + " está caminhando solenemente por esse mundo maravilhoso criado por Nosso Senhor!\n";
   return saida;
}

string Animal::getNome() const { return this->nome; }
void Animal::setNome(string nome) { this->nome = nome; }

string Animal::getRaca() const { return this->raca; }
void Animal::setRaca(string raca) { this->raca = raca; }
