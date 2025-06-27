int evalRPN(char **tokens, int tokensSize)
{
	int *stack = malloc(tokensSize * sizeof(int));
	int topo = -1;

	for (int i = 0; i < tokensSize; i++)
	{
		char *token = tokens[i];

		if (strcmp(token, "+") == 0 ||
			strcmp(token, "-") == 0 ||
			strcmp(token, "*") == 0 ||
			strcmp(token, "/") == 0)
		{
			int b = stack[topo--];
			int a = stack[topo--];

			if (strcmp(token, "+") == 0)
			{
				stack[++topo] = a + b;
			}
			if (strcmp(token, "-") == 0)
			{
				stack[++topo] = a - b;
			}
			if (strcmp(token, "*") == 0)
			{
				stack[++topo] = a * b;
			}
			if (strcmp(token, "/") == 0)
			{
				stack[++topo] = a / b;
			}
		}
		else
		{
			stack[++topo] = atoi(token);
		}
	}

	int resultado = stack[topo];
	free(stack);
	return resultado;
}