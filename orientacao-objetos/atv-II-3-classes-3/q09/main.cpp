#include "CapaBruxo.hpp"

int main() {

  // Capa válida
  CapaBruxo *capaCaue = new CapaBruxo(1.75, "Lufa-Lufa");
  capaCaue->display();

  // Inválida no tamanho e na casa
  CapaBruxo *capaInvalida = new CapaBruxo(1.0, "Lepurianos");

  cout << "====== CAPA DE BRUXO ======" << endl;
  printf("Tamanho: %.1fm\n", capaInvalida->getTam());
  cout << "Cor: " << capaInvalida->getCor() << endl;
  cout << "Casa: " << capaInvalida->getCasa() << endl << endl;

  // Capa criada pelo usuário
  string casa; 
  double tam;

  cout << "A qual casa tu pertences? "; cin >> casa;
  cout << "Qual é o seu tamanho (em metros)? "; cin >> tam;
  cout << endl;

  CapaBruxo capaUsuario = CapaBruxo(tam, casa);
  capaUsuario.display();

  delete capaCaue, capaInvalida; 

  return 0;
}