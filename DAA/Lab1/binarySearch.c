#include <stdio.h>

int binarySearch(int arr[], int n, int low, int high, int x)
{
  if (low > high)
    return -1;

  int mid = (low + high) / 2;

  if (x == arr[mid])
    return mid;

  else if (x < arr[mid])
    return binarySearch(arr, n, low, mid - 1, x);

  else
    return binarySearch(arr, n, mid + 1, high, x);
}
int main()
{
  int arr[] = {4, 5, 7, 8, 10};
  int x = 10;
  int n = sizeof(arr) / sizeof(arr[0]);
  int low = 0, high = n - 1;

  int result = binarySearch(arr, n, low, high, x);
  if (result == -1)
    printf("Element is not present in array");
  else
    printf("Element is present at index %d", result);

  return 0;
}