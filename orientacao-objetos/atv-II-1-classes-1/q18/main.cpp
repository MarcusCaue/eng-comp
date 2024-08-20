#include <iostream>
#include "Bruxo.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

  string nome, casa, feitico;
  
  cout << "Nome do aluno: ";
  cin >> nome;

  cout << "Casa selecionada: ";
  cin >> casa;

  cout << "Feitiço favorito: ";
  cin >> feitico;
  
  // Inicialização
  Bruxo aluno = { nome, casa, feitico };

  // Exibindo informações com o método display()
  aluno.display();
  printf("\n");  
  
  // Lançando feitiço
  aluno.lancarFeitico();
  
  // Alterando os atributos com set()
  aluno.setNome("Virgilius");
  aluno.setFeitico("Destrue Troiam");
  aluno.setCasa("Grifinória");
  
  // Exibindo informações com métodos get()
  cout << "\n===== NOVAS INFORMAÇÕES ===== \n";
  cout << "Nome: " << aluno.getNome() << endl;
  cout << "Casa: " << aluno.getCasa() << endl;
  cout << "Feitiço: " << aluno.getFeitico() << endl;

  return 0;
}

