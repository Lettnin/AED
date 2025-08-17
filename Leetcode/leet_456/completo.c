// Dado um conjunto de n inteiros nums, um padrão 132 é uma subsequência de três inteiros nums[i],
// nums[j] e nums[k] tal que i < j < k e nums[i] < nums[k] < nums[j].

// Retorna true se houver um padrão 132 em nums, caso contrário, retorna false.

// EXEMPLO 1:
// nums = [1,2,3,4]
// Saída: falso
//  Explicação: Não há padrão 132 na sequência.

// Exemplo 3:
// Entrada: nums = [-1,3,2,0]
//  Saída: true
//  Explicação: Há três padrões 132 na sequência: [-1, 3, 2], [-1, 3, 0] e [-1, 2, 0].

#include <stdio.h>
#include <stdbool.h>

bool find132pattern(int *nums, int numsSize)
{
	if (numsSize < 3)
		return false;

	int pilha[numsSize];
	int topo = -1;

	bool temValorDireita = false;
	int valorDireita = 0;

	for (int i = numsSize - 1; i >= 0; i--)
	{
		if (temValorDireita && nums[i] < valorDireita)
		{
			return true;
		}

		while (topo >= 0 && pilha[topo] < nums[i])
		{
			valorDireita = pilha[topo--];
			temValorDireita = true;
		}

		pilha[++topo] = nums[i];
	}

	return false;
}

int main()
{
	int nums[] = {3, 1, 4, 2};
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	bool result = find132pattern(nums, numsSize);

	if (result)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}

	return 0;
}