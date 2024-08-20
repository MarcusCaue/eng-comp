#ifndef VARINHA_HPP
#define VARINHA_HPP

#include <string>

using namespace std;

class Varinha {

  // Não conheço muito o universo de Harry Potter, mas vou considerar que uma vez que uma varinha é criada, ela não pode ter suas características modificadas.
  private:
    const string tipoMadeira;
    const string nucleo;
    const double comprimento;

  public:
    Varinha(string, string, double);

    void display() const;

    // Como não temos uma regra de verificação dos valores que serão enviados para os atributos, e uma vez que estes são consts, optei por não implementar métodos set.
    string getMad()    const;
    string getNucleo() const;
    double getComp()   const;
};

#endif