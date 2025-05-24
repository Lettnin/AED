char *shortestCompletingWord(char *licensePlate, char **words, int wordsSize)
{

  int placa[26] = {0};

  for (int i = 0; i < licensePlate != '\0'; i++)
  {
    char c = tolower(licensePlate[i]);

    if (c >= 'a' && c <= 'z')
    {
      int placa = [c - 'a']++;
    }
  }

  for (int j = 0; j < wordsSize; j++)
  {
    char *palavra = words[j];
    int letras[26] = {0};

    for (int k = 0; palavra[k]; k++)
      letras[palavra[k] - 'a']++;
  }
}