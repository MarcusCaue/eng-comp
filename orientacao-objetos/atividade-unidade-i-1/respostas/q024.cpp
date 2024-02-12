// Questão 24 => Monitoramento de Consumo de Combustível

#include <iostream>

using std::cout, std::cin;

int main() {

   double kmViagem, somaLitros = 0;

   cout << "Quantidade de quilometros rodados na viagem: ";
   cin >> kmViagem;

   while (kmViagem != -1) {
      double litrosViagem;

      cout << "Quantidade de litros para encher o tanque: ";
      cin >> litrosViagem;

      somaLitros += litrosViagem;

      double consumo = kmViagem / litrosViagem;
      printf("\nO seu consumo foi de %.2f km/L nessa viagem.\n", consumo);

      cout << "\nQuantidade de quilometros rodados na viagem: ";
      cin >> kmViagem;
   }

   printf("\nQuantidade total de litros consumidos: %.2f\n", somaLitros);

   return 0;
}