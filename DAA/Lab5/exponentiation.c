#include <stdio.h>

unsigned long long int divideAndConquerExponentiation(int a, int n, int *countDivideNConquer)
{
  ++(*countDivideNConquer);
  if (n == 1)
    return a;
  if (n == 0)
    return 1;
  int number = divideAndConquerExponentiation(a, n / 2, countDivideNConquer);
  if (n & 1)
    return number * a * number;
  else
    return number * number;
}
unsigned long long int bruteForceExponentiation(int a, int n, int *countBrute)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return a;
  int num = a;
  ++(*countBrute);
  for (int i = 1; i < n; i++)
  {
    ++(*countBrute);
    num *= a;
  }
  return num;
}

int main()
{
  int a, b, countBrute = 0, countDivideNConquer = 0;
  printf("Enter the base and exponent :- ");
  scanf("%d %d", &a, &b);
  unsigned long long int pow1 = divideAndConquerExponentiation(a, b, &countDivideNConquer);
  unsigned long long int pow2 = bruteForceExponentiation(a, b, &countBrute);
  printf("Soln by Divide and conquer :-\n");
  printf("Ans: %lli\nNo. of Multiplications:- %d\n", pow1, countDivideNConquer);
  printf("Soln by Brute Force :-\n");
  printf("Ans: %lli\nNo. of Multiplications:- %d\n", pow2, countBrute);

  return 0;
}