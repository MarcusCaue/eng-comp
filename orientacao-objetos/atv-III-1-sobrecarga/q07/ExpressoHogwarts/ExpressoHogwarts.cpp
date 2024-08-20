#include "./ExpressoHogwarts.hpp"

ExpressoHogwarts::ExpressoHogwarts(int vagas) : vagas(vagas), pos(0) { trem = new Bruxo [vagas]; }
ExpressoHogwarts::~ExpressoHogwarts() { delete [] trem; }

int ExpressoHogwarts::buscarBruxo(string nome) const {
   for (int i = 0; i < this->pos; i++) {
      Bruxo& b = this->trem[i];
      if (b.getNome() == nome)
         return i;
   }

   return -1;
}

ostream& operator<<(ostream& cout, const ExpressoHogwarts& trem) {
   if (trem.pos == 0) {
      cout << "{}" << endl;
      return cout;  
   }

   cout << "{ ";
   
   for (int i = 0; i < trem.pos - 1; i++)
      cout << trem.trem[i].getNome() << " | ";

   Bruxo& ultimoBruxo = trem.trem[trem.pos - 1];
   cout << ultimoBruxo.getNome() << " }" << endl;

   return cout;
}

ExpressoHogwarts& ExpressoHogwarts::operator<<(const Bruxo& bruxo) {
   if (this->pos >= this->vagas) {
      cout << "O trem está cheio, o bruxo não pode entrar." << endl;
      return *this;
   }

   this->trem[this->pos++] = bruxo;
   return *this;
}

ExpressoHogwarts& ExpressoHogwarts::operator>>(const Bruxo& bruxo) {
   if (this->pos <= 0) {
      cout << "Não tem ninguém no trem." << endl;
      return *this;
   }
   
   // Procurando o bruxo no trem
   int index = buscarBruxo(bruxo.getNome());

   if (index == -1) {
      cout << "Esse bruxo não está no trem." << endl;
      return *this;
   }
   
   for (int i = index; i < this->pos - 1; i++)
      this->trem[i] = this->trem[i + 1];
   
   this->pos--;
   return *this;
}

ExpressoHogwarts& ExpressoHogwarts::operator>>(string nome) {
   int index = buscarBruxo(nome);

   if (index == -1) {
      cout << "Esse bruxo não está no trem." << endl;
      return *this;
   }

   Bruxo bruxo = this->trem[index];
   return ((*this) >> bruxo);
}
