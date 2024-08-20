#include "./ClassesHeaders.hpp"

Livro::Livro(string title, unsigned int ano, unsigned int quantPags, string content) 
   : title(title), ano(ano), quantPags(quantPags), content(content) { }

void Livro::ler() const {
   cout << "================= DADOS DO LIVRO =================" << endl;
   cout << "    - Título: " << this->title << endl;
   cout << "    - Ano de publicação: " << this->ano << endl;
   cout << "    - Quantidade de páginas: " << this->quantPags << endl;
   cout << "    - O livro diz...: " << endl;
   cout << "        " << this->content << endl;
}