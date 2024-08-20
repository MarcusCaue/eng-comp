#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
using namespace std;

class Complex {
   
   friend ostream& operator<<(ostream& cout, const Complex& numComplex);

private:
   double real;
   double imaginario;

   void show() const;

public:
   Complex() : real(0), imaginario(0) {};
   Complex(double real, double imaginario);

   Complex operator+(const Complex &b);
   Complex operator-(const Complex &b);
   Complex operator+=(const Complex &b);
   Complex operator-=(const Complex &b);
   Complex operator++();
   Complex operator++(int);
   Complex operator--();
   Complex operator--(int);

};

#endif