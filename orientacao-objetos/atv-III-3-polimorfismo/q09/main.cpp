#include "./classes/Headers.hpp"

using namespace std;

int main() {
   Livro* books[] = {
      new Livro("O Senhor dos Anéis: A Sociedade do Anel", 1954, 400, "Em uma toca no chão vivia um Hobbit..."),
      new LivroMonstruosoDosMonstros("Cálculo Integral e Diferencial", 2004, 300, "Entenda-se por 'derivada' a reta tangente..."),
      new LivroInvisivelDaInvisibilidade("Manual de Como Matar um Dragão", 1932, 540, "1º LEI: Não deixe Hágrid descobrir de forma alguma que você está lendo este livro..."),
   };

   for (int i = 0; i < 3; i++) {
      cout << "Invocando o método ler da " << i + 1 << "º classe: " << endl;
      books[i]->ler();
      cout << endl;
      delete books[i];
   }

   return 0;
}