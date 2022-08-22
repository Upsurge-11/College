#include <stdio.h>
#include <time.h>

double timeComplexity(clock_t start, clock_t end)
{
  return (double)(((double)(end - start)) / CLOCKS_PER_SEC);
}

void quicksort(int number[], int first, int last, int *partition, int *comparison)
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
      {
        i++;
        (*comparison)++;
      }
      while (number[j] > number[pivot])
      {
        j--;
        (*comparison)++;
      }
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
    quicksort(number, first, j - 1, partition, comparison);
    quicksort(number, j + 1, last, partition, comparison);
    (*partition) += 2;
  }
}

int main()
{
  printf("Enter the size of the array :- ");
  int n;
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements of the array :- ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  int partition = 0, comparison = 0;
  clock_t start = clock();
  quicksort(a, 0, n - 1, &partition, &comparison);
  clock_t end = clock();
  printf("Sorted array is :- ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }

  printf("\nNumber Of Partitions :- %d\n", partition);
  printf("Number Of Comparisons :- %d\n", comparison);
  printf("The time complexity of sorting this array is %lf.\n", timeComplexity(start, end));

  return 0;
}