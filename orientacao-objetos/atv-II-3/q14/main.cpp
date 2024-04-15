// #include <iostream>
// #include <string>

// using namespace std;

// #include "./classes/Agenda/Agenda.hpp"
// #include "./classes/Pessoa/Pessoa.hpp"

// void printLine() {
//   string linha = "---------------------------------------------";
//   cout << linha << endl;
// }

// int main () {
//   printLine();
  
//   Agenda A;

//   A.armazenaPessoa("Ovidius", 22, 1.78);
//   A.armazenaPessoa("Pyrrha", 2788, 1.96);
//   A.armazenaPessoa(Pessoa("Iulius Caesar", 20, 1.80));
//   A.armazenaPessoa("Aglaurus", 32, 1.65);
//   A.armazenaPessoa(Pessoa("Aeneis", 47, 1.71));
//   A.armazenaPessoa("Phaedrus", 18, 1.86);
//   A.armazenaPessoa("Publilius", 15, 1.72);
//   A.armazenaPessoa(Pessoa("Constantinus", 10, 1.40));
//   A.armazenaPessoa("Marcus Aurelius", 57, 1.63);
//   A.armazenaPessoa(Pessoa("Augustinus", 40, 1.78));
  
//   A.imprimePovo();
//   printLine();

//   // Tentando adicionar uma pessoa com a agenda cheia
//   Pessoa horatius = Pessoa("Horatius", 31, 1.85);
//   A.armazenaPessoa(horatius);

//   cout << endl;
  
//   // Buscando uma pessoa presente na agenda
//   int posicao = A.buscaPessoa("Augustinus");
//   if (posicao > 0)
//       A.imprimePessoa(posicao);

//   // Buscando uma pessoa ausente na agenda
//   posicao = A.buscaPessoa(horatius.getNome());
//   if (posicao > 0)
//       A.imprimePessoa(posicao);
//   else
//     cout << "Este contato não está presente na agenda" << endl;
//   printLine();

//   // Removendo pessoa presente na agenda
//   A.removePessoa("Pyrrha");
//   A.imprimePovo();

//   printLine();

//   // Removendo pessoa ausente na agenda
//   A.removePessoa("Horatius");
//   printLine();

//   A.imprimePovo();
  
//   printLine();

//   return 0;
// }