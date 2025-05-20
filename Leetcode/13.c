int valorromano(char r)
{
  switch (r)
  {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;

  default:
    return 0;
  }
}

int romanToInt(char *s)
{
  int total = 0;
  int len = strlen(s);

  for (int i = 0; i < len; i++)
  {
    int atual = valorromano(s[i]);
    int proximo = valorromano(s[i + 1]);

    if (atual < proximo)
    {
      total = total + (proximo - atual);
      i++;
    }
    else
    {
      total += atual;
    }
  }
  return total;
}