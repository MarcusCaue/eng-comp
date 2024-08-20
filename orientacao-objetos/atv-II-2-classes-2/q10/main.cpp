#include "Time.hpp"
#include <iostream>

int main() {

  Time t1 = Time();
  std::cout << "Hora padrão (AM/PM): "; t1.printStandard();
  std::cout << "Hora universal (24h): "; t1.printUniversal();
  
  return 0;
}