#include "./HugeInteger/HugeInteger.hpp"
#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

int main() {
  string num;
  
  // Adicionando os valores
  HugeInteger hi, ohi;

  cout << "Digite o primeiro numero: ";
  cin >> num;
  hi.input(num);

  cout << "Digite o segundo numero: ";
  cin >> num;
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
  printf("hi(%s) >= ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isGreaterThanOrEqual(ohi));
  printf("hi(%s) <  ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isLessThan(ohi));
  printf("hi(%s) <= ohi(%s) ----> %i\n", hiCstr, ohiCstr, hi.isLessThanOrEqual(ohi));
  
  return 0;
}
