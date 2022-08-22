#include <stdio.h>
#include <limits.h>
#include <time.h>

double timeComplexity(clock_t start, clock_t end)
{
  return (double)(((double)(end - start)) / CLOCKS_PER_SEC);
}

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
  clock_t start = clock();
  findMinAndMax(a, 0, n - 1, &min, &max);
  clock_t end = clock();
  printf("%d %d\n", min, max);
  printf("Time complexity for finding the element in optimised way : %lf\n", timeComplexity(start, end));
  min = INT_MAX, max = INT_MIN;
  start = clock();
  findMinAndMaxBrute(a, n);
  end = clock();
  printf("Time complexity for finding the element in brute force way : %lf\n", timeComplexity(start, end));

  return 0;
}