#include <stdio.h>
#include <limits.h>

void findMinAndMax(int nums[], int low, int high, int *min, int *max)
{
  if (low == high)
  {
    if ((*max) < nums[low])
    {
      (*max) = nums[low];
    }
    if ((*min) > nums[high])
    {
      (*min) = nums[high];
    }
    return;
  }

  if (high - low == 1)
  {
    if (nums[low] < nums[high])
    {
      if ((*min) > nums[low])
      {
        (*min) = nums[low];
      }
      if ((*max) < nums[high])
      {
        (*max) = nums[high];
      }
    }
    else
    {
      if ((*min) > nums[high])
      {
        (*min) = nums[high];
      }
      if ((*max) < nums[low])
      {
        (*max) = nums[low];
      }
    }
    return;
  }

  int mid = (low + high) / 2;

  findMinAndMax(nums, low, mid, min, max);

  findMinAndMax(nums, mid + 1, high, min, max);
}

void findMinAndMaxBrute(int nums[], int n)
{
  int min = INT_MAX;
  int max = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (min > nums[i])
    {
      min = nums[i];
    }
    if (max < nums[i])
    {
      max = nums[i];
    }
  }
  printf("%d %d\n", min, max);
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
  int min = INT_MAX, max = INT_MIN;
  findMinAndMax(a, 0, n - 1, &min, &max);
  printf("%d %d\n", min, max);
  return 0;
}