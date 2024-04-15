// #include "classes/Bruxo/Bruxo.hpp"
// #include "classes/Capa/CapaBruxo.hpp"
// #include "classes/Varinha/Varinha.hpp"
// #include <iostream>

// int main() {
//   // Novo Aluno na escola sem atributos definidos
//   cout << "\n<<< ====== NOVO ALUNO ====== >>>\n";
//   Bruxo novoAluno = Bruxo("Jonas");
//   novoAluno.display();
//   novoAluno.lancarFeitico();

//   // Dados de um aluno com atributos definidos
//   cout << "\n<<< ====== ALUNO MATRICULADO ====== >>>\n";
//   Varinha varinha = Varinha("Carvalho", "Mel de Abelha", 21.4);
//   CapaBruxo capa = CapaBruxo("Grifinoria", 1.70);
//   Bruxo alunoExistente = Bruxo("Ricardo", "Grifinoria", "Pyrus", &varinha, &capa);
//   alunoExistente.display();

//   // Setando novos valores para o aluno novato
//   Varinha varinhaNovato = Varinha("Abeto", "Lagrima de Boi", 19.3);
//   CapaBruxo capaCorvinal = CapaBruxo("Corvinal", 1.5);
//   CapaBruxo capaLufana = CapaBruxo("Lufa-Lufa", 1.5);

//   novoAluno.setCasa("Organistas"); // Tentando setar uma casa inválida
//   novoAluno.setCasa("Lufa-Lufa");

//   novoAluno.setFeitico("Fiat Musicam!");

//   novoAluno.setVarinha(&varinhaNovato);

//   novoAluno.setCapa(&capaCorvinal); // A casa da capa não é a mesma que a do aluno
//   novoAluno.setCapa(&capaLufana);

//   cout << "\n<<< ====== ALUNO NOVATO ====== >>>\n";
//   novoAluno.display();
//   novoAluno.lancarFeitico();

//   return 0;
// }