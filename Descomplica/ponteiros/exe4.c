// Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas
// 2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas
// variaveis A e B por exemplo e, apos a execucao da funcao, A contera o valor de B e B
// tera o valor de A

#include <stdio.h>

void troca(int *a, int *b);

int main()
{
  int A, B;

  printf("Digite o primeiro valor: ");
  scanf("%d", &A);
  printf("Digite o segundo valor: ");
  scanf("%d", &B);

  troca(&A, &B);

  printf("Valores trocados: %d / %d", A, B);
}

void troca(int *a, int *b)
{
  int temporario;

  temporario = *a;
  *a = *b;
  *b = temporario;
}