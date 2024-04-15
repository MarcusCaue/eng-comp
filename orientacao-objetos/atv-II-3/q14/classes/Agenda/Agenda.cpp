// #include "Agenda.hpp"
// #include <iostream>

// using namespace std;

// Agenda::Agenda() : qtdePessoas(0) { }

// void Agenda::armazenaPessoa(const string& nome, int idade, float altura) {
//   if (this->qtdePessoas >= 10) {
//     cout << "A agenda já está cheia. Não cabem mais novos contatos." << endl;
//     return;
//   }
  
//   Pessoa novaPessoa = Pessoa(nome, idade, altura);
//   this->pessoas[this->qtdePessoas++] = novaPessoa;
// }

// void Agenda::armazenaPessoa(const Pessoa& p) {
//   if (this->qtdePessoas >= 10) {
//     cout << "A agenda já está cheia. Não cabem mais novos contatos." << endl;
//     return;
//   }

//   this->pessoas[this->qtdePessoas++] = p;
// }

// void Agenda::imprimePovo() const {
//   cout <<  "========= DADOS DA AGENDA =========" << endl;
//   for (int i = 1; i < this->qtdePessoas + 1; i++)
//     imprimePessoa(i);
// }

// int Agenda::buscaPessoa(const string& nome) const {
//   for (int i = 0; i < this->qtdePessoas; i++) {
//     string nomePessoaI = this->pessoas[i].getNome();
//     if (nomePessoaI == nome)
//       return i + 1;
//   }

//   return 0;
// }

// void Agenda::imprimePessoa(int i) const {
//   Pessoa p = this->pessoas[i - 1];
//   cout << "Pessoa #" << i << ": " << endl;
//   cout << "\t - Nome: " << p.getNome() << endl;    
//   cout << "\t - Idade: " << p.getIdade() << endl;
//   printf("\t - Altura: %.2fm\n\n", p.getAltura()); 
// }

// void Agenda::removePessoa(const string& nome) {
//   int posicao = buscaPessoa(nome);
//   if (posicao <= 0) {
//     cout << "Esta pessoa não está presente na agenda" << endl;
//     return;
//   }

//   for (int i = posicao - 1; i < this->qtdePessoas - 1; i++)
//     this->pessoas[i] = this->pessoas[i+1];

//   this->qtdePessoas--;
// }