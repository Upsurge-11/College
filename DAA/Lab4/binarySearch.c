#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int number[], int first, int last)
{
  int i, j, pivot, temp;
  if (first < last)
  {
    pivot = first;
    i = first;
    j = last;
    while (i < j)
    {
      while (number[i] <= number[pivot] && i < last)
        i++;
      while (number[j] > number[pivot])
        j--;
      if (i < j)
      {
        temp = number[i];
        number[i] = number[j];
        number[j] = temp;
      }
    }
    temp = number[pivot];
    number[pivot] = number[j];
    number[j] = temp;
    quicksort(number, first, j - 1);
    quicksort(number, j + 1, last);
  }
}

double timeComplexity(clock_t start, clock_t end)
{
  return (double)(((double)(end - start)) / CLOCKS_PER_SEC);
}

int binarySearch(int arr[], int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}

int main()
{
  srand(time(NULL));
  printf("Enter the size of the array :- ");
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = rand() % 100;
  }
  quicksort(a, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  printf("Enter the element you want to search :-");
  int x;
  scanf("%d", &x);
  clock_t start = clock();
  int ans = binarySearch(a, 0, n - 1, x);
  clock_t end = clock();
  printf("%d\n", ans);
  printf("%lf\n", timeComplexity(start, end));

  return 0;
}