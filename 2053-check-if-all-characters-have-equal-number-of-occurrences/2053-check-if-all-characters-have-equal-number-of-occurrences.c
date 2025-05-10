bool areOccurrencesEqual(char *s)
{
  int count[26] = {0};
  int len = strlen(s);

  for (int i = 0; i < len; i++)
  {
    char c = s[i];
    if (c >= 'a' && c <= 'z')
    {
      count[c - 'a']++;
    }
  }

  int frequencia = 0;
  for (int i = 0; i < 26; i++)
  {
    if (count[i] > 0)
    {
      if (frequencia == 0)
      {
        frequencia = count[i];
      }
      else if (count[i] != frequencia)
      {
        return false;
      }
    }
  }

  return true;
}