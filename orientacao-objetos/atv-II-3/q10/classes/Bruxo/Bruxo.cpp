// #include <iostream>
// #include "Bruxo.hpp"

// // Novo aluno na escola
// Bruxo::Bruxo(string nome) : nome(nome) {
//   this->casa = "undefined";
//   this->feiticoPredileto = "undefined";
//   this->varinha = nullptr;
//   this->capa = nullptr;
// }

// // Aluno com atributos definidos
// Bruxo::Bruxo(string nome, string casa, string feitico, Varinha *varinha, CapaBruxo *capa) : 
//   nome(nome)
// {
//   setCasa(casa);
//   this->feiticoPredileto = feitico;
//   this->varinha = varinha;
//   setCapa(capa);
// }

// void Bruxo::display() const {
//    cout << "\n===== ATRIBUTOS DO BRUXO =====\n";
//    cout << "Nome: " << this->nome << endl;
//    cout << "Feitico preferido: " << this->feiticoPredileto << endl;
//    cout << "Casa: " << this->casa << endl;

//    if (this->varinha == nullptr) {
//      cout << "Este bruxo ainda nao tem varinha" << endl;
//    }
//    else {
//     // Dados da Varinha
//     this->varinha->display();
//    }

//    if (this->capa == nullptr) {
//      cout << "Este bruxo ainda nao tem capa" << endl;
//    }
//    else {
//      // Dados da Capa
//      this->capa->display();
//    }
//  }

// // Não tem como um bruxo lançar feitiço se ele ainda não tem um
// void Bruxo::lancarFeitico() const {
//   if (this->feiticoPredileto != "undefined") {
//     cout << "Lancando feitico '" << this->feiticoPredileto << "'!!!" << endl;
//   }
//   else {
//     cout << "Este jovem bruxo ainda nao sabe nenhum feitico." << endl;
//   }
//  }

// string Bruxo::getNome() const { return this->nome; }
// string Bruxo::getFeitico() const { return this->feiticoPredileto; }
// string Bruxo::getCasa() const { return this->casa; }
// Varinha Bruxo::getVarinha() const {
//   Varinha copia = *(this->varinha);

//   cout << "Endereço da varinha CAMPO: " << &(this->varinha) << endl;
//   cout << "Endereço da varinha COPIA: " << &copia << endl;

//   return copia;
// };
// CapaBruxo Bruxo::getCapa() const {
//   CapaBruxo copia = *(this->capa);

//   cout << "Endereço da capa CAMPO: " << &(this->capa) << endl;
//   cout << "Endereço da capa COPIA: " << &copia << endl;

//   return copia;
// }

// // Um bruxo não pode ser de uma casa e usar uma capa de outra casa.
// void Bruxo::setCapa(CapaBruxo* capa) {
//   string casaCapa = capa->getCasa();

//   if (this->casa != casaCapa) {
//     this->capa = nullptr;
//   }
//   else {
//     this->capa = capa;
//   }
// };
// void Bruxo::setFeitico(string feitico) { this->feiticoPredileto = feitico; }
// void Bruxo::setCasa(string casa) {
//   string casas[] = {"Lufa-Lufa", "Corvinal", "Grifinoria", "Sonserina"};
//   bool casaValida = false;

//   for (string c : casas) {
//     if (casa == c) {
//       casaValida = true;
//       break;
//     }
//   }

//   this->casa = casaValida ? casa : "undefined";
//  }
// void Bruxo::setVarinha(Varinha* varinha) {
//   this->varinha = varinha;
// }