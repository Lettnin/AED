#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Aluno
{
	int ra;
	char nome[50];
} Aluno;

typedef struct Pilha
{
	Aluno *alunos;
	Aluno *topo;
	Aluno *base;
	int limite;
} Pilha;

// --- Protótipos das Funções da Pilha ---
void Reset(Pilha *pilha);
bool Empty(Pilha *pilha);
void Copia_Pilha(Aluno *destino, Aluno *origem, int tamanho_origem_em_elementos);
bool PUSH(Pilha *pilha, Aluno *item);
void POP(Pilha *pilha, Aluno *aluno);
void Listar(Pilha *pilha);

void Copia_Pilha(Aluno *destino, Aluno *origem, int tamanho_origem_em_elementos)
{
	if (origem == NULL)
		return;
	memcpy(destino, origem, sizeof(Aluno) * tamanho_origem_em_elementos);
}

void Reset(Pilha *pilha)
{
	pilha->alunos = NULL;
	pilha->topo = NULL;
	pilha->base = NULL;
	pilha->limite = 0;
}

bool Empty(Pilha *pilha)
{
	return pilha->alunos == NULL;
}

bool Full(Pilha *pilha)
{
	return false;
}

bool PUSH(Pilha *pilha, Aluno *item)
{
	Aluno *alunos_novos;
	int tamanho_anterior = pilha->limite;

	pilha->limite++;
	alunos_novos = (Aluno *)malloc(sizeof(Aluno) * pilha->limite);

	if (!alunos_novos)
	{
		printf("Erro alocando memoria!\n");
		pilha->limite--; // Desfaz o incremento do limite
		return false;
	}

	// Copia os elementos antigos para o novo espaço de memória
	Copia_Pilha(alunos_novos, pilha->alunos, tamanho_anterior);

	if (pilha->alunos)
	{
		free(pilha->alunos); // Libera a memória antiga
	}

	pilha->alunos = alunos_novos;
	pilha->alunos[pilha->limite - 1] = *item;
	pilha->topo = &pilha->alunos[pilha->limite - 1];
	pilha->base = pilha->alunos;

	return true;
}

void POP(Pilha *pilha, Aluno *aluno)
{
	if (Empty(pilha))
	{
		return;
	}

	*aluno = *pilha->topo; // Pega o valor do topo

	Aluno *alunos_novos;
	pilha->limite--;

	if (pilha->limite == 0)
	{
		free(pilha->alunos);
		Reset(pilha);
		return;
	}

	size_t size = sizeof(Aluno) * pilha->limite;
	alunos_novos = (Aluno *)malloc(size);

	if (!alunos_novos)
	{
		printf("Erro alocando memoria!\n");
		pilha->limite++; // Desfaz o decremento em caso de erro
		return;
	}

	// Copia os N-1 elementos restantes para o novo vetor
	Copia_Pilha(alunos_novos, pilha->alunos, pilha->limite);

	free(pilha->alunos); // Libera a memória antiga

	pilha->alunos = alunos_novos;
	pilha->topo = &pilha->alunos[pilha->limite - 1];
	pilha->base = pilha->alunos;
}

void Listar(Pilha *pilha)
{
	printf("\n--- Listando e Esvaziando a Pilha ---\n");
	while (!Empty(pilha))
	{
		Aluno aluno;
		POP(pilha, &aluno);
		// O printf no PDF tem um erro de sintaxe (-> em vez de .). Corrigido aqui.
		printf("RA: %d - Nome: %s\n", aluno.ra, aluno.nome);
	}
	printf("--- Fim da Lista ---\n");
}

int main()
{
	Pilha minha_pilha;

	printf("1. Inicializando a pilha...\n");
	Reset(&minha_pilha);

	if (Empty(&minha_pilha))
	{
		printf("Pilha esta vazia. (Correto)\n\n");
	}

	printf("2. Empilhando 3 alunos (usando a logica do PDF)...\n");
	Aluno a1 = {10, "Joao Silva"};
	Aluno a2 = {20, "Maria Souza"};
	Aluno a3 = {30, "Pedro Costa"};
	PUSH(&minha_pilha, &a1);
	PUSH(&minha_pilha, &a2);
	PUSH(&minha_pilha, &a3);
	printf("Alunos empilhados.\n\n");

	printf("3. Removendo o elemento do topo (POP)...\n");
	Aluno aluno_removido;
	POP(&minha_pilha, &aluno_removido);
	printf("Aluno removido -> RA: %d, Nome: %s\n\n", aluno_removido.ra, aluno_removido.nome);

	printf("4. Listando os elementos restantes...\n");
	Listar(&minha_pilha);
	printf("\n");

	printf("5. Verificando o estado final da pilha...\n");
	if (Empty(&minha_pilha))
	{
		printf("Pilha esta vazia. (Correto)\n");
	}
	else
	{
		printf("Algo deu errado, a pilha deveria estar vazia.\n");
	}

	return 0;
}