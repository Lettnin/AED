int *luckyNumbers(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
  int *resultado = (int *)malloc(sizeof(int) * matrixSize);
  *returnSize = 0;

  for (int i = 0; i < matrixSize; i++)
  {
    int valormin = matrix[i][0];
    int colunamin = 0;

    for (int j = 1; j < matrixColSize[i]; j++)
    {
      if (matrix[i][j] < valormin)
      {
        valormin = matrix[i][j];
        colunamin = j;
      }
    }

    int maior = 1;
    for (int k = 0; k < matrixSize; k++)
    {
      if (matrix[k][colunamin] > valormin)
      {
        maior = 0;
        break;
      }
    }

    if (maior)
    {
      resultado[*returnSize] = valormin;
      (*returnSize)++;
    }
  }
  return resultado;
}