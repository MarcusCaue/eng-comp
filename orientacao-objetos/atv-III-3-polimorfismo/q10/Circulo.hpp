#ifndef CIRCULO_H
#define CIRCULO_H

#include "./FormaBidimensional.hpp"

#include <iostream>
using std::cout, std::endl;

class Circulo : public FormaBidimensional {
  public:
    Circulo() : FormaBidimensional(99999) {}

    virtual void desenhar() {
      cout << "  _ " << endl;
      cout << "/   \\" << endl;
      cout << "\\   /" << endl;
      cout << "  - " << endl;
    }
};

#endif