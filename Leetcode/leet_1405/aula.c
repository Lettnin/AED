#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct infos
{
	char a;
	char b;
	char c;
} infos;

typedef struct fila
{
	infos letras;
	struct fila *pnext;
} fila;

typedef struct estrutura
{
	char *primeiro;
	char *ultimo;
} estrutura;

typedef struct tipoFila
{
	fila *fila;
} tipoFila;

bool vazia(fila *fila)
{
	if (fila == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(tipoFila *tipo, infos *info)
{
	fila *novo = (fila *)malloc(sizeof(fila));
	if (!novo)
	{
		printf("erro");
		return;
	}

	novo->letras = *info;
	novo->pnext = NULL;

	if (vazia(tipo->fila))
	{
		tipo->fila = novo;
		return;
	}

	if (tipo->fila->pnext == NULL)
	{
		tipo->fila->pnext = novo;
		return;
	}

	fila *aux = tipo->fila;
	while (aux->pnext != NULL)
	{
		aux = aux->pnext;
	}
	aux->pnext = novo;
	return;
	free(aux);
	free(novo);

	return;
}

void pop(tipoFila *tipo)
{
	if (vazia(tipo->fila))
	{
		printf("Pilha vazia");
		return;
	}

	if (tipo->fila->pnext == NULL)
	{
		free(tipo->fila);
		tipo->fila = NULL;
		return;
	}
}

char *longestDiverseString(int a, int b, int c)
{
}

int main()
{

	return 0;
}
