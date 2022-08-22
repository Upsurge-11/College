#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guessANumber(int n, int start, int end)
{
  printf("The number is between %d and %d.\n", start, end);
  int guess, count = 0;
  while (1)
  {
    guess = (start + end) / 2;
    count++;
    if (guess == n)
    {
      printf("You Guessed the number :- %d.\n", guess);
      break;
    }
    else if (guess > n)
    {
      printf("%d is bigger than the number!\n", guess);
      end = guess;
    }
    else
    {
      printf("%d is smaller than the number!\n", guess);
      start = guess;
    }
  }
  return count;
}

int main()
{
  srand(time(NULL));
  int n = (rand() % 100) + 1;
  int numberOfTries = guessANumber(n, 0, 99);
  printf("The number was found in %d tries.\n", numberOfTries);

  return 0;
}