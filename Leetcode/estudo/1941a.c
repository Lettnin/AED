// Given a string s, return true if s is a good string, or false otherwise.
// A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

int main()
{
  char str1[] = "abab";
  char str2[] = "aabbc";

  printf("Resultado 1: %d\n", areOccurrencesEqual(str1));
  printf("Resultado 2: %d\n", areOccurrencesEqual(str2));

  return 0;
}
