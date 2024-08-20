#include "./ClassesHeaders.hpp"

LivroInvisivelDaInvisibilidade::LivroInvisivelDaInvisibilidade(string title, unsigned int ano, unsigned int quantPags, string content) {
   Livro(title, ano, quantPags, content);
}

void LivroInvisivelDaInvisibilidade::ler() const {
   cout << "" << endl;
}