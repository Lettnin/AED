#include <stdbool.h>

bool isPalindrome(int x)
{

  if (x < 0)
  {
    return false;
  }

  int atual = x;
  long int invertido = 0;

  while (x != 0)
  {
    int num = x % 10;
    invertido = invertido * 10 + num;
    x /= 10;
  }

  return atual == invertido;
}
