#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct celula
{
  char nome;
  struct celula *prox;
} celula;

celula *crialista(void);
void adicionar(celula *cabeca, char nome);
int main()
{
  int op;
  do
  {
    printf("Escolha opção: ");
    printf("1- Adicionar Nome\n 2- Remover Nome\n 3- Listar\n 4- Sair");
    scanf("%d", &op);

    switch (op == 4)
    {
    case 1:
      adicionarnome break;

    default:
      break;
    }
  } while (condition);
}

celula *crialista(void)
{
  celula *cabeca = (celula *)malloc(sizeof(celula));
  cabeca = cabeca->prox;
  return cabeca;
}

void adicionar(celula *cabeca, char nome)
{
  celula *nova = (celula *)malloc(sizeof(celula));
  // parei aqui
}