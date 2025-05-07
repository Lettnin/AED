#include <stdio.h>

int sum(int num1, int num2);

int main()
{
  printf("%d", sum(10, 7));
}

int sum(int num1, int num2)
{
  return num1 + num2;
}