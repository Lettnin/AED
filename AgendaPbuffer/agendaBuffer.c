#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *AdicionarPessoa(void *pBuffer);
void *Remover(void *pBuffer);
void *Buscar(void *pBuffer);
void *Listar(void *pBuffer);

int main()
{
	void *pBuffer = NULL;

	pBuffer = malloc(sizeof(int) * 5);

	if (!pBuffer)
	{
		printf("Erro ao alocar memoria\n");
		exit(1);
	}

	*(int *)((char *)pBuffer + 0) = 0;						   // menu
	*(int *)((char *)pBuffer + sizeof(int)) = sizeof(int) * 5; // TAMbuffer
	*(int *)((char *)pBuffer + sizeof(int) * 2) = 0;		   // totalContatos
	*(int *)((char *)pBuffer + sizeof(int) * 3) = 0;		   // aux
	*(int *)((char *)pBuffer + sizeof(int) * 4) = 0;		   // contador

	while (1)
	{
		int *menu = (int *)pBuffer;
		int *TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
		int *totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);

		printf("\n-------- MENU -------\n");
		printf("|1| Adicionar Pessoa\n");
		printf("|2| Remover Pessoa\n");
		printf("|3| Buscar Pessoa\n");
		printf("|4| Listar Todas as Pessoas\n");
		printf("|5| Sair\n");
		printf("--------------------\n");
		printf("Escolha uma opção: ");
		scanf("%d", menu);

		switch (*menu)
		{
		case 1:
			pBuffer = AdicionarPessoa(pBuffer);
			break;

		case 2:
			pBuffer = Remover(pBuffer);
			break;

		case 3:
			pBuffer = Buscar(pBuffer);
			break;

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

	pBuffer = realloc(pBuffer, *TAMbuffer + 179);
	if (!pBuffer)
	{
		printf("ERRO AO REALOCAR MEMORIA\n");
		exit(1);
	}

	TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
	int *totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);

	int *tamanhoNome = (int *)((char *)(pBuffer + *TAMbuffer));
	*TAMbuffer += sizeof(int);

	char *nome = (char *)pBuffer + *TAMbuffer;

	printf("Digite seu Nome: ");
	scanf(" %74[^\n]%*c", nome);

	*tamanhoNome = strlen(nome);
	*TAMbuffer += (*tamanhoNome + 1);

	int *idade = (int *)(char *)(pBuffer + *TAMbuffer);

	printf("Digite sua Idade: ");
	scanf("%d%*c", idade);
	*TAMbuffer += sizeof(int);

	int *tamanhoEmail = (int *)(char *)(pBuffer + *TAMbuffer);
	*TAMbuffer += sizeof(int);

	char *email = (char *)pBuffer + *TAMbuffer;

	printf("Digite o email: ");
	scanf(" %99[^\n]%*c", email);
	*tamanhoEmail = strlen(email);
	*TAMbuffer += (*tamanhoEmail + 1);

	pBuffer = realloc(pBuffer, *TAMbuffer);
	if (!pBuffer)
	{
		printf("ERRO AO ALOCAR MEMORIA\n");
		exit(1);
	}

	totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);
	(*totalContatos)++;

	return pBuffer;
}

void *Remover(void *pBuffer)
{
	int *TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
	int *totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);
	int *aux = (int *)((char *)pBuffer + sizeof(int) * 3);
	int *contador = (int *)((char *)pBuffer + sizeof(int) * 4);

	if (*totalContatos <= 0)
	{
		printf("AGENDA VAZIA\n");
		return pBuffer;
	}

	*contador = *TAMbuffer;

	pBuffer = realloc(pBuffer, *contador + 100);
	if (!pBuffer)
	{
		printf("ERRO AO ALOCAR MEMORIA\n");
		exit(1);
	}

	TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
	totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);
	aux = (int *)((char *)pBuffer + sizeof(int) * 3);
	contador = (int *)((char *)pBuffer + sizeof(int) * 4);

	char *nomeParaRemover = (char *)pBuffer + *contador;

	printf("\nQual nome deseja remover: ");
	scanf(" %99[^\n]%*c", nomeParaRemover);

	char *atual = (char *)pBuffer + sizeof(int) * 5;

	for (*aux = 0; *aux < *totalContatos; (*aux)++)
	{
		char *InicioContatos = atual;

		int *tamanhoNome = (int *)atual;
		atual += sizeof(int);

		char *nome = atual;
		atual += (*tamanhoNome) + 1;

		int *idade = (int *)atual;
		atual += sizeof(int);

		int *tamanhoEmail = (int *)atual;
		atual += sizeof(int);

		char *email = atual;
		atual += (*tamanhoEmail) + 1;

		if (strcmp(nome, nomeParaRemover) == 0)
		{
			memmove(InicioContatos, atual, (*contador) - ((char *)atual - (char *)pBuffer));

			*TAMbuffer -= ((char *)atual - (char *)InicioContatos);

			(*totalContatos)--;

			printf("\nContato removido com sucesso\n");

			pBuffer = realloc(pBuffer, *TAMbuffer);
			if (!pBuffer)
			{
				printf("ERRO AO ALOCAR MEMORIA\n");
				exit(1);
			}
			return pBuffer;
		}
	}

	printf("Contato nao encontrado.\n");

	pBuffer = realloc(pBuffer, *contador);
	if (!pBuffer)
	{
		printf("ERRO AO ALOCAR MEMORIA\n");
		exit(1);
	}

	return pBuffer;
}

