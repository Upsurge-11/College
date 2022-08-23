#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int randInt()
{
  __time_t t;
  srand((unsigned)t * rand());
  return rand() % 1000;
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
}

void analyse(int n)
{
  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    int num = randInt();
    arr[i] = num;
  }
  int mx = INT_MIN, mn = INT_MAX, i;
  clock_t t;
  double rt, bt;
  t = clock();
  findMinAndMaxBrute(arr, n);
  t = clock() - t;
  bt = ((double)t) / CLOCKS_PER_SEC;
  t = clock();
  findMinAndMax(arr, 0, n - 1, &mn, &mx);
  t = clock() - t;
  rt = ((double)t) / CLOCKS_PER_SEC;
  printf("%d\t%5d\t%10f\t%10f", n / 500, n, rt, bt);
}

int main()
{
  printf("S.No.\tVal N\t Using DnC\t Using Brute Force\n");
  for (int i = 500; i <= 5000; i += 500)
  {
    analyse(i);
    printf("\n");
  }

  return 0;
}