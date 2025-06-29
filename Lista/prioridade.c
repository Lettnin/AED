#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int valor;
	int prioridade;
	struct no *prox;
} No;

// Insere um novo elemento na lista com base na prioridade
No *inserirComPrioridade(No *inicio, int valor, int prioridade)
{
	No *novo = (No *)malloc(sizeof(No));
	novo->valor = valor;
	novo->prioridade = prioridade;
	novo->prox = NULL;

	// Caso especial: lista vazia ou nova prioridade menor (mais alta)
	if (inicio == NULL || prioridade < inicio->prioridade)
	{
		novo->prox = inicio;
		return novo;
	}

	// Percorre a lista até encontrar o ponto de inserção
	No *atual = inicio;
	while (atual->prox != NULL && atual->prox->prioridade <= prioridade)
	{
		atual = atual->prox;
	}

	novo->prox = atual->prox;
	atual->prox = novo;
	return inicio;
}

// Remove o elemento com maior prioridade (primeiro da lista)
No *removerComMaiorPrioridade(No *inicio)
{
	if (inicio == NULL)
	{
		printf("Lista vazia.\n");
		return NULL;
	}
	No *temp = inicio;
	inicio = inicio->prox;
	free(temp);
	return inicio;
}

// Exibe a lista
void mostrarLista(No *inicio)
{
	No *atual = inicio;
	while (atual != NULL)
	{
		printf("Valor: %d | Prioridade: %d\n", atual->valor, atual->prioridade);
		atual = atual->prox;
	}
	printf("\n");
}

int main()
{
	No *lista = NULL;

	lista = inserirComPrioridade(lista, 10, 2);
	lista = inserirComPrioridade(lista, 20, 1);
	lista = inserirComPrioridade(lista, 30, 3);
	lista = inserirComPrioridade(lista, 40, 0);

	printf("Lista com prioridade:\n");
	mostrarLista(lista);

	lista = removerComMaiorPrioridade(lista);
	printf("Após remover o de maior prioridade:\n");
	mostrarLista(lista);

	// Libera memória
	while (lista != NULL)
	{
		lista = removerComMaiorPrioridade(lista);
	}

	return 0;
}
