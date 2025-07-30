// You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
// Return the score of s.

int scoreOfString(char *string)
{
  int pontuacao = 0;
  for (int i = 0; string[i + 1] != '\0'; i++)
  {
    pontuacao = pontuacao + abs(string[i] - string[i + 1]);
  }
  return pontuacao;
}