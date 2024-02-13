// Questão 31 => Imprimindo Padrões

#include <iostream>

using std::cout;

void linha() {
   cout << "====================\n";
}

void espacos(int quantEspacos) {
   for (int i = 0; i < quantEspacos; i++)
      cout << ' ';
}

void primeiroPadrao() {
   for (int i = 1; i < 6; i++) {
      for (int j = 0; j < i; j++)
         cout << '*';

      cout << '\n';
   }
}

void segundoPadrao() {
   for (int i = 5; i > 0; i--)
   {
      for (int j = 0; j < i; j++)
         cout << '*';

      cout << '\n';
   }
}

void terceiroPadrao()
{
   for (int i = 1; i < 4; i += 2)
   {
      int quantEspacos = (5 - i) / 2;

      espacos(quantEspacos);
      for (int j = 0; j < i; j++)
         cout << '*';
      espacos(quantEspacos);

      cout << '\n';
   }

   for (int i = 0; i < 5; i++)
      cout << '*';

   cout << '\n';

   for (int i = 3; i > 0; i -= 2)
   {
      int quantEspacos = (5 - i) / 2;

      espacos(quantEspacos);
      for (int j = 0; j < i; j++)
         cout << '*';
      espacos(quantEspacos);

      cout << '\n';
   }
}

void quartoPadrao()
{
   for (int i = 1; i < 8; i += 2)
   {
      int quantEspacos = (7 - i) / 2;

      espacos(quantEspacos);
      for (int j = 0; j < i; j++)
         cout << '*';
      espacos(quantEspacos);

      cout << '\n';
   }
}

int main()
{
   primeiroPadrao();
   linha();
   segundoPadrao();
   linha();
   terceiroPadrao();
   linha();
   quartoPadrao();

   return 0;
}
