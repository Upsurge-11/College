#include <stdio.h>

void swap(int *a, int *b)
{
  int temp;

  temp = *b;
  *b = *a;
  *a = temp;
}

void swapVal(int a, int b)
{
  int temp;
  temp = b;
  b = a;
  a = temp;
}

int main(int argc, char const **argv)
{
  int x, y;
  sscanf(argv[1], "%d", &x);
  sscanf(argv[2], "%d", &y);

  printf("Before Swapping by call by address\nx = %d\ny = %d\n", x, y);

  swap(&x, &y);

  printf("After Swapping by call by address\nx = %d\ny = %d\n", x, y);

  printf("Before Swapping by call by value\nx = %d\ny = %d\n", x, y);

  swapVal(x, y);
  printf("After Swapping by call by value\nx = %d\ny = %d\n", x, y);

  return 0;
}