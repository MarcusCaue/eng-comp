#ifndef FERRAMENTA
#define FERRAMENTA

#include <fstream>
using std::ofstream;

#include <string>
using std::string;

class Ferramenta 
{
   friend ofstream& operator<<(ofstream& file, Ferramenta& f) {
      file.write((char*) &f, sizeof(Ferramenta));
      return file;
   }

   private:
      string nome;
      int numRegistro;
      int quant;
      double preco;
   
   public:
      Ferramenta() {}
      Ferramenta(string nome, int numRegistro, int quant, double preco) :
         nome(nome), numRegistro(numRegistro), quant(quant), preco(preco)
      {}

      string getNome() const { return this->nome; }
      int getNumRegistro() const { return this->numRegistro; }
      int getQuant() const { return this->quant; }
      double getPreco() const { return this->preco; }

      // Métodos setters
      void setNome(string nome) { this->nome = nome; }
      void setNumRegistro(int numRegistro) { this->numRegistro = numRegistro; }
      void setQuant(int quant) { this->quant = quant; }
      void setPreco(double preco) { this->preco = preco; }
};

#endif