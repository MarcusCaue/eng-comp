// Voleibol => https://judge.beecrowd.com/pt/problems/view/1181

#include <stdio.h>

int main() {

   int qJogadores;
   scanf("%i", &qJogadores);

   int saquesTentados = 0, saquesSucedidos = 0,
       bloqueiosTentados = 0, bloqueiosSucedidos = 0,
       ataquesTentados = 0, ataquesSucedidos = 0;
   
   for (int i = 0; i < qJogadores; i++) {
      int sT, sS, bT, bS, aT, aS;
      char nome[200];

      scanf("%s", nome);
      // Saques, bloqueios e ataques tentados
      scanf("%i %i %i", &sT, &bT, &aT);
      saquesTentados += sT;
      bloqueiosTentados += bT;
      ataquesTentados += aT;
      
      // Saques, bloqueios e ataques bem-sucedidos
      scanf("%i %i %i", &sS, &bS, &aS);
      saquesSucedidos += sS;
      bloqueiosSucedidos += bS;
      ataquesSucedidos += aS;
   }

   printf("Pontos de Saque: %.2lf %%.\n", (saquesSucedidos * 100.0 / saquesTentados));
   printf("Pontos de Bloqueio: %.2lf %%.\n", (bloqueiosSucedidos * 100.0 / bloqueiosTentados));
   printf("Pontos de Ataque: %.2lf %%.\n", (ataquesSucedidos * 100.0 / ataquesTentados));
   
   return 0;
}