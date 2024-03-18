// Questão 27 => Troca de valores usando referências

#include <iostream>

using std::cout, std::cin, std::endl;

void swap(int &refer1, int &refer2) 
{
   int intermediario = refer1;

   refer1 = refer2;
   refer2 = intermediario;
}

int main() {

   int n1, n2;
   cout << "Entre com dois valores inteiros: ";
   cin >> n1 >> n2;

   cout << "\nValor de 'n1' => " << n1 << endl
        << "Valor de 'n2' => " << n2 << endl;
   
   swap(n1, n2);

   cout << "\nValor de 'n1' => " << n1 << endl
        << "Valor de 'n2' => " << n2 << endl;
      
   cout << "\nTroca concluida!" << endl;

   return 0;
}