#include "./Ferramenta.hpp"
#include "./FerramentaController.hpp"

#include <iomanip>
using std::fixed, std::setprecision;

int FerramentaController::findFerramenta(const Ferramenta& f) {
   for (int i = 0; i < this->len; i++) {
      Ferramenta& fRef = this->ferramentas[i];
      if (f.getNumRegistro() == fRef.getNumRegistro()) {
         return i;
      }
   }

   return -1;
}

FerramentaController::FerramentaController(int quant) : ferramentas(nullptr), len(0), max(quant) {
   if (quant > 0)
      this->ferramentas = new Ferramenta [quant];
}

FerramentaController::~FerramentaController() {
   if (this->ferramentas) {
      delete [] ferramentas;
      this->len = 0;
      this->max = 0;
   }
}

void FerramentaController::inserirFerramenta(const Ferramenta& f) {
   if (this->len >= this->max)
      return;

   this->ferramentas[this->len++] = f;
}

void FerramentaController::removeFerramenta(const Ferramenta& f) {
   int index = findFerramenta(f);
   removeFerramenta(index);
}

void FerramentaController::removeFerramenta(int index) {
   if (index < 0 || index >= this->len)
      return;

   for (int i = index; i < this->len - 1; i++)
      this->ferramentas[i] = this->ferramentas[i+1];

   this->len--;
}

void FerramentaController::updateFerramenta(const Ferramenta& f) {
   
}

ostream& operator<<(ostream& cout, FerramentaController& fc) {
   cout << "========== FERRAMENTAS CADASTRADAS ==========" << endl;

   if (fc.len <= 0) {
      cout << "[]";
      return cout;
   }

   cout << fixed;
   cout << setprecision(2);

   for (int i = 0; i < fc.len; i++) {
      Ferramenta& f = fc.ferramentas[i];
      cout << " - " << i+1 << "º ferramenta: " << endl;
      cout << "    - Nº registro: " << f.getNumRegistro() << endl;
      cout << "    - Nome: " << f.getNome() << endl; 
      cout << "    - Quantidade: " << f.getQuant() << endl; 
      cout << "    - Preço: R$" << f.getPreco() << endl << endl; 
   }

   return cout;
}
