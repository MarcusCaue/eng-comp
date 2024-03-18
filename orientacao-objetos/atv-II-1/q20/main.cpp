#include <iostream>
#include "Data.hpp"

using std::cout;
using std::endl;

int main() {
  // Inicialização
  Data d1 = { 7, 9, 2003 };
  Data d2 = { 12, -56, 2012 }; // Fazendo a correção automática do mês
  Data d3 = { 30, 21, 2023 }; // Fazendo a correção automática do mês

  // Mostrando as datas
  d1.mostrarData();
  d2.mostrarData();
  d3.mostrarData();

  // Modificando as datas com set
  d1.setDia(22); 
  d1.setMes(78); 
  d1.setAno(2021);

  d2.setDia(19); 
  d2.setMes(3); 
  d2.setAno(2024);
  
  // Recuperando as datas com get
  cout << "\n========= NOVAS DATAS =========\n\n";
  cout << d1.getDia() << "/" << d1.getMes() << "/" << d1.getAno() << endl;
  cout << d2.getDia() << "/" << d2.getMes() << "/" << d2.getAno() << endl;
  cout << d3.getDia() << "/" << d3.getMes() << "/" << d3.getAno() << endl;

  return 0;
}