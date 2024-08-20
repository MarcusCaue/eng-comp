#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

using namespace std;

class Pessoa {
private:
   string nome;
   int idade;
   float altura;

public:
   Pessoa();
   Pessoa(string, int, float);

   string getNome() const;
   int getIdade() const;
   float getAltura() const;

   void setIdade(int);
   void setAltura(float);
};

#endif