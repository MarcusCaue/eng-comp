#include "./Headers.hpp"

LivroMonstruosoDosMonstros::LivroMonstruosoDosMonstros(string title, unsigned int ano, unsigned int quantPags, string content) {
   Livro(title, ano, quantPags, content);
}

void LivroMonstruosoDosMonstros::ler() const { cout << "Mastiga, mastiga, mastiga, mastiga..." << endl; }