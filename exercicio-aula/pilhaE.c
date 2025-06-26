#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
typedef struct Aluno
{
	int ra;
	char nome[50];
} Aluno;

typedef struct Pilha
{
	Aluno alunos[MAX];
	int topo;
	int base;
	int limite;
} Pilha;

void reset(Pilha *pilha);
bool fullpilha(Pilha *pilha);
bool vazia(Pilha *pilha);
bool push(Pilha *pilha, Aluno *item);
bool pop(Pilha *pilha, Aluno *aluno);
void listar(Pilha *pilha);

int main()
{
	Pilha pilha;
	reset(&pilha);

	Aluno a1 = {123, "João"};
	Aluno a2 = {456, "Maria"};
	Aluno a3 = {789, "Carlos"};

	// Inserindo alunos
	push(&pilha, &a1);
	push(&pilha, &a2);
	push(&pilha, &a3);

	// Listando a pilha
	listar(&pilha);

	// Removendo um aluno do topo
	Aluno removido;
	pop(&pilha, &removido);
	printf("\n\nAluno removido: %d - %s", removido.ra, removido.nome);

	// Listando novamente após remoção
	printf("\n\nApós remoção:\n");
	listar(&pilha);

	return 0;
}

void reset(Pilha *pilha)
{
	pilha->topo = 0;
	pilha->base = 0;
	pilha->limite = MAX;
}

bool vazia(Pilha *pilha)
{
	return pilha->topo == 0;
}

bool fullpilha(Pilha *pilha)
{
	return pilha->topo == MAX;
}

bool push(Pilha *pilha, Aluno *item)
{
	if (!fullpilha(pilha))
	{
		pilha->alunos[pilha->topo] = *item;
		pilha->topo++;
		return true;
	}

	else
	{
		return false;
	}
}

bool pop(Pilha *pilha, Aluno *aluno)
{
	if (pilha->topo == 0)
	{
		return false;
	}

	pilha->topo--;
	*aluno = pilha->alunos[pilha->topo];
}

void listar(Pilha *pilha)
{
	printf("\nListando tudo\n");
	for (int i = pilha->topo - 1; i >= 0; i--)
	{
		printf("%d - %s\n", pilha->alunos[i].ra, pilha->alunos[i].nome);
	}
}
