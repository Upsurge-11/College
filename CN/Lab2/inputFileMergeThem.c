#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *combineStrings(char *inputA, char *inputB)
{
  size_t len = 0, lenB = 0;
  while (inputA[len] != '\0')
    len++;
  while (inputB[lenB] != '\0')
    lenB++;
  char *output = malloc(len + lenB);
  sprintf((char *)output, "%s%s", inputA, inputB);
  return output;
}

int main()
{
  char hi[] = "Arghyadeep Mukherjee";
  char bye[] = " is best.";
  char *huihui;
  FILE *fileptr1;
  FILE *fileptr2;
  FILE *fileptr3;

  fileptr1 = fopen("./1.txt", "w");
  fileptr2 = fopen("./2.txt", "w");
  fileptr3 = fopen("./3.txt", "w");

  if (fileptr1 == NULL)
  {
    printf("File couldn't be opened\n\a\a");
    fclose(fileptr1);
    exit(0);
  }

  if (fileptr2 == NULL)
  {
    printf("File couldn't be opened\n\a\a");
    fclose(fileptr2);
    exit(0);
  }

  if (fileptr3 == NULL)
  {
    printf("File couldn't be opened\n\a\a");
    fclose(fileptr3);
    exit(0);
  }

  huihui = combineStrings(hi, bye);

  fputs(hi, fileptr1);
  fclose(fileptr1);

  fputs(bye, fileptr2);
  fclose(fileptr2);

  fputs(huihui, fileptr3);
  fclose(fileptr3);

  return 0;
}