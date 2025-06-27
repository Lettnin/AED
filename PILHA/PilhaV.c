#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 20

// declaracao da estrutura
typedef struct
{
	int vetor[TAMANHO_PILHA];
	int topo;
} Pilha;

// prototipo
void menu();
void empilha(int valor, Pilha *pilha);
void desempilha(Pilha *pilha);
int Cheia(Pilha *pilha);
int Vazia(Pilha *pilha);
void ListaPilha(Pilha *pilha);

int main(int argc, char *argv[])
{
	char opcao = 'a';
	int valor;

	Pilha p;
	p.topo = 0;

	// Loop principal do menu de opções
	do
	{
		menu();				  // Chama a função que exibe o menu
		scanf(" %c", &opcao); // Lê a opção do usuário (o espaço antes de %c limpa o buffer)

		switch (opcao)
		{
		case '1':
			if (!Cheia(&p))
			{
				printf("Informe um valor a ser empilhado: ");
				scanf("%d", &valor);
				empilha(valor, &p);
				printf("Valor %d empilhado com sucesso!\n", valor);
			}
			else
			{
				printf("A pilha esta cheia! Nao e possivel empilhar.\n");
			}
			break;

		case '2':
			if (!Vazia(&p))
			{
				desempilha(&p);
				printf("Elemento do topo desempilhado.\n");
			}
			else
			{
				printf("A pilha esta vazia! Nao e possivel desempilhar.\n");
			}
			break;

		case '3':
			if (!Vazia(&p))
			{
				ListaPilha(&p);
			}
			else
			{
				printf("A pilha esta vazia!\n");
			}
			break;

		case '4':
			// Mostra o valor que está no topo, sem removê-lo
			if (!Vazia(&p))
			{
				printf("Elemento no topo da pilha: %d\n", p.vetor[p.topo - 1]);
				printf("Numero de elementos empilhados: %d\n", p.topo);
			}
			else
			{
				printf("A pilha esta vazia!\n");
			}
			break;

		case '5':
			printf("Saindo do programa...\n");
			break;

		default:
			printf("Opcao invalida! Tente novamente.\n");
			break;
		}

	} while (opcao != '5');

	return 0;
}

void menu()
{

	printf("\n--- MENU DE OPCOES DA PILHA ---\n");
	printf("   1 - Adicionar (Empilhar)\n");
	printf("   2 - Remover (Desempilhar)\n");
	printf("   3 - Listar\n");
	printf("   4 - Ver Topo e Tamanho\n");
	printf("   5 - Sair\n");
	printf("-------------------------------\n");
	printf("Escolha uma opcao: ");
}

// declaracao das funcoes
void empilha(int valor, Pilha *pilha)
{
	pilha->vetor[pilha->topo] = valor;
	pilha->topo++;
}

void desempilha(Pilha *pilha)
{
	pilha->topo--;
}

int Cheia(Pilha *pilha)
{
	if (pilha->topo == TAMANHO_PILHA)
		return 1;
	else
		return 0;
}

int Vazia(Pilha *pilha)
{
	if (pilha->topo == 0)
		return 1;
	else
		return 0;
}

void ListaPilha(Pilha *pilha)
{
	printf("\nListando tudo\n");
	for (int i = pilha->topo - 1; i >= 0; i--)
	{
		printf("Pos %02d, Valor |%02d|\n", i, pilha->vetor[i]);
	}
}
