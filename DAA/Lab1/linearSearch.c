#include <stdio.h>

int linearSearch(int arr[], int n, int x)
{
  int i;
  for (i = 0; i < n; i++)
    if (arr[i] == x)
      return i;
  return -1;
}

int main()
{
  int arr[] = {4, 5, 2, 3, 11, 10};
  int x = 10;
  int n = sizeof(arr) / sizeof(arr[0]);

  int result = linearSearch(arr, n, x);
  if (result == -1)
    printf("Element is not present in array");
  else
    printf("Element is present at index %d", result);
  return 0;
}