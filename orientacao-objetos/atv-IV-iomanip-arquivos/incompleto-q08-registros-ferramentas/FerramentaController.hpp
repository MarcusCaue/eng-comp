#ifndef FERRAMENTA_CONTROLLER
#define FERRAMENTA_CONTROLLER

#include "./Ferramenta.hpp"
#include <iostream>
using std::cout, std::ostream, std::endl;

class FerramentaController
{
   friend ostream& operator<<(ostream& cout, FerramentaController& fc);

   private:
      Ferramenta* ferramentas;
      int len;
      int max;

      int findFerramenta(const Ferramenta& f);

   public:
      FerramentaController(int quant);
      ~FerramentaController();

      void inserirFerramenta(const Ferramenta& f);
      void removeFerramenta(const Ferramenta& f);
      void removeFerramenta(int index);
      void updateFerramenta(const Ferramenta& f);
};

#endif