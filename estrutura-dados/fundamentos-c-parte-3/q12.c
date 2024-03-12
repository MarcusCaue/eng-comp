#include <stdio.h>
#include <stdlib.h>

int len(char s[]) {
   int len;
   for (len = 0; s[len] != '\0'; len++) { }
   return ++len;
}

void swap_str(char s1[], char s2[]) {
   char *backup = (char *) malloc(sizeof(char) * len(s2));

   // Copiando os dados de s2 para backup
   int i;
   for (i = 0; *(s2 + i) != '\0'; i++)
      *(backup + i) = *(s2 + i);
   *(backup + i) = '\0';

   // Atribuindo s1 a s2 
   for (i = 0; *(s1 + i) != '\0'; i++)
      s2[i] = s1[i];

   // Atribuindo backup a s1
   for (i = 0; *(backup + i) != '\0'; i++)
      s1[i] = *(backup + i);
}

int main() {
   char s1[] = "Luiz Gonzaga da Costa";
   char s2[] = "Heitor da Silva Ulixe";

   printf("s1 => '%s'\ns2 => '%s'\n", s1, s2);
   swap_str(s1, s2);
   printf(" \n===== Troca Realizada =====\n\n");
   printf("s1 => '%s'\ns2 => '%s'\n", s1, s2);

   return 0;
}