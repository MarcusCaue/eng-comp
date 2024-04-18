#include "ArrayList.hpp"
#include <iostream>

using namespace std;

int main() {

  ArrayList list = ArrayList(10);

  list.add(2);
  list.add(7);
  list.add(9);
  list.add(8);

  cout << "Lista original: ";
  list.print();
  cout << endl;

  somaArray(list, 5);
  cout << "Lista com cada elemento sendo somado por 5: ";
  list.print();
  cout << endl;

  subArray(list, 6);
  cout << "Lista com cada elemento sendo subtraído por 6: ";
  list.print();
  cout << endl;

  mulArray(list, 12);
  cout << "Lista com cada elemento sendo multiplicado por 12: ";
  list.print();
  cout << endl;

  divArray(list, 10);
  cout << "Lista com cada elemento sendo dividido por 10: ";
  list.print();
  cout << endl;

  return 0;
}