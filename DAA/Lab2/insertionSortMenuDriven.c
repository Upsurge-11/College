#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSortAsc(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void insertionSortDesc(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] < key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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
    printf("5. Find the time complexity to sort random data in ascending order.\n");
    printf("6. Find the time complexity to sort data in ascending order which is already sorted in ascending order.\n");
    printf("7. Find the time complexity to sort data in ascending order which is already sorted in descending order.\n");

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
      insertionSortAsc(arr, n);
      printf("The array after sorting :-\n");
      displayArray(arr, n);
      break;
    case 4:
      printf("The array before sorting :-\n");
      displayArray(arr, n);
      insertionSortDesc(arr, n);
      printf("The array after sorting :-\n");
      displayArray(arr, n);
      break;
    case 5:
      printf("Time complexity of sorting a random array :-\n");
      randomArray(arr, n);
      printf("Array :- ");
      displayArray(arr, n);
      start = clock();
      insertionSortAsc(arr, n);
      end = clock();
      printf("Time complexity:- %lf\n", timeComplexity(start, end));
      break;
    case 6:
      printf("Time complexity of sorting a array already sorted in ascending order :-\n");
      randomArray(arr, n);
      insertionSortAsc(arr, n);
      printf("Array :- ");
      displayArray(arr, n);
      start = clock();
      insertionSortAsc(arr, n);
      end = clock();
      printf("Time complexity:- %lf\n", timeComplexity(start, end));
      break;
    case 7:
      printf("Time complexity of sorting an array already sorted in descending order :-\n");
      randomArray(arr, n);
      insertionSortDesc(arr, n);
      printf("Array :- ");
      displayArray(arr, n);
      start = clock();
      insertionSortAsc(arr, n);
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