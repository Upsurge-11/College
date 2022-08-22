#include <stdio.h>

void printCommon(int boys[], int b, int girls[], int g)
{
  int i = 0, j = 0;
  while (b > i && g > j)
  {
    if (boys[i] < girls[j])
    {
      i++;
    }
    else if (girls[j] < boys[i])
    {
      j++;
    }
    else
    {
      printf("Common age is %d.\n", boys[i]);
      i++;
      j++;
    }
  }
}

int main()
{
  int b, g;
  printf("Enter the number of boys :- ");
  scanf("%d", &b);
  printf("Enter the number of girls :- ");
  scanf("%d", &g);
  int boys[b], girls[g];
  printf("Enter the ages of the boys :- ");
  for (int i = 0; i < b; i++)
  {
    scanf("%d", &boys[i]);
  }
  printf("Enter the ages of the girls :- ");
  for (int i = 0; i < g; i++)
  {
    scanf("%d", &girls[i]);
  }
  printCommon(boys, b, girls, g);

  return 0;
}