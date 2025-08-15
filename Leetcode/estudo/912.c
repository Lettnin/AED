// Dado um array de inteiros nums, classifique o array em ordem crescente e retorne-o.

// Você deve resolver o problema sem usar nenhuma função interna na O(nlog(n))complexidade de tempo e com a menor complexidade de espaço possível.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Particiona o array usando pivô aleatório
int partition(int *arr, int left, int right)
{
	int pivotIndex = left + rand() % (right - left + 1);
	swap(&arr[pivotIndex], &arr[right]);
	int pivot = arr[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[right]);
	return i + 1;
}

// Função recursiva de Quick Sort
void quickSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int pi = partition(arr, left, right);
		quickSort(arr, left, pi - 1);
		quickSort(arr, pi + 1, right);
	}
}

// Função exigida pelo LeetCode
int *sortArray(int *nums, int numsSize, int *returnSize)
{
	srand(time(NULL)); // inicializa pivô aleatório
	quickSort(nums, 0, numsSize - 1);
	*returnSize = numsSize;
	return nums;
}

// Programa de teste
int main()
{
	int nums[] = {5, 2, 3, 1, 4};
	int n = sizeof(nums) / sizeof(nums[0]);
	int returnSize;

	int *sorted = sortArray(nums, n, &returnSize);

	printf("Array ordenado: ");
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", sorted[i]);
	}
	printf("\n");

	return 0;
}
