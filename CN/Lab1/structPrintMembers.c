#include <stdio.h>

struct info
{
  int rollno;
  char *name;
  float cgpa;
};

struct info assign(int r, char *n, float c)
{
  struct info student;
  student.rollno = r;
  student.name = n;
  student.cgpa = c;

  return student;
}

void print(struct info *student)
{
  printf("ROLL NNUMBER:- %d\n", student->rollno);
  printf("NAME:- %s\n", student->name);
  printf("CGPA:- %f\n", student->cgpa);
}

int main()
{
  struct info huihui = assign(69, "Arghyadeep Mukherjee", 9.69);
  print(&huihui);
  return 0;
}