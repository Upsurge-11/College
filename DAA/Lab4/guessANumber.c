#include <stdio.h>
#include <stdlib.h>

void guessANumber(int n)
{
  int guess;
  while (1)
  {
    scanf("%d", &guess);
    if (guess == n)
    {
      printf("You guessed it!\n");
      break;
    }
    else if (guess > n)
    {
      printf("Too high!\n");
    }
    else
    {
      printf("Too low!\n");
    }
  }
}

int main()
{
  int n = rand() % 100;
  guessANumber(n);
  return 0;
}