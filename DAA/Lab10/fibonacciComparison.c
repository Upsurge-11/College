#include <stdio.h>

int fib(int n)
{
  if (n == 0)
  {
    return 0;
  }
  else if (n == 1)
  {
    return 1;
  }
  else
  {
    return fib(n - 1) + fib(n - 2);
  }
}

int fibonacci(int n)
{
  int a = 0;
  int b = 1;
  int c = 0;
  for (int i = 0; i < n; i++)
  {
    c = a + b;
    a = b;
    b = c;
  }
  return a;
}

int main()
{

  return 0;
}