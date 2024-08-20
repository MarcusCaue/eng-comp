#ifndef CLASSES_HEADERS_HPP
#define CLASSES_HEADERS_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

class Livro {

protected:
   string title;
   unsigned int ano;
   unsigned int quantPags;
   string content;

public:
   Livro() {};
   Livro(string title, unsigned int ano, unsigned int quantPags, string content);

   void ler() const;

};

class LivroMonstruosoDosMonstros : public Livro {
public:
   LivroMonstruosoDosMonstros(string title, unsigned int ano, unsigned int quantPags, string content);
   void ler() const;
};

class LivroInvisivelDaInvisibilidade : public Livro {
public:
   LivroInvisivelDaInvisibilidade(string title, unsigned int ano, unsigned int quantPags, string content);
   void ler() const;
};

#endif