#include <iostream>
#include "./Array/Array.hpp"

using std::cout, std::endl, std::cin;

int main() 
{
  Array a(5), b(3), d(3);

  cout << "Valores para a: ";
  cin >> a;

  cout << "Valores para b: ";
  cin >> b;

  cout << endl << "Dados em a: " << a;
  cout << "Dados em b: " << b;

  Array c = a + b;
  cout << "Dados em c: " << c;
  
  cout << endl << "Valores para d: ";
  cin >> d;

  c += d;
  cout << endl << "Dados em d: " << d;
  cout << "Dados em c (depois do incremento): " << c;

  cout << endl << "=============== ESTADOS DAS LISTAS ================" << endl;
  cout << "A: " << a;
  cout << "B: " << b;
  cout << "C: " << c;
  cout << "D: " << d << endl;

  return 0;
}