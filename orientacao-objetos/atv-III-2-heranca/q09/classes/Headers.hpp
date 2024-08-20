#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <string>
#include <iostream>
using namespace std;

class Humano {

protected:
   string nome;

public:
   Humano() {};
   Humano(string nome) : nome(nome) {};

   string getNome() const { return this->nome; }
   void setNome(string nome) { this->nome = nome; }

};

class Trouxa : public Humano {

private:
   string profissao;

public:
   Trouxa() {}
   Trouxa(string nome) : Humano(nome) {}
   Trouxa(string nome, string profissao) : Humano(nome), profissao(profissao) {}

   string getProf() const { return this->profissao; }
   void setProf(string profissao) { this->profissao = profissao; }

   void trabalhar() const { cout << "Trabalhando... trabalhando..." << endl; }

};

class Bruxo : public Humano {

private:
  string casa;
  string feiticoPredileto;

public:
  Bruxo();
  Bruxo(string, string, string);

  void lancarFeitico() const;
  void display() const;

  string getCasa() const;
  void setCasa(string);

  string getFeitico() const;
  void setFeitico(string);

};

#endif