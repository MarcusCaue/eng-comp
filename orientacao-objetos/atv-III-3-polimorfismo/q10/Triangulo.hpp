#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "./FormaBidimensional.hpp"

#include <iostream>
using std::cout, std::endl;

class Triangulo : public FormaBidimensional {
  public:
    Triangulo() : FormaBidimensional(3) {}

    virtual void desenhar() const {
      cout << "   .    " << endl;
      cout << "  / \\  " << endl;
      cout << " /   \\ " << endl;
      cout << "/_____\\" << endl;
    }

    virtual double calcularArea(double base, double altura) const { return (base * altura) / 2.0; }
};

#endif