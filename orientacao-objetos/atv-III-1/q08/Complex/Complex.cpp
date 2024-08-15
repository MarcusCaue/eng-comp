#include "./Complex.hpp"
#include <iostream>

using namespace std;

Complex::Complex(double real, double imaginario) {
   this->real = real;
   this->imaginario = imaginario;
}

void Complex::show() const {
   printf("%.1lf + %.1lfi", this->real, this->imaginario);
}


ostream& operator<<(ostream& cout, const Complex& numComplex) {
   numComplex.show();
   return cout;
}

Complex Complex::operator+(const Complex& b) {
   Complex newNumber = *this;
   newNumber.real += b.real;
   newNumber.imaginario += b.imaginario;
   return newNumber;
}

Complex Complex::operator-(const Complex& b) {
   Complex newNumber = *this;
   newNumber.real -= b.real;
   newNumber.imaginario -= b.imaginario;
   return newNumber;
}

Complex Complex::operator+=(const Complex& b) {
   (*this) = (*this) + b;
   return *this;
}

Complex Complex::operator-=(const Complex& b) {
   (*this) = (*this) - b;
   return *this;
}

// Prefixo ++Complex
Complex Complex::operator++() {
   this->real++;
   return *this;
}

// Pos-fixo Complex++
Complex Complex::operator++(int posfix) {
   Complex oldValue = *this;
   this->real++;
   return oldValue;
}

// Prefixo --Complex
Complex Complex::operator--() {
   this->real--;
   return *this;
}

// Pos-fixo Complex--
Complex Complex::operator--(int posfix) {
   Complex oldValue = *this;
   this->real--;
   return oldValue;
}



