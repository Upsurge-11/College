#include <stdio.h>

void printMaxActivities(int start[], int finish[], int n)
{
  int i, j;
  printf("Following activities are selected :- ");
  i = 0;
  printf("%d ", i);

  for (j = 1; j < n; j++)
  {
    if (start[j] >= finish[i])
    {
      printf("%d ", j);
      i = j;
    }
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Enter the number of activities :- ");
  scanf("%d", &n);
  int start[n], finish[n];
  printf("Enter sorted array according to the finish time :- \n");
  for (int i = 0; i < n; i++)
  {
    printf("Enter the start time of activity %d :- ", i);
    scanf("%d", &start[i]);
    printf("Enter the finish time of activity %d :- ", i);
    scanf("%d", &finish[i]);
  }
  printMaxActivities(start, finish, n);
  return 0;
}
