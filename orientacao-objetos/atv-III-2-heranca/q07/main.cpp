#include <iostream>
#include "./classes/ClassesHeaders.hpp"

using namespace std;

int main()
{
   Animal generico;
   cout << "Animal genérico, sem informações: " << endl;
   cout << "   - Nome: " << generico.getNome() << endl;
   cout << "   - Raça: " << generico.getRaca() << endl;

   Cachorro leopoldo;
   leopoldo.setNome("Leopoldo Alemão");
   leopoldo.setRaca("Pastor Alemão");

   cout << endl << "Dados do Cachorro: " << endl;
   cout << leopoldo.caminha();
   
   cout << leopoldo.getNome() << " agora vai latir ferozmente: " << leopoldo.late() << endl;

   Gato bichano;
   bichano.setNome("Bichano da Rua");
   bichano.setRaca("Siamês Nórdico");

   cout << endl << "Dados do Gato: " << endl;
   cout << bichano.caminha();
   
   cout << bichano.getNome() << " agora vai miar bem tranquilo: " << bichano.mia() << endl;   

   return 0;
}