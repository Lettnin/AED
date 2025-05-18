bool verifica(char **board, int boardSize, int *boardColSize, char *word, int linha, int coluna, int iword);

bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
  for (int i = 0; i < boardSize; i++)
  {
    for (int j = 0; j < boardColSize[0]; j++)
    {
      if (verifica(board, boardSize, boardColSize, word, i, j, 0))
      {
        return true;
      }
    }
  }
  return false;
}

bool verifica(char **board, int boardSize, int *boardColSize, char *word, int linha, int coluna, int iword)
{
  if (word[iword] == '\0')
  {
    return true;
  }

  if (linha < 0 || linha >= boardSize || coluna < 0 || coluna >= boardColSize[0])
  {
    return false;
  }

  if (board[linha][coluna] != word[iword])
  {
    return false;
  }

  char aux = board[linha][coluna];
  board[linha][coluna] = '$';

  if (verifica(board, boardSize, boardColSize, word, linha + 1, coluna, iword + 1))
  {
    board[linha][coluna] = aux;
    return true;
  }
  else if (verifica(board, boardSize, boardColSize, word, linha - 1, coluna, iword + 1))
  {
    board[linha][coluna] = aux;
    return true;
  }
  else if (verifica(board, boardSize, boardColSize, word, linha, coluna + 1, iword + 1))
  {
    board[linha][coluna] = aux;
    return true;
  }
  else if (verifica(board, boardSize, boardColSize, word, linha, coluna - 1, iword + 1))
  {
    board[linha][coluna] = aux;
    return true;
  }

  board[linha][coluna] = aux;
  return false;
}
