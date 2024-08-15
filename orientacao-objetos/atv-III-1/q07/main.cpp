#include <iostream>
#include "./Bruxo/Bruxo.hpp"
#include "./ExpressoHogwarts/ExpressoHogwarts.hpp"

using std::cout, std::endl, std::cin;

int main() 
{
  ExpressoHogwarts expresso(100);

  Bruxo harry("Harry","Grifinoria","expecto patronum");

  cout << "Embarcando..." << endl;

  expresso << harry;
  expresso << Bruxo("Rony","Grifinoria","wingardium leviosa");
  expresso << Bruxo("Hermione","Grifinoria","flipendo");

  expresso << Bruxo("Malfoy","Sonserina","cruciatus");

  cout << "Bruxos no trem: " << expresso;

  cout << "Partindo..." << endl;
  cout << "Viajando..." << endl;

  cout << "Chegando..." << endl;
  cout << "Desembarcando..." << endl;

  expresso >> "Malfoy";
  expresso >> harry;
  expresso >> Bruxo("Rony","Grifinoria","wingardium leviosa");
  expresso >> Bruxo("Hermione","Grifinoria","flipendo");

  cout << "Bruxos no trem: " << expresso;
 
  return 0;
}