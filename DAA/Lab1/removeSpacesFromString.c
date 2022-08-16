#include <stdio.h>

int main()
{
  char name[] = "Arghyadeep Mukherjee";

  int c = 0, j = 0;
  while (name[c] != '\0')
  {
    if (name[c] != ' ')
    {
      name[j++] = name[c];
    }
    c++;
  }
  name[j] = '\0';
  printf("%s", name);

  return 0;
}