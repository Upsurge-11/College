// 20 18 10 12 9 9 3 5 6 8

#include <stdio.h>
#include <stdbool.h>

void swapMax(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void maxHeapify(int arr[], int i, int n)
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
    swapMax(&arr[i], &arr[largest]);
    maxHeapify(arr, largest, n);
  }
}

void convertMaxHeap(int arr[], int n)
{
  for (int i = (n - 2) / 2; i >= 0; i--)
    maxHeapify(arr, i, n);
}

void swapMin(int arr[], int first, int second)
{
  int auxiliary = arr[first];
  arr[first] = arr[second];
  arr[second] = auxiliary;
}

int compare(int arr[], int left, int right, int root, int size)
{
  int location = -1;
  if ((left < size && arr[left] < arr[root]))
  {
    if ((right < size && arr[right] < arr[left]))
    {
      swapMin(arr, right, root);
      location = right;
    }
    else
    {
      swapMin(arr, left, root);
      location = left;
    }
  }
  else if ((right < size && arr[right] < arr[root]))
  {
    swapMin(arr, right, root);
    location = right;
  }
  return location;
}

void minHeapify(int arr[], int size, int root)
{
  int left = 2 * root + 1;
  int right = 2 * root + 2;
  int step = compare(arr, left, right, root, size);
  if ((step != -1))
  {
    minHeapify(arr, size, step);
  }
}
void convertMinHeap(int arr[], int size)
{
  int i = (size / 2) - 1;
  while (i >= 0)
  {
    minHeapify(arr, size, i);
    i--;
  }
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