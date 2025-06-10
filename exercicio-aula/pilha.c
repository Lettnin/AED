#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dados
{
  char nome[50];
  int idade;
} dados;

typedef struct Pilha
{
  dados *topo;
  dados *base;
  dados *limite;
} pilha;

void reset(pilha *pilha);
bool fullpilha(pilha *pilha);

int main()
{
}

void reset(pilha *pilha)
{
  pilha->dados = NULL;
  pilha->topo = NULL;
  pilha->base = NULL;
}

bool fullpilha(pilha *pilha)
{
  return false;
}
