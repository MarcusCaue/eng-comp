#include <iostream>
#include <string>
#include "Time.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void passarMostrarTempo(int secs, Time &timer, string message) {
  cout << endl << message << endl;
  for (int i = 0; i < secs; i++)
    timer.tick();
  timer.printUniversal();
}

int main() {

  cout << "Hora atual: ";
  
  Time t1 = { 10, 19, 20 };
  t1.printUniversal();

  // Passando 30s
  passarMostrarTempo(30, t1, "Contando 30 segundos...");
  // Passando 1min
  passarMostrarTempo(60, t1, "Contando 1 minuto...");
  // Passando 1 hora
  passarMostrarTempo(3600, t1, "Contando 1 hora...");

  /* Casos especiais */
  Time t2 = { 11, 50, 59 };

  // Mudando minuto
  passarMostrarTempo(1, t2, "Contando 1 segundo...");
  // Mudando hora
  t2.setTime(11, 59, 59);
  passarMostrarTempo(1, t2, "Contando 1 segundo...");
  // Mudando o dia
  t2.setTime(23, 59, 59);
  passarMostrarTempo(1, t2, "Contando 1 segundo...");
  
  return 0;
}
