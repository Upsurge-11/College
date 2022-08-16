#include <stdio.h>

struct huihui
{
  int a;
  int b;
  int c;
  int d;
  int e;
};

struct huihui assign(int a, int b, int c, int d, int e)
{
  struct huihui u;
  u.a = a;
  u.b = b;
  u.c = c;
  u.d = d;
  u.e = e;

  return u;
}

void display(struct huihui *u)
{
  printf("%d %d %d %d %d\n", u->a, u->b, u->c, u->d, u->e);
}

int main()
{
  int a, b, c, d, e;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  struct huihui v = assign(a, b, c, d, e);
  display(&v);
  return 0;
}