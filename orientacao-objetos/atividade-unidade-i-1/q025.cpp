// Questão 25 => Retonar números em sequência a cada chamada da função

#include <iostream>

using std::cout;
using std::endl;

int returnNumber() {
  static int num = 0;
  return num++;
}

int main() {

  cout << returnNumber() << endl;
  cout << returnNumber() << endl;
  cout << returnNumber() << endl;
  cout << returnNumber() << endl;

}
