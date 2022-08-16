#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeAsc(int arr[], int left, int m, int right)
{
  int i, j, k;
  int n1 = m - left + 1;
  int n2 = right - m;

  int leftArray[n1], rightArray[n2];

  for (i = 0; i < n1; i++)
    leftArray[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    rightArray[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2)
  {
    if (leftArray[i] <= rightArray[j])
    {
      arr[k] = leftArray[i];
      i++;
    }
    else
    {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = rightArray[j];
    j++;
    k++;
  }
}

void mergeSortAsc(int arr[], int left, int right)
{
  if (left < right)
  {
    int m = left + (right - left) / 2;

    mergeSortAsc(arr, left, m);
    mergeSortAsc(arr, m + 1, right);

    mergeAsc(arr, left, m, right);
  }
}

void mergeDesc(int arr[], int left, int m, int right)
{
  int i, j, k;
  int n1 = m - left + 1;
  int n2 = right - m;

  int leftArray[n1], rightArray[n2];

  for (i = 0; i < n1; i++)
    leftArray[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    rightArray[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2)
  {
    if (leftArray[i] >= rightArray[j])
    {
      arr[k] = leftArray[i];
      i++;
    }
    else
    {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = rightArray[j];
    j++;
    k++;
  }
}

void mergeSortDesc(int arr[], int left, int right)
{
  if (left < right)
  {
    int m = left + (right - left) / 2;

    mergeSortDesc(arr, left, m);
    mergeSortDesc(arr, m + 1, right);

    mergeDesc(arr, left, m, right);
  }
}

void randomArray(int arr[], int n)
{
  int rand_max;
  printf("Enter the largest random number you want :- ");
  scanf("%d", &rand_max);
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % rand_max;
  }
}

void displayArray(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

double timeComplexity(clock_t start, clock_t end)
{
  return (double)(((double)(end - start)) / CLOCKS_PER_SEC);
}

int main()
{
  int t = 1;
  int n;
  printf("Enter the size of the array :- ");
  scanf("%d", &n);
  int arr[n];
  while (t)
  {
    printf("0. Quit.\n");
    printf("1. Create array with random Numbers.\n");
    printf("2. Display the array.\n");
    printf("3. Sort the array in ascending order.\n");
    printf("4. Sort the array in descending order.\n");
    printf("5. Find the time complexity to sort ascending of random data.\n");
    printf("6. Find the time complexity to sort ascending of data already sorted in ascending order.\n");
    printf("7. Find the time complexity to sort ascending of data already sorted in descending order.\n");

    int choice;
    printf("Enter Your choice :-");
    scanf("%d", &choice);
    clock_t start, end;

    switch (choice)
    {
    case 0:
      printf("Exiting the code....\n");
      t = 0;
      break;
    case 1:
      randomArray(arr, n);
      printf("Random array generated...\n");
      break;
    case 2:
      printf("The current array is :- \n");
      displayArray(arr, n);
      break;
    case 3:
      printf("The array before sorting :-\n");
      displayArray(arr, n);
      mergeSortAsc(arr, 0, n - 1);
      printf("The array after sorting :-\n");
      displayArray(arr, n);
      break;
    case 4:
      printf("The array before sorting :-\n");
      displayArray(arr, n);
      mergeSortDesc(arr, 0, n - 1);
      printf("The array after sorting :-\n");
      displayArray(arr, n);
      break;
    case 5:
      printf("Time complexity of sorting a random array :-\n");
      randomArray(arr, n);
      printf("Array :- ");
      displayArray(arr, n);
      start = clock();
      mergeSortAsc(arr, 0, n - 1);
      end = clock();
      printf("Time complexity:- %lf\n", timeComplexity(start, end));
      break;
    case 6:
      printf("Time complexity of sorting a array already sorted in ascending order :-\n");
      randomArray(arr, n);
      mergeSortAsc(arr, 0, n - 1);
      printf("Array :- ");
      displayArray(arr, n);
      start = clock();
      mergeSortAsc(arr, 0, n - 1);
      end = clock();
      printf("Time complexity:- %lf\n", timeComplexity(start, end));
      break;
    case 7:
      printf("Time complexity of sorting an array already sorted in descending order :-\n");
      randomArray(arr, n);
      mergeSortDesc(arr, 0, n - 1);
      printf("Array :- ");
      displayArray(arr, n);
      start = clock();
      mergeSortAsc(arr, 0, n - 1);
      end = clock();
      printf("Time complexity:- %lf\n", timeComplexity(start, end));
      break;
    default:
      printf("Invalid choice...\n");
      break;
    }
  }

  return 0;
}