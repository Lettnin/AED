#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Aluno
{
	int ra;
	char nome[50];
} Aluno;
typedef struct No
{
	Aluno dado;
	struct No *prox;
} No;
typedef struct Pilha
{
	No *topo;
} Pilha;

void reset(Pilha *pilha);
bool fullpilha(Pilha *pilha);
bool vazia(Pilha *pilha);
bool push(Pilha *pilha, Aluno a);
int pop(Pilha *pilha, Aluno *a);
void listar(Pilha *pilha);
void limpar(Pilha *p);

int main()
{

	Pilha pilha;
	reset(&pilha);

	Aluno a1 = {123, "João"};
	Aluno a2 = {456, "Maria"};
	Aluno a3 = {789, "Carlos"};

	// Inserindo alunos
	push(&pilha, a1);
	push(&pilha, a2);
	push(&pilha, a3);

	// Listando a pilha
	listar(&pilha);

	// Removendo um aluno do topo
	Aluno removido;
	pop(&pilha, &removido);
	printf("\n\nAluno removido: %d - %s", removido.ra, removido.nome);

	// Listando novamente após remoção
	printf("\n\nApós remoção:\n");
	listar(&pilha);

	limpar(&pilha);

	return 0;
}

void reset(Pilha *pilha)
{
	pilha->topo = NULL;
}

bool vazia(Pilha *pilha)
{
	return pilha->topo == NULL;
}

bool fullpilha(Pilha *pilha)
{
	return false;
}

void limpar(Pilha *p)
{
	Aluno aux;
	while (pop(p, &aux))
		;
}

bool push(Pilha *pilha, Aluno a)
{

	No *novo = (No *)malloc(sizeof(No));

	if (!novo)
	{
		printf("ERRO no alocar");
		return false;
	}

	novo->dado = a;
	novo->prox = pilha->topo;
	pilha->topo = novo;

	return true;
}

int pop(Pilha *pilha, Aluno *a)
{
	if (vazia(pilha))
	{
		return 0;
	}

	No *remover = pilha->topo;

	*a = remover->dado;
	pilha->topo = remover->prox;
	free(remover);
	return 1;
}

void listar(Pilha *pilha)
{
	printf("\nListando tudo\n");
	No *atual = pilha->topo;
	while (atual)
	{
		printf("%d - %s\n", atual->dado.ra, atual->dado.nome);
		atual = atual->prox;
	}
}
