/**
 * Questão 23 - Média Ponderada
 * 
 * Considere um sistema de notas que utiliza números de ponto flutuante de dupla precisão dentro do intervalo de 0.0 a 10.0.
 * 
*/

#include <iostream>

using std::cout, std::cin;

int main() {

   char nome[20] = {'\0'};
   cout << "Digite seu primeiro nome: ";
   cin >> nome;

   double n1, n2, n3;
   cout << "Informe as notas que voce tirou: ";
   cin >> n1 >> n2 >> n3;

   double media = ((n1 * 3) + (n2 * 4) + (n3 * 5)) / 12;

   printf("O aluno %s obteve media %.1f", nome, media);

   return 0;
}