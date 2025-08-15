#include <stdio.h>

void intercalar(int vetor[], int inicio, int meio, int fim)
{
	int tamanhoEsq = meio - inicio + 1;
	int tamanhoDir = fim - meio;
	int esquerda[tamanhoEsq], direita[tamanhoDir];

	for (int i = 0; i < tamanhoEsq; i++)
		esquerda[i] = vetor[inicio + i];
	for (int j = 0; j < tamanhoDir; j++)
		direita[j] = vetor[meio + 1 + j];

	int i = 0, j = 0, k = inicio;
	while (i < tamanhoEsq && j < tamanhoDir)
	{
		if (esquerda[i] <= direita[j])
		{
			vetor[k++] = esquerda[i++];
		}
		else
		{
			vetor[k++] = direita[j++];
		}
	}
	while (i < tamanhoEsq)
		vetor[k++] = esquerda[i++];
	while (j < tamanhoDir)
		vetor[k++] = direita[j++];
}

void mergeSort(int vetor[], int inicio, int fim)
{
	if (inicio < fim)
	{
		int meio = inicio + (fim - inicio) / 2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, fim);
		intercalar(vetor, inicio, meio, fim);
	}
}

int main()
{
	int vetor[] = {5, 2, 3, 1, 4};
	int tamanho = sizeof(vetor) / sizeof(vetor[0]);
	mergeSort(vetor, 0, tamanho - 1);
	for (int i = 0; i < tamanho; i++)
	{
		printf("%d ", vetor[i]);
	}
	return 0;
}
