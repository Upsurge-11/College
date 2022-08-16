#include <string.h>
#include <stdio.h>

int main()
{
  char s[100];
  printf("Enter  the string : ");
  gets(s);

  char s1[20] = {}, s2[20] = {};

  int i = 0, j = 0, k = 0, x = 0;

  while (s[i] != ' ')
  {
    s1[i] = s[i];

    i++;
  }
  i++;

  while (i < strlen(s))
  {
    s2[j] = s[i];
    i++;
    j++;
  }
  char s3[100] = {};

  while (k < strlen(s2))
  {
    s3[k] = s2[k];
    k++;
  }
  s3[k] = ' ';
  k++;

  while (k < strlen(s))
  {
    s3[k] = s1[x];
    k++;
    x++;
  }

  printf("%s", s3);

  return 0;
}