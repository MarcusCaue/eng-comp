// Aaah! => https://www.beecrowd.com.br/judge/pt/problems/view/3224

#include <stdio.h>

int quantA(char string[]) {
   int len = 0;
   for (len; string[len] != 'h'; len++) { }
   return len;
}

int main() {

   char jonMarius[1001] = {'\0'};
   char medico[1001] = {'\0'};

   scanf("%s %s", jonMarius, medico);

   int quantAJonMarius = quantA(jonMarius);
   int quantAMedico = quantA(medico);

   if (quantAJonMarius >= quantAMedico) {
      printf("go\n");
   } else {
      printf("no\n");
   }
   
   return 0;
}