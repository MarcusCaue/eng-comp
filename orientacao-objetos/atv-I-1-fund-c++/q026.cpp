// Questão 26 => Troca de valores usando ponteiros

#include <iostream>

using std::cout, std::cin, std::endl;

void swap(int *param1, int *param2) {
   
   int intermed = *param1;

   *param1 = *param2;
   *param2 = intermed;
   
}

int main() {

   int n1, n2;
   cout << "Entre com dois valores inteiros: ";
   cin >> n1 >> n2;

   cout << "\nValor de 'n1' => " << n1 << endl
        << "Valor de 'n2' => " << n2 << endl;
   
   swap(&n1, &n2);

   cout << "\nValor de 'n1' => " << n1 << endl
        << "Valor de 'n2' => " << n2 << endl;
      
   cout << "\nTroca concluida!" << endl;

   return 0;
}