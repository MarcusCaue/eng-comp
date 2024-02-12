// Questão 30 => "Removendo" characteres

#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

string removeSigns(string str) {

   string newString;

   for (int i = 0; str[i] != '\0'; i++) {
      int c = str[i];

      /**
       * 32 => ' '
       * 33 => '!'
       * 44 => ','
       * 46 => '.'
       * 58 => ':'
       * 59 => ';'
       * 63 => '?'
      */
      if (! (c == 32 || c == 33 || c == 44 || c == 46 || c == 58 || c == 59 || c == 63)) {
         newString += (char) c;
      }
   }

   return newString;

}

int main() {

   string texto;
   cout << "Escreva uma frase: ";
   getline(cin, texto);

   cout << "\nNova string sem os sinais de pontuacao e o espaco: " removeSigns(texto);

   return 0;
}