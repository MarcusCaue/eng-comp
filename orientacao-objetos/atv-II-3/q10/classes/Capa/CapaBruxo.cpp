// #include <iostream>
// #include "CapaBruxo.hpp"

// CapaBruxo::CapaBruxo(string casa, double tamanho) {
//   setTam(tamanho);
//   setCasa(casa);
// }

// void CapaBruxo::display() const {
//   cout << "====== CAPA DE BRUXO ======" << endl;
//   printf("Tamanho: %.1lfm\n", this->tamanho);
//   cout << "Cor: " << this->cor << endl;
//   cout << "Casa: " << this->casa << endl << endl;
// }

// string CapaBruxo::getCor() const { return this->cor; }
// string CapaBruxo::getCasa() const { return this->casa; }
// double CapaBruxo::getTam() const { return this->tamanho; }

// void CapaBruxo::setCasa(string casa) {

//   if (casa == "Grifinoria") {
//     this->cor = "Vermelho";
//     this->casa = "Grifinoria";
//   } else if (casa == "Corvinal") {
//     this->cor = "Azul";
//     this->casa = "Corvinal";
//   } else if (casa == "Sonserina") {
//     this->cor = "Verde";
//     this->casa = "Sonserina";
//   } else if (casa == "Lufa-Lufa") {
//     this->cor = "Amarelo";
//     this->casa = "Lufa-Lufa";
//   } else {
//     this->cor = "undefined";
//     this->casa = "undefined";
//   }

// }
// void CapaBruxo::setTam(double tam) {
//   // Considere as dimensões mínimas e máximas de uma pessoa que vá usar uma capa:
//   // 1.20m -> 2.10m

//   this->tamanho = (tam < 1.20 || tam > 2.10) ? 1.20 : tam;
// }
