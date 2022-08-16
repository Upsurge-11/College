#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  printf("Enter the total number of elements: ");
  scanf("%d", &n);

  int *data;
  data = (int *)calloc(n, sizeof(int));
  if (data == NULL)
  {
    printf("Error!!! memory not allocated.");
    exit(0);
  }

  for (int i = 0; i < n; ++i)
  {
    printf("Enter number %d: ", i + 1);
    scanf("%d", data + i);
  }

  for (int i = 1; i < n; ++i)
  {
    if (*data < *(data + i))
    {
      *data = *(data + i);
    }
  }
  printf("Largest number = %d\n", *data);

  for (int i = 1; i < n; ++i)
  {
    if (*data > *(data + i))
    {
      *data = *(data + i);
    }
  }
  printf("Smallest number = %d\n", *data);

  free(data);

  return 0;
}