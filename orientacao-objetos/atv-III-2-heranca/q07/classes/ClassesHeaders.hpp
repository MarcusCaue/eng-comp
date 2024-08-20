#ifndef CLASSES_HEADERS_HPP
#define CLASSES_HEADERS_HPP

#include <string>
using std::string;

class Animal {

protected:
   string nome;
   string raca;

public:
   Animal();
   Animal(string nome);

   string caminha() const;

   string getNome() const;
   void setNome(string nome);
   
   string getRaca() const;
   void setRaca(string raca);
};

class Cachorro : public Animal {

public:
   string late() const;

};

class Gato : public Animal {

public:
   string mia() const;

};

#endif