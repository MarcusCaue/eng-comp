#include <iostream>
#include "Retangulo.hpp"

using std::cout;
using std::cin;
using std::endl;

void showInfoRetangulo(Retangulo ret) {
  cout << "Retângulo " << ret.getLarg() << "mx" << ret.getAlt() << "m:\n\n";
  printf("Perímetro: %.1lfm\nÁrea: %.1lfm²\n", ret.perimetro(), ret.area());
}
void title(char *message) {
  cout << "\n======== " << message << " ========\n\n";
}

int main() {
  double larg, alt;
  
  cout << "Largura do retangulo: ";
  cin >> larg;
  cout << "Altura do retangulo: ";
  cin >> alt;

  // Definições
  Retangulo ret = { alt, larg };
  Retangulo retPad;
  Retangulo retInv = { 40.5, 80.25 };

  // Desenhos
  char message[] = "DESENHOS DOS RETÂNGULOS";
  title(message);
  
  showInfoRetangulo(ret);
  ret.desenho();
  cout << endl;

  showInfoRetangulo(retPad);
  retPad.desenho(); 
  cout << endl;

  showInfoRetangulo(retInv);
  retInv.desenho();
  cout << endl;
  
  return 0;
}