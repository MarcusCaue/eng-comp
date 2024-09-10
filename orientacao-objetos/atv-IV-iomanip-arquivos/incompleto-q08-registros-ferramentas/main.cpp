#include <iostream>
#include <fstream>

#include "./Ferramenta.hpp"
#include "./FerramentaController.hpp"

using namespace std;

void chargeFile(ofstream& file) 
{
   int quant = 8;

   Ferramenta initialData[] = {
      Ferramenta("Lixadeira", 3, 7, 57.98),
      Ferramenta("Martelo", 17, 76, 11.99),
      Ferramenta("Serra tico-tico", 24, 21, 11.00),
      Ferramenta("Cortador de grama", 39, 3, 79.50),
      Ferramenta("Serra elétrica", 56, 18, 99.99),
      Ferramenta("Chave de fenda", 68, 106, 6.99),
      Ferramenta("Marreta", 77, 11, 21.50),
      Ferramenta("Chave inglesa", 83, 34, 7.50)
   };

   file.write((char*) &quant, sizeof(int));

   for (Ferramenta& f : initialData)
      file << f;
}

int main()
{
   ofstream file = ofstream("./hardware.dat", ios::out | ios::binary);
   // chargeFile(file);
   
   FerramentaController minhasFerramentas = FerramentaController(10);
   cout << minhasFerramentas << endl;

   minhasFerramentas.inserirFerramenta(Ferramenta("Lixadeira", 3, 7, 57.98));
   minhasFerramentas.inserirFerramenta(Ferramenta("Serra tico-tico", 24, 21, 11.00));
   minhasFerramentas.inserirFerramenta(Ferramenta("Cortador de grama", 39, 3, 79.50));
   minhasFerramentas.inserirFerramenta(Ferramenta("Serra elétrica", 56, 18, 99.99));
   minhasFerramentas.inserirFerramenta(Ferramenta("Chave de fenda", 68, 106, 6.99));

   cout << minhasFerramentas << endl;

   minhasFerramentas.removeFerramenta(Ferramenta("Serra tico-tico", 24, 21, 11.00));
   minhasFerramentas.removeFerramenta(1);
   minhasFerramentas.removeFerramenta(100);
   minhasFerramentas.removeFerramenta(Ferramenta("Chave de fenda", 9876, 106, 6.99));

   cout << minhasFerramentas << endl;


   

   




   file.close();


   return 0;
}