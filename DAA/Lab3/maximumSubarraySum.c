#include <stdio.h>

// int maxSubArraySum(int a[], int size)
// {
//   int maxSubArraySum = -999999, maxAbhiTak = 0;

//   for (int i = 0; i < size; i++)
//   {
//     maxAbhiTak = maxAbhiTak + a[i];
//     if (maxSubArraySum < maxAbhiTak)
//       maxSubArraySum = maxAbhiTak;

//     if (maxAbhiTak < 0)
//       maxAbhiTak = 0;
//   }
//   return maxSubArraySum;
// }

int maxSubArraySum(int a[], int size)
{
  int ans = 0;
  for (int i = 0; i < size; i++)
  {
    int sum = 0;
    for (int j = i; j < size; j++)
    {
      sum += a[j];
      if (ans < sum)
      {
        ans = sum;
      }
    }
  }
  return ans;
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
  printf("%d\n", maxSubArraySum(arr, n));

  return 0;
}