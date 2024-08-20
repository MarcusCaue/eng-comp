#include <iostream>
#include <string>

using namespace std;

#include "./classes/Agenda/Agenda.hpp"
#include "./classes/Pessoa/Pessoa.hpp"

void printLine() {
   string linha = "---------------------------------------------";
   cout << linha << endl;
}

int main() {

   Agenda agendaRomana = Agenda(20);
   Agenda agendaPadrao = Agenda();

   cout << "-=-=-=-=-=-=-=-=-=-=-=- AGENDA PADRÃO -=-=-=-=-=-=-=-=-=-=-=-" << endl;
   agendaPadrao.armazenaPessoa(Pessoa("Padrao", 0, 0.00));
   agendaPadrao.armazenaPessoa("Padrao 2", 0, 0.0);
   agendaPadrao.imprimePovo();

   cout << "-=-=-=-=-=-=-=-=-=-=-=- AGENDA ROMANA -=-=-=-=-=-=-=-=-=-=-=-" << endl;

   agendaRomana.armazenaPessoa("Ovidius", 22, 1.78);
   agendaRomana.armazenaPessoa("Pyrrha", 2788, 1.96);
   agendaRomana.armazenaPessoa(Pessoa("Iulius Caesar", 20, 1.80));
   agendaRomana.armazenaPessoa("Aglaurus", 32, 1.65);
   agendaRomana.armazenaPessoa(Pessoa("Aeneis", 47, 1.71));
   agendaRomana.armazenaPessoa("Phaedrus", 18, 1.86);
   agendaRomana.armazenaPessoa("Publilius", 15, 1.72);
   agendaRomana.armazenaPessoa(Pessoa("Constantinus", 10, 1.40));
   agendaRomana.armazenaPessoa("Marcus Aurelius", 57, 1.63);
   agendaRomana.armazenaPessoa(Pessoa("Augustinus", 40, 1.78));

   // Agora é possível adicionar Horácio
   Pessoa horatius = Pessoa("Horatius", 31, 1.85);
   agendaRomana.armazenaPessoa(horatius);

   agendaRomana.imprimePovo();

   printLine();

   // Buscando uma pessoa presente na agenda
   int posicao = agendaRomana.buscaPessoa("Augustinus");
   if (posicao > 0)
      agendaRomana.imprimePessoa(posicao);

   // Buscando uma pessoa ausente na agenda
   posicao = agendaRomana.buscaPessoa("Gaius");
   if (posicao > 0)
      agendaRomana.imprimePessoa(posicao);
   else
      cout << "Este contato não está presente na agenda" << endl;
   printLine();

   // Removendo pessoa presente na agenda
   agendaRomana.removePessoa("Pyrrha");
   agendaRomana.imprimePovo();

   printLine();

   // Removendo pessoa ausente na agenda
   agendaRomana.removePessoa("Gaius");
   printLine();

   agendaRomana.imprimePovo();

   printLine();

   return 0;
}