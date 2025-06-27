#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a estrutura 'Aluno', que irá armazenar os dados de cada elemento da nossa pilha.
typedef struct Aluno
{
	int ra;		   // Um número inteiro para o Registro do Aluno.
	char nome[50]; // Um array de caracteres para armazenar o nome do aluno.
} Aluno;

// Define a estrutura 'Pilha', que gerencia nosso conjunto de alunos.
typedef struct Pilha
{
	Aluno *alunos; // Um ponteiro para o início do nosso array dinâmico de alunos na memória.
	Aluno *topo;   // Um ponteiro que aponta sempre para o último aluno inserido (o topo da pilha).
	Aluno *base;   // Um ponteiro que aponta sempre para o primeiro aluno inserido (a base da pilha).
	int limite;	   // Um inteiro que guarda o número total de elementos atualmente na pilha.
} Pilha;

bool Empty(Pilha *pilha);
void Copia_Pilha(Aluno *destino, Aluno *origem, int tamanho_origem_em_elementos);
bool PUSH(Pilha *pilha, Aluno *item);
void POP(Pilha *pilha, Aluno *aluno);
void Listar(Pilha *pilha);

// Função auxiliar para copiar os dados de um array de Alunos para outro.
void Copia_Pilha(Aluno *destino, Aluno *origem, int tamanho_origem_em_elementos)
{
	// Se o ponteiro de origem for nulo (não há nada para copiar), a função retorna.
	if (origem == NULL)
		return;
	// Usa a função 'memcpy' para fazer uma cópia em bloco da memória.
	// É muito mais rápido do que copiar elemento por elemento com um laço 'for'.
	memcpy(destino, origem, sizeof(Aluno) * tamanho_origem_em_elementos);
}

// Inicializa uma pilha para um estado seguro e vazio.
void Reset(Pilha *pilha)
{
	// Define o ponteiro principal como NULO, indicando que não há memória alocada.
	pilha->alunos = NULL;
	// Os ponteiros de topo e base também são definidos como NULOS.
	pilha->topo = NULL;
	pilha->base = NULL;
	// O limite (tamanho) da pilha é zerado.
	pilha->limite = 0;
}

// Verifica se a pilha está vazia.
bool Empty(Pilha *pilha)
{
	// A forma mais simples de verificar se a pilha dinâmica está vazia é
	// checar se o ponteiro principal é NULO.
	return pilha->alunos == NULL;
}

// Verifica se a pilha está "cheia". Em uma pilha dinâmica, isso nunca acontece,
// pois ela pode sempre crescer (até o limite da memória do sistema).
bool Full(Pilha *pilha)
{
	return false;
}

// Adiciona um novo aluno (item) ao topo da pilha.
bool PUSH(Pilha *pilha, Aluno *item)
{
	// Declara um ponteiro para o futuro novo bloco de memória.
	Aluno *alunos_novos;
	// Guarda o tamanho atual da pilha antes de modificá-lo.
	int tamanho_anterior = pilha->limite;

	// Aumenta o contador de limite, pois teremos mais um elemento.
	pilha->limite++;
	alunos_novos = (Aluno *)malloc(sizeof(Aluno) * pilha->limite);

	// Se a alocação de memória falhar (retornar NULO), imprime um erro.
	if (!alunos_novos)
	{
		printf("Erro alocando memoria!\n");
		// Desfaz o incremento do limite, pois a operação falhou.
		pilha->limite--;
		return false; // Retorna 'false' para indicar que o PUSH falhou.
	}
	Copia_Pilha(alunos_novos, pilha->alunos, tamanho_anterior);

	// Se o ponteiro antigo 'pilha->alunos' não for NULO (ou seja, a pilha não estava vazia antes)...
	if (pilha->alunos)
	{
		free(pilha->alunos);
	}

	pilha->alunos = alunos_novos;
	// O novo item é inserido na última posição do novo array.
	pilha->alunos[pilha->limite - 1] = *item;
	pilha->topo = &pilha->alunos[pilha->limite - 1];
	pilha->base = pilha->alunos;

	return true; // Retorna 'true' para indicar que o PUSH foi bem-sucedido.
}

