#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt(int n)
{
  __time_t t;
  srand((unsigned)t * rand());
  return rand() % n;
}

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

void analyse(int n)
{
  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    arr[i] = i + 1;
  }
  clock_t t;
  double time_taken;
  int x, result;
  x = 0;
  t = clock();
  result = binarySearch(arr, 0, n - 1, x);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC;
  double count3 = time_taken;
  x = arr[randInt(n)];
  t = clock();
  result = binarySearch(arr, 0, n - 1, x);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC;
  double count1 = time_taken;
  x = arr[n / 2];
  t = clock();
  result = binarySearch(arr, 0, n - 1, x);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC;
  double count2 = time_taken;
  printf("%f %f %f \n", count1, count2, count3);
}

int main()
{
  printf("avg\t best\tworst\n");
  for (int i = 5001; i <= 50001; i += 5000)
  {
    analyse(i);
  }

  return 0;
}