char *shortestCompletingWord(char *licensePlate, char **words, int wordsSize)
{
  int placa[26] = {0};
  char *resposta = NULL;

  for (int i = 0; i < licensePlate[i] != '\0'; i++)
  {
    char caracter = tolower(licensePlate[i]);

    if (caracter >= 'a' && caracter <= 'z')
    {
      placa[caracter - 'a']++;
    }
  }

  for (int j = 0; j < wordsSize; j++)
  {
    char *palavra = words[j];

    int letras[26] = {0};
    for (int k = 0; palavra[k]; k++)
    {
      char caracter = tolower(palavra[k]);
      if (caracter >= 'a' && caracter <= 'z')
      {
        letras[caracter - 'a']++;
      }
    }

    int palavraValida = 1;
    for (int i = 0; i < 26; i++)
    {
      if (letras[i] < placa[i])
      {
        palavraValida = 0;
        break;
      }
    }

    if (palavraValida)
    {
      if (resposta == NULL || strlen(palavra) < strlen(resposta))
      {
        resposta = palavra;
      }
    }
  }
  return resposta;
}