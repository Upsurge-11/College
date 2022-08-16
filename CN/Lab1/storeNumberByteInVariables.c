#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  char a = (char)((n >> 24) & 0xFF);
  char b = (char)((n >> 16) & 0xFF);
  char c = (char)((n >> 8) & 0xFF);
  char d = (char)(n & 0xFF);

  printf("%d %d %d %d\n", a, b, c, d);

  return 0;
}