// Remove o aluno do topo da pilha e retorna seus dados.
void POP(Pilha *pilha, Aluno *aluno)
{
	// Se a pilha já estiver vazia, não há nada a fazer.
	if (Empty(pilha))
	{
		return;
	}

	// Copia os dados do aluno do topo para o ponteiro 'aluno' fornecido como parâmetro.
	// Isso permite que quem chamou a função saiba qual aluno foi removido.
	*aluno = *pilha->topo;

	// Declara um ponteiro para o futuro novo bloco de memória (menor).
	Aluno *alunos_novos;
	// Diminui o contador de limite, pois teremos um elemento a menos.
	pilha->limite--;

	// Se o limite chegou a zero, significa que este era o último elemento.
	if (pilha->limite == 0)
	{
		// Libera a memória do último elemento.
		free(pilha->alunos);
		// Reseta a pilha para o estado inicial de "vazia".
		Reset(pilha);
		return; // A operação termina aqui.
	}

	// Calcula o tamanho do novo bloco de memória (para N-1 elementos).
	size_t size = sizeof(Aluno) * pilha->limite;
	// Aloca um novo bloco de memória menor.
	alunos_novos = (Aluno *)malloc(size);

	// Se a alocação falhar, imprime um erro.
	if (!alunos_novos)
	{
		printf("Erro alocando memoria!\n");
		// Desfaz o decremento do limite, pois a operação falhou.
		pilha->limite++;
		return;
	}

	// Copia os N-1 elementos restantes do bloco antigo para o novo bloco menor.
	Copia_Pilha(alunos_novos, pilha->alunos, pilha->limite);

	// Libera a memória do bloco antigo (que era maior).
	free(pilha->alunos);

	// O ponteiro principal agora aponta para o novo bloco de memória.
	pilha->alunos = alunos_novos;
	// O ponteiro 'topo' é atualizado para o novo último elemento.
	pilha->topo = &pilha->alunos[pilha->limite - 1];
	// O ponteiro 'base' é atualizado para o início do novo bloco.
	pilha->base = pilha->alunos;
}

// Imprime todos os elementos da pilha na tela. ATENÇÃO: Esta função é "destrutiva".
void Listar(Pilha *pilha)
{
	printf("\n--- Listando e Esvaziando a Pilha ---\n");
	// O laço continua enquanto a pilha não estiver vazia.
	while (!Empty(pilha))
	{
		// A cada iteração, um aluno é criado para receber os dados.
		Aluno aluno;
		// O elemento do topo é removido (POP) e seus dados são copiados para a variável 'aluno'.
		POP(pilha, &aluno);
		// Os dados do aluno removido são impressos na tela.
		printf("RA: %d - Nome: %s\n", aluno.ra, aluno.nome);
	} // O laço se repete até que a pilha esteja completamente vazia.
	printf("--- Fim da Lista ---\n");
}

// --- Função Principal: O Ponto de Entrada do Programa ---
int main()
{
	// Declara a variável principal que representará nossa pilha.
	Pilha minha_pilha;

	printf("1. Inicializando a pilha...\n");
	// Chama a função Reset para garantir que a pilha comece em um estado limpo e seguro.
	Reset(&minha_pilha);

	// Verifica se a pilha está vazia após a inicialização.
	if (Empty(&minha_pilha))
	{
		printf("Pilha esta vazia. (Correto)\n\n");
	}

	printf("2. Empilhando 3 alunos (usando a logica do PDF)...\n");
	// Cria 3 instâncias da struct Aluno com dados de exemplo.
	Aluno a1 = {10, "Joao Silva"};
	Aluno a2 = {20, "Maria Souza"};
	Aluno a3 = {30, "Pedro Costa"};
	// Adiciona os 3 alunos à pilha. A ordem de entrada é: Joao -> Maria -> Pedro.
	PUSH(&minha_pilha, &a1);
	PUSH(&minha_pilha, &a2);
	PUSH(&minha_pilha, &a3);
	printf("Alunos empilhados.\n\n");

	printf("3. Removendo o elemento do topo (POP)...\n");
	// Declara uma variável para receber os dados do aluno que será removido.
	Aluno aluno_removido;
	// Remove o aluno do topo. Como a pilha é LIFO (Last-In, First-Out),
	// o último a entrar (Pedro) deve ser o primeiro a sair.
	POP(&minha_pilha, &aluno_removido);
	printf("Aluno removido -> RA: %d, Nome: %s\n\n", aluno_removido.ra, aluno_removido.nome);

	printf("4. Listando os elementos restantes...\n");
	// Chama a função Listar. Ela irá imprimir os alunos restantes (Maria e depois Joao)
	// e, ao mesmo tempo, esvaziar a pilha.
	Listar(&minha_pilha);
	printf("\n");

	printf("5. Verificando o estado final da pilha...\n");
	// Verifica se a pilha está de fato vazia após a chamada da função Listar.
	if (Empty(&minha_pilha))
	{
		printf("Pilha esta vazia. (Correto)\n");
	}
	else
	{
		printf("Algo deu errado, a pilha deveria estar vazia.\n");
	}

	// Retorna 0 para o sistema operacional, indicando que o programa terminou com sucesso.
	return 0;
}