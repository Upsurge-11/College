#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void newSort(int a[], int n)
{
  if (n == 1)
    return;
  else if (n == 2)
  {
    if (a[0] > a[1])
    {
      swap(&a[0], &a[1]);
    }
  }
  else
  {
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  newSort(a, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  return 0;
}