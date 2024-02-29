// Questão 03 => R+L=J => https://judge.beecrowd.com/pt/problems/view/2557

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char entrada[24] = {'\0'};

  while (scanf("%s", entrada) != EOF) {
    long int r, l, j;
    char rString[21] = {'\0'},
         lString[21] = {'\0'},
         jString[21] = {'\0'}
    ;

    // Variável de controle para percorrer 'entrada'
    int i;
    // Variável para adicionar os valores nos outros arrays de caracteres;
    int k = 0;

    // Pegar o valor de R
    for (i = 0; entrada[i] != '+'; i++)
      rString[k++] = entrada[i];

    // Pegar o valor de L
    k = 0;
    for (i += 1; entrada[i] != '='; i++)
      lString[k++] = entrada[i];

    // Pegar o valor de J
    k = 0;
    for (i += 1; entrada[i] != '\0'; i++)
      jString[k++] = entrada[i];

    // Preciso descobrir R
    if (rString[0] == 'R') {
      l = atoi(lString);
      j = atoi(jString);

      r = j - l;
      printf("%li\n", r);
    }
    // Preciso descobrir L
    else if (lString[0] == 'L') {
      r = atoi(rString);
      j = atoi(jString);

      l = j - r;
      printf("%li\n", l);
    }
    // Preciso descobrir J
    else {
      r = atoi(rString);
      l = atoi(lString);

      j = r + l;
      printf("%li\n", j);
    }
  }

  return 0;
}