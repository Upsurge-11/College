#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void merge(int arr[], int l, int m, int r, int *comparison)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      (*comparison)++;
      i++;
    }
    else
    {
      arr[k] = R[j];
      (*comparison)++;
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void newSortUtil(int arr[], int l, int r, int *comparison)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    newSortUtil(arr, l, m, comparison);
    newSortUtil(arr, m + 1, r, comparison);

    merge(arr, l, m, r, comparison);
  }
}

void newSort(int a[], int n, int *comparison)
{
  if (n == 1)
    return;
  else if (n == 2)
  {
    if (a[0] > a[1])
    {
      (*comparison)++;
      swap(&a[0], &a[1]);
    }
  }
  else
  {
    int m = (2 * n) / 3;
    newSortUtil(a, 0, m, comparison);
    int o = n / 3;
    newSortUtil(a, 0, m, comparison);
    newSortUtil(a, o, n - 1, comparison);
  }
}

int main()
{
  int n, comparison = 0;
  printf("Enter the size of the array :- ");
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements of the array :- ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  newSort(a, n, &comparison);
  printf("The sorted array is :- ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\nThe number of comparisons is :- %d\n", comparison);
  return 0;
}