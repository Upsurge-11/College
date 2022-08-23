#include <stdio.h>

int count_divide_and_conquer = 0;
int count_naive = 0;

unsigned long long int divideAndConquerExponentiation(int a, int n)
{
  ++count_divide_and_conquer;
  if (n == 1)
    return a;
  if (n == 0)
    return 1;
  int number = divideAndConquerExponentiation(a, n / 2);
  if (n & 1)
    return number * a * number;
  else
    return number * number;
}
unsigned long long int bruteForceExponentiation(int a, int n)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return a;
  int num = a;
  ++count_naive;
  for (int i = 1; i < n; i++)
  {
    ++count_naive;
    num *= a;
  }
  return num;
}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  unsigned long long int pow1 = divideAndConquerExponentiation(a, b);
  unsigned long long int pow2 = bruteForceExponentiation(a, b);
  printf("Soln by Divide and conquer :-\n");
  printf("Ans: %lli\nNo. of Multiplications:- %d\n", pow1, count_divide_and_conquer);
  printf("Soln by Brute Force :-\n");
  printf("Ans: %lli\nNo. of Multiplications:- %d\n", pow2, count_naive);

  return 0;
}