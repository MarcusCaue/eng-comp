// Questão 01 => C mais ou menos? => https://judge.beecrowd.com/pt/problems/view/2486

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vitC(char alimento[]) {
  if (strcmp(alimento, "suco de laranja") == 0) {
    return 120;
  } else if (strcmp(alimento, "morango fresco") == 0 || strcmp(alimento, "mamao") == 0) {
    return 85;
  } else if (strcmp(alimento, "goiaba vermelha") == 0) {
    return 70;
  } else if (strcmp(alimento, "manga") == 0) {
    return 56;
  } else if (strcmp(alimento, "laranja") == 0) {
    return 50;
  } else {
    return 34;
  }
}

int main() {

  int qAlimentos = 0;
  scanf("%i", &qAlimentos);

  while (qAlimentos) {

    int totVitC = 0;
    
    for (int i = 0; i < qAlimentos; i++) {
      int quant = 0; 
      char alimento[16] = {'\0'};
      
      scanf("%i ", &quant);
      gets(alimento);

      totVitC += (vitC(alimento) * quant);
    }

    if (totVitC > 130) {
      printf("Menos %i mg\n", (totVitC - 130));
    } else if (totVitC < 110) {
      printf("Mais %i mg\n", (110 - totVitC));
    } else {
      printf("%i mg\n", totVitC);
    }
    
    scanf("%i", &qAlimentos);
  }
  
  return 0;
}