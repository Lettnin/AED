#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Estrutura do aluno, com RA e nome
typedef struct Aluno
{
	int ra;
	char nome[50];
} Aluno;

// Estrutura da pilha dinâmica
typedef struct Pilha
{
	Aluno *alunos; // Ponteiro para vetor dinâmico de alunos
	Aluno *topo;   // Ponteiro para o elemento no topo da pilha
	Aluno *base;   // Ponteiro para o início da pilha
	int limite;	   // Quantidade de elementos armazenados
} Pilha;

// Função para reiniciar a pilha (zera ponteiros e contador)
void Reset(Pilha *pilha)
{
	pilha->alunos = NULL;
	pilha->topo = NULL;
	pilha->base = NULL;
	pilha->limite = 0;
}

// Retorna se a pilha está vazia
int Empty(Pilha *pilha)
{
	return pilha->limite == 0;
}

bool full(Pilha *pilha)
{
	return false;
}
// Função auxiliar para copiar elementos de um vetor para outro
void CopiaPilha(Aluno *dest, int tamDest, Aluno *orig, int tamOrig)
{
	int min = tamDest < tamOrig ? tamDest : tamOrig;
	for (int i = 0; i < min; i++)
	{
		dest[i] = orig[i];
	}
}

// Função para inserir um novo elemento na pilha
bool PUSH(Pilha *pilha, Aluno *item)
{
	Aluno *alunos;

	pilha->limite++; // Aumenta o número de elementos esperados

	// Aloca novo vetor com espaço para mais um aluno
	alunos = (Aluno *)malloc(sizeof(Aluno) * pilha->limite);
	if (!alunos)
	{
		printf("Erro alocando memoria!\\n");
		return 0;
	}

	// Copia os alunos antigos para o novo vetor
	CopiaPilha(alunos, pilha->limite, pilha->alunos, pilha->limite - 1);

	// Libera a memória antiga
	if (pilha->alunos)
	{
		free(pilha->alunos);
	}

	pilha->alunos = alunos;

	// Insere o novo item na última posição
	pilha->alunos[pilha->limite - 1] = *item;

	// Atualiza topo e base
	pilha->topo = &pilha->alunos[pilha->limite - 1];
	pilha->base = pilha->alunos;

	return 1;
}

// Função para remover o elemento do topo da pilha
void POP(Pilha *pilha, Aluno *aluno)
{
	if (Empty(pilha))
	{
		return 0;
	}

	// Copia o último aluno para a variável de retorno
	*aluno = pilha->alunos[pilha->limite - 1];

	pilha->limite--; // Reduz o número de elementos

	// Se não houver mais alunos, zera a pilha
	if (pilha->limite == 0)
	{
		free(pilha->alunos);
		Reset(pilha);
		return 1;
	}

	// Aloca novo vetor com uma posição a menos
	size_t size = sizeof(Aluno) * pilha->limite;
	Aluno *alunos = (Aluno *)malloc(size);
	if (!alunos)
	{
		printf("Erro alocando memoria!\\n");
		return 0;
	}

	// Copia os alunos restantes
	CopiaPilha(alunos, pilha->limite, pilha->alunos, pilha->limite);

	free(pilha->alunos);
	pilha->alunos = alunos;

	pilha->topo = &pilha->alunos[pilha->limite - 1];
	pilha->base = pilha->alunos;

	return 1;
}

// Função para listar todos os elementos da pilha
void Listar(Pilha *pilha)
{
	printf("\\nListando elementos da pilha:\\n");
	for (int i = pilha->limite - 1; i >= 0; i--)
	{
		printf("%d - %s\\n", pilha->alunos[i].ra, pilha->alunos[i].nome);
	}
}

// Exemplo de uso no main
int main()
{
	Pilha pilha;
	Reset(&pilha);

	Aluno a1 = {123, "João"};
	Aluno a2 = {456, "Maria"};
	Aluno a3 = {789, "Carlos"};

	PUSH(&pilha, &a1);
	PUSH(&pilha, &a2);
	PUSH(&pilha, &a3);

	Listar(&pilha);

	Aluno removido;
	if (POP(&pilha, &removido))
	{
		printf("\\nRemovido: %d - %s\\n", removido.ra, removido.nome);
	}

	printf("\\nApós remoção:\\n");
	Listar(&pilha);

	Reset(&pilha);
	return 0;
}
