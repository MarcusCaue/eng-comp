#include "ViraTempo.hpp"

ViraTempo::ViraTempo(int limite, char modo) {
  setModo(modo);
  setLimite(limite);
  this->numAtual = 0;
}

void ViraTempo::setModo(char modo) { this->modo = modo != 'I' && modo != 'D' ? 'I' : modo; }
void ViraTempo::setLimite(int limite) { this->limite = limite < 0 ? 0 : limite; }

void ViraTempo::mostrarTempo() { cout << this->numAtual << endl; }
void ViraTempo::avancarTempo() {
  if (this->modo == 'I' && this->numAtual < this->limite)
    this->numAtual++;
  else if (this->modo == 'D' && this->numAtual > 0)
    this->numAtual--;
}
void ViraTempo::virarTempo() { this->modo = this->modo == 'I' ? 'D' : 'I'; }