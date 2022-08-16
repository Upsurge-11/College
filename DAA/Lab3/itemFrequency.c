#include <stdio.h>
#include <stdbool.h>

bool frequencyOfElementsN(int arr[], int n, int element)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == element)
    {
      count++;
    }
    if (count > n / 2)
    {
      return true;
    }
  }
  return false;
}

bool frequencyOfElementsN2(int arr[], int n, int element)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == element)
    {
      arr[i] = 1;
      for (int j = i + 1; j < n; j++)
      {
        if (arr[j] == element)
          arr[i]++;
        if (arr[i] > n / 2)
        {
          return true;
        }
      }
      arr[i] = element;
      return false;
    }
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  int element;
  scanf("%d", &element);
  if (frequencyOfElementsN(arr, n, element))
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  if (frequencyOfElementsN2(arr, n, element))
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}