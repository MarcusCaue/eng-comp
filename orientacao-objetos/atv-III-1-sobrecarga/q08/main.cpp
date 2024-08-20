#include <iostream>
#include "./Complex/Complex.hpp"

using namespace std;

int main() {

   Complex numPadrao;
   Complex n1 = Complex(2, 7);

   cout << "Número complexo padrão: " << numPadrao << endl;
   cout << "Número complexo n1: " << n1 << endl << endl;

   numPadrao = Complex(5, 5) + n1;
   n1 += n1; 

   cout << "======= PRIMEIRAS ALTERAÇÕES =======" << endl;
   cout << "Número complexo padrão: " << numPadrao << endl;
   cout << "Número complexo n1: " << n1 << endl << endl;

   cout << "======= COM OPERADORES DE INCREMENTO E DECREMENTO =======" << endl;
   cout << "Número complexo padrão (pós-incrementado): " << numPadrao++ << endl;
   cout << "Número complexo padrão (pré-incrementado): " << ++numPadrao << endl;
   cout << "Número complexo n1 (pós-decrementado): " << n1-- << endl;
   cout << "Número complexo n1 (pré-decrementado): " << --n1 << endl << endl;

   numPadrao = Complex(10, 8) - n1;
   n1 -= n1;

   cout << "======= APÓS A ÚLTIMAS ALTERAÇÕES =======" << endl;
   cout << "Número complexo padrão: " << numPadrao << endl;
   cout << "Número complexo n1: " << n1 << endl;

   return 0;
}