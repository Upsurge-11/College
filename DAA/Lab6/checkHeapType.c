// 20 18 10 12 9 9 3 5 6 8

#include <stdio.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void MaxHeapify(int arr[], int i, int n)
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i;

  if (l < n && arr[l] > arr[i])
    largest = l;
  if (r < n && arr[r] > arr[largest])
    largest = r;
  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    MaxHeapify(arr, largest, n);
  }
}

void MinHeapify(int arr[], int i, int n)
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int smallest = i;

  if (l < n && arr[l] < arr[i])
    smallest = l;
  if (r < n && arr[r] < arr[smallest])
    smallest = r;
  if (smallest != i)
  {
    swap(&arr[i], &arr[smallest]);
    MinHeapify(arr, i, n);
  }
}

void convertMaxHeap(int arr[], int n)
{
  for (int i = (n - 2) / 2; i >= 0; i--)
    MaxHeapify(arr, i, n);
}

void convertMinHeap(int arr[], int n)
{
  for (int i = (n - 2) / 2; i >= 0; i--)
    MinHeapify(arr, i, n);
}

bool isMinHeap(int arr[], int n)
{
  for (int i = 0; i <= (n - 2) / 2; i++)
  {
    if (arr[2 * i + 1] < arr[i])
      return false;
    if (2 * i + 2 < n && arr[2 * i + 2] < arr[i])
      return false;
  }
  return true;
}

bool isMaxHeap(int arr[], int n)
{
  for (int i = 0; i <= (n - 2) / 2; i++)
  {
    if (arr[2 * i + 1] > arr[i])
      return false;
    if (2 * i + 2 < n && arr[2 * i + 2] > arr[i])
      return false;
  }
  return true;
}

bool MinMax(int arr[], int n)
{
  if (isMinHeap(arr, n))
  {
    convertMaxHeap(arr, n);
    return true;
  }
  return false;
}

bool MaxMin(int arr[], int n)
{
  if (isMaxHeap(arr, n))
  {
    convertMinHeap(arr, n);
    return true;
  }
  return false;
}

void displayArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Enter the size of the array :- ");
  scanf("%d", &n);

  int a[n];

  printf("Enter the elements of the array :- ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  if (MaxMin(a, n))
  {
    printf("MAX\n");
    displayArray(a, n);
  }

  if (MinMax(a, n))
  {
    printf("MIN\n");
    displayArray(a, n);
  }

  return 0;
}