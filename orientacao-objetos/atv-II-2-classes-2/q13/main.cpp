#include <iostream>
#include "HugeInteger.hpp"
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
  string num;
  
  HugeInteger hi = {};
  cout << "Digite o primeiro numero: ";
  cin >> num;

  // Adicionando os valores
  hi.input(num);

  HugeInteger ohi = {};
  cout << "Digite o segundo numero: ";
  cin >> num;

  // Adicionando os valores
  ohi.input(num);

  // Exibindo os números
  cout << "\nPrimeiro: ";
  hi.output();
  cout << "\nSegundo: ";
  ohi.output();

  // Somando os números
  hi.add(ohi);
  cout << "\n\nhi = hi + ohi = ";
  hi.output();

  // Comparações
  string copyHi = hi.copyDigits();
  string copyOhi = ohi.copyDigits();

  const char *hiCstr = copyHi.c_str();
  const char *ohiCstr = copyOhi.c_str();

  printf("\n\nhi(%s) == ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isEqualTo(ohi));
  printf("hi(%s) != ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isNotEqualTo(ohi));
  printf("hi(%s) >  ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isGreaterThan(ohi));
  printf("hi(%s) >= ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isGreaterThanOrIqual(ohi));
  printf("hi(%s) <  ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isLessThan(ohi));
  printf("hi(%s) <= ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isLessThanOrIqual(ohi));
  
  return 0;
}
