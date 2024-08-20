#include "./classes/ImoveisHeaders.hpp"

#include <iostream>

using namespace std;

// As adições e descontos são em forma de porcentagem

int main() {

  ImovelNovo plazaHostel = ImovelNovo("Rua Presidente Farias Gonzaga, nº 21", 890000.0, 25.0);
  ImovelVelho mansaoBarbosa = ImovelVelho("Rua da Grécia Macedônica, nº 90", 30000.0, 12.0);

  cout << "============ DADOS DO IMÓVEL NOVO ============" << endl;
  cout << " - Endereço: " << plazaHostel.getEndereco() << endl;
  cout << " - Percentual de adição: " << static_cast<int>(plazaHostel.getAdicionalPreco()) << "%\n";
  printf(" - Preço final: R$%.2f\n\n", plazaHostel.getPreco());

  cout << "============ DADOS DO IMÓVEL VELHO ============" << endl;
  cout << " - Endereço: " << mansaoBarbosa.getEndereco() << endl;
  cout << " - Percentual de desconto: " << static_cast<int>(mansaoBarbosa.getDesconto()) << "%\n";
  printf(" - Preço final: R$%.2f\n", mansaoBarbosa.getPreco());
  
  return 0;
}