#include "./classes/PessoasHeaders.hpp"
#include "./classes/Empresa.hpp"

void pause() {
   cout << "Programa pausado, pressione enter para continuar...";
   getchar();
   cout << endl;
}

int main() {
   
   Empresa marcenariaFamiliar = Empresa("Marcenaria Familiar", "47.857.673/0001-00", "Fabrício Aguiar", 10, 5);
   cout << marcenariaFamiliar << endl;
   marcenariaFamiliar.showClients();
   marcenariaFamiliar.showFuncs();
   pause();

   marcenariaFamiliar.insertFunc(Funcionario("Felipe", "432.554.323-65", "891", 1200, 160, 160));
   marcenariaFamiliar.insertFunc(Funcionario("João", "433.114.332-65", "102", 1500, 160, 100));
   marcenariaFamiliar.insertFunc(Funcionario("Caio", "323.667.111-00", "121", 900, 40, 40));

   marcenariaFamiliar.insertClient(Cliente("Rodrigo", "443.553.434-11", "Rua Palmeiras e São Paulo", "99808-8876"));
   marcenariaFamiliar.insertClient(Cliente("Marcos", "111.435.776-87", "Rua Cristiano Ronaldo Milhor", "98785-9988"));
   marcenariaFamiliar.insertClient(Cliente("Sebastião", "677.887.445-22", "Rua Messi é muito bom também", "93665-3396"));

   cout << marcenariaFamiliar;
   printf("Folha de pagamento atual: R$%.2f\n\n", marcenariaFamiliar.calcularFolhaDePagamento());
   marcenariaFamiliar.showClients();
   marcenariaFamiliar.showFuncs();
   pause();
   
   marcenariaFamiliar.popClient();
   marcenariaFamiliar.popFunc();

   cout << marcenariaFamiliar;
   pause();

   marcenariaFamiliar.removeFunc("111.435.776-87"); // Cpf inválido dentro da lista de funcionários
   marcenariaFamiliar.removeClient("432.554.323-65"); // Cpf inválido dentro da lista de clientes
   marcenariaFamiliar.removeFunc("432.554.323-65"); // Felipe
   marcenariaFamiliar.removeClient("443.553.434-11"); // Rodrigo

   cout << marcenariaFamiliar;
   printf("Folha de pagamento atual: R$%.2f\n\n", marcenariaFamiliar.calcularFolhaDePagamento());
   pause();

   return 0;
}