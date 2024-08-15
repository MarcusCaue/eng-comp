#include "./HugeInteger/HugeInteger.hpp"
#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

string boolToStr(bool value) { return value ? "true" : "false"; }

int main() {
   string num;
   
   // Adicionando os valores
   HugeInteger hi, ohi;

   cout << "Digite o primeiro numero: ";
   cin >> num;
   hi = num;

   cout << "Digite o segundo numero: ";
   cin >> num;
   ohi = num;

   // Exibindo os números
   cout << endl << "Primeiro: " << hi << endl;
   cout << "Segundo: " << ohi << endl;

   // Somando os números
   HugeInteger soma1;
   soma1 = hi + ohi;
   cout << endl << "soma1 = hi + ohi => " << soma1 << endl;
   
   soma1 += hi;
   cout << "soma1 = soma1 + hi => " << soma1 << endl;

   // Comparações
   cout << endl << "hi(" << hi << ") == ohi(" << ohi << ") ----> " << boolToStr(hi == ohi) << endl;
   cout << "hi(" << hi << ") != ohi(" << ohi << ") ----> " << boolToStr(hi != ohi) << endl;
   cout << "hi(" << hi << ") > ohi(" << ohi << ") ----> " << boolToStr(hi > ohi) << endl;
   cout << "hi(" << hi << ") < ohi(" << ohi << ") ----> " << boolToStr(hi < ohi) << endl;
   cout << "hi(" << hi << ") >= ohi(" << ohi << ") ----> " << boolToStr(hi >= ohi) << endl;
   cout << "hi(" << hi << ") <= ohi(" << ohi << ") ----> " << boolToStr(hi <= ohi) << endl;

   return 0;
}  