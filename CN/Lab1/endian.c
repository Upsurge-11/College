#include <stdio.h>

int changeEndian(int num)
{
  int byte0, byte1, byte2, byte3;
  byte0 = (num & 0x000000FF) >> 0;
  byte1 = (num & 0x0000FF00) >> 8;
  byte2 = (num & 0x00FF0000) >> 16;
  byte3 = (num & 0xFF000000) >> 24;
  return ((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));
}

void displayBytes(int n)
{
  int a = (n >> 24) & 0xFF;
  int b = (n >> 16) & 0xFF;
  int c = (n >> 8) & 0xFF;
  int d = n & 0xFF;

  printf("%d %d %d %d\n", a, b, c, d);
}

int main()
{
  unsigned int x = 1;
  char *c = (char *)&x;

  printf("*c is: 0x%x\n", *c);
  if (*c == 0x10)
  {
    printf("Machine is little endian. \n");
  }
  else
  {
    printf("Machine is big endian. \n");
  }

  int n;
  scanf("%d", &n);

  displayBytes(n);

  int changedEndian = changeEndian(n);
  printf("%d\n", changedEndian);

  return 0;
}