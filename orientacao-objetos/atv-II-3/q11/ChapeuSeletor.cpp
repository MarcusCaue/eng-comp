#include "ChapeuSeletor.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

void ChapeuSeletor::recepcionar() {
   cout << "Não há nada escondido em sua cabeça que o Chapéu Seletor não consiga ver, por isso é só me porem na cabeça que vou dizer em que casa de Hogwarts deverão ficar." << endl << endl;
}

string ChapeuSeletor::sortearCasa() {
   unsigned int semente = time(0);
   srand(semente);

   string casas[] = {"Lufa-Lufa", "Corvinal", "Grifinória", "Sonserina"};

   int numSorteado = rand() % 4;
   string casaSorteada = casas[numSorteado];

   return casaSorteada;
}

void ChapeuSeletor::avaliarCasa(string& casa) {
   if (casa == "Lufa-Lufa")
      cout << " (simplesmente a melhor casa de Hogwarts)" << endl;
   else if (casa == "Sonserina")
      cout << " (vixe... vai ser do mal)" << endl;
   else if (casa == "Grifinória")
      cout << " (bravo! Sede valente e lute pela justiça)" << endl;
   else
      cout << " (hmmm... Sabedoria é importante, mas cuidado para não corromper-se...)" << endl;
}