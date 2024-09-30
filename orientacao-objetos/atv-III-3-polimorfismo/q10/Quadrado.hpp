#ifndef QUADRADO_H
#define QUADRADO_H

#include "./FormaBidimensional.hpp"

#include <iostream>
using std::cout, std::endl;

class Quadrado : public FormaBidimensional {
  public:
    Quadrado() : FormaBidimensional(4) {}

    virtual void desenhar() {
      cout << "+---+" << endl;
      cout << "|   |" << endl;
      cout << "+---+" << endl;
    }
};

#endif