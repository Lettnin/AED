#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
	char caracter;
	int quantidade;
} letras;

char *longestDiverseString(int a, int b, int c)
{
	char *resultado = malloc(a + b + c + 1);
	if (!resultado)
	{
		printf("erro ao alocar");
		exit(1);
	}

	letras letra[3] = {{'a', a}, {'b', b}, {'c', c}};
	int pos = 0;

	while (1)
	{
		int primeira = 0;
		int ultimo = 2;

		for (int i = primeira; i < ultimo; i++)
		{
			for (int j = i + 1; j <= ultimo; j++)
			{
				if (letra[i].quantidade < letra[j].quantidade)
				{
					letras aux = letra[i];
					letra[i] = letra[j];
					letra[j] = aux;
				}
			}
		}

		if (letra[0].quantidade == 0)
		{
			break;
		}

		if (pos >= 2 && resultado[pos - 1] == letra[0].caracter && resultado[pos - 2] == letra[0].caracter)
		{
			if (letra[1].quantidade == 0)
			{
				break;
			}
			resultado[pos++] = letra[1].caracter;
			letra[1].quantidade--;
		}
		else
		{
			resultado[pos++] = letra[0].caracter;
			letra[0].quantidade--;
		}
	}
	resultado[pos] = '\0';
	return resultado;
}

int main()
{
	char *res = longestDiverseString(1, 1, 7);
	printf("%s\n", res);
	free(res);
	return 0;
}
