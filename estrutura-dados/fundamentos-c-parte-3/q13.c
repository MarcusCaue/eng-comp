#include <stdio.h>
#include <stdlib.h>

void str_copy(char *s1, char *s2) {
   int i;
   for (i = 0; *(s1 + i) != '\0'; i++) {
      *(s2 + i) = *(s1 + i);
   }
   *(s2 + i) = '\0';
}

int main() {

   int len;
   printf("Tamanho da String: ");
   scanf("%i", &len);

   char *s1 = (char *) malloc(sizeof(char) * len);
   printf("Digite o conteudo da primeira string: ");
   getchar();
   gets(s1);
   
   char *s2 = (char *) malloc(sizeof(char) * len);
   *s2 = '\0';

   printf("\ns1 => '%s'\ns2 => '%s'\n", s1, s2);
   str_copy(s1, s2);
   printf(" \n===== Copia Realizada =====\n\n");
   printf("s1 => '%s'\ns2 => '%s'\n", s1, s2);

   return 0;
}