#include "./classes/Headers.hpp"
#include <iostream>

using namespace std;

int main() {
   
   Humano pessoa = Humano("Clayton");
   Bruxo bruxo = Bruxo("Welton", "Lufa-lufa", "Lumentrix");
   Trouxa rikelme = Trouxa("Rikelme", "Faxineiro");

   cout << "Pessoa comum: " << endl;
   cout << "    - Nome: " << pessoa.getNome() << endl << endl;

   cout << "Bruxo: " << endl;
   cout << "    - Nome: " << bruxo.getNome() << endl;
   cout << "    - Casa: " << bruxo.getCasa() << endl;
   cout << "    - Feitiço predileto: " << bruxo.getFeitico() << endl << endl;
   bruxo.lancarFeitico();

   cout << endl << "Trouxa: " << endl;
   cout << "    - Nome: " << rikelme.getNome() << endl;
   cout << "    - Profissão: " << rikelme.getProf() << endl << endl;
   rikelme.trabalhar();
   
   return 0;
}