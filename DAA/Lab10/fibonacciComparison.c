#include <stdio.h>
#include <math.h>

int fibRecur(int n)
{
  if (n <= 1)
    return n;
  else
  {
    return fibRecur(n - 1) + fibRecur(n - 2);
  }
}

int fibIter(int n)
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

void multiply(int F[2][2], int M[2][2])
{
  int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
  int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
  int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
  int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(int F[2][2], int n)
{
  if (n == 0 || n == 1)
    return;
  int M[2][2] = {{1, 1}, {1, 0}};

  power(F, n / 2);
  multiply(F, F);

  if (n % 2 != 0)
    multiply(F, M);
}

int fibDnC(int n)
{
  int F[2][2] = {{1, 1}, {1, 0}};
  if (n == 0)
    return 0;
  power(F, n - 1);
  return F[0][0];
}

int main()
{
  int n;
  scanf("%d", &n);
  printf("Recursion :- Fibonacci of %d is %d.\n", n, fibRecur(n));
  printf("Iterative :- Fibonacci of %d is %d.\n", n, fibIter(n));
  printf("Divide and Conquer :- Fibonacci of %d is %d.\n", n, fibDnC(n));

  return 0;
}