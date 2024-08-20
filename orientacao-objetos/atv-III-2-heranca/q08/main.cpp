#include "./classes/ClassesHeaders.hpp"
#include <iostream>

using namespace std;

int main() {

   Livro lotr = Livro("O Senhor dos Anéis: A Sociedade do Anel", 1954, 400, "Em uma toca no chão vivia um Hobbit...");

   LivroMonstruosoDosMonstros calculo = LivroMonstruosoDosMonstros("Cálculo Integral e Diferencial", 2004, 300, "Entenda-se por 'derivada' a reta tangente...");

   LivroInvisivelDaInvisibilidade invisivel = LivroInvisivelDaInvisibilidade("Manual de Como Matar um Dragão", 1932, 540, "1º LEI: Não deixe Hágrid descobrir de forma alguma que você está lendo este livro...");

   lotr.ler();
   cout << endl;
   calculo.ler();
   cout << endl;
   invisivel.ler();

   return 0;
}