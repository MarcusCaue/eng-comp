#ifndef AGENDA_HPP
#define AGENDA_HPP

#include "../Pessoa/Pessoa.hpp"

class Agenda {

private:
   Pessoa pessoas[10];
   int qtdePessoas;

public:
   Agenda();

   void armazenaPessoa(const string &nome, int idade, float altura);
   void armazenaPessoa(const Pessoa &p);

   void removePessoa(const string &nome);

   // informa em que posição da agenda está a pessoa
   int buscaPessoa(const string &nome) const;

   // imprime todos os dados de todas as pessoas da agenda
   void imprimePovo() const;

   // imprime os dados da pessoa que está na posição 'i' da agenda
   void imprimePessoa(int i) const;
};

#endif