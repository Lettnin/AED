// Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e
// exiba o maior endereco.

#include <stdio.h>

int main()
{
  int primeiro, segundo;

  if (&primeiro > &segundo)
  {

    printf("O endereço de memória do primeiro é maior: %p > %p", &primeiro, &segundo);
  }
  else
  {
    printf("O endereço de memória do segundo é maior: %p > %p", &segundo, &primeiro);
  }

  return 0;
}
