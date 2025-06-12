#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *AdicionarPessoa(void *pBuffer);
void *Listar(void *pBuffer);

int main()
{
  // Zerei o pBuffer para nao pegar lixo
  void *pBuffer = NULL;

  // Aloco 4 ints para o tamanho do meu buffer inicialmente 4*4 = 16 bytes
  pBuffer = malloc(sizeof(int *) * 4);

  if (!pBuffer)
  {
    printf("Erro ao alocar memoria\n");
    return 1;
  }

  // crio as caixinhas para o meu menu, guardar quantidade de contatos da agenda,
  // o meu tamanho atual do buffer e um ponteiro para saber a proxima posição vazia
  int *menu = (int *)((char *)pBuffer + 0);                        // Menu
  int *TAMbuffer = (int *)((char *)pBuffer + sizeof(int));         // TAMANHO DO MEU BUFFER
  int *totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2); // QUANTIDADE DE CONTATOS
  int *Aux = (int *)((char *)pBuffer + sizeof(int) * 3);           // Ponteiro para saber a proxima posição vazia

  // zerei todos parametros para não puxar lixos como da memoria e causar bugs futuros
  *menu = 0;
  *TAMbuffer = sizeof(int) * 4;
  *totalContatos = 0;
  *Aux = 0;

  while (1)
  {
    printf("\n-------- MENU -------\n");
    printf("|1| Adicionar Pessoa\n");
    printf("|2| Remover Pessoa\n");
    printf("|3| Buscar Pessoa\n");
    printf("|4| Listar Todas as Pessoas\n");
    printf("|5| Sair\n");
    printf("--------------------\n");
    printf("Escolha uma opção: ");
    scanf("%d", menu); // menu

    switch (*menu)
    {
    case 1:
      pBuffer = AdicionarPessoa(pBuffer);
      break;

      // case 2:
      //   RemoverContato(pBuffer);
      //   break;

      // case 3:
      //   BuscarPessoa(pBuffer);
      //   break;

    case 4:
      pBuffer = Listar(pBuffer);
      break;

    case 5:
      printf("Finalizando o Programa...\n");
      free(pBuffer);
      return 0;

    default:
      printf("Opção invalida\n");
    }
  }
}

void *AdicionarPessoa(void *pBuffer)
{
  int *TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
  int *totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);
  // realoquei o tamanho do buffer para adicionar os contatos
  void *novoBuffer = realloc(pBuffer, *TAMbuffer + 50);

  if (!novoBuffer)
  {
    printf("ERRO AO ALOCAR MEMORIA");
    return pBuffer;
  }

  // buffer aponta pra onde está o novo espaço do buffer agora
  pBuffer = novoBuffer;

  TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
  totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);

  char *nome = (char *)(pBuffer + *TAMbuffer);

  printf("Digite seu Nome: ");
  scanf(" %[^\n]", nome);

  void *novoBuffer = realloc(pBuffer, *TAMbuffer + strlen(nome) + 1 + sizeof(int));
  if (!novoBuffer)
  {
    printf("ERRO AO ALOCAR MEMORIA");
    return pBuffer;
  }

  pBuffer = novoBuffer;
  TAMbuffer = (int *)((char *)pBuffer + sizeof(int));

  char *idade = (char *)(pBuffer + *TAMbuffer + strlen(nome) + 1 + sizeof(int *));

  printf("Digite sua Idade: ");
  scanf("%d", idade);

  void *novoBuffer = realloc(pBuffer, *TAMbuffer + strlen(nome) + 1 + sizeof(int) + 100);
  if (!novoBuffer)
  {
    printf("ERRO AO ALOCAR MEMORIA");
    return pBuffer;
  }

  pBuffer = novoBuffer;
  TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
  totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);

  char *email = realloc(pBuffer, *TAMbuffer + strlen(nome) + 1 + sizeof(int));

  printf("Digite seu Email: ");
  scanf(" %[^\n]", email);

  (*totalContatos)++;
  *TAMbuffer += strlen(nome) + 1 + sizeof(int) + strlen(email) + 1;

  return pBuffer;
}

void *Listar(void *pBuffer)
{
  int *totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);
  int *Aux = (int *)((char *)pBuffer + sizeof(int) * 3);

  if (totalContatos <= 0)
  {
    printf("AGENDA VAZIA");
    return;
  }

  char *lista = (char *)(pBuffer + sizeof(int) * 4);
  for (*Aux = 0; *Aux < totalContatos; (*Aux)++)
  {
    /* code */
  }
}