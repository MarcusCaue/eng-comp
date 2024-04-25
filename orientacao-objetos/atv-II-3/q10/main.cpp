#include <iostream>
#include "classes/Bruxo/Bruxo.hpp"

int main() {
  // Novo Aluno na escola sem atributos definidos
  cout << "\n<<< ====== NOVO ALUNO ====== >>>\n";
  Bruxo novoAluno = Bruxo("Jonas");
  novoAluno.display();
  novoAluno.lancarFeitico();

  // Dados de um aluno com atributos definidos
  cout << "\n<<< ====== ALUNO MATRICULADO ====== >>>\n";
  Varinha varinha = Varinha("Carvalho", "Mel de Abelha", 21.4);
  CapaBruxo capa = CapaBruxo("Grifinória", 1.70);
  Bruxo aluno = Bruxo("Ricardo", "Grifinória", "Pyrus", varinha, capa);
  aluno.display();
  aluno.lancarFeitico();

  // Setando novos valores para o aluno novato
  Varinha varinhaNovato =  Varinha("Abeto", "Lágrima de Boi", 19.3);
  CapaBruxo capaCorvinal = CapaBruxo("Corvinal", 1.5);
  CapaBruxo capaLufaLufa = CapaBruxo("Lufa-Lufa", 1.5);

  novoAluno.setCasa("Organistas"); // Tentando setar uma casa inválida
  novoAluno.setCasa("Corvinal");

  novoAluno.setFeitico("Fiat Musicam!");
  novoAluno.setVarinha(varinhaNovato);

  novoAluno.setCapa(capaLufaLufa); // A casa da capa não é a mesma que a do aluno
  novoAluno.setCapa(capaCorvinal); 

  cout << "\n<<< ====== NOVO ALUNO ====== >>>\n";
  novoAluno.display();
  novoAluno.lancarFeitico();

  return 0;
}