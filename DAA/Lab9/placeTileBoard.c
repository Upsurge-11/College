#include <stdio.h>

int countWays(int n)
{
  if(n < 4)
  {
    return 1;
  }
  return countWays(n-2) + countWays(n-4);
}

int main()
{
  printf("Enter the width of the board :- ");
  int n;
  scanf("%d", &n);

  printf("The number of possible ways is %d.\n", countWays(n));

  return 0;
}
