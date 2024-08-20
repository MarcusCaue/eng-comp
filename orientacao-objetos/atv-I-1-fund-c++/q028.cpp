// Questão 28 => Verifica se tem letra maiúscula

#include <iostream>

using std::cout, std::cin;

bool containsUpper(char str[]) 
{
   bool contains = false;

   for (int i = 0; str[i] != '\0'; i++) {
      int asciiCode = str[i];

      // Intervalo das letras maiúsculas
      if (asciiCode > 64 && asciiCode < 91) {
         contains = true;
         break;
      }
   }

   return contains;
}

int main() {

   char texto[200] = {'\0'};

   cout << "Escreva uma string qualquer: ";
   cin.getline(texto, 200);

   bool response = containsUpper(texto);

   if (response) {
      cout << "\nA string informada CONTEM uma letra maiuscula em codificacao ASCII\n";
   } else {
      cout << "\nA string informada NAO CONTEM uma letra maiuscula em codificacao ASCII\n";
   }
   
   return 0;
}