#ifndef EXP_HOGT_HPP
#define EXP_HOGT_HPP

#include <string>
#include <iostream>
#include "../Bruxo/Bruxo.hpp"
using std::string, std::cout, std::ostream, std::endl;

class ExpressoHogwarts {

   friend ostream& operator<<(ostream& cout, const ExpressoHogwarts& trem);

private:
   Bruxo *trem;
   int vagas;
   int pos;

   int buscarBruxo(string nome) const;

public:
   ExpressoHogwarts(int vagas = 5);
   ~ExpressoHogwarts();

   ExpressoHogwarts& operator<<(const Bruxo& bruxo); //Embarque

   ExpressoHogwarts& operator>>(const Bruxo& bruxo); //Desembarque
   ExpressoHogwarts& operator>>(string nome);

};

#endif