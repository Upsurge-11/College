#include <stdio.h>

struct pkt
{
  char ch1;
  char ch2[2];
  char ch3;
};

int byteArraytoInt(unsigned char b[])
{
  return (b[0] << 24) + ((b[1] & 0xFF) << 16) + ((b[2] & 0xFF) << 8) + (b[3] & 0xFF);
}

int main()
{
  int n;
  scanf("%d", &n);
  int a = (n >> 24) & 0xFF;
  int b = (n >> 16) & 0xFF;
  int c = (n >> 8) & 0xFF;
  int d = n & 0xFF;

  struct pkt i;
  i.ch1 = (char)(a);
  i.ch2[0] = (char)(b);
  i.ch2[1] = (char)(c);
  i.ch3 = (char)(d);

  printf("%d %d %d %d\n", i.ch1, i.ch2[0], i.ch2[1], i.ch3);

  unsigned char bytes[4] = {i.ch1, i.ch2[0], i.ch2[1], i.ch3};

  int ans = byteArraytoInt(bytes);

  printf("%d\n", ans);

  return 0;
}