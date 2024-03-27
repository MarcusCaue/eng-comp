#include <iostream>
#include "ViraTempo.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
  ViraTempo vt = {5};

  vt.mostrarTempo(); 
  vt.avancarTempo(); 
  vt.mostrarTempo();
  vt.virarTempo(); 
  vt.avancarTempo(); 
  vt.mostrarTempo(); 
  vt.virarTempo();
  
  for (int i = 0; i < 6; i++) {
    vt.avancarTempo();
    vt.mostrarTempo();
  }
  
  vt.virarTempo(); // Decrementa

  for (int i = 0; i < 7; i++) {
    vt.avancarTempo(); 
    vt.mostrarTempo();
  }

  return 0;
}
