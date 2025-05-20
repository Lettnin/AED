bool lemonadeChange(int *bills, int billsSize)
{
  int nota5 = 0;
  int nota10 = 0;

  for (int i = 0; i < billsSize; i++)
  {
    int notarecebida = bills[i];

    if (notarecebida == 5)
    {
      nota5++;
    }

    else if (notarecebida == 10)
    {
      if (nota5 > 0)
      {
        nota5--;
        nota10++;
      }
      else
      {
        return false;
      }
    }

    else if (notarecebida == 20)
    {
      if (nota10 > 0 && nota5 > 0)
      {
        nota5--;
        nota10--;
      }
      else if (nota5 >= 3)
      {
        nota5 -= 3;
      }
      else
      {
        return false;
      }
    }
  }
  return true;
}