void *Buscar(void *pBuffer)
{
	int *TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
	int *totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);
	int *aux = (int *)((char *)pBuffer + sizeof(int) * 3);
	int *contador = (int *)pBuffer;

	if (*totalContatos <= 0)
	{
		printf("AGENDA VAZIA\n");
		return pBuffer;
	}

	pBuffer = realloc(pBuffer, *TAMbuffer + sizeof(char) * 100);
	if (!pBuffer)
	{
		printf("ERRO AO ALOCAR MEMORIA\n");
		exit(1);
	}

	TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
	totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);
	aux = (int *)((char *)pBuffer + sizeof(int) * 3);
	contador = (int *)pBuffer;

	char *nomeParaBuscar = (char *)pBuffer + *TAMbuffer;

	printf("\nQual nome voce deseja procurar na sua agenda: ");
	scanf(" %99[^\n]%*c", nomeParaBuscar);

	char *atual = (char *)pBuffer + sizeof(int) * 5;
	for (*aux = 0; *aux < *totalContatos; (*aux)++)
	{
		char *InicioContatos = atual;

		int *tamanhoNome = (int *)atual;
		atual += sizeof(int);

		char *nome = atual;
		atual += (*tamanhoNome) + 1;

		int *idade = (int *)atual;
		atual += sizeof(int);

		int *tamanhoEmail = (int *)atual;
		atual += sizeof(int);

		char *email = atual;
		atual += (*tamanhoEmail) + 1;
		if (strcmp(nome, nomeParaBuscar) == 0)
		{
			printf("--------------------\n");
			printf("CONTATO %d\n", *aux + 1);
			printf("Nome: %s\n", nome);
			printf("Idade: %d\n", *idade);
			printf("Email: %s\n", email);
			printf("--------------------\n");

			*contador = 0;
			pBuffer = realloc(pBuffer, *TAMbuffer);
			if (!pBuffer)
			{
				printf("ERRO AO ALOCAR MEMORIA\n");
				exit(1);
			}
			TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
			return pBuffer;
		}
		(*contador)++;
	}
	printf("\n Pessoa nao encontrada!\n");
	*contador = 0;

	pBuffer = realloc(pBuffer, *TAMbuffer);
	if (!pBuffer)
	{
		printf("ERRO AO ALOCAR MEMORIA\n");
		exit(1);
	}

	TAMbuffer = (int *)((char *)pBuffer + sizeof(int));
	return pBuffer;
}

void *Listar(void *pBuffer)
{
	int *totalContatos = (int *)((char *)pBuffer + sizeof(int) * 2);
	int *aux = (int *)((char *)pBuffer + sizeof(int) * 3);

	if (*totalContatos <= 0)
	{
		printf("AGENDA VAZIA");
		return pBuffer;
	}

	char *lista = (char *)(pBuffer + sizeof(int) * 5);
	for (*aux = 0; *aux < *totalContatos; (*aux)++)
	{
		int *tamanhoNome = (int *)lista;
		lista += sizeof(int);

		char *nome = lista;
		lista += (*tamanhoNome + 1);

		int *idade = (int *)lista;
		lista += sizeof(int);

		int *tamanhoEmail = (int *)lista;
		lista += sizeof(int);

		char *email = lista;
		lista += (*tamanhoEmail + 1);

		printf("--------------------\n");
		printf("CONTATO %d\n", *aux + 1);
		printf("Nome: %s\n", nome);
		printf("Idade: %d\n", *idade);
		printf("Email: %s\n", email);
		printf("--------------------\n");
	}
	return pBuffer;
}