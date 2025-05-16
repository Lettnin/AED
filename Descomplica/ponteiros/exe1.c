// Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros(use &). Modifique os valores de cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a modificacao.

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int inteiro = 3, *p_int = NULL;
  char caracter = 'S', *p_char = NULL;

  p_int = &inteiro;
  p_char = &caracter;

  printf("caracter = %c\n", caracter);
  printf("caracter = %d\n", inteiro);

  *p_char = 'A';
  *p_int = 5;

  printf("caracter = %c\n", caracter);
  printf("caracter = %d\n", inteiro);
  return 0;
}