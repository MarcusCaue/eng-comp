// Questão 29 => Implementação do toLowerCase

#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

string toLower(char str[]) 
{
   string newString;

   for (int i = 0; str[i] != '\0'; i++) {
      int c = str[i];

      if (c > 64 && c < 91) {
         int cLower = c + 32;
         newString += cLower;
      } else {
         newString += c;
      }
   }

   return newString;
}

int main() {

   char texto[200] = {'\0'};
   cout << "Digite uma string: ";
   cin.getline(texto, 200);

   string newString = toLower(texto);

   cout << "\nString com todos os caracteres minusculos: " << newString << '\n';

   return 0;
}