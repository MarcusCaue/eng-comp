#include "Varinha.hpp"

int main() {

  Varinha* v1 = new Varinha("Eucalipto", "Água do Rio Tigre", 23.5);
  v1->display();

  delete v1;
  
  return 0;
}